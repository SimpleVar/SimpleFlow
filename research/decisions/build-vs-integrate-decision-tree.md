# Build vs. Integrate vs. Research Decision Tree

Use this framework to decide whether to use existing solutions, build custom, or conduct research.

---

## Decision Tree

```
START: Is there a library/tool that does this?
│
├─ NO ─────────────────────────────────────────────────┐
│                                                        │
│   Q: Is it theoretically possible?                    │
│   │                                                    │
│   ├─ YES ─> RESEARCH + PROTOTYPE ─> Publish findings?
│   │         │                                          │
│   │         ├─ Success ─> BUILD CUSTOM ──────────────┐
│   │         └─ Failure ─> PIVOT to alternative        │
│   │                                                    │
│   └─ NO ──> PIVOT to alternative approach             │
│                                                        │
└─ YES ────────────────────────────────────────────────┐
    │                                                    │
    Q: Is it good enough?                               │
    │                                                    │
    ├─ YES ────────────────────────────────────────────┐
    │   │                                               │
    │   INTEGRATE IT                                    │
    │   │                                               │
    │   Q: Can we improve it meaningfully?              │
    │   │                                               │
    │   ├─ YES + worth time ─> FORK & ENHANCE ─────────┤
    │   │                                               │
    │   └─ NO / not worth ──> USE AS-IS ───────────────┤
    │                                                    │
    └─ NO ─────────────────────────────────────────────┐
        │                                               │
        Q: Can we build better?                         │
        │                                               │
        ├─ YES + worth time ─> BUILD CUSTOM ───────────┤
        │                                               │
        └─ NO / not worth ──> USE EXISTING + WORKAROUND │
                                                        │
                                                        ▼
                                                    IMPLEMENT
```

---

## Decision Criteria

### "Is there a library/tool that does this?"

**How to find out:**
- Search GitHub (stars >100, recent activity)
- Check package managers (vcpkg, npm, pip)
- Review academic implementations (Papers With Code)
- Ask communities (Reddit, Discord, forums)

**Consider:**
- Does it solve the exact problem or close enough?
- Is it production-ready or just a demo?
- Is it maintained and supported?

**Threshold:** At least one viable option exists

---

### "Is it good enough?"

**Evaluation dimensions:**
1. **Meets requirements?** (accuracy, performance, features)
2. **Fits constraints?** (license, cost, platform support)
3. **Acceptable UX?** (learning curve, user satisfaction)
4. **Integrates cleanly?** (API design, dependencies)

**Rating:**
- **Good enough:** Meets 80%+ of needs, minor gaps acceptable
- **Not good enough:** Critical gaps (accuracy, performance, features)

**Test:** Build small prototype integration - does it "just work"?

---

### "Can we improve it meaningfully?"

**Meaningful improvements:**
- Accuracy boost >20%
- Performance improvement >2x
- Key missing feature that's feasible to add
- Better UX for our specific use case
- Customization for domain (e.g., code-aware prediction)

**Not meaningful:**
- Marginal improvements (<10%)
- Nice-to-haves that aren't critical
- Optimizations that don't matter for our scale

**Feasibility check:**
- Is source code available and readable?
- Do we have skills to improve it?
- Is the architecture extensible?
- Time estimate: days/weeks (OK) vs. months (not worth)

---

### "Can we build better?"

**Be honest:**
- Do we have expertise in this domain?
- Have we researched state-of-the-art thoroughly?
- Is there a clear technical path to better results?
- Do we have time to build + maintain custom solution?

**Build if:**
- Existing solutions fundamentally flawed
- We have domain expertise
- Requirements are unique to our use case
- Time investment is justified by impact

**Don't build if:**
- We'd just be reinventing the wheel
- Existing solution is "good enough"
- We lack expertise (would end up with worse version)
- Maintenance burden outweighs benefits

---

### "Is it theoretically possible?"

