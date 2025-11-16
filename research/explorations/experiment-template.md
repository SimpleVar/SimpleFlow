# Experiment: [Name]

**Date:** YYYY-MM-DD

**Status:** [Planning | In Progress | Complete | Abandoned]

**Time Budget:** X hours

**Category:** [Technical Feasibility | User Experience | Integration | Creative Exploration]

---

## Hypothesis

What we believe will work and why.

**Format:** "I believe [APPROACH] will achieve [OUTCOME] with [CONSTRAINTS]"

**Example:**
```
I believe dwell clicking with 500ms threshold will provide
acceptable balance between false positives (<10%) and interaction
speed (<3 seconds per click) for users controlling cursor with gaze.
```

**Your Hypothesis:**
```
[Write hypothesis here]
```

---

## Why This Matters

How does this experiment relate to project goals?

- What research question does it answer?
- What decision depends on this result?
- What's the impact if successful/failed?

```
[Explain importance]
```

---

## Success Criteria

Clear, measurable criteria for go/no-go decision.

### Quantitative Metrics

| Metric | Target | Measurement Method |
|--------|--------|-------------------|
| [Metric 1] | [Target value/range] | [How to measure] |
| [Metric 2] | [Target value/range] | [How to measure] |
| [Metric 3] | [Target value/range] | [How to measure] |

**Example:**
| Metric | Target | Measurement Method |
|--------|--------|-------------------|
| Click accuracy | >90% | 20 button clicks, count successful |
| False positive rate | <10% | Hovers per minute, count accidental clicks |
| Avg time per click | <3 seconds | Timestamp start to click, average 20 clicks |

### Qualitative Criteria

- [ ] [Criterion 1 - e.g., "Feels responsive and natural"]
- [ ] [Criterion 2 - e.g., "Visual feedback is clear and helpful"]
- [ ] [Criterion 3 - e.g., "Can develop rhythm/flow"]

---

## Implementation Plan

### Minimal Scope

**Build:**
- [Component 1]
- [Component 2]
- [Component 3]

**Mock/Stub:**
- [Non-critical part 1]
- [Non-critical part 2]

**Out of Scope:**
- [Feature not needed]
- [Optimization can wait]

### Architecture

[Diagram, component list, or description of how it works]

**Example:**
```
User Input → Dwell Detector → Click Trigger → Metrics Logger
             ↓
          Visual Feedback
```

### Implementation Sequence

1. [Step 1 - e.g., "Set up Dear ImGui window"]
2. [Step 2 - e.g., "Implement dwell timer state machine"]
3. [Step 3 - e.g., "Add visual feedback circle"]
4. [Step 4 - e.g., "Create test UI with buttons"]
5. [Step 5 - e.g., "Add metrics collection"]

### Time Estimates

| Component | Estimated Time | Actual Time |
|-----------|----------------|-------------|
| [Component 1] | X hours | [Fill after] |
| [Component 2] | X hours | [Fill after] |
| **Total** | **X hours** | **[Fill after]** |

---

## Test Protocol

How will you validate the hypothesis?

### Test Environment

- **Hardware:** [e.g., "1080p webcam, consumer laptop"]
- **Software:** [e.g., "Windows 11, built with CMake"]
- **User:** [e.g., "Myself simulating gaze with mouse" or "Friend with CP"]

### Test Procedure

1. [Step 1 - e.g., "Launch experiment application"]
2. [Step 2 - e.g., "Click 20 buttons using dwell (500ms threshold)"]
3. [Step 3 - e.g., "Repeat with 300ms and 800ms thresholds"]
4. [Step 4 - e.g., "Record metrics for each threshold"]
5. [Step 5 - e.g., "Survey user about experience"]

### Data Collection

**Automated:**
- [Metric 1 - how collected, format]
- [Metric 2 - how collected, format]

**Manual:**
- [Observation 1]
- [Observation 2]

