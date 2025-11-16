# SimpleFlow: Complete Project Summary

*Last Updated: 2025-11-16*

---

## Executive Summary

SimpleFlow is an open-source accessibility software project aimed at enabling people with motor impairments to use computers with the same fluidity and capability as able-bodied users. The software provides alternative input methods (eye tracking, head tracking, voice) that integrate deeply with the operating system, IDEs, and web browsers. The ultimate goal is to create software so effective that even non-disabled users adopt it as an enhancement.

---

## Vision & Philosophy

### Core Belief
Physical disability should not prevent anyone from being a productive computer user, programmer, or digital creator. Current accessibility tools are fragmented, interrupt workflow, and fail to support complex tasks like software development.

### Design Principles
1. **Flow State Preservation** - Never interrupt user concentration
2. **Universal Design** - Useful for disabled and non-disabled alike
3. **Modality Agnostic** - Support multiple input methods that users can combine
4. **Context Awareness** - Understand what the user is trying to do, not just track movements
5. **Customizable** - Every user's disability is different; one size doesn't fit all

---

## Target Users

### Primary Focus: Motor Impairments
- Cerebral palsy
- Muscular dystrophy
- ALS/motor neuron disease
- Spinal cord injuries
- Repetitive strain injuries (RSI)
- Parkinson's disease (tremors)
- Limb differences or amputations
- Temporary injuries

### User Personas

**Developer with CP**: Limited fine motor control, can use head movements but not precise mouse control. Needs to write code, navigate IDE, run builds.

**Designer with RSI**: Intermittent pain makes mouse use painful. Needs to switch between mouse and alternative input depending on fatigue.

**Student with Paralysis**: Quadriplegic, can move eyes and speak. Needs full computer control for coursework and communication.

---

## Core Challenges & Solutions

### 1. Input Diversity
**Problem**: Motor impairments vary enormously in type and severity.

**Solution**:
- Multiple input modalities (eye, head, voice)
- Pluggable InputSource architecture
- User-configurable sensitivity and filtering
- Support for both coarse control (limited range) and fine control (limited duration)
- Fatigue-aware adaptations

### 2. Maintaining Flow State
**Problem**: Accessibility tools break concentration with calibration, errors, and mode switching.

**Solution**:
- Seamless input switching
- Predictive actions based on context
- Minimal explicit commands
- Smart error recovery
- Persistent state across sessions

### 3. Complex Task Support (Programming)
**Problem**: Coding requires precise cursor control, rapid text input, complex command sequences.

**Solution**:
- VS Code extension with semantic understanding
- Gesture-to-action mapping (not just cursor clicks)
- Code-aware word prediction
- Macro recording and playback
- Intent-based commands ("go to definition", not "click at x,y")

### 4. Fatigue Management
**Problem**: Alternative inputs can be more tiring than keyboard/mouse.

**Solution**:
- Adaptive dwell times
- Efficiency optimizations (fewer movements needed)
- Multiple text input methods (rest specific muscles)
- Fatigue detection algorithms
- Smart shortcuts and predictions

### 5. Accuracy vs. Accessibility
**Problem**: Webcams are universally available but less accurate than specialized hardware.

**Solution**:
- Support both consumer webcams and Tobii eye trackers
- Multiple precision modes (grid navigation, zoom cursor)
- Temporal filtering and prediction
- Calibration systems
- Graceful degradation based on hardware

---

## Technical Architecture

### System Overview
```
┌─────────────────────────────────────────────────────────────┐
│                        SimpleFlow Core                       │
│                         (C++ Desktop)                        │
├─────────────┬──────────────┬──────────────┬─────────────────┤
│   Input     │   Processing │   Output     │   Extensions    │
│   Layer     │   Layer      │   Layer      │   Layer         │
├─────────────┼──────────────┼──────────────┼─────────────────┤
│ • Camera    │ • Tracking   │ • Cursor     │ • VS Code       │
│ • Tobii SDK │ • Filtering  │ • Text Input │ • Browser       │
│ • Voice     │ • Prediction │ • GUI        │ • WebSocket IPC │
└─────────────┴──────────────┴──────────────┴─────────────────┘
```

### Core Components

**InputSource** (Abstract Interface)
- `init()` - Initialize hardware/resource
- `shutdown()` - Clean up
- `poll()` → TrackingData - Get current position
- `name()` - Identifier for source

**InputManager**
- Manages multiple InputSources
- Switch between active sources
- Future: Combine/blend multiple sources

**Config**
- TOML-based configuration
- Dot-notation access ("input.sensitivity")
- Default values support
- Save/load user preferences

**TrackingData**
- x, y coordinates (normalized 0-1)
- confidence score
- Future: velocity, acceleration, gesture state

---

## Technology Stack

