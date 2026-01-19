def compute_score(event):
    weights = {
        "REGISTER_HIJACK": 1.0,
        "HEAP_DRIFT": 0.6
    }
    return weights.get(event["type"], 0.1) * event["severity"]