**Research questions:**
- Has anyone solved a similar problem?
- What's the state-of-the-art?
- What are known hard limits (physics, computation, etc.)?
- Is this an open research problem?

**Possible if:**
- Academic papers demonstrate feasibility
- Similar solutions exist in other domains
- No fundamental blocker identified

**Not possible if:**
- Contradicts physics/math
- Known hard limits exist (e.g., webcam resolution, human perception)
- Expert consensus is "unsolved problem"

---

## Decision Paths Explained

### Path 1: INTEGRATE (Use existing as-is)

**When:**
- Library exists and meets 80%+ of needs
- Integration is straightforward
- Maintenance is handled by maintainers
- License is compatible
- No meaningful improvements feasible/needed

**Pros:**
- Fast time to market
- Proven, tested solution
- No maintenance burden
- Community support

**Cons:**
- Dependent on external project
- Can't customize deeply
- May have unnecessary features/complexity

**Example:** Using MediaPipe Iris for gaze estimation

---

### Path 2: FORK & ENHANCE

**When:**
- Existing solution is 60-80% there
- Source is available and well-architected
- We can add missing 20-40% (features, performance, customization)
- Original project may benefit from our changes (contribute back)

**Pros:**
- Start from solid foundation
- Add exactly what we need
- Can contribute improvements upstream
- Maintain fork if needed

**Cons:**
- Need to keep up with upstream changes
- More work than pure integration
- Risk of divergence

**Example:** Forking a text prediction engine to add code-awareness

---

### Path 3: USE EXISTING + WORKAROUND

**When:**
- Existing solution is imperfect but acceptable
- Gap is annoying but not critical
- Building better would take too long
- Workaround is feasible

**Pros:**
- Ship faster with imperfect solution
- Learn what improvements matter most
- Can build better in v2 with user feedback

**Cons:**
- User experience compromise
- Technical debt accumulates
- May need to rewrite later

**Example:** Using basic voice recognition even though accuracy isn't perfect, plan to improve later

---

### Path 4: BUILD CUSTOM

**When:**
- No existing solution meets needs
- We have clear path to better results
- Domain-specific requirements
- Research validates feasibility

**Pros:**
- Exactly what we need
- Full control and customization
- Can optimize for specific use case
- Potential research contribution

**Cons:**
- Highest time investment
- Maintenance burden on us
- Risk of ending up worse than existing solutions
- Reinventing wheel in some areas

**Example:** Custom calibration algorithm optimized for accessibility use case

---

### Path 5: RESEARCH + PROTOTYPE

**When:**
- No solution exists
- Theoretically possible but unproven
- Would advance state-of-the-art
- High-risk, high-reward

