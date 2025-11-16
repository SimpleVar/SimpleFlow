# Research Log: YYYY-MM-DD

**Day:** [Monday, Tuesday, etc.]
**Hours Worked:** X hours
**Focus:** [What you investigated today]

---

## Goals for Today

- [ ] [Goal 1]
- [ ] [Goal 2]
- [ ] [Goal 3]

---

## Agent Tasks Spawned

| Agent ID | Task Description | Status | Key Findings |
|----------|------------------|--------|--------------|
| - | - | - | - |

**Example:**
| Agent ID | Task Description | Status | Key Findings |
|----------|------------------|--------|--------------|
| explore-001 | Eye tracking methods research | Complete | Found 8 options, MediaPipe looks promising |
| plan-002 | Dwell click implementation plan | In Progress | - |

---

## Experiments Run

| Experiment | Status | Outcome |
|------------|--------|---------|
| - | - | - |

**Example:**
| Experiment | Status | Outcome |
|------------|--------|---------|
| mediapipe-iris-accuracy | Complete | 2.5° accuracy, acceptable for v1 |

---

## Key Discoveries

**High-level insights:**

1. [Discovery 1 - important finding that changes understanding]
2. [Discovery 2 - unexpected result from experiment]
3. [Discovery 3 - insight from agent research]

**Details:**
- [Discovery 1 expanded - context, implications, next steps]
- [Discovery 2 expanded]
- [Discovery 3 expanded]

---

## Decisions Made

| Decision | Rationale | Impact |
|----------|-----------|--------|
| - | - | - |

**Example:**
| Decision | Rationale | Impact |
|----------|-----------|--------|
| Use MediaPipe Iris for v1 | Best accessibility-to-accuracy tradeoff | Enables prototyping with any webcam |
| Defer implicit calibration to v2 | Too risky for initial release | Simplifies v1 scope |

**ADRs Created:**
- [Link to ADR-001 if decision documented formally]

---

## Progress on Research Questions

### Tier 1 Questions (Make-or-Break)

- [x] **Can webcam-based eye tracking achieve <2-degree accuracy?**
  - **Answer:** Yes, MediaPipe Iris achieves 2-3° with calibration
  - **Confidence:** High (tested with prototype)

- [ ] **What dwell time is tolerable without breaking flow?**
  - **Status:** Experiment planned, not yet run

- [ ] **Is offline voice recognition accurate enough?**
  - **Status:** Not yet investigated

### Tier 2-4 Questions

[Update as you investigate them]

---

## Hypotheses Updated

| Hypothesis ID | Status Change | New Evidence |
|---------------|---------------|--------------|
| - | - | - |

**Example:**
| Hypothesis ID | Status Change | New Evidence |
|---------------|---------------|--------------|
| H001 | Active → Validated | MediaPipe prototype achieved 90% accuracy on test clicks |
| H002 | Active → Invalidated | 300ms dwell caused 40% false positives, too high |

---

## Code Written

| File/Component | Purpose | Status |
|----------------|---------|--------|
| - | - | - |

**Example:**
| File/Component | Purpose | Status |
|----------------|---------|--------|
| experiments/mediapipe-iris-test/main.cpp | Test MediaPipe accuracy | Complete, 200 LOC |

**Commit:** [Link to commit if pushed]

---

## Reading/Research Completed

**Papers Read:**
- [Paper title, author, year] - Key takeaway: [summary]

**Documentation:**
- [Library/tool docs] - Learned: [what you learned]

**Code Reviewed:**
- [GitHub repo] - Insights: [what you found]

**Competitors Analyzed:**
- [Product/tool] - Strengths: [X], Weaknesses: [Y]

---

## Blockers/Challenges

| Blocker | Impact | Resolution Status |
|---------|--------|-------------------|
| - | - | - |

**Example:**
| Blocker | Impact | Resolution Status |
|---------|--------|-------------------|
| MediaPipe CMake integration failing | Can't run experiment | Resolved - found vcpkg config issue |
| Test user unavailable this week | Can't validate UX hypotheses | Deferred - running self-tests instead |

---

## Questions Raised

**New unknowns discovered today:**

1. [Question 1 - something you realized you don't know]
2. [Question 2 - follow-up needed]
3. [Question 3 - decision needed]

**Assigned to:**
- [Question 1] → Spawn agent / run experiment / research tomorrow
- [Question 2] → Add to hypothesis log
- [Question 3] → Discuss with friend

---

## Tomorrow's Focus

**Priorities:**
1. [Top priority task]
2. [Second priority]
3. [Third priority]

**Agent tasks to spawn:**
- [Agent task 1]
- [Agent task 2]

**Experiments to run:**
- [Experiment 1]

**Decisions to make:**
- [Decision 1]

---

## Time Breakdown

| Activity | Hours |
|----------|-------|
| Agent research (spawning, reading outputs) | X.X |
| Coding/experiments | X.X |
| Testing/debugging | X.X |
| Documentation | X.X |
| Reading papers/docs | X.X |
| Meetings/discussions | X.X |
| **Total** | **X.X** |

**Efficiency notes:**
- [What went well time-wise]
- [What took longer than expected]
- [What to optimize tomorrow]

---

## Reflections

**What went well:**
- [Success 1]
- [Success 2]

**What didn't go well:**
- [Challenge 1]
- [Frustration 1]

**What I learned about the process:**
- [Meta-learning 1 - about research methods, agent usage, etc.]

**Mood/Energy:**
- [How you felt - energized, frustrated, stuck, flowing]
- [Context if relevant]

---

## Links

**Research documents updated:**
- [domains/X/file.md] - Added section on [topic]
- [synthesis/hypothesis-log.md] - Updated H001, H002

**Files created:**
- [explorations/YYYY-MM-DD-experiment.md]
- [decisions/ADR-NNN.md]

**Commits:**
- [Commit hash] - [Message]
