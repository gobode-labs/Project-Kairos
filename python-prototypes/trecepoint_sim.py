from symbolic_engine_sim import compute_score

events = [
    {"type": "REGISTER_HIJACK", "severity": 0.7},
    {"type": "HEAP_DRIFT", "severity": 0.5}
]

for e in events:
    score = compute_score(e)
    print(f"{e['type']} → Score: {score}")