**Process:**
1. Literature review (what's been tried?)
2. Hypothesis formation (what might work?)
3. Prototype/experiment (test hypothesis)
4. Publish if successful (contribute to field)
5. Integrate if validated (use in SimpleFlow)

**Pros:**
- Push boundaries
- Potential breakthrough
- Publishable research
- Differentiation

**Cons:**
- High risk of failure
- Long timeline
- Requires research skills
- May not pan out

**Example:** Implicit calibration using intent inference

---

### Path 6: PIVOT

**When:**
- Original approach isn't feasible
- Existing solutions inadequate and can't build better
- Theoretical blocker discovered
- Cost/time exceeds value

**Process:**
1. Document why original approach failed
2. Identify alternative approaches
3. Evaluate alternatives (back to start of decision tree)
4. Commit to pivot quickly (don't sink more time)

**Example:** If gaze tracking proves too inaccurate, pivot to head tracking

---

## Example Decisions

### Example 1: Eye Tracking Method

**Question:** Should we use MediaPipe, Tobii SDK, or build custom?

**Path:**
1. Libraries exist (MediaPipe, Tobii) ✓
2. Are they good enough?
   - MediaPipe: 70% there (accuracy ok, but not great)
   - Tobii: 95% there (excellent, but expensive hardware)
3. Can we improve MediaPipe meaningfully?
   - Maybe: Add calibration (feasible)
   - Maybe: Add filtering (feasible)
4. Can we build better than both?
   - Unlikely: Would need ML expertise + datasets

**Decision:** INTEGRATE MediaPipe + ENHANCE with calibration/filtering

**Rationale:**
- MediaPipe provides solid foundation
- Calibration/filtering are well-understood (not research)
- Better than building from scratch
- Can support Tobii later as premium option

---

### Example 2: Code-Aware Text Prediction

**Question:** Should we use existing prediction engine or build custom?

**Path:**
1. Libraries exist (n-gram models, some code completion) ✓
2. Are they good enough?
   - General text prediction: Yes for prose, No for code
   - Code completion (LSP): Yes for specific files, No for context-aware prediction across files
3. Can we build better?
   - Yes: Combine code completion + usage patterns + user history
   - Research shows this is feasible
4. Worth the time?
   - Maybe: Core feature for programmer users
   - v1: Use existing code completion as-is
   - v2: Build custom with user data

**Decision:** USE EXISTING + WORKAROUND (v1), plan BUILD CUSTOM (v2)

**Rationale:**
- Ship v1 faster with LSP-based completion
- Learn what users actually need
- Build custom in v2 with real usage data
- Avoid premature optimization

---

### Example 3: Implicit Calibration

**Question:** Should we build implicit calibration or use explicit (stare at dots)?

**Path:**
1. Library exists? No - this is novel ✗
2. Is it theoretically possible?
   - Research: Some papers on intent inference
   - Bayesian optimization could work
   - Yes, but unproven ✓
3. Research + Prototype needed

**Path:** RESEARCH + PROTOTYPE

**Process:**
1. Literature review on implicit calibration
2. Hypothesis: Infer calibration from click events
3. Prototype: Collect gaze + click data, optimize calibration
4. Test: Does accuracy improve over time?
5. If success: Integrate, consider publishing
6. If failure: Use explicit calibration (known to work)

**Decision:** RESEARCH for v2, use explicit calibration for v1

**Rationale:**
- High-risk research not critical for v1
- Explicit calibration is good enough
- Implicit would be great UX improvement for v2
- Time-box research, pivot if not panning out

---

## Decision Template

Use this template when making build-vs-integrate decisions:

```markdown
# Decision: [Component/Feature Name]

## Existing Solutions

| Option | Good Enough? | Can Improve? | Can Build Better? | Path |
|--------|--------------|--------------|-------------------|------|
| [Name] | Yes/No | Yes/No | Yes/No | [Path] |
| [Name] | Yes/No | Yes/No | Yes/No | [Path] |
| None | - | - | Theoretically? | [Path] |

## Chosen Path

**Path:** [Integrate / Fork / Use+Workaround / Build / Research / Pivot]

**Rationale:**
- [Primary reason]
- [Secondary reason]
- [Tradeoffs accepted]

## Implementation

**What to do:**
1. [Step 1]
2. [Step 2]
3. [Step 3]

**Time estimate:** [Duration]

**Risks:**
- [Risk and mitigation]

**Review criteria:**
- [How to know if this was right choice]
```

---

## Tips

**Do:**
- Research thoroughly before building custom
- Prototype integrations before committing
- Be honest about expertise gaps
- Consider maintenance long-term
- Start with simplest viable approach

**Don't:**
- Build from scratch as first instinct ("not invented here" syndrome)
- Ignore existing solutions without evaluation
- Underestimate effort to build + maintain
- Overestimate ability to improve existing work
- Pursue research without clear path to value

**Remember:**
- "Perfect is the enemy of good" - ship with existing solution, improve later
- "If it ain't broke, don't fix it" - integrate if it works well enough
- "Standing on shoulders of giants" - build on existing work when possible
- "Know when to fold" - pivot quickly if approach isn't working
