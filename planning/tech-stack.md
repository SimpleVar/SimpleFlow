# SimpleFlow Tech Stack

## Core Infrastructure

### Language & Build
- **C++20** - Modern features (concepts, ranges, coroutines)
- **CMake 3.16+** - Build system
- **vcpkg** - Package manager (manifest mode)

### Libraries
- **Eigen3** - Linear algebra, transformations, filtering
- **taskflow** - Parallel task execution, thread pool
- **toml++** - Configuration file parsing
- **nlohmann/json** - JSON for IPC messages
- **Google Test** - Unit/integration testing

## Input & Tracking

### Camera
- **OpenCV 4.x** - Camera capture, image processing, basic CV
- Supports: webcam enumeration, frame capture, preprocessing

### Face/Head Tracking
- **MediaPipe** - Primary (Google's ML solution)
  - Face Mesh for head pose estimation
  - Holistic tracking
  - Good accuracy, heavier resource usage

### Eye Tracking (Experimental - Pick Best)
- **MediaPipe Iris** - Webcam-based gaze
- **OpenGazer** - Open source alternative
- **Custom ONNX** - Research models via ONNX Runtime
- **Tobii SDK** - Specialized hardware (Windows)

### Voice Recognition (Experimental - Pick Best)
- **Vosk** - Offline, lightweight, Kaldi-based
- **Whisper.cpp** - OpenAI Whisper, higher accuracy, heavier
- **PocketSphinx** - Very lightweight, lower accuracy

## OS Integration

### Cursor Control
- **Custom wrapper** - Thin abstraction over platform APIs
  - Windows: Win32 (SetCursorPos, SendInput)
  - Linux: X11/libxdo or Wayland protocols

### GUI
- **Dear ImGui** - Immediate mode GUI
  - Calibration interface
  - Settings panel
  - Debug overlays
  - Lightweight, easy to integrate

## Extensions & IPC

### VS Code Extension
- **TypeScript** - Standard VS Code extension language
- Extension API for command palette, semantic actions
- Local development with VS Code extension host

### Browser Extension
- **Chrome/Firefox WebExtension API**
- JavaScript/TypeScript
- Link navigation, form filling

### Inter-Process Communication
- **WebSocket** - Core ↔ Extensions
  - Local server in C++ core
  - JSON messages
  - Real-time cursor position, commands, state

## Deferred Decisions

### Word Prediction
Options to evaluate:
- **N-gram model** - Statistical, lightweight
- **Markov chains** - Very fast, simple
- **Small transformer** - ONNX Runtime, better accuracy

Will decide after testing with human user feedback.

## Development Tools

### Testing
- Google Test for unit tests
- Integration tests for full pipelines
- Mock input sources for CI

### Debugging
- Custom minimal logger (not spdlog)
- Compile-time log levels
- Performance profiling built-in

## Platform Support

### Primary: Windows
- Win32 API access
- Tobii SDK native
- DirectShow camera fallback

### Secondary: Linux
- X11/Wayland cursor control
- V4L2 camera access
- Wider open source compatibility
