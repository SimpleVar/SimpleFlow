# SimpleFlow Master Plan

**Date:** 2025-11-16
**Status:** Research Complete → Implementation Starting

---

## Executive Summary

**Project:** Accessibility software for motor impairments using gaze+voice+head tracking for OS-level cursor control.

**Research Validation:**
- Webcam eye tracking: 1.4-2.5° accuracy achievable (sufficient for UI)
- Multi-modal reduces errors: 43% → 11.7% (75% reduction)
- Target market: 7.8M-30M users globally (RSI developers = 1-2M)
- Latency: 38-58ms achievable (<75ms required)
- Competitive gap: No tool combines gaze+voice+AI for programming

**Decision:** ✅ **GO** - Proceed with implementation

---

## Part 1: Unanswered Research Questions

### Critical (Must Answer During Implementation)

#### RQ-001: MediaPipe Actual Accuracy
**Question:** Does MediaPipe Iris + homography achieve 1.4-2.5° on real hardware?

**How to Answer:**
1. Implement MediaPipe integration
2. Build 5-point calibration
3. Measure accuracy across screen regions
4. Test multiple webcams (720p, 1080p) and lighting conditions

**Success:** Central <2°, edge <3°, typical indoor lighting
**Timeline:** Phase 1 (weeks 5-6)

---

#### RQ-002: Threading Performance
**Question:** Does producer-consumer threading deliver 52-379% FPS improvement?

**How to Answer:**
1. Build threaded camera capture
2. Benchmark single vs multi-threaded MediaPipe
3. Profile on target hardware (Intel i5 8th gen, 8GB)

**Success:** 30+ FPS sustained, <50ms latency, <40% CPU
**Timeline:** Phase 1 (weeks 3-4)

---

#### RQ-003: Voice Recognition Latency
**Question:** Can Vosk achieve <200ms speech-to-action with >95% accuracy?

**How to Answer:**
1. Integrate Vosk streaming
2. Define 100-word command vocabulary
3. Measure end-to-end latency and accuracy
4. Test noise conditions and accents

**Success:** <200ms latency, >95% accuracy, no false activations
**Timeline:** Phase 2 (weeks 7-8)

---

#### RQ-004: Grid Size Optimization
**Question:** What grid subdivision minimizes clicks for precision mode?

**How to Answer:**
1. Implement multiple grids (2x2, 3x3, 4x4, hierarchical)
2. User testing with different target sizes
3. Measure time-to-target and error rates

**Success:** <3 clicks for 44px targets, <2 seconds total
**Timeline:** Phase 3 (week 13)

---

#### RQ-005: Universal IDE Features
**Question:** Can UI Automation APIs provide code-aware features without per-IDE extensions?

**How to Answer:**
1. Research Windows UIA capabilities
2. Prototype: read file, cursor position, symbols
3. Test with VS Code, IntelliJ, Notepad++
4. Evaluate coverage vs dedicated extension

**Success:** >80% of needed IDE features accessible
**Timeline:** Phase 4 (week 18) and Phase 5 (weeks 19-22)

---

#### RQ-006: Fatigue Detection Accuracy
**Question:** Can we detect fatigue >85% using only gaze metrics?

**How to Answer:**
1. Collect gaze metrics during extended sessions (Phase 1-5 data)
2. Collect self-reported fatigue scores
3. Build and validate classifier
4. Test proactive detection (before user notices)

**Success:** >85% accuracy, <15% false positives
**Timeline:** Phase 6 (weeks 23-26)

---

#### RQ-011: Word Prediction Algorithm Selection
**Question:** Which prediction algorithm achieves >40% keystroke savings in <50ms latency?

**How to Answer:**
1. Benchmark algorithms: n-gram, RNN (LSTM/GRU), transformer (TinyLlama)
2. Test on general text and code datasets
3. Measure keystroke savings, top-1/top-3 accuracy, inference time
4. Evaluate model size vs performance trade-offs

**Success:** Select algorithm with >40% keystroke savings, <50ms inference, <100MB model
**Timeline:** Phase 4 (week 16)

---

