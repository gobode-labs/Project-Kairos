#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/types.h>
#include "trecepoint.h"

/**
 * MODULE: Register Auditor
 * FUNCTION: inspect_registers
 * * DESCRIPTION: 
 * Interrogates the CPU to retrieve the architectural state of the target PID.
 * This is critical for detecting 'Control Flow Hijacking' by verifying if 
 * the Instruction Pointer (RIP) is executing in unauthorized memory zones.
 */
void inspect_registers(pid_t pid) {
    // user_regs_struct is defined in <sys/user.h> and matches the CPU architecture
    struct user_regs_struct regs;

    // PTRACE_GETREGS copies the target process's general-purpose registers to 'regs'
    if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1) {
        perror("[-] Forensic Error: Failed to fetch CPU registers");
        return;
    }

    printf("[+] Trecepoint: CPU Register State Captured:\n");
    // RIP: The 'brain' of the process, pointing to the current machine code instruction
    printf("    RIP: 0x%llx (Instruction Pointer)\n", regs.rip);
    // RSP: Points to the current top of the stack (used for tracking function calls)
    printf("    RSP: 0x%llx (Stack Pointer)\n", regs.rsp);
    // RAX/RBX: General purpose registers often used for system call indices and math
    printf("    RAX: 0x%llx | RBX: 0x%llx\n", regs.rax, regs.rbx);
}
