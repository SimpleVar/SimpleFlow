# Template E: Rapid Prototype Planning

**Use When:** Ready to test an idea with code, need implementation plan

**Agent Type:** Plan agent

**Thoroughness:** Quick to Medium

---

## Template Structure

### 1. What to Validate
What specific hypothesis are you testing with this prototype?

**Format:** Clear, testable statement

**Examples:**
- "Dwell clicking with 500ms threshold feels natural and has <10% false positives"
- "MediaPipe Iris can achieve <3° accuracy with 9-point calibration"
- "Voice commands can supplement gaze for faster mode switching"

**Your Hypothesis:**
```
[What are you testing?]
```

---

### 2. Minimal Implementation Scope
What's the absolute minimum to build for a valid test?

**Guidelines:**
- Build only what's needed to measure hypothesis
- Mock/stub everything else
- Prefer simple over elegant
- Target: runnable in <1 day

**Your Scope:**
```
Build:
- [Component 1]
- [Component 2]
- [Component 3]

Mock/Stub:
- [Non-critical part 1]
- [Non-critical part 2]

Out of Scope:
- [Feature not needed for test]
- [Optimization can wait]
```

---

### 3. Test Criteria
How will you know if hypothesis is validated?

**Format:** Quantitative metrics + qualitative observations

**Examples:**
- **Quant:** Accuracy >90%, latency <50ms, false positive rate <5%
- **Qual:** "Feels responsive", "Can complete task without frustration"

**Your Criteria:**
```
Quantitative:
- [Metric 1]: [Target value]
- [Metric 2]: [Target value]

Qualitative:
- [Observation 1]
- [Observation 2]

Test Protocol:
- [How to measure - manual test, automated, user trial]
```

---

### 4. Time Budget
How long should this take? (Be realistic but aggressive)

**Guidelines:**
- Simple integration: 2-4 hours
- New component: 4-8 hours
- Novel algorithm: 8-16 hours

**Includes:** Design, implement, test, document

**Your Budget:**
```
Estimated time: [X hours]
Hard deadline: [Stop if not done by Y hours]
```

---

### 5. Success/Failure Metrics
Clear criteria for go/no-go decision after prototype

**Format:**
- **Success:** What results mean "pursue this approach"
- **Partial:** What results mean "needs refinement but promising"
- **Failure:** What results mean "abandon this approach"

**Your Metrics:**
```
SUCCESS if: [conditions]
PARTIAL if: [conditions]
FAILURE if: [conditions]

Next steps for each outcome:
- Success → [what to build next]
- Partial → [what to refine/retest]
- Failure → [alternative to try]
```

---

## Example: Dwell Click Timing Experiment

### 1. What to Validate
"A dwell time of 500ms provides acceptable balance between false positives (accidental clicks) and interaction speed for users controlling cursor with gaze."

### 2. Minimal Implementation Scope
**Build:**
- Dwell timer (track cursor position, detect stillness)
- Click trigger (when stillness exceeds threshold)
- Visual feedback (circle fills up during dwell)
- Adjustable threshold (test 300ms, 500ms, 800ms)
- Test UI (grid of large buttons to click)
- Metrics collection (time per click, false positive count)

**Mock/Stub:**
- Actual gaze tracking (use mouse to simulate gaze)
- Cursor movement (normal mouse, just track position)
- Integration with apps (just click buttons in test UI)

**Out of Scope:**
- Blink-based clicking (different experiment)
- Precision modes (separate feature)
- Smoothing/filtering (not relevant to dwell timing)
- Real gaze input (test mechanics first)

**Implementation:**
- C++ application (Dear ImGui for UI)
- Simple state machine (tracking, dwelling, clicked, cooldown)
- Timestamp-based logic
- CSV output for metrics

### 3. Test Criteria
**Quantitative:**
- **Task completion time:** Average time to click 10 targets
- **False positive rate:** Unintended clicks per minute
- **Successful dwell rate:** % of intended dwells that trigger click
- **Cooldown effectiveness:** % of double-clicks prevented

