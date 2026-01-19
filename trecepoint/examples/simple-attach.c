#include "../include/trecepoint.h"

int main() {
    pid_t pid = 1234; // Replace with target PID
    attach_to_process(pid);
    scan_memory(pid);
    inspect_registers(pid);
    return 0;
}
