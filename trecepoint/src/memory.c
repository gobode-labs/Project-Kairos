#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include "trecepoint.h"

/**
 * MODULE: Memory Auditor
 * FUNCTION: scan_memory
 * * This function performs a non-invasive audit of the target process address space.
 * In Linux, /proc/[pid]/maps provides a text representation of the process's 
 * virtual memory, including permissions (read, write, execute) and backing files.
 */
void scan_memory(pid_t pid) {
    char path[64];
    char line[256];
    FILE *maps;

    // Construct the kernel-level path for the target process metadata
    snprintf(path, sizeof(path), "/proc/%d/maps", pid);
    
    // Open the maps file. This requires the same permissions as the target process.
    maps = fopen(path, "r");

    if (maps == NULL) {
        fprintf(stderr, "[-] Critical: Unable to access memory maps for PID %d. check permissions.\n", pid);
        perror("Reason");
        return;
    }

    printf("[*] Trecepoint: Successfully accessed VMA (Virtual Memory Area) for PID %d\n", pid);
    printf("    ADDRESS RANGE           PERMS   OFFSET  DEV   INODE     PATH\n");

    // Iterate through each memory segment (VMA) defined by the kernel
    while (fgets(line, sizeof(line), maps)) {
        // Output each segment for forensic analysis
        printf("    %s", line);
    }

    // Close the file descriptor to prevent resource leaks
    fclose(maps);
}
