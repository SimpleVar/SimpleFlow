# SimpleFlow Roadmap

## Phase 1: Foundation (Current)
Core abstractions and project setup.
- [x] Project structure
- [x] CMake build system
- [x] Input source abstraction
- [x] TOML config system
- [ ] Basic webcam capture

## Phase 2: Tracking Core
Head and eye tracking implementation.
- [ ] MediaPipe integration
- [ ] Head tracking via webcam
- [ ] Basic eye gaze estimation
- [ ] Tobii SDK integration (Windows)
- [ ] Calibration system
- [ ] Smoothing/filtering

## Phase 3: Cursor Control
OS-level cursor manipulation.
- [ ] Windows cursor API
- [ ] X11/Wayland cursor (Linux)
- [ ] Click simulation (dwell, blink)
- [ ] Scroll and drag
- [ ] Precision modes
- [ ] Grid navigation

## Phase 4: Text Input
Multiple text entry methods.
- [ ] Voice dictation (Vosk/Whisper offline)
- [ ] Word prediction engine
- [ ] Virtual keyboard
- [ ] Code-aware suggestions
- [ ] Experimental input methods

## Phase 5: IDE Integration
VS Code extension for coding workflow.
- [ ] VS Code extension scaffold
- [ ] Command palette integration
- [ ] Semantic code actions
- [ ] Gesture-to-action mapping
- [ ] Macro recording

## Phase 6: Browser Extension
Web accessibility layer.
- [ ] Chrome/Firefox extension
- [ ] Link navigation
- [ ] Form filling
- [ ] Tab management
