# Template C: Technical Feasibility Study

**Use When:** Validating if an approach is viable before building

**Agent Type:** Plan agent

**Thoroughness:** Medium

---

## Template Structure

### 1. Hypothesis
What do you think will work? Be specific.

**Format:** "I believe [APPROACH] will achieve [OUTCOME] with [CONSTRAINTS]"

**Examples:**
- "MediaPipe Iris can achieve <2-degree gaze accuracy with a 1080p webcam at 30fps"
- "Dwell clicking with 500ms threshold will have <10% false positive rate"
- "Voice commands using Vosk offline will recognize 95%+ of accessibility commands"

**Your Hypothesis:**
```
[Write your hypothesis here]
```

---

### 2. Technical Constraints
What are the hard requirements or limits?

**Common Constraints:**
- Latency budget (e.g., <50ms end-to-end)
- Accuracy requirement (e.g., <2 degrees error)
- Resource limits (CPU <30%, <500MB RAM)
- Hardware assumptions (webcam specs, OS, etc.)
- Cost limits (must work with <$50 hardware)

**Your Constraints:**
```
[List technical constraints]
```

---

### 3. Proof-of-Concept Requirements
What's the minimal implementation to test this?

**Scope:**
- What to build (specific components)
- What to mock/stub (non-critical parts)
- How to measure (metrics, test protocol)
- Time budget (hours, not days)

**Your PoC Scope:**
```
[Define minimal implementation]
```

---

### 4. Risk Assessment
What could go wrong? How likely? How bad?

**Risk Matrix:**

| Risk | Likelihood | Impact | Mitigation |
|------|------------|--------|------------|
| [Risk 1] | High/Med/Low | High/Med/Low | [How to reduce] |
| [Risk 2] | High/Med/Low | High/Med/Low | [How to reduce] |

**Your Risks:**
```
[List potential failure modes]
```

---

### 5. Go/No-Go Criteria
How will you decide if this approach is viable?

**Format:** Clear, measurable decision criteria

**Examples:**
- "GO if accuracy >90%, latency <100ms, CPU <40%"
- "NO-GO if any metric misses target by >20%"
- "MAYBE if 1-2 metrics need optimization but path forward is clear"

**Your Criteria:**
```
GO if: [conditions]
NO-GO if: [conditions]
MAYBE if: [conditions]
```

---

## Example: MediaPipe Iris Gaze Tracking Feasibility

### 1. Hypothesis
"MediaPipe Iris can provide sufficient gaze accuracy (<3 degrees) for dwell-based clicking on UI elements (size >50px) using a standard 1080p webcam at 30fps, with <50ms processing latency per frame."

### 2. Technical Constraints
- Latency: <50ms per frame processing (for 30fps real-time)
- Accuracy: <3 degrees gaze error for targets >50px
- Hardware: Standard 1080p webcam, consumer laptop (not gaming PC)
- Resources: <30% CPU usage (need headroom for other tasks)
- Cost: Must work with webcam <$50
- Distance: User 50-70cm from screen

### 3. Proof-of-Concept Requirements
**Build:**
- MediaPipe Iris integration (face mesh + eye landmarks)
- Gaze vector calculation (pupil position → screen coordinates)
- Simple calibration (9-point grid)
- Visualization (show gaze point overlay)
- Metric collection (accuracy, latency, jitter)

**Mock/Stub:**
- Cursor control (just visualize, don't move actual cursor)
- Click mechanisms (not testing this yet)
- Smoothing/filtering (test raw output first)

**Measure:**
- Accuracy: User looks at known targets, measure error distance
- Latency: Timestamp frame capture → gaze point output
- Stability: Variance when staring at fixed point (jitter)
- CPU usage: Monitor during operation

**Time Budget:** 4-6 hours

### 4. Risk Assessment

| Risk | Likelihood | Impact | Mitigation |
|------|------------|--------|------------|
| Accuracy insufficient (<3°) | Medium | High | Try custom ONNX models, add calibration |
| Latency too high (>50ms) | Low | Medium | Optimize with threading, use GPU |
| Jitter makes cursor unusable | High | High | Add Kalman filtering (separate experiment) |
| Calibration drift over time | Medium | Medium | Implement implicit recalibration |
| Lighting sensitivity | High | Medium | Test in varied conditions, add preprocessing |
| Works on test laptop but not lower-end hardware | Medium | High | Profile on min-spec hardware |

### 5. Go/No-Go Criteria
**GO if:**
- Accuracy <3° for 80%+ of frames
- Latency <50ms on target hardware
- CPU <40% on consumer laptop
- Jitter <1° when looking at fixed point

**NO-GO if:**
- Accuracy >5° consistently (fundamental limitation)
- Latency >100ms (can't meet real-time requirement)
- CPU >60% (leaves no headroom)

**MAYBE if:**
- Accuracy 3-4° (might be acceptable with larger targets/filtering)
- Latency 50-75ms (acceptable for dwell, not for continuous tracking)
- Jitter 1-2° (needs filtering but solvable)

**Next Step if MAYBE:** Run filtering experiment, test with real user

---

## Agent Prompt Template

```
I need a technical feasibility analysis for the following approach:

Hypothesis: [YOUR HYPOTHESIS]

Technical Constraints:
- [CONSTRAINT 1]
- [CONSTRAINT 2]
- [CONSTRAINT 3]

Please analyze:
1. Is this approach technically feasible based on current state-of-the-art?
2. What are the known challenges and how have others addressed them?
3. What performance can we realistically expect?
4. What are the main risks and failure modes?
5. What proof-of-concept would validate or invalidate this hypothesis?

Research:
- Academic papers on this specific approach
- Existing implementations (open-source preferred)
- Benchmarks and performance data
- Known limitations and workarounds

Output:
1. Feasibility assessment (Highly Feasible / Feasible with Challenges / Risky / Not Feasible)
2. Expected performance ranges (best case, typical, worst case)
3. Risk analysis (what could go wrong)
4. Recommended PoC scope (minimal test to validate)
5. Alternative approaches if this seems infeasible

Thoroughness level: medium
```

---

## After Agent Completes

### 1. Make Go/No-Go Decision
Based on agent research and your criteria, decide:
- **GO:** Proceed to build PoC
- **NO-GO:** Pivot to alternative approach (spawn agent for alternatives)
- **MAYBE:** Need more research or prototype to decide

### 2. If GO: Build Proof-of-Concept
- Create experiment in research/explorations/
- Follow experiment structure template
- Implement minimal version
- Measure against criteria
- Document results

### 3. If NO-GO: Document Why
- Write decision record (research/decisions/)
- Explain why approach failed feasibility
- List alternatives to explore
- Update hypothesis log (invalidated)

### 4. If MAYBE: Design Next Experiment
- Identify specific unknowns
- Design targeted test to resolve
- May need additional agent research

### 5. Update Research Index
- Link to feasibility study
- Update hypothesis log
- Mark next actions
