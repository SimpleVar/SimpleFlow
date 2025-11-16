# Technology Evaluation Matrix

Use this framework to systematically evaluate technology options.

## Evaluation Dimensions

### 1. Accuracy/Quality (Weight: 1.5x)
How well does it perform its core function?

**Rating Scale:**
- **5:** Exceeds requirements, best-in-class
- **4:** Meets all requirements reliably
- **3:** Meets most requirements with minor gaps
- **2:** Significant limitations but usable
- **1:** Barely functional, major issues

**Evidence:**
- Benchmark data
- Academic papers
- User reviews
- Own testing

---

### 2. Accessibility (Weight: 2.0x)
Can target users actually use/afford this?

**Rating Criteria:**
- **Cost:** Free vs. paid, hardware requirements
- **Availability:** Widely available vs. niche/regional
- **Setup complexity:** Minutes vs. hours to configure
- **Hardware requirements:** Works with consumer devices vs. specialized equipment

**Rating Scale:**
- **5:** Free, works with any webcam, <5 min setup
- **4:** Free, specific but common hardware (<$100), <30 min setup
- **3:** Low cost (<$200), moderately easy setup
- **2:** Expensive ($200-$1000), complex setup
- **1:** Very expensive (>$1000), requires specialist support

---

### 3. Performance (Weight: 1.0x)
Does it meet latency and resource constraints?

**Key Metrics:**
- **Latency:** End-to-end processing time
- **CPU usage:** % during normal operation
- **Memory:** RAM footprint
- **FPS:** Frame rate achieved
- **Scalability:** Degrades gracefully under load?

**Rating Scale:**
- **5:** <30ms latency, <20% CPU, <200MB RAM
- **4:** <50ms latency, <30% CPU, <500MB RAM
- **3:** <100ms latency, <40% CPU, <1GB RAM
- **2:** <200ms latency, <60% CPU, <2GB RAM
- **1:** >200ms latency or resource-intensive

---

### 4. User Experience (Weight: 1.5x)
Is it learnable, comfortable, sustainable?

**Dimensions:**
- **Learning curve:** How long to become proficient?
- **Fatigue:** Can use for extended sessions (hours)?
- **Flow preservation:** Interruptions, mode switching
- **Error handling:** Graceful degradation, recovery
- **Feedback:** Clear indication of system state

**Rating Scale:**
- **5:** Intuitive (<15 min to learn), low fatigue, natural flow
- **4:** Learnable (<1 hour), manageable fatigue
- **3:** Moderate learning curve, requires breaks
- **2:** Steep learning curve, tiring, frequent interruptions
- **1:** Frustrating, unsustainable for long sessions

---

### 5. Development Effort (Weight: 1.0x)
How hard is it to integrate and maintain?

**Considerations:**
- **Integration complexity:** Lines of code, dependencies
- **API quality:** Well-documented, intuitive, stable
- **Build system:** Easy to integrate with CMake/vcpkg
- **Debugging:** Easy to troubleshoot when issues arise
- **Maintenance:** How often does it break with updates?

**Rating Scale:**
- **5:** Drop-in integration, excellent docs, stable API
- **4:** Straightforward integration, good docs
- **3:** Moderate effort, adequate docs
- **2:** Complex integration, sparse docs
- **1:** Very difficult, poor docs, fragile

---

### 6. Extensibility (Weight: 1.0x)
Can we customize and improve it?

**Aspects:**
- **Source access:** Can we modify internals?
- **Plugin architecture:** Designed for extension?
- **Research potential:** Room for improvement?
- **Forking viability:** Could we maintain a fork?

**Rating Scale:**
- **5:** Open-source, modular, well-architected, active development
- **4:** Open-source, can modify, decent architecture
- **3:** Partially open, some customization possible
- **2:** Closed but documented, workarounds possible
- **1:** Black box, no customization

---

### 7. Community/Support (Weight: 1.0x)
Can we get help when stuck?

**Indicators:**
- **Documentation:** Comprehensive, up-to-date, examples
- **Community:** Active forums, Discord, StackOverflow
- **Development:** Regular updates, responsive maintainers
- **Resources:** Tutorials, blog posts, videos

**Rating Scale:**
- **5:** Excellent docs, active community, frequent updates
- **4:** Good docs, helpful community, regular updates
- **3:** Adequate docs, some community, occasional updates
- **2:** Sparse docs, small community, infrequent updates
- **1:** Poor docs, no community, abandoned

---