#### RQ-012: Virtual Keyboard Usability
**Question:** Does hierarchical gaze keyboard achieve usable text entry speeds as voice fallback?

**How to Answer:**
1. Implement hierarchical half-screen selection (proven OptiKey approach)
2. Integrate word prediction suggestions
3. Measure WPM with gaze-only, gaze+voice confirm
4. User testing: library scenarios, speech impairment simulation

**Success:** >10 WPM achievable (adequate for fallback, not primary method)
**Timeline:** Phase 4 (week 17)

---

### Strategic (Answer During Beta)

#### RQ-007: Productivity Loss Tolerance
**Question:** Maximum acceptable productivity loss for developer adoption?

**How to Answer:** Beta user study (baseline vs SimpleFlow performance)
**Success:** <20% loss, >60% retention, reduced pain/fatigue
**Timeline:** Phase 7 (weeks 27-34)

---

#### RQ-008: Switch Scanning Demand
**Question:** Market size for users without eye/head control?

**How to Answer:** User surveys, OT interviews, competitive analysis
**Decision:** If >10% of market needs it → add to roadmap
**Timeline:** Phase 7 (concurrent with beta)

---

### Future (Monitor)

**RQ-009:** On-device LLM viability for code prediction (<50ms inference)
**RQ-010:** Monetization without excluding disabled users
**RQ-013:** Programming Text Entry Optimization (local LLMs for code completion)

---

### Separate Projects (High Value, Wrong Vehicle)

These ideas have revolutionary potential but would derail SimpleFlow's core mission. Recommended as independent projects that integrate with SimpleFlow.

#### Chord Input System
**Opportunity:** 40-80 WPM potential, >30 WPM for motor-impaired users
**Why Separate:** Requires custom hardware, 3-6 month learning curve, entire parallel codebase
**Recommendation:** Build as standalone tool that uses SimpleFlow's multi-modal architecture
**Value:** Very high for power users willing to invest in learning

#### Accessibility-First Programming Language
**Opportunity:** >30% faster code entry, eliminates symbol burden, voice-dictation-friendly syntax
**Why Separate:** Multi-year project (parser, transpiler, tooling, ecosystem), extreme scope
**Recommendation:** Research project that could use SimpleFlow as input method
**Value:** Revolutionary if successful, could define industry

---

## Part 2: Implementation Phases

### Phase 1: Foundation (Weeks 1-6)
**Goal:** Core abstractions + MediaPipe accuracy validation

**Tasks:**
1. **Input Abstraction** (Week 1)
   - `InputSource` interface (init, shutdown, poll)
   - `TrackingData` struct (x, y, confidence)
   - `InputManager` (multiple sources)
   - TDD: tests first

2. **Configuration System** (Week 2)
   - TOML file load/save
   - Dot-notation access
   - Default values
   - Cross-session persistence (calibration, preferences)

3. **Webcam Capture** (Week 2)
   - OpenCV VideoCapture wrapper
   - Camera enumeration
   - Frame grabbing
   - Error handling (camera disconnect, permission denied)

4. **MediaPipe Integration** (Week 3-4)
   - Face mesh + iris landmarks
   - Threading architecture (producer-consumer)
   - **Answer RQ-002**

5. **Gaze Estimation + Calibration** (Week 5-6)
   - 3D face pose → screen coordinates
   - 5-point homography calibration
   - One Euro Filter smoothing
   - **Answer RQ-001**

6. **Performance & Privacy Foundation** (Throughout)
   - FPS counter, latency tracker, accuracy self-test
   - Privacy-by-default: no gaze logging, no telemetry without consent
   - Error recovery: graceful degradation when components fail
   - Diagnostic mode for troubleshooting

7. **Opt-in Metrics Collection Framework** (Week 6)
   - Local storage for gaze patterns, blink rate, fixation duration
   - Foundation for future ML (intent prediction, fatigue detection)
   - User controls: enable/disable, clear data, export
   - Privacy-preserving: data never leaves device without consent

**Deliverables:**
- Working build system
- Gaze tracking with calibration
- Accuracy measurements validated
- Threading performance proven
- Performance monitoring dashboard
- Privacy-respecting data handling
- Metrics collection framework (opt-in, local)

