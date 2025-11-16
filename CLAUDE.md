# SimpleFlow

Accessibility software for motor impairments. OS-level cursor control via eye/head tracking.

## Tech Stack

### Core
- C++20, CMake, vcpkg (package manager)
- Eigen (linear algebra)
- taskflow (thread pool)
- Custom minimal logger
- nlohmann/json + toml++ (config)
- Google Test (testing)
- The Unlicense

### Input/Tracking
- OpenCV (camera capture)
- MediaPipe (face/head tracking)
- Eye tracking: experimental (MediaPipe Iris, OpenGazer, ONNX models)
- Voice: experimental (Vosk, Whisper.cpp, PocketSphinx)
- Tobii SDK (specialized hardware, Windows)

### OS Integration
- Custom cross-platform cursor wrapper (Win32 + X11/Wayland)
- Dear ImGui (calibration/settings UI)

### Extensions
- VS Code extension (TypeScript)
- WebSocket IPC (core ↔ extensions)
- Browser extension (Chrome/Firefox)

### Deferred
- Word prediction engine (TBD after research)

## Architecture
Feature-based structure:
- `src/core/` - input abstractions
- `src/input/` - tracking implementations (eye, head, webcam)
- `src/cursor/` - OS cursor control
- `src/text/` - text input methods
- `src/config/` - configuration management

## Platforms
- Windows (primary)
- Linux (secondary)

## Key Interfaces
- `InputSource` - abstract input device
- `InputManager` - manages multiple input sources
- `Config` - TOML configuration wrapper

## Build
```powershell
# First time: install vcpkg dependencies
vcpkg install

# Configure and build
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

## Test
```powershell
cd build
ctest
```

## Current Phase
Phase 1: Foundation (input abstraction, config system)

## Agent Usage
- **Explore agent**: Use for "where is X implemented", "find all uses of Y", codebase questions
- **Plan agent**: Use for "how should we implement Z", architecture decisions
- **Avoid agents**: Single file reads, simple greps, sequential TDD work
