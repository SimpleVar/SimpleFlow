# Template B: Competitive Analysis

**Use When:** Need to understand existing solutions in detail

**Agent Type:** Explore agent

**Thoroughness:** Medium to Very thorough

---

## Template Structure

### 1. Solution Category
What type of solutions are we analyzing?

**Examples:**
- "Eye tracking accessibility software"
- "Text prediction engines for AAC devices"
- "Voice-based computer control tools"
- "Grid-based precision pointer systems"

**Your Category:**
```
[Define solution category here]
```

---

### 2. Competitors to Analyze
Which specific solutions should be researched?

**How to identify:**
- Market leaders (most users, revenue)
- Open-source alternatives (GitHub stars, community)
- Academic prototypes (recent publications)
- Platform-specific (Windows Eye Control, etc.)

**Your List:**
```
1. [Competitor 1]
2. [Competitor 2]
3. [Competitor 3]
4. [Competitor 4]
5. [Competitor 5]
```

---

### 3. Evaluation Criteria
What dimensions matter for comparison?

**Common Criteria:**
- Features (what can it do?)
- Accuracy/Performance (how well does it work?)
- Cost (free, paid, hardware required?)
- Ease of use (learning curve, setup time)
- Target users (disabilities supported)
- Platform support (Windows, Mac, Linux)
- Extensibility (plugins, customization)
- Community/Support (docs, forums, updates)
- License (open-source, commercial, restrictions)

**Your Criteria:**
```
[List evaluation dimensions]
```

---

### 4. Sources
Where to find information about competitors?

**Options:**
- Official websites/documentation
- GitHub repositories (README, issues, PRs)
- Academic papers (if research-based)
- User reviews (Reddit, forums, YouTube)
- Demo videos/tutorials
- Accessibility community discussions

**Your Sources:**
```
[Specify where to look]
```

---

### 5. Output Format
How should the analysis be structured?

**Recommended:** Feature comparison matrix

| Tool | Features | Accuracy | Cost | Ease of Use | Platform | License | Notes |
|------|----------|----------|------|-------------|----------|---------|-------|
| ... | ... | ... | ... | ... | ... | ... | ... |

**Your Format:**
```
[Specify desired output]
```

---

## Example: Eye Tracking Accessibility Software

### 1. Solution Category
"Webcam-based eye tracking software for cursor control (accessibility focus)"

### 2. Competitors
1. OptiKey (open-source, keyboard focus)
2. Camera Mouse (Boston College, simple tracker)
3. Tobii Dynavox (commercial, premium hardware)
4. eViacam (open-source, head tracking)
5. Windows Eye Control (built-in, requires Tobii)

### 3. Evaluation Criteria
- Eye/head tracking method
- Click mechanisms (dwell, blink, voice, etc.)
- Text input features (keyboard, prediction)
- Precision modes (grid, zoom, smooth)
- Calibration (one-point, multi-point, none)
- Platform support
- Hardware requirements
- Cost
- Active development (last update)
- License
- Notable strengths/weaknesses

### 4. Sources
- GitHub repos (OptiKey, eViacam)
- Official websites (Tobii, Camera Mouse)
- YouTube demos
- r/accessibility, r/disability discussions
- Academic papers citing Camera Mouse

### 5. Output Format
**Part 1:** Feature comparison matrix (table)
**Part 2:** Strengths/weaknesses analysis (prose)
**Part 3:** Gap analysis (what's missing in all solutions)
**Part 4:** Differentiation opportunities (how SimpleFlow can be better)

---

## Agent Prompt Template

```
I need a comprehensive competitive analysis of [SOLUTION CATEGORY].

Competitors to Analyze:
1. [COMPETITOR 1]
2. [COMPETITOR 2]
3. [COMPETITOR 3]
4. [COMPETITOR 4]
5. [COMPETITOR 5]

Evaluation Criteria:
- [CRITERION 1]
- [CRITERION 2]
- [CRITERION 3]
- [etc.]

Sources to Check:
- [SOURCE 1]
- [SOURCE 2]
- [SOURCE 3]

Output Format:
1. Feature comparison matrix (table with all criteria)
2. Strengths and weaknesses for each tool (2-3 sentences each)
3. Gap analysis: what do ALL tools lack or do poorly?
4. Differentiation opportunities: how could we build something better?

Thoroughness level: [medium/very thorough]

Please provide detailed analysis that helps us understand the competitive landscape and identify opportunities for a new solution.
```

---

## After Agent Completes

### 1. Review & Validate
- Verify claims (check sources yourself if critical)
- Note any contradictions or uncertainties
- Fill gaps with focused follow-up agents

### 2. Create Gap Analysis Document
research/domains/7-competitive/gap-analysis.md

Identify:
- What users want but no tool provides
- What tools do poorly (common weaknesses)
- What's technically possible but not implemented
- What would be a "10x better" experience

### 3. Define Differentiation Strategy
How will SimpleFlow be meaningfully different/better?

Write this in: research/domains/7-competitive/differentiation-strategy.md

### 4. Extract Design Lessons
What UX patterns work well? What mistakes to avoid?

### 5. Update Research Index
Link to competitive analysis, mark domain as explored
