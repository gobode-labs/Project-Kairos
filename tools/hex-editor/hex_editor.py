def highlight_hex(data):
    for i, byte in enumerate(data):
        if byte in [0x90, 0xCC]:  # NOP sled or INT3
            print(f"Suspicious byte at {i}: {hex(byte)}")

sample = [0x55, 0x90, 0xCC, 0x8B]
highlight_hex(sample)
