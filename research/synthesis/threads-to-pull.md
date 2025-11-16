# Promising Research Threads

High-potential directions for SimpleFlow innovation.

**Last Updated:** 2025-11-16

---

## Overview

These are promising research directions that could differentiate SimpleFlow from existing accessibility tools. Each thread represents a potential breakthrough opportunity - not incremental improvement, but 10x better experiences.

**Evaluation Criteria:**
- **Novelty:** Has this been tried before? Is it unique?
- **Impact:** How much better would user experience be?
- **Feasibility:** Can we actually build this with current/near-future tech?
- **Timeline:** Near-term (v1), medium-term (v2-3), or long-term (research)?

---

## Thread 1: Implicit Calibration

**Opportunity:** Eliminate explicit calibration (stare at dots) by inferring calibration from user behavior over time.

### The Problem
Current eye tracking requires explicit calibration:
- User must stop workflow and stare at 9+ dots
- Tedious and disruptive (breaks flow)
- Needs recalibration when drift occurs
- Major UX barrier for accessibility tools

### The Opportunity
**What if the system calibrated itself automatically during normal use?**

Approach:
1. Track correlation between gaze position and actual click events (dwell, voice, blink)
2. Use Bayesian optimization to infer true calibration from this data
3. Continuously refine calibration model as user works
4. Zero explicit calibration needed - just start using it

### Why It Could Work
- **Click events are ground truth:** When user clicks (dwell/voice), we know they intended to click there
- **Bayesian optimization:** Well-studied technique, works with sparse data
- **Continuous improvement:** Gets more accurate over time
- **Reinforcement learning:** User feedback (undo, re-click) signals errors

### Research Needed
- Literature: Has anyone done implicit eye tracking calibration?
- Feasibility: How many clicks needed to achieve acceptable accuracy?
- Algorithm: Bayesian optimization, particle filters, or RL approach?
- Comparison: How good vs. explicit calibration? (goal: 90%+ as good)

### Estimated Timeline
- **v1:** No - too risky, use explicit calibration
- **v2:** Prototype as experimental feature
- **v3:** Main calibration method if successful

### Impact if Successful
- **UX:** Massive improvement - no calibration interruptions
- **Differentiation:** No existing tool does this well
- **Universal appeal:** Even able-bodied users would prefer this

### Risks
- May never achieve accuracy of explicit calibration
- Requires many clicks to converge (slow start)
- Could be confusing if accuracy fluctuates
- Complex algorithm - debugging/maintenance burden

**Priority:** Medium (high impact, medium feasibility, not critical for v1)

---

## Thread 2: Predictive Clicking

**Opportunity:** Predict where user wants to click before they complete the dwell/action, reducing interaction latency.

### The Problem
- Dwell clicking requires 500-800ms of stillness
- Feels slow compared to mouse (instant click)
- Fatigue from waiting for dwell completion
- Breaks flow in fast-paced tasks

### The Opportunity
**What if the system predicted the click target and triggered automatically?**

