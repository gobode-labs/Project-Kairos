#ifndef TRECEPOINT_H
#define TRECEPOINT_H

#include <sys/types.h> /* Provides pid_t definition for process IDs */
#include <unistd.h>    /* Provides POSIX standard API constants */

/**
 * PROJECT: Project-Kairos
 * MODULE:  Trecepoint Debugger
 * * DESCRIPTION:
 * Defines the core forensic interface for process attachment, 
 * memory scanning, and register inspection.
 */

/**
 * @brief Establishes a ptrace connection to a target process.
 * @param pid The Process ID of the target to audit.
 */
void attach_to_process(pid_t pid);

/**
 * @brief Performs a linear scan of the target process's virtual memory maps.
 * @param pid The Process ID of the target.
 */
void scan_memory(pid_t pid);

/**
 * @brief Captures and prints the current state of CPU registers.
 * @param pid The Process ID of the target.
 */
void inspect_registers(pid_t pid);

#endif /* TRECEPOINT_H */
