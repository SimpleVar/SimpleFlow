# Phase 1: Foundation

## Goal
Establish core abstractions and build system for extensible input tracking.

## Tasks

### 1.1 Project Structure [DONE]
- Create directory layout (src/, include/, tests/, config/, lib/, cmake/)
- Feature-based organization (core/, input/, cursor/, text/, config/)

### 1.2 Build System [DONE]
- CMake 3.16+ with C++20
- FetchContent for dependencies (toml++, GoogleTest)
- Separate test target

### 1.3 Input Abstraction [DONE]
- `InputSource` interface: init(), shutdown(), poll(), name()
- `TrackingData` struct: x, y, confidence
- `InputManager`: manages multiple sources, switch active source

### 1.4 Configuration [DONE]
- `Config` class wrapping toml++
- Load/save TOML files
- Dot-notation path access (e.g., "input.sensitivity")
- Default values support

### 1.5 Webcam Capture [PENDING]
- OpenCV VideoCapture wrapper
- Frame grabbing interface
- Camera selection/enumeration
- Basic frame preprocessing

## Dependencies
- toml++ v3.4.0
- GoogleTest v1.14.0
- OpenCV 4.x (for webcam)

## Tests
- test_input_source.cpp - InputSource interface compliance
- test_input_manager.cpp - Manager add/switch/poll
- test_config.cpp - TOML load/save/get/set