### 8. License/Cost (Weight: 1.0x)
Legal and financial considerations

**Factors:**
- **License type:** Permissive (MIT/Apache) vs. copyleft (GPL) vs. commercial
- **Cost:** Free vs. paid, per-user vs. one-time
- **Restrictions:** Can we use in our context?
- **Attribution:** What's required?

**Rating Scale:**
- **5:** Public domain, MIT, Apache, BSD (permissive free)
- **4:** LGPL, MPL (weak copyleft)
- **3:** GPL (strong copyleft but free)
- **2:** Free with restrictions or low-cost commercial
- **1:** Expensive commercial or incompatible license

---

## Evaluation Template

| Option | Accuracy | Accessibility | Performance | UX | Dev Effort | Extensibility | Support | License | **Weighted Total** |
|--------|----------|---------------|-------------|----|-----------:|--------------:|--------:|--------:|-------------------:|
| [Name] | X | X | X | X | X | X | X | X | **XX.X** |

**Weight:** 1.5x, 2.0x, 1.0x, 1.5x, 1.0x, 1.0x, 1.0x, 1.0x

**Calculation:**
```
Total = (Accuracy × 1.5) + (Accessibility × 2.0) + (Performance × 1.0)
      + (UX × 1.5) + (DevEffort × 1.0) + (Extensibility × 1.0)
      + (Support × 1.0) + (License × 1.0)

Max Score = 50.0
```

---

## Example: Eye Tracking Method Evaluation

| Option | Accuracy | Accessibility | Performance | UX | Dev Effort | Extensibility | Support | License | **Total** |
|--------|----------|---------------|-------------|----|-----------:|--------------:|--------:|--------:|----------:|
| MediaPipe Iris | 3 | 5 | 4 | 3 | 4 | 3 | 5 | 5 | **35.5** |
| Custom ONNX | 4 | 5 | 3 | 3 | 2 | 5 | 2 | 5 | **32.0** |
| Tobii SDK | 5 | 2 | 5 | 4 | 3 | 2 | 4 | 2 | **31.5** |
| Hybrid | 5 | 4 | 3 | 4 | 2 | 4 | 3 | 4 | **34.5** |

**Analysis:**

**MediaPipe Iris wins** due to:
- Highest accessibility (works with any webcam)
- Excellent support and docs
- Permissive license
- Good enough accuracy for initial version

**Tradeoffs accepted:**
- Lower accuracy than Tobii (but 2x accessibility weight compensates)
- Less extensibility than custom model (but better support compensates)

**Recommendation:**
Start with MediaPipe Iris. Build abstraction layer (InputSource) to allow Tobii as premium option later. Keep custom ONNX path open for research integration.

---

## Customizing Weights

Adjust weights based on project priorities:

**Maximizing accessibility (default for SimpleFlow):**
- Accessibility: 2.0x
- Accuracy: 1.5x
- UX: 1.5x
- All others: 1.0x

**Maximizing performance (low-latency focus):**
- Performance: 2.0x
- Accuracy: 1.5x
- UX: 1.5x
- All others: 1.0x

**Rapid prototyping (speed to market):**
- Dev Effort: 2.0x (easier integration prioritized)
- Support: 1.5x (need good docs)
- Accuracy: 1.5x (still needs to work)
- All others: 1.0x

**Research project (novelty focus):**
- Extensibility: 2.0x (must be able to modify)
- Accuracy: 1.5x (pushing boundaries)
- Community: 1.5x (academic support)
- All others: 1.0x

---

## Decision Process

1. **List options** (from domain research, competitive analysis)
2. **Gather evidence** (benchmarks, experiments, papers, reviews)
3. **Rate each dimension** (use evidence, not intuition)
4. **Calculate weighted totals** (use appropriate weights)
5. **Analyze tradeoffs** (not just highest score - context matters)
6. **Make recommendation** (with rationale)
7. **Document as ADR** (using adr-template.md)
8. **Validate with prototype** (test top 1-2 options if close)

---

## Tips for Good Evaluation

**Do:**
- Use data where possible (benchmarks, user studies)
- Consider project phase (early vs. late)
- Weight according to priorities (accessibility for SimpleFlow)
- Be honest about cons (don't rationalize preferred choice)
- Test finalists with prototypes

**Don't:**
- Guess ratings without evidence
- Ignore low scores in critical dimensions
- Let personal preferences override evaluation
- Forget to document decision rationale
- Skip prototyping when scores are close
