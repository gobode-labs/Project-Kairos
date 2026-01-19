def map_event_to_signal(event):
    weights = {
        "HEX_ANOMALY": 0.4,
        "MITRE_T1059": 0.8
    }
    return weights.get(event["type"], 0.1) * event["severity"]
