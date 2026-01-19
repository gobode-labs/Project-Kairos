#include "trecepoint.h"
#include "memory.h"
#include "registers.h"
#include "symbolic.h"

void attach_to_process(pid_t pid) {
    // ptrace attach logic
}

void scan_memory(pid_t pid) {
    // read memory regions
}

void inspect_registers(pid_t pid) {
    // read RIP, RSP, RBP, etc.
}