---

### Phase 2: Multi-Modal Core (Weeks 7-10)
**Goal:** Gaze+voice fundamental interaction

**Tasks:**
1. **Voice Recognition** (Week 7-8)
   - Vosk integration (streaming)
   - Command vocabulary (click, scroll, undo, etc.)
   - Latency and accuracy measurement
   - Error handling (mic disconnect, recognition failure)
   - **Answer RQ-003**

2. **Dwell Clicking** (Week 8)
   - Gaze stability detection
   - Configurable dwell time (600ms default)
   - Visual feedback (progress indicator)
   - Cancel on movement threshold

3. **Gaze+Voice Fusion** (Week 9)
   - Temporal correlation
   - "Click" at gaze position
   - Modality state machine
   - Fallback logic (voice fails → dwell, gaze fails → voice-only)

4. **Basic Configuration UI** (Week 9)
   - Voice-controllable settings (say "increase dwell time")
   - Adjust dwell time, sensitivity, volume threshold
   - Minimal but accessible (no TOML editing required)

5. **Adaptive Dwell** (Week 10)
   - Error rate monitoring
   - Target size adjustment
   - Range: 400-800ms
   - Start collecting fatigue metrics (blink rate, fixation duration)

6. **Bootstrap Mode** (Week 10)
   - Voice-only setup for users without working cursor
   - Simplified calibration (voice-guided)
   - Accessibility of SimpleFlow itself

**Deliverables:**
- Gaze+voice clicking working
- Dwell fallback for voice-free environments
- Error rate <15% (down from 43% gaze-only)
- Basic voice-controllable settings
- Bootstrap mode for accessible setup
- Fatigue metrics collection started

---

### Phase 3: Cursor Control (Weeks 11-14)
**Goal:** Full OS-level cursor manipulation + user-facing UX

**Tasks:**
1. **Windows Cursor API** (Week 11)
   - SetCursorPos, mouse_event
   - Click simulation (left, right, double)
   - Permission handling

2. **Scroll and Drag** (Week 12)
   - Scroll wheel simulation
   - Drag/drop via voice commands
   - Edge scrolling (gaze at screen edge)

3. **Precision Modes + Configuration UI** (Week 13)
   - Grid overlay (hierarchical half-screen selection)
   - Zoom lens for fine targeting
   - Snap-to-target (nearest clickable element)
   - Enhanced Config UI (gaze/voice-controllable settings panel)
   - Save/load profiles
   - **Answer RQ-004**

4. **Head Tracking + Onboarding** (Week 14)
   - MediaPipe head pose
   - Head for coarse navigation
   - Sensor fusion (eye+head Kalman filter)
   - First-run calibration wizard
   - Interactive tutorial (gaze here, say this)
   - Progressive disclosure (basic → advanced features)
   - Tooltip system for discoverability

**Deliverables:**
- Complete cursor control (move, click, scroll, drag)
- Precision mode optimized
- Head tracking integrated
- Accessible configuration UI
- Guided onboarding experience

---

### Phase 4: Text Input (Weeks 15-18)
**Goal:** Voice dictation + virtual keyboard fallback

**Tasks:**
1. **Whisper.cpp Integration** (Week 15)
   - High-accuracy dictation engine
   - Hybrid: Vosk (commands) + Whisper (dictation)
   - Mode switching (command vs dictation)
   - Benchmark accuracy and latency

2. **Word Prediction Algorithm** (Week 16)
   - Implement n-gram based prediction (bounded scope)
   - Measure keystroke savings and latency
   - Integration with voice dictation and virtual keyboard
   - **Answer RQ-011**

3. **Virtual Keyboard** (Week 17)
   - Hierarchical half-screen selection (proven approach)
   - Gaze-based key selection with dwell/voice confirm
   - Word prediction integration (suggestion bar)
   - Essential fallback for voice-free environments
   - **Answer RQ-012**

