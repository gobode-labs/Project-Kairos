# TRECEpoint

TRECEpoint is a symbolic debugger and runtime memory analysis tool designed for adversarial detection and symbolic event generation. It monitors heap, stack, and register behavior in live processes and emits symbolic tokens for classification by the Gobode-Labs symbolic engine.

## Features

- Live process attachment and memory inspection
- Symbolic token generation from heap/register anomalies
- MITRE technique mapping via symbolic triggers
- Integration-ready with DAC and symbolic-engine modules
- Lightweight C implementation with test coverage

## Directory Structure

trecepoint/
├── README.md
├── examples/              # Demonstration programs
│   ├── heap-dump-demo.c
│   ├── simple-attach.c
│   └── symbolic-trigger-demo.c
├── include/               # Header files
│   ├── lexical.h
│   ├── memory.h
│   ├── mitre.h
│   ├── registers.h
│   ├── symbolic.h
│   └── trecepoint.h
├── src/                   # Core debugger logic
│   ├── lexical.c
│   ├── memory.c
│   ├── mitre.c
│   ├── registers.c
│   ├── symbolic.c
│   └── trecepoint.c
└── tests/                 # Unit tests
├── test_lexical.c
├── test_memory.c
├── test_mitre.c
└── test_symbolic.c


## Build Instructions

From the root of the project:

```bash
cd trecepoint
make


cd examples
gcc heap-dump-demo.c -o heap_demo
./heap_demo



gcc symbolic-trigger-demo.c -o trigger_demo
./trigger_demo



gcc simple-attach.c -o attach
./attach <pid>


TESTING

Test ALL
make test

gcc -I../include tests/test_memory.c src/memory.c -o test_memory
./test_memory


Integration
TRECEpoint is designed to emit symbolic tokens that can be:

Scored by symbolic-engine

Visualized via memory-visualizer

Translated to analog signals via dac-module

Future Work
Add support for ARM and RISC-V architectures

Real-time symbolic streaming over sockets

Symbolic token compression for embedded use

Integration with FreeRTOS memory maps


Build Everything:
make

Run All Test:
make test

Clean Up:
Make Clean

License
MIT © 2026 Eduardo Morales

