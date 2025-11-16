# SimpleFlow Roadmap

## Phase 1: Foundation (Weeks 1-6)
Core abstractions + MediaPipe validation
- [ ] Input abstraction (InputSource, InputManager)
- [ ] Configuration system (TOML, persistence)
- [ ] Webcam capture + error handling
- [ ] MediaPipe integration + threading
- [ ] Gaze estimation + 5-point calibration
- [ ] One Euro Filter smoothing
- [ ] Performance monitoring + privacy foundation
- [ ] Opt-in metrics collection framework

## Phase 2: Multi-Modal Core (Weeks 7-10)
Gaze+voice fundamental interaction
- [ ] Vosk voice recognition (streaming)
- [ ] Dwell clicking + visual feedback
- [ ] Gaze+voice fusion (temporal correlation)
- [ ] Basic voice-controllable config UI
- [ ] Adaptive dwell time (400-800ms)
- [ ] Bootstrap mode (voice-only setup)
- [ ] Start fatigue metrics collection

## Phase 3: Cursor Control (Weeks 11-14)
Full OS cursor manipulation + UX
- [ ] Windows cursor API (SetCursorPos, mouse_event)
- [ ] Scroll and drag (voice commands)
- [ ] Precision modes (grid, zoom, snap-to-target)
- [ ] Head tracking + sensor fusion
- [ ] Enhanced configuration UI (save/load profiles)
- [ ] Onboarding system (wizard, tutorial)

## Phase 4: Text Input (Weeks 15-18)
Voice dictation + virtual keyboard
- [ ] Whisper.cpp integration (high-accuracy dictation)
- [ ] Word prediction algorithm (n-gram)
- [ ] Virtual keyboard (hierarchical selection)
- [ ] Code dictation (keywords, symbols, formatting)
- [ ] Text field auto-detection (Windows UIA)

**🎯 MVP Complete**

## Phase 5: IDE Integration (Weeks 19-22)
VS Code extension for coding
- [ ] VS Code extension scaffold (TypeScript)
- [ ] WebSocket IPC (core ↔ extension)
- [ ] Code-aware commands (go to definition, find refs)
- [ ] LSP integration (semantic actions)

## Phase 6: Fatigue & Adaptive Systems (Weeks 23-26)
Intelligent user-state adaptation
- [ ] Fatigue detection classifier (>85% accuracy)
- [ ] Adaptive UI (target size, dwell time, breaks)
- [ ] Proactive break recommendations
- [ ] Intent prediction foundation

## Phase 7: Beta Testing (Weeks 27-34)
User validation
- [ ] Recruit 10-20 beta users (RSI/motor impairments)
- [ ] Baseline measurements
- [ ] Training period (2 weeks)
- [ ] Productivity measurement (<20% loss target)
- [ ] Satisfaction surveys (>4.5/5 target)

## Phase 8: AI Features (Weeks 35-42)
ML-based prediction
- [ ] Intent prediction model (>80% accuracy)
- [ ] Code prediction (enhanced n-gram or LLM)
- [ ] Personalized adaptation
- [ ] 30-40% action reduction

---

## Milestones

**MVP:** Phase 4 complete (18 weeks / 4.5 months)
- Cursor control + text entry + onboarding

**Professional Tool:** Phase 6 complete (26 weeks / 6.5 months)
- IDE integration + fatigue detection

**Production Ready:** Phase 8 complete (42 weeks / 10.5 months)
- AI features + user-validated