4. **Code Dictation** (Week 18)
   - Code-aware vocabulary (keywords, symbols)
   - Formatting commands (new line, indent, tab)
   - Identifier dictation (camel case, snake case)
   - Symbol shortcuts ("dot", "open paren", "equals")
   - Text field auto-detection (Windows UI Automation)
   - **Start RQ-005**

**Deliverables:**
- Voice dictation working (prose and code)
- Virtual keyboard with hierarchical selection
- Word prediction with >40% keystroke savings
- Code-aware dictation commands
- Multiple text entry methods (voice primary, keyboard fallback)

**🎯 MVP Complete at End of Phase 4**

---

### Phase 5: IDE Integration (Weeks 19-22)
**Goal:** VS Code extension for professional coding

**Tasks:**
1. **VS Code Extension Scaffold** (Week 19)
   - TypeScript extension project
   - WebSocket IPC (core ↔ extension)
   - Basic command mapping
   - Status bar indicator

2. **Code-Aware Commands** (Week 20-21)
   - Go to definition (gaze at symbol + "go to definition")
   - Find references, rename symbol
   - Run tests, toggle breakpoint
   - Error navigation ("next error", "previous error")

3. **Semantic Actions** (Week 22)
   - LSP integration for intelligent suggestions
   - Context-aware completions
   - Code snippet insertion via voice
   - **Complete RQ-005**

**Deliverables:**
- VS Code extension working
- Code-aware voice commands
- IDE integration proven valuable

---

### Phase 6: Fatigue & Adaptive Systems (Weeks 23-26)
**Goal:** Intelligent adaptation based on user state

**Tasks:**
1. **Fatigue Detection Classifier** (Week 23-24)
   - Analyze collected metrics (blink rate, fixation duration, saccade velocity)
   - Build threshold-based or ML classifier
   - Self-reported fatigue validation
   - **Answer RQ-006**

2. **Adaptive UI** (Week 25)
   - Increase target sizes when fatigued
   - Adjust dwell time based on fatigue level
   - Suggest breaks proactively (before user notices)
   - Reduce visual complexity when strained

3. **Intent Prediction Foundation** (Week 26)
   - Analyze collected gaze+click data
   - Feature extraction (velocity, trajectory, fixation patterns)
   - Simple rule-based predictions
   - Baseline metrics for Phase 8 ML

**Deliverables:**
- Fatigue detection with >85% accuracy
- Adaptive UI based on user state
- Proactive break recommendations
- Intent prediction baseline established

---

### Phase 7: Beta Testing (Weeks 27-34)
**Goal:** User validation and productivity measurement

**Tasks:**
1. **Beta User Recruitment** (Week 27-28)
   - Recruit 10-20 developers (RSI/motor impairments)
   - Define onboarding process
   - Set up feedback channels (Discord, email)
   - Opt-in telemetry for improvement

2. **Baseline Measurements** (Week 29)
   - Tasks per hour with current setup
   - Pain/fatigue levels (self-reported)
   - Error rates and frustration points
   - Qualitative interviews

3. **Training Period** (Week 30-31)
   - Users learn SimpleFlow (2 weeks)
   - Progressive disclosure in action
   - Collect usage patterns and feedback

4. **Performance Measurement** (Week 32-34)
   - Tasks per hour with SimpleFlow
   - Productivity loss calculation
   - Satisfaction surveys
   - Feature request prioritization
   - **Answer RQ-007, RQ-008**

**Deliverables:**
- Productivity metrics (baseline vs SimpleFlow)
- User satisfaction data (>4.5/5 target)
- Market validation (>60% retention)
- Bug reports and feature requests prioritized

---

### Phase 8: AI Features (Weeks 35-42)
**Goal:** ML-based prediction and optimization

**Tasks:**
1. **Intent Prediction Model** (Week 35-37)
   - Train on collected gaze+click data from Phases 1-7
   - >80% accuracy for click target prediction
   - Reduce dwell time for high-confidence predictions
   - "Predictive clicking" feature

2. **Code Prediction** (Week 38-40)
   - Evaluate local LLM viability (if tech matures)
   - OR: Enhanced n-gram with codebase indexing
   - 30-40% action reduction target
   - **Monitor RQ-013**