**Qualitative:**
- "Does 500ms feel too slow or too fast?"
- "Is visual feedback clear and helpful?"
- "Do false positives disrupt flow?"
- "Can user develop rhythm/flow?"

**Test Protocol:**
1. User clicks 20 buttons using mouse-as-gaze
2. Repeat with 300ms, 500ms, 800ms thresholds
3. Record metrics for each threshold
4. Ask user which threshold felt best
5. Note any frustration or confusion

### 4. Time Budget
**Estimated:** 4-6 hours
- Design state machine: 30 min
- Implement dwell logic: 1.5 hours
- Build test UI: 1 hour
- Add metrics collection: 1 hour
- Testing: 1 hour
- Documentation: 30 min

**Hard deadline:** 8 hours (if taking longer, scope is too large)

### 5. Success/Failure Metrics
**SUCCESS if:**
- One threshold achieves <5% false positives AND <3 seconds avg click time
- User feedback is "this feels usable"
- Clear winner among tested thresholds

**Next step:** Integrate with real gaze tracking

**PARTIAL if:**
- No threshold fully meets criteria, but trend is clear (e.g., "needs to be 600-700ms")
- False positives still high (5-15%) but solvable with cooldown tuning
- User says "needs refinement but concept works"

**Next step:** Run follow-up experiment with refined thresholds or add cooldown logic

**FAILURE if:**
- All thresholds have >20% false positive rate
- User says "this is frustrating and unusable"
- Fundamental UX issue discovered (e.g., can't hover without clicking)

**Next step:** Test alternative click mechanism (blink, voice, gesture)

---

## Agent Prompt Template

```
I need an implementation plan for a rapid prototype to test this hypothesis:

Hypothesis: [YOUR HYPOTHESIS]

Success Criteria:
- [CRITERION 1]
- [CRITERION 2]
- [CRITERION 3]

Constraints:
- Time budget: [X hours]
- Must use: [Required technologies/libraries]
- Should integrate with: [Existing code, if any]

Please provide:
1. Minimal implementation scope (what to build, what to mock, what to skip)
2. Suggested architecture (components, interfaces, data flow)
3. Implementation sequence (what order to build things)
4. Testing approach (how to validate hypothesis)
5. Risk mitigation (what could block progress, how to avoid)

Output Format:
1. Component breakdown (list of what to build)
2. Interface definitions (key classes/functions)
3. Build sequence (ordered steps)
4. Test protocol (how to measure success)
5. Time estimates (per component)
6. Risks and mitigations

Thoroughness level: quick

I need to build this today, so focus on pragmatic, minimal approach that still validates the hypothesis reliably.
```

---

## After Agent Completes

### 1. Review Implementation Plan
- Is scope truly minimal? (Cut more if possible)
- Are interfaces clear?
- Is build sequence logical?
- Can this be done in time budget?

### 2. Set Up Experiment
Create research/explorations/YYYY-MM-DD-experiment-name.md:
```markdown
# Experiment: [Name]
Date: YYYY-MM-DD
Status: Planning

## Hypothesis
[From template section 1]

## Implementation Plan
[From agent output]

## Test Protocol
[From template section 3]

## Time Budget
[From template section 4]

## Success Criteria
[From template section 5]

## Results
[To be filled after running experiment]

## Decision
[GO/PARTIAL/NO-GO with rationale]
```

### 3. Build Prototype
Follow the plan, but stay flexible:
- If something is harder than expected, cut it or simplify
- If new insights emerge, adjust on the fly
- Track actual time vs. estimated

### 4. Run Tests
Execute test protocol:
- Collect quantitative metrics
- Gather qualitative feedback
- Note surprises and unexpected behaviors

### 5. Document Results
In experiment file:
- Data tables/charts
- Observations
- Hypothesis outcome (validated/invalidated/partial)
- Lessons learned

### 6. Make Decision
Based on success/failure criteria:
- **SUCCESS:** Move to integration (build it for real)
- **PARTIAL:** Design refinement experiment
- **FAILURE:** Document why, try alternative approach

### 7. Update Hypothesis Log
Mark hypothesis as validated/invalidated/refined

### 8. Update Research Index
Link to experiment, note decision
