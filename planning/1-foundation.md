# Phase 1: Foundation (Weeks 1-6)

## Goal
Core abstractions + MediaPipe accuracy validation + metrics collection framework

## Tasks

### 1.1 Input Abstraction (Week 1)
- `InputSource` interface: init(), shutdown(), poll(), name()
- `TrackingData` struct: x, y, confidence, timestamp
- `InputManager`: manages multiple sources, switch active source
- TDD: write tests first

**Tests:**
- test_input_source.cpp - InputSource interface compliance
- test_input_manager.cpp - Manager add/switch/poll

### 1.2 Configuration System (Week 2)
- `Config` class wrapping toml++
- Load/save TOML files
- Dot-notation path access (e.g., "input.sensitivity")
- Default values support
- Cross-session persistence (calibration matrices, preferences)

**Tests:**
- test_config.cpp - TOML load/save/get/set

### 1.3 Webcam Capture (Week 2)
- OpenCV VideoCapture wrapper
- Camera selection/enumeration
- Frame grabbing interface
- Basic frame preprocessing
- Error handling: camera disconnect, permission denied, no camera found
- Graceful degradation on failure

**Tests:**
- test_webcam.cpp - Camera operations, error handling

### 1.4 MediaPipe Integration (Week 3-4)
- Add MediaPipe to vcpkg dependencies
- Create wrapper class for face mesh + iris
- Extract 468 face landmarks + 10 iris landmarks
- Producer-consumer threading pattern
- Benchmark: single-threaded vs multi-threaded FPS
- **Answer RQ-002: Threading Performance**

**Success Criteria:**
- 30+ FPS sustained
- <50ms latency
- <40% CPU usage
- 52-379% FPS improvement from threading

**Tests:**
- test_mediapipe.cpp - Landmark extraction, threading

### 1.5 Gaze Estimation + Calibration (Week 5-6)
- 3D face pose estimation from landmarks
- Map iris position to screen coordinates
- 5-point calibration system
  - Display calibration points sequentially
  - Collect gaze data at each point
  - Compute homography transformation matrix
- Apply calibration to gaze estimation
- One Euro Filter for smoothing
  - Tune parameters (min cutoff, beta, d cutoff)
  - Measure jitter reduction and lag introduced
- **Answer RQ-001: MediaPipe Actual Accuracy**

**Success Criteria:**
- Central screen: <2° visual angle error
- Edge screen: <3° visual angle error
- Works with 720p and 1080p webcams
- Works in typical indoor lighting (200-500 lux)

**Tests:**
- test_gaze_estimation.cpp - Calibration, accuracy
- test_one_euro_filter.cpp - Smoothing parameters

### 1.6 Performance & Privacy Foundation (Throughout)
- FPS counter with rolling average
- Latency tracker (camera → screen update)
- Accuracy self-test mode
- Privacy-by-default: no gaze logging, no telemetry without consent
- Error recovery: graceful degradation when components fail
- Diagnostic mode for troubleshooting (toggle on/off)

**Tests:**
- test_performance.cpp - Metrics accuracy
- test_privacy.cpp - No logging by default

### 1.7 Opt-in Metrics Collection Framework (Week 6)
- Local storage for gaze patterns (SQLite or binary format)
- Metrics: blink rate, fixation duration, saccade velocity, gaze jitter
- Foundation for future ML (intent prediction, fatigue detection)
- User controls: enable/disable, clear data, export to file
- Privacy-preserving: data never leaves device without explicit consent
- Storage size limits and rotation

**Tests:**
- test_metrics.cpp - Storage, retrieval, privacy controls

## Dependencies
- toml++ v3.4.0
- GoogleTest v1.14.0
- OpenCV 4.x (for webcam)
- MediaPipe (face mesh, iris)
- Eigen (linear algebra)
- taskflow (threading)

## Deliverables
- Working build system (CMake + vcpkg)
- InputSource abstraction with comprehensive tests
- Config system with persistence
- Webcam capture with error handling
- MediaPipe integration with threading
- Gaze tracking with 5-point calibration
- One Euro Filter smoothing
- Accuracy measurements validated (RQ-001 answered)
- Threading performance proven (RQ-002 answered)
- Performance monitoring dashboard
- Privacy-respecting data handling
- Opt-in metrics collection framework

## Research Questions Answered
- **RQ-001:** MediaPipe Iris + homography accuracy (target: <2.5°)
- **RQ-002:** Threading performance improvement (target: 52%+ FPS gain)

## Decision Point
**End of Phase 1:** Is MediaPipe accuracy sufficient for UI interaction?
- If YES: Continue with webcam-based approach
- If NO: Pivot to Tobii SDK integration or hybrid approach

## Notes
- TDD approach: tests first, then implementation
- Privacy-by-default: no data collection without explicit opt-in
- Error handling everywhere: users with disabilities can't afford crashes
- Performance monitoring from day 1: catch regressions early
- Metrics collection framework enables Phase 6 (fatigue detection) and Phase 8 (intent prediction)