3. **Personalized Adaptation** (Week 41-42)
   - ML learns user's modality preferences
   - Personalized dwell times and sensitivities
   - Context-aware feature suggestions
   - Continuous improvement loop

**Deliverables:**
- Predictive clicking (30-40% action reduction)
- Code-aware prediction enhanced
- Personalized user models
- Production-ready accessibility tool

---

## Part 3: Technology Stack

### Core
- **Language:** C++20
- **Build:** CMake + vcpkg
- **Eye Tracking:** MediaPipe Iris
- **Smoothing:** One Euro Filter
- **Calibration:** 5-point homography
- **Voice:** Vosk (commands) + Whisper.cpp (dictation)
- **Threading:** Producer-consumer (taskflow)
- **Config:** TOML (toml++)

### Architecture
- **Multi-Modal Core:** Gaze+voice+head (75% error reduction)
- **Adaptive Systems:** Dwell time, target size, modality switching, fatigue-aware
- **AI-First:** Intent prediction, code awareness, fatigue detection
- **Developer Focus:** Programming first, then expand

### Dependencies
- OpenCV 4.x (webcam, image processing)
- MediaPipe (face mesh, iris, head pose)
- Vosk (real-time voice commands)
- Whisper.cpp (high-accuracy dictation)
- Eigen (linear algebra)
- taskflow (threading)
- GoogleTest (testing)

---

## Part 4: Timeline Summary

| Phase | Weeks | Duration | Key Deliverable |
|-------|-------|----------|-----------------|
| 1: Foundation | 1-6 | 6 weeks | MediaPipe accuracy validated |
| 2: Multi-Modal | 7-10 | 4 weeks | Gaze+voice clicking |
| 3: Cursor Control | 11-14 | 4 weeks | Full OS cursor control + UX |
| 4: Text Input | 15-18 | 4 weeks | Voice dictation + keyboard |
| 5: IDE Integration | 19-22 | 4 weeks | VS Code extension |
| 6: Fatigue & Adaptive | 23-26 | 4 weeks | Fatigue detection + adaptation |
| 7: Beta Testing | 27-34 | 8 weeks | User validation |
| 8: AI Features | 35-42 | 8 weeks | Intent prediction |

**🎯 MVP (Phases 1-4): 18 weeks (~4.5 months)**
- Gaze+voice cursor control
- Text entry (voice + keyboard fallback)
- Usable accessibility tool

**Professional Tool (Phases 1-6): 26 weeks (~6.5 months)**
- IDE integration
- Fatigue detection
- Adaptive UI

**AI-Enhanced Production (Phases 1-8): 42 weeks (~10.5 months)**
- Intent prediction
- Personalized adaptation
- Market-validated

---

## Part 5: Success Metrics

### Technical
- Gaze accuracy: <2.5° visual angle
- Latency: <50ms end-to-end
- FPS: 30+ sustained
- Voice latency: <200ms

### User Experience
- Error rate: <15% (vs 43% baseline)
- Grid precision: <3 clicks for 44px targets
- Text entry: >20 WPM dictation, >10 WPM keyboard fallback
- Satisfaction: >4.5/5 rating
- Fatigue detection: >85% accuracy

### Market
- Beta retention: >60%
- Productivity loss: <20%
- User growth: 100+ active users

---

## Part 6: Critical Decision Points

1. **End of Phase 1:** Is MediaPipe accuracy sufficient? (Webcam vs Tobii path)
2. **End of Phase 2:** Is multi-modal working? (Validate 75% error reduction)
3. **End of Phase 4:** Is MVP usable? (Internal testing before IDE work)
4. **End of Phase 5:** Is VS Code integration valuable? (User feedback)
5. **End of Phase 7:** Is productivity loss acceptable? (Market validation)

---

## Next Actions

### Immediate (This Week)
1. Clean up existing code (remove if needed)
2. Set up vcpkg dependencies
3. Start Phase 1.1: Input abstraction (TDD)

### Week 2
1. Complete configuration system
2. Implement webcam capture
3. Verify build on target hardware

### Week 3-4
1. MediaPipe integration
2. Threading prototype
3. Benchmark performance
