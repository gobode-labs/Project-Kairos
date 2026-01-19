# Summation Logic

We define a symbolic score function:

S(t) = Σ(w_i * e_i)

Where:
- e_i: symbolic event (e.g., HEX anomaly, heap drift)
- w_i: weight assigned to event type

Thresholds:
- S(t) > 0.8 → trigger DAC alert
- S(t) > 1.2 → halt execution
