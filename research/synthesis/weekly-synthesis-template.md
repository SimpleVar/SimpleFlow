# Week NN Synthesis

**Dates:** YYYY-MM-DD to YYYY-MM-DD
**Total Hours:** XX hours
**Phase:** [Foundation Research | Deep Dives | Validation | Implementation | etc.]

---

## Executive Summary

[3-5 sentence overview of the week's progress, major learnings, and decisions]

**Example:**
```
This week focused on evaluating eye tracking methods. We tested MediaPipe Iris,
researched Tobii SDK, and ran accuracy benchmarks. Key finding: MediaPipe achieves
2-3° accuracy with calibration, sufficient for v1. Decided to use MediaPipe for
prototyping and defer Tobii integration to v2. Also discovered implicit calibration
as promising research direction for future work.
```

---

## Goals vs. Actuals

### Week's Goals (from last week)

- [ ] [Goal 1] - **Status:** [Complete / In Progress / Not Started]
- [ ] [Goal 2] - **Status:** [Complete / In Progress / Not Started]
- [ ] [Goal 3] - **Status:** [Complete / In Progress / Not Started]

### What Actually Happened

- [Actual achievement 1]
- [Actual achievement 2]
- [Unexpected work 1]

**Variance Analysis:**
- [Why goals shifted]
- [What blocked progress]
- [What accelerated progress]

---

## Domain Progress

Which research domains were explored this week?

| Domain | Status Before | Status After | Key Updates |
|--------|---------------|--------------|-------------|
| 1. Users | 🔴 Not Started | 🟡 In Progress | Reviewed 3 user research papers |
| 2. Input Modalities | 🔴 Not Started | 🟢 Complete | Evaluated all major options, chose MediaPipe |
| [etc.] | - | - | - |

**Legend:** 🔴 Not Started | 🟡 In Progress | 🟢 Complete

**Detailed Updates:**

### [Domain Name]
- [Update 1]
- [Update 2]
- [Open questions remaining]

---

## Major Learnings

**Top 5 insights this week:**

### 1. [Learning 1 Title]
**What:** [Description of insight]
**Why it matters:** [Implications for project]
**Source:** [Experiment, agent research, paper, etc.]
**Action:** [What changes based on this]

### 2. [Learning 2 Title]
[Same structure]

### 3. [Learning 3 Title]
[Same structure]

### 4. [Learning 4 Title]
[Same structure]

### 5. [Learning 5 Title]
[Same structure]

---

## Decisions Made

### Technology Decisions

| Decision | Options Considered | Chosen | Rationale |
|----------|-------------------|--------|-----------|
| Eye tracking method | MediaPipe, Tobii, Custom | MediaPipe | Best accessibility-accuracy balance |
| [Decision 2] | [Options] | [Chosen] | [Why] |

**ADRs Created:**
- [ADR-001: Eye Tracking Method](../decisions/001-eye-tracking-method.md)
- [ADR-002: ...]

### Architecture Decisions

| Decision | Impact | Rationale |
|----------|--------|-----------|
| [Decision 1] | [What's affected] | [Why] |

### Scope Decisions

**Added to scope:**
- [Feature/task added] - Reason: [why]

**Removed from scope:**
- [Feature/task cut] - Reason: [why]

**Deferred to later:**
- [Feature/task delayed] - Reason: [why], When: [target phase]

---

## Hypothesis Updates

### Validated This Week

| ID | Hypothesis | Evidence | Implications |
|----|------------|----------|--------------|
| H001 | [Hypothesis text] | [What proved it] | [What this enables] |
| H002 | [Hypothesis text] | [What proved it] | [What this enables] |

### Invalidated This Week

| ID | Hypothesis | Evidence | Lessons Learned |
|----|------------|----------|-----------------|
| H005 | [Hypothesis text] | [What disproved it] | [What we learned from failure] |

### Refined This Week

| ID | Old Hypothesis | New Hypothesis | Why Changed |
|----|----------------|----------------|-------------|
| H003 | [Original] | [Updated] | [New information that changed understanding] |

### New Hypotheses Formed

| ID | Hypothesis | Priority | Next Step |
|----|------------|----------|-----------|
| H010 | [New hypothesis] | High/Med/Low | [How to test] |

**Full hypothesis log:** [../synthesis/hypothesis-log.md](hypothesis-log.md)

---

## Agent Tasks Summary

**Total agents spawned:** X
**Completed:** X | **In Progress:** X | **Blocked:** X

### High-Value Agent Outputs

| Agent ID | Task | Key Findings | Follow-Up Needed |
|----------|------|--------------|------------------|
| explore-001 | Eye tracking landscape | Found 8 options, MediaPipe best for accessibility | Test MediaPipe accuracy |
| plan-002 | Cursor control architecture | Designed 3-layer approach | Prototype filtering layer |
| [etc.] | - | - | - |

**Lessons on agent usage:**
- [What worked well when spawning agents]
- [What to improve next week]

---

## Experiments Summary

**Total experiments:** X
**Successful:** X | **Partial:** X | **Failed:** X

### Completed Experiments

| Experiment | Hypothesis | Outcome | Next Step |
|------------|------------|---------|-----------|
| mediapipe-iris-accuracy | <2° accuracy achievable | Validated (2.5° avg) | Integrate into main project |
| dwell-click-timing | 500ms is optimal | Partial (600ms better) | Refine and retest |
| [etc.] | - | - | - |

### Valuable Failures

**What didn't work:**
- [Failed experiment 1] - Why it failed: [reason] - Learned: [lesson]
- [Failed experiment 2] - Why it failed: [reason] - Learned: [lesson]

**Pivots made:**
- From [original approach] to [new approach] because [reason]

---

## Research Questions Answered

### Tier 1 (Make-or-Break)

- [x] **Can webcam-based eye tracking achieve <2-degree accuracy?**
  - **Answer:** Yes, 2-3° with MediaPipe + calibration
  - **Confidence:** High (validated with prototype)
  - **Implication:** Can proceed with webcam-based approach for v1

- [x] **What dwell time is tolerable without breaking flow?**
  - **Answer:** 600-700ms (not 500ms as initially thought)
  - **Confidence:** Medium (self-test only, need user validation)
  - **Implication:** Design UI for 600ms baseline, make configurable

- [ ] **Remaining question 3**
  - **Status:** Not yet investigated
  - **Planned:** Week NN+1

### New Questions Raised

1. [New question 1]
   - **Why it matters:** [context]
   - **How to answer:** [research plan]
   - **Priority:** High/Med/Low

2. [New question 2]
   [Same structure]

---

## Code Progress

### New Components

| Component | LOC | Status | Purpose |
|-----------|-----|--------|---------|
| experiments/mediapipe-iris-test | 250 | Complete | Accuracy benchmark |
| experiments/dwell-click-proto | 180 | Complete | UX validation |

### Commits This Week

- [Commit hash] - [Message] - [Date]
- [Commit hash] - [Message] - [Date]

**Total lines added:** +XXX
**Total lines deleted:** -XXX

### Technical Debt

**Introduced:**
- [Technical debt item 1] - Will address: [when/how]

**Paid down:**
- [Technical debt resolved] - How: [what was done]

---

## Threads Identified

**New promising directions discovered:**

### [Thread Name]
**Opportunity:** [What could be achieved]
**Approach:** [How to pursue it]
**Evidence:** [Why it looks promising]
**Priority:** High/Med/Low
**Timeline:** [When to explore - now, v2, research]

**Example:**
### Implicit Calibration
**Opportunity:** Eliminate explicit calibration (stare at dots) by inferring from user behavior
**Approach:** Bayesian optimization using click events as ground truth
**Evidence:** 2 papers demonstrate feasibility, matches SimpleFlow's interaction model
**Priority:** Medium (not critical for v1)
**Timeline:** Research in v2 phase

---

## Blockers & Risks

### Active Blockers

| Blocker | Impact | Resolution Plan | Status |
|---------|--------|-----------------|--------|
| [Blocker 1] | [What's blocked] | [How to resolve] | In Progress / Waiting |

### Risks Identified

| Risk | Likelihood | Impact | Mitigation |
|------|------------|--------|------------|
| [Risk 1] | High/Med/Low | High/Med/Low | [What we're doing about it] |

### Risks Retired

- [Risk that's no longer a concern] - Why: [reason]

---

## Next Week Priorities

### Focus Areas

1. **[Primary focus]** - Why: [rationale]
2. **[Secondary focus]** - Why: [rationale]
3. **[Tertiary focus]** - Why: [rationale]

### Specific Goals

**Research:**
- [ ] [Specific research goal 1]
- [ ] [Specific research goal 2]

**Experiments:**
- [ ] [Experiment to run]
- [ ] [Prototype to build]

**Decisions:**
- [ ] [Decision to make]
- [ ] [Technology to choose]

**Agent Tasks:**
- [ ] [Agent task 1]
- [ ] [Agent task 2]

### Deadlines/Milestones

- [Date]: [Milestone]
- [Date]: [Deadline]

---

## Metrics

### Weekly Targets vs. Actuals

| Metric | Target | Actual | Status |
|--------|--------|--------|--------|
| Hypotheses tested | 3-5 | X | ✓ / ✗ |
| Prototypes built | 1-2 | X | ✓ / ✗ |
| Agent tasks completed | 5-10 | X | ✓ / ✗ |
| Research documents updated | 10+ | X | ✓ / ✗ |

### Cumulative Progress

- **Total hypotheses tested:** X (X validated, X invalidated, X refined)
- **Total experiments run:** X (X successful, X partial, X failed)
- **Total decisions made:** X ADRs
- **Total agent tasks:** X completed
- **Total code written:** XXXX LOC (experiments)

---

## Process Reflections

### What Worked Well

- [Process/approach that was effective]
- [Tool/technique that helped]
- [Collaboration pattern that succeeded]

### What Didn't Work

- [Process issue encountered]
- [Inefficiency identified]
- [Obstacle faced]

### Improvements for Next Week

1. [Process change to make]
2. [Tool/technique to try]
3. [Workflow optimization]

---

## Team/Collaboration

_[If working with others]_

### Discussions This Week

- [Discussion with friend] - Topics: [X, Y] - Decisions: [Z]
- [User testing session] - Participant: [who] - Key feedback: [summary]

### Feedback Received

- [Feedback 1 and response]
- [Feedback 2 and response]

---

## External Engagement

### Papers Read

- [Paper 1] - Citation - Key takeaway
- [Paper 2] - Citation - Key takeaway

### Communities/Forums

- [Post in r/accessibility] - Asked about [topic] - Learned: [summary]
- [Discord discussion] - Topic: [X] - Insight: [Y]

### Inspiration Sources

- [Tool/project discovered] - What's interesting: [why relevant]

---

## Appendix

### Detailed Data

[Link to detailed experiment data, charts, etc.]

### Raw Notes

[Link to day-by-day logs]

### Additional Context

[Anything else worth recording]
