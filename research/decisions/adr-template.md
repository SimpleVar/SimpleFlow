# ADR NNN: [Decision Title]

**Status:** [Proposed | Accepted | Superseded | Rejected]

**Date:** YYYY-MM-DD

**Deciders:** [Who made this decision]

**Related ADRs:** [Links to related decisions, if any]

---

## Context

What is the issue we're trying to address? What are the forces at play?

- What problem are we solving?
- Why is this decision necessary now?
- What are the constraints (technical, business, user needs)?
- What assumptions are we making?

**Example:**
```
We need to choose an eye tracking method for cursor control. Our target users have motor impairments and may not afford specialized hardware like Tobii ($1000+). The tracking must be accurate enough for clicking UI elements (buttons, links) but doesn't need sub-pixel precision. We need real-time performance (<50ms latency) on consumer hardware.
```

---

## Options Considered

### Option 1: [Name]

**Description:** Brief explanation of this approach

**Pros:**
- [Advantage 1]
- [Advantage 2]
- [Advantage 3]

**Cons:**
- [Disadvantage 1]
- [Disadvantage 2]
- [Disadvantage 3]

**Evaluation:**

| Criterion | Rating (1-5) | Notes |
|-----------|--------------|-------|
| Accuracy | X | [Comments] |
| Accessibility | X | [Cost, hardware requirements] |
| Performance | X | [Latency, resource usage] |
| UX | X | [Learning curve, fatigue] |
| Dev Effort | X | [Implementation complexity] |
| Extensibility | X | [Can we customize/improve?] |
| Support | X | [Docs, community, maintenance] |
| License | X | [Open-source, cost, restrictions] |

**Total Score:** XX/40

---

### Option 2: [Name]

[Same structure as Option 1]

---

### Option 3: [Name]

[Same structure as Option 1]

---

## Decision

**Chosen Option:** [Which option was selected]

**Rationale:**

We chose [option] because:

1. [Primary reason - most important factor]
2. [Secondary reason - supporting factor]
3. [Tertiary reason - tiebreaker or nice-to-have]

While [alternative] had advantages in [dimension], we prioritized [factor] because [user need / technical constraint / strategic goal].

**Key Tradeoffs Accepted:**
- We're accepting [downside] in exchange for [benefit]
- We're deprioritizing [factor] to optimize for [priority]
- We're betting that [assumption] holds true

---

## Consequences

### Positive

**What we gain:**
- [Benefit 1]
- [Benefit 2]
- [Benefit 3]

**Opportunities enabled:**
- [What this makes possible]
- [Future enhancements supported]

### Negative

**What we lose:**
- [Tradeoff 1]
- [Tradeoff 2]
- [Limitation accepted]

**Risks introduced:**
- [Risk 1 and mitigation plan]
- [Risk 2 and mitigation plan]

### Neutral

**Changes required:**
- [Implementation tasks]
- [Architecture adjustments]
- [Documentation updates]

---

## Implementation Notes

**What needs to be built:**
- [Component 1]
- [Component 2]
- [Integration work]

**Dependencies:**
- [Library/tool needed]
- [Other decisions that must be made first]

**Estimated Effort:** [Time estimate]

**First Steps:**
1. [Immediate next action]
2. [Second action]
3. [Third action]

---

## Validation

**How we'll know this was the right choice:**
- [Success metric 1]
- [Success metric 2]
- [User feedback indicator]

**Review Timeline:** [When to revisit this decision]

**Conditions for Reconsidering:**
- If [metric] doesn't meet [threshold]
- If [assumption] turns out false
- If [new information] emerges

---

## References

**Research:**
- [Link to domain research]
- [Link to feasibility study]
- [Link to competitive analysis]

**Experiments:**
- [Link to prototype/experiment]
- [Benchmark data]

**External:**
- [Academic papers]
- [Documentation]
- [Relevant discussions]

---

## Notes

**Additional context:**
- [Anything else worth recording]
- [Historical context]
- [Lessons learned]

**Future refinements:**
- [Ideas for improving this later]
- [Known limitations we might address]
