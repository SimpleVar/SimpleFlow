# Template D: Cross-Domain Synthesis

**Use When:** Need to connect insights across multiple domains to make integrated decisions

**Agent Type:** Plan agent

**Thoroughness:** Medium

---

## Template Structure

### 1. Domains to Integrate
Which research areas need to be considered together?

**Examples:**
- Computer Vision + UX Design + Performance
- Input Modalities + System Integration + Cost
- Text Entry + Voice Recognition + IDE Integration

**Your Domains:**
```
Domain 1: [Name]
Domain 2: [Name]
Domain 3: [Name]
```

---

### 2. Integration Questions
What questions require cross-domain thinking?

**Format:** Questions that can't be answered by looking at just one domain

**Examples:**
- "If we choose MediaPipe for eye tracking (CV), how does that constrain our precision mode design (UX)?"
- "Given 50ms latency budget (Performance), which combination of input modalities (Input) is viable?"
- "If we target programmers (Users), does that change our text prediction engine choice (Text Entry)?"

**Your Questions:**
```
1. [Question requiring domain 1 + domain 2 insights]
2. [Question requiring domain 2 + domain 3 insights]
3. [Question requiring all domain insights]
```

---

### 3. Tradeoff Analysis
What are the competing constraints?

**Common Tradeoffs:**
- Accuracy vs. Cost (better sensors vs. accessibility)
- Latency vs. Accuracy (filtering smooths but delays)
- Features vs. Simplicity (power-user vs. easy-to-learn)
- Generality vs. Optimization (works everywhere vs. best for programming)

**Your Tradeoffs:**
```
[Dimension A] vs [Dimension B]
- Pulling toward A: [reasons]
- Pulling toward B: [reasons]
- Sweet spot: [hypothesis]
```

---

### 4. Context and Constraints
What's the broader context for this synthesis?

**Consider:**
- Project phase (early exploration vs. late refinement)
- User priorities (what matters most to target users)
- Technical maturity (proven tech vs. research-stage)
- Resource constraints (time, budget, team skills)

**Your Context:**
```
[Describe current state and constraints]
```

---

### 5. Desired Output
What decision or recommendation are you trying to reach?

**Options:**
- Architecture design (component diagram with justification)
- Technology selection (final stack with tradeoff analysis)
- Feature prioritization (roadmap with rationale)
- Risk mitigation plan (addressing cross-domain challenges)

**Your Output:**
```
[Specify what you need to decide]
```

---

## Example: Eye Tracking + UX + Performance Integration

### 1. Domains to Integrate
- **Domain 3: Computer Vision** (gaze estimation methods, accuracy, filtering)
- **Domain 4: Interaction UX** (click mechanisms, precision modes, flow preservation)
- **Domain 8: Performance** (latency budgets, resource constraints)

### 2. Integration Questions
1. "Given MediaPipe Iris accuracy of 2-3 degrees, what click mechanisms are viable without frustrating users?"
2. "If we implement Kalman filtering for smooth cursor (adds 20-30ms latency), does that break our <50ms budget?"
3. "What precision mode UX can compensate for gaze tracking inaccuracy without disrupting flow?"
4. "Should we optimize for speed (lower latency, less filtering) or accuracy (more filtering, higher latency)?"

### 3. Tradeoff Analysis
**Latency vs. Smoothness:**
- **Low latency (no filtering):** <30ms, but cursor jitters, hard to aim
- **Heavy filtering:** Smooth cursor, but 80-100ms lag, feels disconnected
- **Sweet spot hypothesis:** Light Kalman filter (one-step prediction), ~40ms total, acceptable smoothness

**Accuracy vs. Click Confidence:**
- **High accuracy needed:** Dwell time must be long (800ms+), slower interaction
- **Accept lower accuracy:** Use larger targets + grid mode, faster interaction
- **Sweet spot hypothesis:** 500ms dwell with 1.5x target expansion, grid for small targets

**Simplicity vs. Power:**
- **Simple (just dwell):** Easy to learn, limited capability
- **Complex (gaze gestures, modes):** Powerful, steeper learning curve
- **Sweet spot hypothesis:** Dwell as default, grid as explicit mode, defer gestures to v2

### 4. Context and Constraints
- **Project Phase:** Early exploration, choosing core technologies
- **User Priority:** Programmers with motor impairments - need precision for code, tolerance for learning curve
- **Technical Maturity:** MediaPipe is proven, custom ML is risky
- **Resources:** Solo developer + friend testing, need to ship v1 in 3 months

**Constraints:**
- Must work on $50 webcam (accessibility requirement)
- Latency <50ms preferred, <100ms acceptable
- CPU <40% (need headroom for IDE)
- Accuracy 2-3° (MediaPipe Iris limit)

### 5. Desired Output
**Decision:** Architecture for cursor control pipeline

Components to define:
1. Tracking method (CV choice)
2. Filtering approach (performance tradeoff)
3. Click mechanism (UX design)
4. Precision mode (compensate for accuracy limits)

With justification for each based on cross-domain analysis.

---

## Agent Prompt Template

```
I need synthesis across multiple research domains to make an integrated decision.

Domains to Integrate:
1. [DOMAIN 1]: [Key findings/constraints from this domain]
2. [DOMAIN 2]: [Key findings/constraints from this domain]
3. [DOMAIN 3]: [Key findings/constraints from this domain]

Integration Questions:
1. [QUESTION 1]
2. [QUESTION 2]
3. [QUESTION 3]

Key Tradeoffs:
- [DIMENSION A] vs [DIMENSION B]: [describe tension]
- [DIMENSION C] vs [DIMENSION D]: [describe tension]

Context:
- Project phase: [where we are]
- User priorities: [what matters most]
- Resources: [time, skills, budget]
- Must-have constraints: [non-negotiables]

Please analyze:
1. How do choices in one domain affect possibilities in others?
2. What are the viable combinations given all constraints?
3. What are the tradeoffs between different approaches?
4. What's the recommended solution that best balances all factors?

Output Format:
1. Constraint interaction analysis (how domains affect each other)
2. Viable options (2-3 different approaches that could work)
3. Tradeoff comparison (pros/cons of each option)
4. Recommendation (which option + detailed rationale)
5. Risk assessment (what could still go wrong)

Thoroughness level: medium
```

---

## After Agent Completes

### 1. Validate Integration Logic
- Do the domain interactions make sense?
- Are there missing considerations?
- Does the recommendation align with project goals?

### 2. Make Decision
Based on synthesis, commit to:
- Technology choices
- Architecture approach
- Feature priorities
- Risk mitigation strategies

### 3. Document as ADR
Write Architecture Decision Record in research/decisions/:
- Context (why this decision needed)
- Options considered (from synthesis)
- Decision (what was chosen)
- Consequences (tradeoffs accepted)

### 4. Update Affected Domains
If decision changes assumptions in any domain:
- Update domain research documents
- Mark affected hypotheses for retesting
- Adjust roadmap if needed

### 5. Identify Implementation Dependencies
What needs to be built first? What can be parallel?

Create implementation sequence plan.

### 6. Update Research Index
- Link to synthesis document
- Mark integrated decision
- Note next actions
