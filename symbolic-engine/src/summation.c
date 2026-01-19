#include "summation.h"
#include <string.h>

float compute_symbolic_score(const char* event_type, float severity) {
    float weight = 0.0;
    if (strcmp(event_type, "HEX_ANOMALY") == 0) weight = 0.4;
    else if (strcmp(event_type, "MITRE_T1059") == 0) weight = 0.8;
    return weight * severity;
}