**User Feedback:**
- [Question 1 to ask user]
- [Question 2 to ask user]

---

## Results

_[Fill in after running experiment]_

### Quantitative Data

| Metric | Target | Actual Result | Pass/Fail |
|--------|--------|---------------|-----------|
| [Metric 1] | [Target] | [Result] | ✓ / ✗ |
| [Metric 2] | [Target] | [Result] | ✓ / ✗ |
| [Metric 3] | [Target] | [Result] | ✓ / ✗ |

**Detailed Data:**
```
[Tables, charts, raw data]
```

### Qualitative Observations

- [Observation 1]
- [Observation 2]
- [Surprise 1 - unexpected finding]

### User Feedback

- [Quote or summary from user]
- [Key takeaways]

### Screenshots/Videos

- [Link to results/ directory with screenshots]
- [Link to demo video if captured]

---

## Analysis

_[Fill in after collecting results]_

### Hypothesis Outcome

- [ ] **Validated** - Results confirm hypothesis
- [ ] **Partially Validated** - Some criteria met, needs refinement
- [ ] **Invalidated** - Hypothesis disproven
- [ ] **Inconclusive** - Need more data

**Explanation:**
```
[Why did hypothesis succeed/fail? What does data tell us?]
```

### Key Insights

1. [Insight 1 - important learning]
2. [Insight 2 - surprising finding]
3. [Insight 3 - implication for design]

### What Went Right

- [Success 1]
- [Success 2]

### What Went Wrong

- [Problem 1]
- [Problem 2]

### Unexpected Findings

- [Surprise 1 - didn't anticipate this]
- [Surprise 2 - interesting side effect]

---

## Decision

_[Fill in after analysis]_

### Go/No-Go

- [ ] **GO** - Proceed with this approach, integrate into main project
- [ ] **NO-GO** - Abandon this approach, try alternative
- [ ] **ITERATE** - Refine and test again
- [ ] **DEFER** - Promising but not critical, revisit later

**Rationale:**
```
[Why this decision? What factors weighed most heavily?]
```

### Next Steps

**If GO:**
1. [Next action - e.g., "Integrate dwell timer into main cursor control"]
2. [Next action - e.g., "Add user-configurable threshold"]
3. [Next action - e.g., "Test with real eye tracking input"]

**If NO-GO:**
1. [Alternative to try - e.g., "Experiment with blink-based clicking"]
2. [Update affected research - e.g., "Mark dwell timing as failed in hypothesis log"]

**If ITERATE:**
1. [What to change - e.g., "Test 600-700ms range"]
2. [What to measure - e.g., "Add jitter tolerance metric"]
3. [Timeline - e.g., "Retest in 2 days"]

**If DEFER:**
- [When to revisit - e.g., "After v1 ships, based on user feedback"]

---

## Lessons Learned

_[Fill in after completing experiment]_

### Technical Learnings

- [Learning 1 - e.g., "Dear ImGui timer precision is ±5ms"]
- [Learning 2 - e.g., "Need debouncing to prevent double-clicks"]

### Process Learnings

- [Learning 1 - e.g., "Should have tested with real user earlier"]
- [Learning 2 - e.g., "Time estimate was too optimistic by 50%"]

### What to Do Differently Next Time

- [Improvement 1]
- [Improvement 2]

---

## References

**Related Research:**
- [Link to domain research document]
- [Link to competitive analysis]

**Related Experiments:**
- [Link to previous/related experiment]

**External:**
- [Academic paper]
- [Tutorial/documentation]
- [Inspiration source]

---

## Appendix

### Code Location

`C:\proj\SimpleFlow\experiments\[experiment-name]\`

**How to build:**
```bash
cd experiments/[experiment-name]
mkdir build && cd build
cmake ..
cmake --build .
```

**How to run:**
```bash
./[experiment-name]
```

### Raw Data

[Link to CSV, JSON, or other data files]

### Additional Notes

[Any other relevant information]