### Core Infrastructure
| Component | Technology | Rationale |
|-----------|-----------|-----------|
| Language | C++20 | Performance critical, low-level OS access |
| Build | CMake 3.16+ | Industry standard, cross-platform |
| Package Mgr | vcpkg | Microsoft's C++ package manager |
| Math | Eigen3 | Linear algebra, transformations |
| Threading | taskflow | Parallel task execution |
| Config | toml++ | Human-readable config files |
| JSON | nlohmann/json | IPC message serialization |
| Testing | Google Test | Unit and integration tests |
| License | The Unlicense | Public domain, maximum freedom |

### Input/Tracking Stack
| Component | Technology | Notes |
|-----------|-----------|-------|
| Camera | OpenCV 4.x | Universal, full-featured |
| Face Tracking | MediaPipe | Google's ML, accurate head pose |
| Eye Tracking | TBD | Testing MediaPipe Iris, OpenGazer, ONNX models |
| Hardware Eye | Tobii SDK | Professional grade (Windows) |
| Voice | TBD | Testing Vosk, Whisper.cpp, PocketSphinx |

### OS Integration
| Component | Technology | Notes |
|-----------|-----------|-------|
| Cursor Control | Custom wrapper | Win32 + X11/Wayland abstraction |
| GUI | Dear ImGui | Lightweight immediate mode |

### Extensions
| Component | Technology | Notes |
|-----------|-----------|-------|
| VS Code | TypeScript | Standard extension language |
| IPC | WebSocket | Core ↔ extensions communication |
| Browser | WebExtension API | Chrome/Firefox support |

---

## Project Structure

```
SimpleFlow/
├── .claude/
│   └── commands/           # Slash commands for Claude
│       ├── build.md        # /build command
│       ├── test.md         # /test command
│       └── run.md          # /run command
├── .git/                   # Git repository
├── .gitignore              # Ignore patterns
├── CLAUDE.md               # Project-specific Claude instructions
├── CMakeLists.txt          # Root build configuration
├── README.md               # Project overview
├── vcpkg.json              # Package manifest
├── config/
│   └── default.toml        # Default configuration
├── docs/
│   └── full-summary.md     # This document
├── include/
│   ├── config/
│   │   └── config.hpp      # Config class (TOML wrapper)
│   └── core/
│       ├── input_manager.hpp  # Manages input sources
│       └── input_source.hpp   # Abstract input interface
├── planning/
│   ├── 0-roadmap.md        # 6-phase roadmap
│   ├── 1-foundation.md     # Phase 1 details
│   └── tech-stack.md       # Technology decisions
├── src/
│   ├── CMakeLists.txt
│   ├── main.cpp            # Entry point (stub)
│   ├── core/               # Core abstractions
│   ├── input/              # Tracking implementations
│   ├── cursor/             # OS cursor control
│   ├── text/               # Text input methods
│   └── config/             # Configuration handling
├── tests/
│   ├── CMakeLists.txt
│   ├── test_main.cpp       # Placeholder test
│   ├── test_input_source.cpp   # InputSource tests
│   ├── test_input_manager.cpp  # InputManager tests
│   └── test_config.cpp     # Config tests
├── cmake/                  # CMake modules
└── lib/                    # Third-party libs
```

---

## Development Workflow

### Strict TDD Process
1. **Red** - Write failing test first
2. **Green** - Minimal code to pass
3. **Refactor** - Clean up, optimize
4. **Verify** - Run all tests
5. **Commit** - When explicitly asked
6. **Push** - After commit

### Code Standards
- Zero comments (tests document behavior)
- Ultra-concise naming (u, i, err, ctx, mgr, src)
- Performance first
- No raw pointers for ownership
- RAII for resources
- Const correctness
- All error paths handled
- All inputs validated

### Git Workflow
- Commits only when explicitly requested
- Never auto-push
- Only interact with SimpleFlow repository
- Private repository (SimpleVar/SimpleFlow)

### Build Commands
```powershell
# Install dependencies
vcpkg install

# Configure
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[vcpkg]/scripts/buildsystems/vcpkg.cmake

# Build
cmake --build .

# Test
ctest
```

---

## Current Implementation Status

### Completed
- [x] Project structure created
- [x] CMake build system configured
- [x] vcpkg integration
- [x] InputSource abstract interface
- [x] InputManager for multiple sources
- [x] Config class with TOML support
- [x] Basic test suite structure
- [x] Default configuration file
- [x] Project documentation (README, CLAUDE.md)
- [x] Planning documents (roadmap, phases)
- [x] GitHub repository created
- [x] Initial commit pushed

### Not Yet Implemented
- [ ] Webcam capture (OpenCV integration)
- [ ] Head tracking (MediaPipe)
- [ ] Eye tracking (any method)
- [ ] Voice recognition
- [ ] Cursor control (OS integration)
- [ ] GUI (Dear ImGui)
- [ ] VS Code extension
- [ ] Browser extension
- [ ] Text prediction
- [ ] Calibration system
- [ ] Filtering/smoothing algorithms

---

## Development Phases

### Phase 1: Foundation (Current)
Core abstractions and infrastructure.
- Input source interface ✓
- Configuration system ✓
- Webcam capture (pending)

### Phase 2: Tracking Core
Computer vision and ML integration.
- MediaPipe face mesh
- Head pose estimation
- Basic gaze tracking
- Calibration
- Temporal filtering

