from mapping import map_event_to_signal

events = [
    {"type": "HEX_ANOMALY", "severity": 0.6},
    {"type": "MITRE_T1059", "severity": 0.9}
]

for e in events:
    signal = map_event_to_signal(e)
    print(f"{e['type']} → Analog signal: {signal}")
