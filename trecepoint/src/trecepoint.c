#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "trecepoint.h"

/**
 * MODULE: Trecepoint Orchestrator
 * DESCRIPTION: Handles the lifecycle of the forensic audit.
 */

/**
 * attach_to_process:
 * Initiates the ptrace handshake. This is the primary mechanism
 * for pausing a process to perform a memory or register audit.
 */
void attach_to_process(pid_t pid) {
    printf("[*] Trecepoint: Initiating ptrace handshake with PID %d\n", pid);
    /* Note: ptrace(PTRACE_ATTACH, pid, NULL, NULL) will be implemented here */
}

/**
 * main:
 * Entry point for the Trecepoint module.
 * Logic: Validates input, converts CLI argument to pid_t, and triggers the audit.
 */
int main(int argc, char *argv[]) {
    // Validate command line arguments
    if (argc < 2) {
        fprintf(stderr, "[-] Error: Missing Target PID\n");
        fprintf(stderr, "    Usage: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Cast the input string to a Process ID type
    pid_t target_pid = (pid_t)atoi(argv[1]);

    printf("========================================\n");
    printf("     KAIROS: TRECEPOINT FORENSIC AUDIT  \n");
    printf("========================================\n");

    // Execute the modular forensic sequence
    attach_to_process(target_pid);  // Defined in this file
    scan_memory(target_pid);        // Defined in memory.c
    inspect_registers(target_pid);  // Defined in registers.c

    printf("========================================\n");
    printf("Audit sequence finalized for PID %d.\n", target_pid);

    return EXIT_SUCCESS;
}