Approach:
1. Track gaze patterns and UI context (what's on screen)
2. ML model predicts probability of click for each UI element
3. When confidence exceeds threshold, trigger click without waiting for full dwell
4. Could reduce perceived latency by 30-50%

### How It Could Work
**Context signals:**
- What's on screen (buttons, links, input fields)
- User's current task (reading vs. navigating vs. editing)
- Gaze trajectory (landing on element from specific direction)
- Element properties (size, color, position, type)
- Historical behavior (user often clicks this element)

**Prediction model:**
- Input: Current gaze position, velocity, UI context, history
- Output: Probability of click for each element (0-1)
- Decision: If P > threshold (e.g., 0.85), trigger click early
- Fallback: If uncertain, wait for full dwell

### Why It Could Work
- **UI is structured:** Limited set of clickable targets (not free-form)
- **Patterns exist:** Users tend to click similar things in similar contexts
- **ML is mature:** Click prediction is well-studied (web analytics, A/B testing)
- **Gradual adoption:** Can start conservative (high threshold), tune based on data

### Research Needed
- Academic: Papers on gaze-based click prediction, intent inference
- Data: Would need gaze+click dataset to train model (could collect from users)
- Models: Lightweight enough for real-time inference (<10ms)?
- UX: Would users trust it? Would false positives be frustrating?

### Estimated Timeline
- **v1:** No - need baseline data first
- **v2:** Prototype with opt-in experimental feature
- **v3:** Refined based on v2 data

### Impact if Successful
- **Speed:** 30-50% faster clicking (massive for high-frequency tasks)
- **UX:** Feels more responsive, less waiting
- **Differentiation:** No accessibility tool does this
- **Universal appeal:** Even mouse users might want "predictive click" for speed

### Risks
- False positives could be infuriating (clicking wrong thing)
- Requires ML expertise and training data
- May feel "magical" or "creepy" (trust issue)
- Complexity - debugging issues would be hard

**Priority:** Medium-High (very high impact, medium feasibility, needs v1 data)

---

## Thread 3: Gaze Gestures

**Opportunity:** Use eye movement patterns as commands, not just pointing.

### The Problem
- Current gaze input: eyes point, separate mechanism clicks (dwell/voice/blink)
- Slow compared to mouse+keyboard shortcuts
- Mode switching between pointing and commanding

### The Opportunity
**What if specific eye movement patterns triggered actions?**

Examples:
- **Smooth pursuit:** Follow a moving target → select it
- **Saccade sequence:** Look at corners of a square → select region
- **Quick glance:** Look at element, look away, look back quickly → click
- **Double-take:** Look at element twice in rapid succession → activate
- **Scan pattern:** Look left-right-left quickly → undo

### Why It Could Work
- **Humans naturally use gaze gestures:** Nodding, head shaking, etc. (this is eye version)
- **Faster than dwell:** No waiting, just execute pattern
- **Bandwidth increase:** Can encode more commands beyond just pointing
- **Research exists:** Papers on gaze gestures (Dasher text entry, gaze patterns for commands)

### Types of Gestures
**Smooth pursuit:**
- User tracks moving object with eyes
- System detects smooth pursuit (different from saccades)
- Could be used for selection, scrolling

**Saccadic patterns:**
- Rapid eye movements in specific sequences
- Example: Triangle (look at 3 corners) = delete
- Example: Circle (trace circular path) = undo

**Fixation patterns:**
- Where you look and in what order
- Example: Look at item A, then item B → copy A to B
- Example: Look at function name, then error message → go to definition

**Dwell variations:**
- Long dwell (1+ second) = primary action
- Short dwell (300ms) = context menu
- Double dwell = delete/close

### Research Needed
- Academic: Gaze gesture recognition papers (HCI conferences)
- Feasibility: Can gestures be recognized reliably with webcam tracking?
- UX: Are gestures learnable? Memorable? Comfortable?
- Fatigue: Do eye gestures cause strain?

### Estimated Timeline
- **v1:** No - too experimental
- **v2:** Prototype 2-3 simple gestures as opt-in
- **v3:** Expand gesture vocabulary if successful

### Impact if Successful
- **Speed:** Much faster than dwell for power users
- **Expressiveness:** More actions available without mode switching
- **Learning curve:** Could be steep (like vim), but powerful once learned
- **Differentiation:** Novel - no accessibility tool has comprehensive gesture system

### Risks
- Hard to discover (not obvious like buttons)
- Accidental triggers (false positives)
- Fatigue from deliberate eye movements
- Accessibility concern (some users may lack precise eye control)

**Priority:** Medium (high impact for power users, uncertain feasibility, v2+ feature)

---

## Thread 4: Fatigue-Adaptive Interface

**Opportunity:** Detect when user is getting tired and automatically adjust interface to reduce strain.

### The Problem
- Extended computer use causes fatigue (physical and cognitive)
- Accessibility users fatigue faster (more effort for same tasks)
- Current tools have no awareness of user state
- Users must manually adjust settings when tired

### The Opportunity
**What if the system detected fatigue and adapted automatically?**

Adaptations when fatigue detected:
1. **Larger targets:** Increase click target size (easier to aim)
2. **Slower pace:** Increase dwell time (more tolerance for tremor)
3. **More prediction:** Increase text/click prediction aggressiveness
4. **Simplified UI:** Reduce visual clutter, larger fonts
5. **More breaks:** Prompt user to rest (with usage stats)

### Fatigue Signals
**Gaze-based indicators:**
- Increased jitter (less stable fixations)
- Slower saccades (eye movements slowing)
- Missed targets (clicking outside intended element)
- Longer dwell times (taking longer to click)
- Blink rate changes (dry eyes, strain)

**Performance indicators:**
- Error rate increasing (more undo/redo)
- Task completion time slowing
- Voice command accuracy declining
- More corrections needed

**Physiological (future):**
- Heart rate variability (if wearable available)
- Posture changes (if depth camera available)

### Why It Could Work
- **Signals are detectable:** Research shows gaze stability correlates with fatigue
- **Adaptation is automatable:** UI changes can be algorithmic
- **User benefits are clear:** Reduces strain, prolongs usable session
- **Privacy-preserving:** All detection is local, no data sharing needed

### Research Needed
- Academic: Fatigue detection from gaze, physiological signals
- Metrics: What gaze features correlate with fatigue? (jitter, drift, blinks)
- Thresholds: When to trigger adaptation? (gradual vs. threshold-based)
- UX: Do users appreciate adaptation or find it confusing?

### Estimated Timeline
- **v1:** No - focus on baseline experience first
- **v2:** Basic fatigue detection + simple adaptations
- **v3:** Sophisticated model with personalization

### Impact if Successful
- **Sustainability:** Users can work longer sessions without strain
- **Health:** Proactive rather than reactive (prevents overexertion)
- **Differentiation:** No accessibility tool does this
- **Universal appeal:** Everyone experiences fatigue - could help all users

### Risks
- False positives (adapting when user isn't actually tired)
- Could be paternalistic (some users may resent automatic changes)
- Complexity (need good modeling)
- Privacy concerns (fatigue = health data, even if local)

**Priority:** Medium (good UX value, medium feasibility, not critical for v1)

---

## Thread 5: Code-Aware Everything

**Opportunity:** Make every component understand that you're writing code, not just text.

### The Problem
- Existing accessibility tools treat code like any other text
- No understanding of syntax, semantics, or coding workflows
- Text prediction is generic (doesn't know variable names, APIs)
- Voice commands don't understand programming concepts
- Navigation doesn't leverage IDE structure (functions, classes, etc.)

### The Opportunity
**What if SimpleFlow was the first accessibility tool designed specifically for programmers?**

Code-aware features:
1. **Prediction:** Predict variable names from codebase, API completions, common patterns
2. **Voice commands:** "insert for loop", "rename variable", "go to definition", "run tests"
3. **Navigation:** Gaze at function name + voice "go to definition" (IDE integration)
4. **Snippets:** Voice-triggered code templates ("try catch block", "async function")
5. **Context:** Know when you're in IDE vs. terminal vs. browser (adjust input methods)

### Why Programmers Specifically
- **High value:** Programmers are highly paid, professional work is at stake
- **Complex workflows:** If we can solve coding, we can solve anything
- **Underserved:** No good accessibility solution for programming exists
- **Tool acceptance:** Developers already use complex tools (vim, emacs, IDE extensions)
- **Potential crossover:** Able-bodied devs might use for speed/ergonomics

### How It Could Work
**IDE Integration (VS Code extension):**
- SimpleFlow communicates with VS Code via LSP/extension API
- Knows current file, cursor position, available symbols, errors
- Voice commands map to VS Code commands
- Gaze + voice: Look at code, say action

**Code-aware prediction:**
- Parse codebase to extract identifiers (variables, functions, classes)
- Predict completions based on context (scope, type, usage patterns)
- Use language server for intelligent suggestions

**Programming-specific voice commands:**
- "Go to [symbol name]" - navigate to definition
- "Rename [old] to [new]" - refactor
- "Insert [snippet]" - code template
- "Find usages of [symbol]" - cross-reference
- "Run tests" - execute test suite
- "Debug [function]" - set breakpoint

### Research Needed
- Market: How many programmers have motor impairments? (validate segment)
- Current state: What do programmers with disabilities use today? Pain points?
- Voice coding: Research Talon, Voice Code, Dictation, existing solutions
- IDE capabilities: What APIs exist for integration? (LSP, extensions)
- UX: What workflows are hardest? (typing, navigation, debugging, refactoring)

### Estimated Timeline
- **v1:** Basic cursor control, no code-specific features
- **v2:** VS Code extension, basic voice commands, code-aware prediction
- **v3:** Advanced IDE integration, sophisticated code understanding

### Impact if Successful
- **Market:** Could be *the* solution for programmers with motor impairments
- **Differentiation:** Only accessibility tool focused on programming
- **Crossover potential:** Able-bodied devs might use for ergonomics/speed
- **Value:** Enables professional work, not just basic computer access

### Risks
- Market might be too small (niche within niche)
- Complex to build (need IDE integration expertise)
- Competition with voice coding tools (Talon, etc.)
- May not generalize (too specific to programming)

**Priority:** High (core differentiator, aligns with vision, medium-high feasibility)

---

## Thread 6: Multi-Modal Fusion

**Opportunity:** Intelligently combine eye, head, voice inputs to get the best of each modality.

### The Problem
- Most accessibility tools support one input method (eye OR voice OR head)
- Each modality has strengths and weaknesses
- Users forced to choose one, accept tradeoffs
- Mode switching is clunky (explicitly switch between input modes)

### The Opportunity
**What if multiple input modalities worked together seamlessly?**

Multi-modal combinations:
- **Gaze + Voice:** Eyes point (coarse), voice confirms ("click", "type hello")
- **Gaze + Head:** Eyes for fast aiming, head for fine adjustments
- **Voice + Context:** "Click" (clicks where you're looking), "scroll down" (no pointing needed)
- **All three:** Eyes select general area, head fine-tunes, voice confirms action

### Why It Could Work
- **Humans are multi-modal:** We naturally use speech + gesture + gaze together
- **Complementary strengths:** Each modality compensates for others' weaknesses
- **Faster than single modality:** Parallel processing (eyes move while speaking)
- **Flexible:** User can use whichever modality fits the task

**Modality strengths:**
| Modality | Strengths | Weaknesses |
|----------|-----------|------------|
| Eye gaze | Very fast pointing (300ms saccade) | Inaccurate (~2-3°), jitter, Midas touch problem |
| Head tracking | More stable than eyes, works without eye control | Slower than eyes, requires head mobility |
| Voice | Expressive (commands, dictation), hands-free | Slower for pointing, privacy/noise concerns |

**Combined:**
- Eyes do fast pointing (what they're good at)
- Head provides stabilization (compensates for eye jitter)
- Voice provides confirmation (solves Midas touch)
- Context determines which modality is active (automatic switching)

### Fusion Strategies

**Strategy 1: Sensor Fusion (Low-Level)**
- Kalman filter combines eye + head position
- Weighted average based on confidence (if eye jittery, weight head more)
- Single cursor position from multiple inputs
- User doesn't think about which input (just works)

**Strategy 2: Task-Based Routing (High-Level)**
- Different modalities for different tasks:
  - Gaze for pointing/navigation
  - Voice for commands/typing
  - Head for fine adjustments
- System automatically routes based on task
- Example: User looks at button (gaze), says "click" (voice) → action

**Strategy 3: Parallel + Consensus**
- Multiple modalities active simultaneously
- System uses consensus (if eye and head agree, high confidence)
- If disagree, ask user for clarification
- Example: Eye looking at A, head pointing at B → "Did you mean A or B?"

### Research Needed
- Academic: Multi-modal HCI, sensor fusion techniques (Kalman filters, particle filters)
- UX: Does seamless fusion feel natural or confusing?
- Latency: Can fusion be fast enough (<50ms)?
- Conflicts: How to handle disagreements between modalities?

### Estimated Timeline
- **v1:** Basic multi-modal (gaze for pointing, voice for clicking - no fusion)
- **v2:** Sensor fusion (Kalman filter for eye+head stabilization)
- **v3:** Sophisticated fusion (AI-based routing, consensus)

### Impact if Successful
- **Accuracy:** Better than any single modality
- **Speed:** Faster (parallel processing)
- **Flexibility:** User chooses natural input per situation
- **Differentiation:** Most tools are single-modality, this would be unique

### Risks
- Complexity (coordination between modalities is hard)
- Latency (fusion adds processing time)
- Confusion (user may not understand which modality is active)
- Hardware (requires camera + microphone, not just one)

**Priority:** High (core to SimpleFlow philosophy, medium feasibility, start in v1)

---

## Thread 7: Contextual Precision

**Opportunity:** Automatically detect when precision is needed and switch modes without user intervention.

### The Problem
- Sometimes need precision (clicking small button), sometimes don't (reading webpage)
- Current tools require manual mode switching (enter grid mode, exit grid mode)
- Breaks flow, cognitive load

### The Opportunity
**What if the system knew when precision was needed and adapted automatically?**

Triggers for precision mode:
1. **UI context:** Targeting small element (<50px) automatically enables grid
2. **User behavior:** Multiple failed clicks → trigger precision assistance
3. **Task context:** Editing code (precision needed) vs. browsing web (less precision)
4. **Gaze stability:** If gaze is jittery, increase target assist

Precision assistance techniques:
- **Grid mode:** Overlay grid for two-stage selection (zone → target)
- **Magnification:** Zoom area around gaze for fine-tuning
- **Snap-to-target:** Cursor snaps to nearest clickable element
- **Larger click zones:** Invisible expanded hitboxes around small targets

### Why It Could Work
- **UI is analyzable:** Can detect small vs. large targets programmatically
- **User behavior signals intent:** Failed clicks indicate difficulty
- **Context is inferrable:** IDE = precision, browser = less critical
- **Adaptation can be smooth:** Gradual zoom or snap rather than abrupt mode switch

### Research Needed
- Academic: Adaptive interfaces, Fitts' Law for gaze-based pointing
- Detection: What signals reliably indicate precision need?
- UX: Do users appreciate automatic adaptation or prefer manual control?
- Timing: How quickly to trigger? (immediate vs. after failed attempt)

### Estimated Timeline
- **v1:** Manual precision mode (grid, zoom)
- **v2:** Automatic detection + adaptation
- **v3:** AI-based context prediction

### Impact if Successful
- **UX:** Seamless - no mode switching
- **Speed:** No time wasted entering/exiting modes
- **Accessibility:** Helps users who struggle with small targets
- **Universal appeal:** Even mouse users struggle with tiny click targets

### Risks
- False positives (triggering precision when not needed)
- Distracting (grid appearing unexpectedly)
- May be slower than manual mode switching for experts

**Priority:** Medium (good UX improvement, medium feasibility, v2 feature)

---

## Thread 8: Lightweight On-Device ML

**Opportunity:** Run sophisticated ML models on consumer hardware without cloud dependency.

### The Problem
- Many ML applications require cloud (latency, privacy, cost)
- Accessibility users may not have reliable internet
- Privacy concerns with sending gaze/voice data to cloud
- Latency for round-trip to cloud (>100ms, breaks real-time interaction)

### The Opportunity
**What if all ML ran locally on-device with low latency?**

Use cases for on-device ML:
1. **Gaze estimation:** Custom models for better accuracy than MediaPipe
2. **Click prediction:** ML model predicting click targets (Thread 2)
3. **Intent inference:** Understanding user goals from behavior
4. **Text prediction:** Code-aware prediction using language models
5. **Voice recognition:** Offline speech-to-text

### Why It Could Work
- **Edge AI maturing:** TensorFlow Lite, ONNX Runtime, optimized for edge devices
- **Model optimization:** Quantization (INT8), pruning, distillation can shrink models
- **Hardware acceleration:** Even laptops have GPUs, NPUs (Neural Processing Units)
- **Research progress:** Efficient neural architectures (MobileNet, EfficientNet, etc.)

### Technical Approach
**Quantization:**
- Convert FP32 models to INT8 (4x smaller, 4x faster)
- Minimal accuracy loss (<1-2% typically)
- Supported by ONNX Runtime, TFLite

**Model selection:**
- Use efficient architectures (MobileNet, not ResNet)
- Smaller models (<10MB)
- Focus on inference speed (not training)

**Hardware acceleration:**
- Use ONNX Runtime or TFLite with GPU/NPU support
- DirectML on Windows, Metal on Mac, CUDA on Linux
- Fallback to CPU if acceleration unavailable

**Latency budget:**
- Gaze estimation: <20ms per frame (30fps real-time)
- Click prediction: <10ms (part of pointing pipeline)
- Text prediction: <50ms (acceptable typing lag)

### Research Needed
- Benchmarking: What models can run <10ms on consumer CPU?
- Frameworks: ONNX Runtime vs. TFLite vs. custom?
- Models: Which pre-trained models are suitable? (or train custom)
- Optimization: Quantization trade-offs, accuracy vs. speed

### Estimated Timeline
- **v1:** Use MediaPipe (optimized for edge), no custom ML
- **v2:** Experiment with custom models (ONNX)
- **v3:** Production ML pipeline for multiple features

### Impact if Successful
- **Privacy:** All processing local (no data leaves device)
- **Latency:** <10ms inference (fast enough for real-time)
- **Offline:** Works without internet
- **Differentiation:** Cloud-dependent tools can't match this UX

### Risks
- Complexity (ML expertise required)
- Hardware assumptions (may not run on all devices)
- Maintenance (models need updates, retraining)
- Battery impact (ML can drain battery on laptops)

**Priority:** Medium-High (enables multiple features, medium feasibility, foundation for v2+)

---

## Thread 9: Universal Accessibility Layer

**Opportunity:** Understand and control any application, not just those with specific integrations.

### The Problem
- Most accessibility requires app-specific integration (extensions, APIs)
- Only works with supported apps (VS Code ✓, random app ✗)
- Users want to control *everything* on their computer
- Building integrations for every app is impossible

### The Opportunity
**What if SimpleFlow could understand and control any UI, even without integration?**

Approach:
1. **OS accessibility APIs:** Use AT-SPI (Linux), UI Automation (Windows), Accessibility API (Mac)
2. **Computer vision:** Analyze screen visually to understand UI (OCR, object detection)
3. **Semantic understanding:** Combine accessibility tree + visual analysis → full UI model
4. **Universal control:** Click, type, navigate anything using this model

### Why It Could Work
- **Accessibility APIs expose structure:** Most apps have accessibility tree (for screen readers)
- **Computer vision is mature:** OCR (Tesseract), UI element detection (YOLO, Detectron)
- **Hybrid is powerful:** Combine semantic (API) + visual (CV) for full understanding
- **Research exists:** Papers on GUI automation, accessibility tree + vision

### Capabilities

**Level 1: Accessibility API**
- Read UI structure (buttons, text fields, menus)
- Programmatic click/type actions
- Works for apps with good accessibility support

**Level 2: Accessibility API + OCR**
- Read text even if not in accessibility tree
- Identify labels, buttons, links from visual text
- Works for apps with partial accessibility

**Level 3: Accessibility API + Computer Vision**
- Detect UI elements visually (buttons, icons, controls)
- Understand layout, grouping, relationships
- Works even for apps with zero accessibility support

**Level 4: Semantic Understanding**
- Combine all signals → infer semantics
- "This is a toolbar", "This is a form", "This is a menu"
- Enable intelligent actions (click button, fill form, select menu item)

### Research Needed
- Feasibility: How reliably can CV detect UI elements?
- Performance: Can this run in real-time (<100ms)?
- Accuracy: What's success rate for diverse UIs?
- APIs: What accessibility APIs are available per platform?

### Estimated Timeline
- **v1:** Use accessibility APIs where available, basic fallback
- **v2:** Add OCR for text extraction
- **v3:** Full CV + semantic understanding

### Impact if Successful
- **Coverage:** Works everywhere (not just supported apps)
- **Maintenance:** No per-app integrations needed
- **Differentiation:** Universal vs. app-specific tools
- **Flexibility:** Adapts to new apps automatically

### Risks
- Accuracy may be insufficient (CV fails on complex UIs)
- Performance (CV + OCR is computationally expensive)
- Fragility (apps change, CV breaks)
- Privacy (requires screenshot access, permission concerns)

**Priority:** Medium (great for universality, uncertain feasibility, v2+ research)

---

## Thread 10: Social/Collaborative Features

**Opportunity:** Enable users to share configurations, learn from each other, and build community.

### The Problem
- Accessibility is isolating (users struggle alone)
- Configuration is complex (many settings, hard to optimize)
- Each user reinvents wheel (figuring out what works)
- No community or shared expertise

### The Opportunity
**What if SimpleFlow had a community and marketplace for sharing?**

Features:
1. **Configuration sharing:** Export/import full setup (voice commands, gaze settings, shortcuts)
2. **Macro marketplace:** Community-created voice command sets, gesture libraries
3. **Profile sync:** Cloud sync configs across devices
4. **Community library:** Pre-made setups for different use cases (programming, design, writing)
5. **Social learning:** "Top 10 voice commands for VS Code" curated by community

### Why It Could Work
- **Accessibility community exists:** Reddit, Discord, forums (they want to share)
- **Configuration is shareable:** TOML files can be exported/imported easily
- **Network effects:** More users = more shared configs = more value
- **Inspiration:** Similar to vim plugins, VS Code extensions, browser bookmarklets

### What Could Be Shared
**Voice command sets:**
- "Programming commands for Python"
- "Web browsing shortcuts"
- "Email workflow voice macros"

**Gaze calibration profiles:**
- "Settings for glasses wearers"
- "Low-jitter configuration"
- "Multi-monitor setup"

**Macro libraries:**
- "Git commands via voice"
- "Common code snippets for JavaScript"
- "Accessibility shortcuts for Windows"

**Use case templates:**
- "Setup for coding in VS Code"
- "Configuration for graphic design in Photoshop"
- "Writer's setup (dictation + editing)"

### Implementation
**Phase 1: Local sharing**
- Export config to file
- Import config from file
- Share via Gist, Discord, forums

**Phase 2: Built-in marketplace**
- Browse community configs in-app
- One-click install
- Ratings and reviews

**Phase 3: Cloud sync**
- Account system (optional)
- Sync configs across devices
- Version control (rollback if new config doesn't work)

**Phase 4: Social features**
- Follow power users
- Discover trending configs
- Remix and build on others' work

### Research Needed
- Community: Is there appetite for sharing? (survey users)
- Privacy: What data is safe to share? (configs might contain personal info)
- Legal: Licensing for shared content (CC, GPL, etc.)
- Infrastructure: Hosting costs, moderation needs

### Estimated Timeline
- **v1:** No - focus on core product
- **v2:** Local export/import
- **v3:** Community marketplace (if traction)

### Impact if Successful
- **Adoption:** Lower barrier (use someone else's config)
- **Innovation:** Community finds creative uses we didn't imagine
- **Retention:** Social features increase stickiness
- **Network effects:** More users = more value (virtuous cycle)

### Risks
- Moderation burden (inappropriate/harmful content)
- Privacy (users accidentally share sensitive info)
- Complexity (building marketplace is significant work)
- Low adoption (if community doesn't form)

**Priority:** Low (high long-term value, low priority for v1-2, v3+ feature)

---

## Priority Summary

| Thread | Priority | Timeline | Impact | Feasibility | Differentiator |
|--------|----------|----------|--------|-------------|----------------|
| 1. Implicit Calibration | Medium | v2-3 | Very High | Medium | High |
| 2. Predictive Clicking | Medium-High | v2-3 | Very High | Medium | Very High |
| 3. Gaze Gestures | Medium | v2-3 | High | Medium-Low | High |
| 4. Fatigue-Adaptive Interface | Medium | v2-3 | High | Medium | Medium |
| 5. Code-Aware Everything | **High** | v2 | Very High | Medium-High | **Very High** |
| 6. Multi-Modal Fusion | **High** | v1-2 | Very High | Medium | High |
| 7. Contextual Precision | Medium | v2 | Medium | Medium-High | Medium |
| 8. Lightweight On-Device ML | Medium-High | v2-3 | High | Medium | High |
| 9. Universal Accessibility Layer | Medium | v2-3 | High | Medium-Low | Medium |
| 10. Social/Collaborative Features | Low | v3+ | Medium | High | Low |

---

## Recommended Focus

**For v1:**
- Thread 6 (Multi-Modal Fusion) - Basic version, gaze+voice
- Foundation for others (input abstraction supports future threads)

**For v2:**
- Thread 5 (Code-Aware Everything) - Core differentiator
- Thread 2 (Predictive Clicking) - Use v1 data to train
- Thread 6 (Multi-Modal Fusion) - Advanced sensor fusion
- Thread 8 (Lightweight ML) - Foundation for prediction

**For v3+:**
- Thread 1 (Implicit Calibration) - If v2 data shows it's viable
- Thread 3 (Gaze Gestures) - For power users
- Thread 4 (Fatigue-Adaptive) - Health/longevity feature

**Research-Track (Ongoing):**
- Thread 9 (Universal Layer) - Prototype, assess feasibility
- Thread 10 (Social) - If community forms organically

---

## Next Steps

1. **Validate hypotheses:** Research each thread to assess feasibility
2. **Prototype cheaply:** Build quick experiments for top 3-5 threads
3. **User feedback:** Test with target users (programmers with motor impairments)
4. **Commit to roadmap:** Based on data, lock in v2-3 priorities

**These threads represent our opportunity to build something 10x better, not just incrementally improved.**
