# Experiments & Explorations

This directory contains records of prototypes and experiments conducted during SimpleFlow development.

## Structure

Each experiment is documented in a markdown file with this naming convention:

```
YYYY-MM-DD-experiment-name.md
```

Example: `2025-11-16-mediapipe-iris-accuracy.md`

---

## Experiment Categories

### Technical Feasibility
Testing if an approach meets performance/accuracy requirements

**Examples:**
- Eye tracking accuracy benchmarks
- Voice recognition latency tests
- Cursor smoothing algorithm comparison
- Real-time ML inference profiling

### User Experience
Validating interaction patterns with users

**Examples:**
- Dwell click timing experiments
- Precision mode usability tests
- Calibration flow user testing
- Feedback mechanism evaluation

### Integration
Verifying libraries/tools work in our stack

**Examples:**
- MediaPipe C++ integration
- Vosk speech recognition setup
- Dear ImGui UI prototyping
- WebSocket IPC testing

### Creative Exploration
Testing novel ideas that might be better

**Examples:**
- Gaze gesture recognition
- Predictive clicking
- Implicit calibration
- Fatigue detection

---

## Experiment Lifecycle

### 1. Planning
- Define hypothesis
- Determine minimal scope
- Set success criteria
- Estimate time budget

### 2. Implementation
- Build minimal prototype
- Keep it simple and fast
- Time-box the work
- Use experiments/ directory for code

### 3. Testing
- Execute test protocol
- Collect quantitative data
- Gather qualitative feedback
- Note surprises

### 4. Analysis
- Compare results to criteria
- Interpret data
- Identify lessons learned
- Make go/no-go decision

### 5. Documentation
- Update experiment file with results
- Link from research index
- Update hypothesis log
- Create ADR if decision made

---

## Template

Use `experiment-template.md` for all new experiments.

Every experiment should answer:
- **What** are we testing?
- **Why** does this matter?
- **How** will we measure success?
- **What** did we learn?

---

## Code Prototypes

Experimental code goes in `C:\proj\SimpleFlow\experiments\` directory:

```
C:\proj\SimpleFlow\
└── experiments/
    ├── CMakeLists.txt             # Standalone experiment builds
    ├── template/                  # Boilerplate for new experiments
    ├── mediapipe-iris-test/       # Individual experiments
    ├── dwell-click-proto/
    └── voice-command-test/
```

Each experiment directory contains:
- `main.cpp` - Standalone executable
- `README.md` - How to build/run
- `results/` - Data, screenshots, videos

---

## Best Practices

**Do:**
- Define hypothesis before coding
- Keep scope minimal (hours, not days)
- Measure objectively (numbers, not feelings)
- Test with real user when UX-related
- Document failures (they're valuable too)
- Link experiments to research questions

**Don't:**
- Build production-quality code (experiments are throw-away)
- Spend more than time budget (time-box strictly)
- Skip measurement (no data = no learning)
- Ignore negative results (invalidation is progress)
- Reuse experiment code in main project (rewrite cleanly)

---

## Index

| Date | Experiment | Status | Outcome |
|------|------------|--------|---------|
| - | No experiments yet | - | - |

---

## Quick Reference

**Starting new experiment:**
1. Copy `experiment-template.md` to `YYYY-MM-DD-name.md`
2. Fill in hypothesis and success criteria
3. Create code directory in `experiments/`
4. Build minimal prototype
5. Run tests and collect data
6. Update experiment file with results
7. Make decision (go/no-go/iterate)
8. Update research index
