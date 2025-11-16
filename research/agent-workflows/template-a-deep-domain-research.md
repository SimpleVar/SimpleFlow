# Template A: Deep Domain Research

**Use When:** Need comprehensive exploration of a single domain

**Agent Type:** Explore agent

**Thoroughness:** Very thorough (for broad exploration) or Medium (for focused queries)

---

## Template Structure

### 1. Research Question
**Format:** Specific, bounded question with clear scope

**Examples:**
- "What are all the webcam-based gaze tracking methods developed in the last 5 years?"
- "How do existing text prediction engines handle code completion?"
- "What calibration approaches are used in commercial eye trackers?"

**Your Question:**
```
[Write your specific research question here]
```

---

### 2. Success Criteria
What counts as "done"? What information must the agent find?

**Examples:**
- "List of at least 5 different approaches with pros/cons"
- "Comparison table with accuracy, cost, hardware requirements"
- "Timeline of evolution from 2015-2025"

**Your Criteria:**
```
[Define success criteria here]
```

---

### 3. Key Resources to Check
Where should the agent look?

**Common Sources:**
- GitHub repositories (stars >100, recent activity)
- Academic papers (Google Scholar, arXiv, specific conferences)
- Product documentation/websites
- Research lab publications
- Technical blogs/forums

**Your Sources:**
```
[Specify key resources to prioritize]
```

---

### 4. Output Format
How should findings be structured?

**Options:**
- Comparison table (features, pros/cons, metrics)
- Taxonomy/categorization
- Timeline/evolution
- Mind map of concepts
- Decision tree
- Annotated bibliography

**Your Format:**
```
[Specify desired output structure]
```

---

### 5. Time Budget Estimate
How long should this research take?

**Guidelines:**
- Quick scan: 10-20 minutes (surface-level, top results)
- Medium exploration: 30-60 minutes (thorough domain coverage)
- Deep dive: 1-2 hours (comprehensive, multiple sources)

**Your Estimate:**
```
[Estimate time needed]
```

---

## Example: Eye Tracking Methods Research

### 1. Research Question
"What are all the webcam-based gaze estimation methods published or released from 2020-2025, focusing on open-source implementations?"

### 2. Success Criteria
- At least 10 different methods identified
- For each: approach type, accuracy claims, hardware requirements, license
- GitHub repos with >50 stars or published papers with implementations
- Comparison of accuracy metrics where available

### 3. Key Resources
- GitHub (search: "gaze estimation", "eye tracking", filters: stars>50, updated 2020+)
- arXiv (computer vision section, keywords: gaze, eye tracking)
- CVPR/ICCV/ECCV papers (2020-2025)
- Papers With Code (gaze estimation leaderboards)

### 4. Output Format
Comparison table with columns:
- Method Name
- Approach (appearance-based, geometry-based, hybrid)
- Claimed Accuracy (degrees)
- Hardware (webcam spec, specialized equipment)
- Real-time? (FPS)
- License
- Link (repo or paper)
- Notes

### 5. Time Budget
60 minutes (thorough exploration, multiple sources)

---

## Agent Prompt Template

```
I need comprehensive research on [DOMAIN/TOPIC].

Research Question: [YOUR QUESTION]

Success Criteria:
- [CRITERION 1]
- [CRITERION 2]
- [CRITERION 3]

Key Resources to Check:
- [SOURCE 1]
- [SOURCE 2]
- [SOURCE 3]

Output Format: [YOUR FORMAT - comparison table, taxonomy, etc.]

Thoroughness level: [quick/medium/very thorough]

Please provide a detailed exploration of this domain, ensuring coverage of recent developments (2020-2025), open-source options where available, and practical considerations for implementation.
```

---

## After Agent Completes

### 1. Review Output
- Does it answer the research question?
- Are success criteria met?
- Any gaps or missing information?

### 2. Extract Key Insights
Create a summary document in research/domains/[domain]/

### 3. Identify Follow-Up Questions
What new questions emerged? Spawn additional agents if needed.

### 4. Update Research Index
Mark domain as explored, link to findings.

### 5. Add to Hypothesis Log
What hypotheses can be formed from this research?