### Phase 3: Cursor Control
OS-level mouse manipulation.
- Windows API integration
- Linux X11/Wayland
- Dwell clicking
- Precision modes
- Grid navigation

### Phase 4: Text Input
Alternative text entry methods.
- Voice dictation (offline)
- Word prediction
- Virtual keyboard
- Code-aware suggestions

### Phase 5: IDE Integration
VS Code extension for programming.
- Semantic code actions
- Gesture mapping
- Macro system
- Debug support

### Phase 6: Browser Extension
Web accessibility layer.
- Link navigation
- Form filling
- Tab management
- Scroll control

---

## Required Research & Expertise

### Computer Vision & ML
- Face landmark detection accuracy
- Gaze estimation from monocular camera
- Real-time inference optimization
- Model quantization (ONNX)
- Temporal consistency in predictions

### Human-Computer Interaction
- Fitts' Law for alternative inputs
- Cognitive load in assistive tech
- Error tolerance design
- Feedback mechanisms
- Learning curves for new input methods

### Speech Recognition
- Offline acoustic models
- Code/programming vocabulary
- Command vs. dictation mode switching
- Speaker adaptation
- Noise robustness

### Systems Programming
- Low-latency input processing
- Cross-platform OS hooks
- Memory management in real-time
- Thread synchronization
- Resource cleanup

### Accessibility Domain
- WCAG compliance
- ADA/Section 508 requirements
- Existing AT interoperability
- User testing methodologies
- Ethical considerations

### Signal Processing
- Kalman filtering for tracking
- Jitter reduction
- Predictive smoothing
- Gesture recognition from noisy data
- Adaptive thresholding

---

## Open Questions & Deferred Decisions

### Eye Tracking Method
**Options**: MediaPipe Iris, OpenGazer, custom ONNX models, Tobii-only
**Decision**: Test all, choose based on accuracy/performance tradeoffs with human tester feedback

### Voice Recognition Engine
**Options**: Vosk (lightweight), Whisper.cpp (accurate but heavy), PocketSphinx (very light)
**Decision**: Benchmark all three with disabled users, choose based on real-world performance

### Word Prediction Engine
**Options**: N-gram statistical, Markov chains, small transformer (ONNX)
**Decision**: Deferred to Phase 4, will research accuracy vs. resource usage

### Cross-Platform Cursor Library
**Chosen**: Custom thin wrapper over platform APIs
**Rationale**: More control, less dependencies, specific to our needs

---

## User Testing Strategy

### Feedback Loop
1. Build feature with minimal viable implementation
2. Test with human user (motor impairment)
3. Collect qualitative and quantitative feedback
4. Iterate based on real usage patterns
5. Refine before moving to next feature

### Key Metrics
- Task completion time
- Error rate
- User fatigue level
- Flow interruptions
- Learning curve steepness
- User satisfaction (qualitative)

---

## Risk Assessment

### Technical Risks
1. **Webcam tracking accuracy insufficient** - Mitigation: Support Tobii hardware fallback
2. **Latency too high for flow** - Mitigation: C++ performance, efficient algorithms
3. **Voice recognition poor in noisy environment** - Mitigation: Multiple input options, push-to-talk
4. **Cross-platform complexity** - Mitigation: Abstract early, test both Windows and Linux

### Project Risks
1. **Scope creep** - Mitigation: Phased approach, MVP first
2. **No user feedback** - Mitigation: Human tester committed, iterate early
3. **Dependency on external libs** - Mitigation: vcpkg management, version pinning

---

## Next Steps

### Immediate (Phase 1 Completion)
1. Integrate OpenCV for webcam capture
2. Create WebcamSource implementing InputSource
3. Test camera enumeration and frame capture
4. Basic frame preprocessing

### Short-term (Phase 2 Start)
1. Integrate MediaPipe C++ bindings
2. Implement HeadTrackingSource
3. Build calibration procedure
4. Add smoothing/filtering layer

### Medium-term
1. Prototype cursor control on Windows
2. First end-to-end test (head → cursor)
3. User testing with human participant
4. Iterate based on feedback

---

## Repository Information

**GitHub**: https://github.com/SimpleVar/SimpleFlow
**License**: The Unlicense (public domain)
**Primary Language**: C++
**Initial Commit**: 2025-11-16
**Files**: 22
**Lines of Code**: 761 (initial)

---

## Conclusion

SimpleFlow is an ambitious project addressing a real gap in accessibility software. By focusing on motor impairments first, using modern C++ with proven libraries, and building with user feedback from the start, the project has a solid foundation for success. The modular architecture allows for experimentation with different tracking methods while maintaining a stable core. The emphasis on flow state preservation and complex task support (especially programming) differentiates this from existing accessibility tools.

The next critical step is completing the input pipeline (camera → tracking → cursor) and getting real user feedback to validate the approach before investing in advanced features.

---

*This document serves as the canonical reference for the SimpleFlow project. Update as decisions are made and features are implemented.*
