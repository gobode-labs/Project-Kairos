#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "trecepoint.h"

/**
 * attach_to_process:
 * Initiates a PTRACE_ATTACH signal. The kernel will send a SIGSTOP to 
 * the target, ensuring a static state for memory and register consistency.
 */
void attach_to_process(pid_t pid) {
    printf("[*] Trecepoint: Initiating ptrace handshake with PID %d\n", pid);
    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
        perror("[-] PTRACE_ATTACH failed");
        exit(EXIT_FAILURE);
    }
    // Synchronize with the kernel to confirm the process has entered a stopped state
    waitpid(pid, NULL, 0);
    printf("[+] Process suspended for forensic audit.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t target_pid = (pid_t)atoi(argv[1]);

    printf("========================================\n");
    printf("     KAIROS: TRECEPOINT FORENSIC AUDIT  \n");
    printf("========================================\n");

    // Start Forensic Sequence
    attach_to_process(target_pid);
    scan_memory(target_pid);
    inspect_registers(target_pid);

    // CRITICAL: DETACH
    // This resumes the process. Without this, the target remains a 'Zombie' or 'Stopped' process.
    if (ptrace(PTRACE_DETACH, target_pid, NULL, NULL) == -1) {
        perror("[-] PTRACE_DETACH failed");
    } else {
        printf("[+] Trecepoint: Detached successfully. PID %d resumed.\n", target_pid);
    }

    printf("========================================\n");
    return EXIT_SUCCESS;
}
