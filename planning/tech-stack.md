# SimpleFlow Tech Stack

## Core Infrastructure

### Language & Build
- **C++20** - Modern features (concepts, ranges, modules)
- **CMake 3.16+** - Build system
- **vcpkg** - Package manager (manifest mode)

### Libraries
- **Eigen3** - Linear algebra, homography transformations, Kalman filtering
- **taskflow** - Producer-consumer threading, parallel task execution
- **toml++** - Configuration file parsing (user preferences, calibration)
- **nlohmann/json** - JSON for WebSocket IPC messages
- **Google Test** - Unit/integration testing (TDD approach)

---

## Input & Tracking

### Camera Capture
- **OpenCV 4.x** - Webcam enumeration, frame capture, image preprocessing
- Error handling: camera disconnect, permission denied, no camera found
- 720p/1080p support

### Eye Tracking ✅ DECIDED
- **MediaPipe Iris** - Primary method
  - 468 face landmarks + 10 iris landmarks
  - 1.4-2.5° gaze accuracy achievable
  - $0 cost (uses standard webcam)
  - Cross-platform (Windows, Linux, macOS)
  - 30+ FPS on consumer hardware
  - GPU acceleration available but not required

### Gaze Estimation
- **5-point homography calibration** - 0.75° accuracy in 30 seconds
- **One Euro Filter** - Adaptive smoothing (<2ms overhead)
  - Balances jitter reduction vs lag
  - Parameters: min cutoff, beta, d cutoff
- **3D face pose estimation** - Maps iris position to screen coordinates

### Head Tracking
- **MediaPipe Face Mesh** - Head pose estimation
- Coarse navigation complement to eye gaze
- **Kalman filter** - Sensor fusion (eye+head)

### Voice Recognition ✅ DECIDED
- **Vosk** - Real-time voice commands
  - Offline, lightweight, Kaldi-based
  - <200ms latency target
  - >95% accuracy for 100-word command vocabulary
  - No cloud dependency, privacy-preserving

- **Whisper.cpp** - High-accuracy dictation
  - OpenAI Whisper ported to C++
  - 2.5% WER (word error rate)
  - Prose and code dictation
  - Mode switching (command vs dictation)

### Word Prediction ✅ DECIDED
- **N-gram model** - Primary algorithm (Phase 4)
  - Statistical, lightweight, <50ms inference
  - >40% keystroke savings target
  - <100MB model size
  - Integration with virtual keyboard and voice dictation

---

## Cursor Control

### OS Integration
- **Windows API** (Primary)
  - Win32: SetCursorPos, SendInput, mouse_event
  - Click simulation (left, right, double, drag)
  - Scroll wheel emulation
  - Permission handling

- **Linux** (Phase 8+, deferred)
  - X11/libxdo or Wayland protocols
  - V4L2 camera access

### Precision Modes
- **Grid overlay** - Hierarchical half-screen selection
- **Zoom lens** - Fine targeting for small elements
- **Snap-to-target** - Nearest clickable element detection

### Adaptive Systems
- **Adaptive dwell time** - 400-800ms range based on target size and fatigue
- **Error rate monitoring** - Automatic adjustment
- **Fatigue detection** - Blink rate, fixation duration, saccade velocity analysis
- **Intent prediction** - Gaze pattern analysis for predictive clicking

---

## User Interface

### GUI Framework
- **Dear ImGui** - Immediate mode GUI
  - Calibration wizard (5-point)
  - Settings panel (gaze/voice controllable)
  - Debug overlays (FPS, latency, accuracy)
  - Onboarding tutorial
  - Virtual keyboard (hierarchical selection)
  - Lightweight, easy to integrate

### Configuration UI
- Voice-controllable settings
- Gaze-based navigation
- Profile save/load
- No TOML editing required (accessible)

---

## Extensions & IPC

### VS Code Extension (Phase 5)
- **TypeScript** - Standard VS Code extension language
- **WebSocket IPC** - Core ↔ Extension communication
  - Local server in C++ core
  - JSON messages for commands and state
  - Real-time cursor position
- Code-aware commands (go to definition, find references, rename)
- LSP integration for semantic actions

### Inter-Process Communication
- **WebSocket server** - C++ core hosts local server
- **JSON protocol** - Structured messages
- Low latency for real-time interaction

---

## Data & Privacy

### Metrics Collection (Opt-in)
- **Local storage** - SQLite or binary format
- Gaze patterns, blink rate, fixation duration, saccade velocity
- Foundation for ML (fatigue detection, intent prediction)
- User controls: enable/disable, clear data, export
- **Privacy-preserving**: Data never leaves device without explicit consent
- Storage size limits and rotation

### Configuration Persistence
- **TOML files** - Human-readable, easy to edit manually if needed
- Calibration matrices (homography)
- User preferences (dwell time, sensitivity)
- Voice command customization
- Profile system (multiple users/setups)

---

## Performance

### Threading Architecture ✅ DECIDED
- **Producer-consumer pattern** - 52-379% FPS improvement
  - Camera capture thread (producer)
  - MediaPipe processing thread (consumer)
  - Cursor update thread
- **taskflow** - Thread pool management
- Target: <50ms end-to-end latency

### Performance Monitoring
- FPS counter (rolling average)
- Latency tracker (camera → screen)
- Accuracy self-test mode
- Diagnostic mode for troubleshooting
- CPU usage monitoring (<40% target)

---

## Development & Testing

### Testing Framework
- **Google Test** - Unit and integration tests
- TDD approach: tests first, then implementation
- Mock input sources for CI
- Accuracy validation tests

### Debugging
- Custom minimal logger (compile-time levels)
- Performance profiling built-in
- Error tracking and recovery

### CI/CD
- GitHub Actions for build verification
- Cross-platform build testing (Windows primary)
- Automated test suite

---

## Platform Support

### Primary: Windows
- Win32 API for cursor control
- DirectShow camera fallback
- Full feature set
- Primary development target

### Secondary: Linux (Phase 8+)
- X11/Wayland cursor control
- V4L2 camera access
- Deferred until Windows version proven

---

## Upgrade Paths (Future)

### Hardware Upgrades
- **Tobii SDK** - Optional integration for <0.6° precision ($230+ hardware)
- Premium option for users who need sub-degree accuracy

### AI Enhancements (Phase 8)
- **Intent prediction ML** - >80% click prediction accuracy
- **Transformer models** - Enhanced word/code prediction (if NPU tech matures)
- **Personalized adaptation** - ML learns user preferences

### Separate Projects (Not Integrated)
- **Chord input system** - Standalone tool using SimpleFlow architecture
- **Accessibility-first programming language** - Research project using SimpleFlow as input
