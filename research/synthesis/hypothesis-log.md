# Hypothesis Log

Central tracker for all hypotheses formed, tested, and refined during SimpleFlow research.

**Last Updated:** 2025-11-16

---

## Active Hypotheses

Currently being tested or awaiting validation.

| ID | Hypothesis | Priority | Evidence So Far | Next Step | Status |
|----|------------|----------|-----------------|-----------|--------|
| H001 | MediaPipe Iris with 5-point calibration can achieve <2.5° gaze accuracy | High | Research: Labvanced 2024 shows 1.4-2.5° achievable | Build prototype, measure actual accuracy | Testing |
| H003 | Producer-consumer threading provides 52-379% FPS improvement | High | Research validated on similar systems | Implement threaded architecture, benchmark | Planning |
| H005 | End-to-end latency <50ms achievable with 60 FPS camera | High | Budget: 8.3ms camera + 15ms processing + 2ms OS + 10ms display = 38ms | Build full pipeline, measure with profiling | Testing |
| H102 | Gaze pattern analysis can predict intent with >80% accuracy | Medium | Research shows 80-92% in production systems | Collect gaze data, train ML model in Phase 3 | Deferred (needs Phase 1-2 data) |
| H103 | Fatigue detection using eye metrics achieves >90% accuracy | Medium | Research: 91% using blink/fixation/pupil | Implement detection algorithm in Phase 2 | Planning |
| H200 | MediaPipe maintains 30+ FPS on consumer hardware (i5 8th gen) | High | Research: 30-100+ FPS reported on smartphones | Test on target hardware spec | Testing |
| H300 | Programmers with RSI will adopt if productivity loss <20% | High | Talon adoption proves willingness to try new tools | User testing with beta group | Planning |
| H301 | Developers prefer gaze+voice over voice-only (vs Talon) | Medium | Research: Gaze enables pointing, voice confirms | Comparative user study | Deferred (Phase 2) |

---

## Validated Hypotheses

Proven true through experiments or research.

