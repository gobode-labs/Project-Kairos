#ifndef TRECEPOINT_H
#define TRECEPOINT_H

void attach_to_process(pid_t pid);
void scan_memory(pid_t pid);
void inspect_registers(pid_t pid);
void trigger_symbolic_event(const char* event_type, float severity);

#endif