| ID | Hypothesis | Validation Evidence | Date Validated | Implications |
|----|------------|---------------------|----------------|--------------|
| H002 | One Euro Filter smooths gaze with <2ms overhead and superior lag/jitter balance | Academic Research Review (Section 5.3), CHI 2012 paper | 2025-11-16 | Use One Euro Filter for cursor smoothing in Phase 1 |
| H004 | Offline voice (Vosk) achieves >95% accuracy for constrained vocabulary | Voice Recognition Research: Vosk benchmarks for commands | 2025-11-16 | Can use offline voice for command & control (Phase 1) |
| H100 | Multi-modal (gaze+voice) reduces error from 43% to 11.7% (75% reduction) | Academic Research Review (Tier 1 Finding #2), multiple studies | 2025-11-16 | Multi-modal is CORE to SimpleFlow, not optional feature |
| H101 | Adaptive dwell time (400-800ms) more usable than static (600ms) | Academic Research: "Significantly more usable than static" (systematic review) | 2025-11-16 | Implement adaptive dwell from Phase 1, not static |
| H104 | 5-point calibration with homography achieves 0.75° accuracy in 30 seconds | Academic Research Review (Tier 1 Finding #9) | 2025-11-16 | 5-point is sweet spot for calibration UX vs accuracy |
| H201 | Threading (producer-consumer) eliminates blocking I/O, critical for real-time | Academic Research: 52-379% FPS improvement validated | 2025-11-16 | Threaded architecture is essential, not optimization |
| H302 | RSI is largest addressable developer market (1-2M devs, 60% experience symptoms) | Motor Disability Research, Stack Overflow 2024 survey | 2025-11-16 | Target RSI prevention/treatment as primary market |
| H303 | Programming-first strategy is optimal (largest gap, hardest use case proves tech) | Competitive Analysis: No tool does gaze+voice+AI for coding | 2025-11-16 | Focus Phase 1-3 on developers, Phase 4+ expand to general |

---

## Invalidated Hypotheses

Proven false - equally valuable for learning.

| ID | Hypothesis | Invalidation Evidence | Date Invalidated | Lesson Learned |
|----|------------|----------------------|------------------|----------------|
| - | No invalidated hypotheses yet | - | - | - |

**Example:**
| ID | Hypothesis | Invalidation Evidence | Date Invalidated | Lesson Learned |
|----|------------|----------------------|------------------|----------------|
| H003 | 300ms dwell time is usable | Experiment showed 45% false positive rate | 2025-11-19 | Need minimum 500ms for acceptable accuracy, faster = more errors |
| H007 | Calibration-free eye tracking is accurate enough | Tested 3 methods, all >5° error without calibration | 2025-11-25 | Calibration is essential, focus on making it quick/easy instead |

---

## Refined Hypotheses

Modified based on new information.

| ID | Original Hypothesis | Refined Hypothesis | Why Refined | Date |
|----|---------------------|-------------------|-------------|------|
| - | No refined hypotheses yet | - | - | - |

**Example:**
| ID | Original Hypothesis | Refined Hypothesis | Why Refined | Date |
|----|---------------------|-------------------|-------------|------|
| H002 | Dwell time of 500ms is optimal | Dwell time of 600-700ms is optimal | Experiment showed 500ms had 15% false positives, 600ms had 8% | 2025-11-20 |
| H009 | Voice commands for all actions | Voice for high-level actions, gaze for pointing | User feedback: saying everything is tiring, hybrid is better | 2025-11-28 |

---

## Deferred Hypotheses

Important but not testing right now.

| ID | Hypothesis | Priority | Why Deferred | When to Test |
|----|------------|----------|--------------|--------------|
| - | No deferred hypotheses yet | - | - | - |

**Example:**
| ID | Hypothesis | Priority | Why Deferred | When to Test |
|----|------------|----------|--------------|--------------|
| H012 | Implicit calibration can achieve same accuracy as explicit | Medium | Too risky for v1, research needed | v2, after explicit calibration working |
| H015 | BCI can supplement gaze for click confirmation | Low | Technology not mature/accessible yet | 2026+, monitor BCI progress |

---

## Hypothesis Categories

### Technical Feasibility

Hypotheses about whether something can work at all.

**Examples:**
- "MediaPipe Iris can achieve <2° accuracy with webcam"
- "Real-time ML inference can run <50ms on consumer CPU"
- "Offline voice recognition can achieve 95%+ accuracy for commands"

**Status:**
- Active: 0
- Validated: 0
- Invalidated: 0

### UX & Interaction

Hypotheses about user experience and interaction patterns.

**Examples:**
- "Dwell clicking feels natural with right timing"
- "Grid mode doesn't disrupt flow for precision tasks"
- "Multi-modal (gaze+voice) reduces cognitive load vs. single modality"

**Status:**
- Active: 0
- Validated: 0
- Invalidated: 0

### Performance

Hypotheses about system performance and optimization.

**Examples:**
- "Kalman filtering can smooth cursor without perceptible lag"
- "Can maintain 30 FPS with full tracking pipeline on min-spec hardware"
- "Prediction can reduce dwell time by 30%+"

**Status:**
- Active: 0
- Validated: 0
- Invalidated: 0

### User Adoption

Hypotheses about what users will actually use/prefer.

**Examples:**
- "Users will tolerate 9-point calibration for better accuracy"
- "Programmers will adopt gaze control if it doesn't slow them down >20%"
- "Able-bodied users will choose multi-modal for ergonomics"

**Status:**
- Active: 0
- Validated: 0
- Invalidated: 0

---

## Hypothesis Template

When forming a new hypothesis, use this structure:

### HXXX: [Hypothesis Title]

**Category:** [Technical Feasibility | UX & Interaction | Performance | User Adoption]

**Priority:** [High | Medium | Low]

**Hypothesis Statement:**
"I believe [APPROACH] will achieve [OUTCOME] because [REASONING]."

**Success Criteria:**
- [Quantitative metric 1]: [Target]
- [Quantitative metric 2]: [Target]
- [Qualitative criterion 1]

**How to Test:**
- [Research approach, experiment design, or user study]

**Time Estimate:** [Hours/days to test]

**Dependencies:**
- [What needs to exist first]
- [What decisions this depends on]

**Impact if Validated:**
- [What this enables]
- [Decisions this informs]

**Impact if Invalidated:**
- [What we'll do instead]
- [Alternative approaches]

---

## Hypothesis Formation Guidelines

### Good Hypotheses Are:

**Specific:**
- ✓ "Dwell time of 500ms will have <10% false positive rate"
- ✗ "Dwell clicking will work well"

**Testable:**
- ✓ "MediaPipe Iris can achieve <3° accuracy" (can measure)
- ✗ "Eye tracking will feel natural" (too subjective)

**Falsifiable:**
- ✓ "Calibration drift will be <1° per hour" (can be proven wrong)
- ✗ "Eye tracking is the best input method" (opinion, not testable)

**Actionable:**
- ✓ "Grid mode will improve targeting accuracy for elements <50px"
- ✗ "Users will like the software" (doesn't guide design)

### When to Form Hypotheses

- After domain research (form testable hypotheses from findings)
- During design discussions (turn assumptions into testable statements)
- When making technology choices (explicitly state what you believe will work)
- Before building features (what are you betting on?)
- After experiments (refine based on what you learned)

### When to Test Hypotheses

**Immediately if:**
- High priority (blocking decision)
- Quick to test (<4 hours)
- High confidence it will validate (build momentum)

**Soon if:**
- Medium priority (informs design)
- Moderate effort (1-2 days)
- Dependencies are nearly ready

**Later if:**
- Low priority (nice-to-know)
- High effort (would delay critical work)
- Missing dependencies (can't test yet)

**Never if:**
- Not actually important (doesn't affect decisions)
- Can't be tested (not falsifiable)
- Already answered (literature or prior work)

---

## Stats Dashboard

### Overall Statistics

- **Total hypotheses formed:** 16
- **Currently active:** 8 (awaiting testing/validation)
- **Validated:** 8 (50%)
- **Invalidated:** 0 (0%)
- **Refined:** 0 (0%)
- **Deferred:** 0 (0%)

### By Category

| Category | Active | Validated | Invalidated | Refined | Total |
|----------|--------|-----------|-------------|---------|-------|
| Technical Feasibility (H001-H099) | 3 | 2 | 0 | 0 | 5 |
| UX & Interaction (H100-H199) | 2 | 2 | 0 | 0 | 4 |
| Performance (H200-H299) | 1 | 1 | 0 | 0 | 2 |
| User Adoption (H300-H399) | 2 | 3 | 0 | 0 | 5 |

### By Priority

| Priority | Active | Validated | Invalidated |
|----------|--------|-----------|-------------|
| High | 5 | 5 | 0 |
| Medium | 3 | 0 | 0 |
| Low | 0 | 0 | 0 |

### Validation Rate

**Target:** 60-70% validated (some hypotheses should fail - if none fail, not testing risky enough ideas)

**Actual:** 50% (8/16 validated through research literature)

**Note:** Strong research backing gives high confidence. Active hypotheses will be tested during Phase 1-3 implementation.

---

## Notes

### Philosophy

- **Invalidation is progress** - Proving something doesn't work is valuable
- **Refine freely** - Update hypotheses as you learn
- **Test risky ideas** - Don't just validate safe bets
- **Be honest** - Don't rationalize failures as successes
- **Move fast** - Form hypotheses, test quickly, iterate

### Integration with Other Systems

- **Experiments:** Each experiment should test specific hypothesis (link IDs)
- **ADRs:** Technology decisions should reference validated hypotheses
- **Research questions:** Answering questions often generates hypotheses
- **Weekly synthesis:** Review hypothesis status every week

---

## Index by ID

**H001-H099:** Technical Feasibility
**H100-H199:** UX & Interaction
**H200-H299:** Performance
**H300-H399:** User Adoption
**H400+:** Other/TBD

| ID | Hypothesis (Short) | Status |
|----|-------------------|--------|
| H001 | MediaPipe Iris + 5-point calibration achieves <2.5° accuracy | Active (Testing) |
| H002 | One Euro Filter: <2ms overhead, best lag/jitter balance | Validated |
| H003 | Producer-consumer threading: 52-379% FPS improvement | Active (Planning) |
| H004 | Offline voice (Vosk) >95% accuracy for commands | Validated |
| H005 | End-to-end latency <50ms achievable with 60 FPS | Active (Testing) |
| H100 | Multi-modal reduces errors 43% → 11.7% (75% reduction) | Validated |
| H101 | Adaptive dwell (400-800ms) more usable than static | Validated |
| H102 | Gaze pattern prediction: >80% intent accuracy | Active (Deferred to Phase 3) |
| H103 | Fatigue detection: >90% accuracy using eye metrics | Active (Planning Phase 2) |
| H104 | 5-point homography: 0.75° accuracy in 30 seconds | Validated |
| H200 | MediaPipe maintains 30+ FPS on consumer hardware | Active (Testing) |
| H201 | Threading architecture is essential for real-time | Validated |
| H300 | Programmers adopt if productivity loss <20% | Active (Planning user testing) |
| H301 | Developers prefer gaze+voice over voice-only | Active (Deferred to Phase 2) |
| H302 | RSI is largest developer market (1-2M devs) | Validated |
| H303 | Programming-first strategy is optimal | Validated |
