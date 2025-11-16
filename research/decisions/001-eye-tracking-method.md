# ADR 001: Eye Tracking Method - MediaPipe Iris

**Status:** Accepted

**Date:** 2025-11-16

**Deciders:** Research findings from Input Modalities domain research

**Related ADRs:**
- ADR-002: Multi-Modal Architecture
- ADR-006: Performance Threading Architecture

---

## Context

We need to choose an eye tracking method for cursor control in SimpleFlow. Our target users have motor impairments (CP, ALS, SCI, RSI) and may not be able to afford specialized hardware like Tobii Eye Tracker ($150-$15,000). The tracking must be accurate enough for clicking UI elements (buttons, links, form controls) but doesn't need sub-pixel precision. We need real-time performance (<50ms latency contribution) on consumer hardware (standard webcams, mid-range laptops).

**Key Constraints:**
- Accessibility: Must work with $0 additional hardware (standard webcam)
- Accuracy: Must achieve sufficient precision for UI interaction (target: <2° visual angle)
- Performance: Must run in real-time (30+ FPS) on consumer CPUs
- Cross-platform: Must work on Windows and Linux
- Cost: Free/open-source strongly preferred for accessibility mission

**Assumptions:**
- Users have access to a webcam (built-in or external, 720p minimum)
- Reasonable lighting conditions (standard indoor office/home lighting)
- Users can complete initial calibration process (5-point, ~30 seconds)

---

## Options Considered

### Option 1: MediaPipe Iris

**Description:** Google's MediaPipe framework with Iris landmark detection. Uses RGB webcam input to detect 468 face landmarks + 10 iris landmarks (5 per eye). Performs 3D face mesh and iris tracking using trained ML models. Open-source, cross-platform, optimized for real-time performance.

**Pros:**
- $0 cost - works with any RGB webcam
- Cross-platform (Windows, Linux, macOS)
- Real-time performance (30-60+ FPS on consumer hardware)
- Active maintenance by Google
- Well-documented, large community
- GPU acceleration available but not required
- 1.4-2.5° accuracy achievable (sufficient for UI interaction)
- No specialized hardware required

**Cons:**
- Lower accuracy than specialized infrared trackers (1.4-2.5° vs 0.5°)
- Requires good lighting (struggles in darkness)
- Accuracy degrades at screen edges
- Gaze estimation not built-in (must build custom gaze mapping)
- Blink detection less robust than dedicated systems

**Evaluation:**

| Criterion | Rating (1-5) | Notes |
|-----------|--------------|-------|
| Accuracy | 4 | 1.4-2.5° sufficient for accessibility (not precision CAD work) |
| Accessibility | 5 | $0 cost, standard hardware, removes major adoption barrier |
| Performance | 5 | 30+ FPS on CPU, 60+ with GPU, <20ms latency contribution |
| UX | 4 | Quick calibration, but sensitive to lighting/head movement |
| Dev Effort | 3 | Gaze estimation must be implemented, not out-of-box |
| Extensibility | 5 | Open-source, can customize models, active ecosystem |
| Support | 5 | Google-maintained, extensive docs, large community |
| License | 5 | Apache 2.0, fully open, no restrictions |

**Total Score:** 36/40

---

### Option 2: Tobii Eye Tracker SDK

**Description:** Commercial eye tracking SDK from Tobii, industry leader. Requires Tobii Eye Tracker 5 hardware ($230) or Tobii Pro hardware ($3,000-$32,000). Uses infrared illumination for high-precision tracking. SDK provides gaze point out-of-box.

**Pros:**
- Highest accuracy (<0.6° for consumer, 0.3° for Pro)
- Works in darkness (infrared illumination)
- Mature, battle-tested SDK
- Built-in gaze estimation and calibration
- Robust to head movement and lighting
- Professional support available
- Low latency (<10ms hardware)

**Cons:**
- **$230-$32,000 hardware cost** - major accessibility barrier
- Windows-only for consumer hardware (Pro supports Linux)
- Proprietary SDK, closed-source
- Hardware requirement excludes many users
- Single vendor lock-in
- Ongoing hardware costs for users

**Evaluation:**

| Criterion | Rating (1-5) | Notes |
|-----------|--------------|-------|
| Accuracy | 5 | Best-in-class, sub-degree precision |
| Accessibility | 1 | $230+ cost excludes target demographic |
| Performance | 5 | <10ms latency, 90Hz tracking |
| UX | 5 | Professional-grade, reliable |
| Dev Effort | 5 | SDK provides everything out-of-box |
| Extensibility | 2 | Closed-source, limited customization |
| Support | 5 | Professional support, extensive docs |
| License | 2 | Proprietary, licensing fees may apply |

**Total Score:** 30/40

---

### Option 3: OpenGazer

**Description:** Open-source webcam-based eye tracker. Academic project, C++ implementation, uses OpenCV. Supports low-cost webcams, provides gaze point estimation.

**Pros:**
- $0 cost, open-source (GPL)
- Works with standard webcams
- Gaze estimation included
- Research-proven approach

**Cons:**
- **Linux-only** (not cross-platform)
- Inactive development (last major update 2011)
- Lower accuracy than modern approaches (2-3°)
- Requires head stability (chin rest in research setups)
- Poor documentation, small community
- No GPU acceleration
- GPL license (copyleft, restricts licensing options)

**Evaluation:**

| Criterion | Rating (1-5) | Notes |
|-----------|--------------|-------|
| Accuracy | 3 | 2-3° achievable but requires stability |
| Accessibility | 4 | $0 cost, but Linux-only limits access |
| Performance | 3 | CPU-only, 20-30 FPS typical |
| UX | 2 | Requires stable head position, poor UX |
| Dev Effort | 4 | Gaze estimation included, saves work |
| Extensibility | 3 | Open-source but outdated codebase |
| Support | 1 | Inactive project, minimal docs |
| License | 3 | GPL (copyleft, limits SimpleFlow licensing) |

**Total Score:** 23/40

---

### Option 4: Custom ONNX Models (GazeML, etc.)

**Description:** Use pre-trained ONNX models for gaze estimation (e.g., GazeML, MPIIGaze). Load models via ONNX Runtime, perform inference on webcam frames. Flexible, can swap models.

**Pros:**
- $0 cost, works with webcams
- Cross-platform (ONNX Runtime everywhere)
- Model flexibility (can upgrade as research improves)
- Open-source models available
- GPU acceleration supported

**Cons:**
- **Experimental accuracy** (4.63° for GazeML, not production-ready)
- Limited pre-trained models available
- Requires custom face detection integration
- More complex integration (model loading, preprocessing, etc.)
- Less robust than MediaPipe (which is ONNX-based under hood)
- Research models often lack calibration support

**Evaluation:**

| Criterion | Rating (1-5) | Notes |
|-----------|--------------|-------|
| Accuracy | 2 | Current models 4-5°, not sufficient |
| Accessibility | 5 | $0 cost, standard hardware |
| Performance | 4 | Fast inference, but depends on model |
| UX | 2 | Research models lack polish |
| Dev Effort | 2 | Significant integration work required |
| Extensibility | 5 | Maximum flexibility to swap models |
| Support | 2 | Research models, minimal docs |
| License | 4 | Most are Apache/MIT |

**Total Score:** 26/40

---

## Decision

**Chosen Option:** MediaPipe Iris (with custom gaze estimation)

**Rationale:**

We chose MediaPipe Iris because:

1. **Accessibility is paramount** - $0 additional hardware cost removes the single biggest adoption barrier for our target users (people with disabilities, RSI sufferers). $230-$15K Tobii hardware would exclude 90%+ of potential users.

2. **Accuracy is sufficient** - Research proves 1.4-2.5° visual angle is achievable with webcam + MediaPipe. At typical viewing distance (50-70cm) and monitor size (24"), this translates to 40-60 pixel precision - more than adequate for clicking buttons, links, and UI controls (WCAG AAA minimum target size is 44x44px).

3. **Production-ready performance** - MediaPipe is battle-tested in production (used in Google products, millions of users). Achieves 30+ FPS on consumer CPUs, 60+ with GPU. Active maintenance ensures ongoing optimization and bug fixes.

While Tobii hardware offers superior accuracy (<0.6° vs 1.4-2.5°), we prioritized accessibility over precision. Our use case (cursor control for accessibility, not precision CAD/design) doesn't require sub-degree accuracy. We can address precision needs through UX (hierarchical selection, zoom modes, adaptive target sizing) rather than expensive hardware.

**Key Tradeoffs Accepted:**
- We're accepting 1.4-2.5° accuracy in exchange for $0 hardware cost (democratizes access)
- We're accepting lighting sensitivity in exchange for RGB vs infrared (users can control lighting more easily than affording $230 hardware)
- We're accepting DIY gaze estimation implementation in exchange for using modern, well-supported framework

**Upgrade Path:** We can add optional Tobii SDK integration in Phase 6+ for users who want sub-degree precision and can afford hardware. MediaPipe remains the accessible default.

---

## Consequences

### Positive

**What we gain:**
- **Universal accessibility** - Works for anyone with a webcam (removes $230-$15K barrier)
- **Cross-platform from day 1** - Windows, Linux, macOS support immediately
- **Active ecosystem** - Google-maintained, large community, ongoing improvements
- **Performance headroom** - 30-60 FPS leaves room for additional processing (filtering, ML prediction)
- **Credibility** - Using production-grade, Google-backed technology vs experimental/abandoned projects

**Opportunities enabled:**
- Can integrate future MediaPipe improvements (hand tracking for hybrid input, emotion detection for fatigue)
- Can build on existing MediaPipe expertise in community
- Can contribute improvements back to MediaPipe (accessibility use case valuable to Google)
- Enables "try before you buy" path (start free, upgrade to Tobii later if needed)

### Negative

**What we lose:**
- **Sub-degree precision** - Can't match Tobii's 0.3-0.6° accuracy
- **Darkness use** - Requires reasonable lighting (infrared works in pitch black)
- **Edge accuracy** - MediaPipe degrades at screen edges (Tobii maintains accuracy)
- **Out-of-box gaze** - Must implement custom gaze estimation (Tobii SDK provides it)

**Risks introduced:**
- **Lighting sensitivity** - User frustration if lighting is poor
  - *Mitigation:* Detect poor lighting conditions, provide user guidance, fall back to voice-only mode
- **Accuracy insufficient for precision work** - Users may find 1.4-2.5° too imprecise
  - *Mitigation:* Implement hierarchical selection, zoom lens, grid navigation for precision tasks; offer Tobii upgrade path
- **MediaPipe discontinuation** - Google could abandon project
  - *Mitigation:* Open-source, can fork if needed; community is large enough to continue maintenance

### Neutral

**Changes required:**
- Implement custom gaze estimation algorithm (map iris landmarks → screen coordinates)
- Build calibration system (5-point minimum, homography transformation)
- Integrate MediaPipe into build system (vcpkg or manual)
- Add lighting quality detection (warn user if too dark/bright)
- Design UX around 1.4-2.5° accuracy constraints (target sizing, precision modes)

---

## Implementation Notes

**What needs to be built:**
- MediaPipe integration layer (C++ wrapper around MediaPipe API)
- Face mesh and iris landmark extraction
- Custom gaze estimation (3D face pose → 2D gaze point)
- Calibration system (collect calibration points, compute homography matrix)
- Implicit recalibration (continuous refinement using interaction data)
- Lighting quality detection (luminance analysis, user warnings)
- Fallback modes (voice-only if tracking fails)

**Dependencies:**
- MediaPipe framework (add to vcpkg.json)
- OpenCV (already included)
- Eigen (already included for matrix math)

**Estimated Effort:**
- Phase 1 (basic integration): 1-2 weeks
- Phase 2 (gaze estimation + calibration): 2-3 weeks
- Phase 3 (optimization + implicit recalibration): 2-3 weeks
- **Total:** 5-8 weeks for production-quality implementation

**First Steps:**
1. Add MediaPipe to vcpkg.json, verify build
2. Create MediaPipe wrapper class (initialize, process frame, extract landmarks)
3. Implement basic gaze estimation (simplified mapping for POC)
4. Test with real webcam, measure accuracy
5. Build calibration UI (5-point grid)

---

## Validation

**How we'll know this was the right choice:**
- Achieve 1.4-2.5° accuracy in real-world testing (matches research benchmarks)
- Users can complete common tasks (web browsing, email, simple coding) with MediaPipe
- 90%+ of beta users have compatible webcam (accessibility goal met)
- Performance metrics: 30+ FPS on mid-range laptop (Intel i5 8th gen or equivalent)
- User feedback: "Good enough for daily use" rating >4/5

**Review Timeline:** End of Phase 2 (after gaze estimation + calibration complete)

**Conditions for Reconsidering:**
- If accuracy <3° in practice (below usable threshold for most UI elements)
- If performance <20 FPS on target hardware (too laggy for real-time feel)
- If >30% of users report lighting issues (too environmentally sensitive)
- If Tobii releases <$50 hardware (changes cost/benefit calculus)
- If MediaPipe abandoned by Google and community doesn't maintain (technology risk)

**Upgrade Path Trigger:**
- If user feedback shows strong demand for sub-degree precision (add Tobii SDK support)
- If affordable infrared webcams emerge (<$50) (re-evaluate hardware recommendation)

---

## References

**Research:**
- [Input Modalities Research](../agent-outputs/input-modalities-findings.md) - Comprehensive comparison of tracking methods
- [Computer Vision Research](../agent-outputs/computer-vision-findings.md) - MediaPipe technical specifications
- [Performance Research](../agent-outputs/performance-findings.md) - Latency and FPS benchmarks

**Benchmarks:**
- MediaPipe Iris: 4.3% depth estimation error, 30+ FPS on mobile devices
- Webcam-based systems: 1.3-1.5° visual angle in central screen regions (2024-2025 literature)
- Tobii Eye Tracker 5: <0.6° accuracy, $230 retail

**External:**
- [MediaPipe Documentation](https://developers.google.com/mediapipe)
- [MediaPipe Iris GitHub](https://github.com/google/mediapipe/blob/master/docs/solutions/iris.md)
- Academic papers on webcam gaze estimation accuracy (cited in Input Modalities research)

---

## Notes

**Additional context:**
- This decision aligns with SimpleFlow's mission: accessibility for all, not just those who can afford expensive hardware
- MediaPipe Iris is a 2020+ technology; older research (pre-2018) shows much worse webcam accuracy, creating misconception that webcam eye tracking "doesn't work"
- The 1.4-2.5° accuracy is a measured real-world result, not theoretical - validated by recent independent research

**Future refinements:**
- Phase 6+: Add optional Tobii SDK integration (user chooses during setup)
- Research: Explore ML-enhanced gaze estimation (train custom model on larger dataset)
- Experiment: Multi-camera setup (stereo webcams) for improved depth/accuracy
- Monitor: MediaPipe Face Mesh v2, Attention Mesh (newer models may improve accuracy)

**Lessons learned from research:**
- Accessibility (cost) is more important than precision for our target market
- "Good enough" accuracy + excellent UX beats "perfect" accuracy with barriers to entry
- Modern webcam eye tracking (2020+) is dramatically better than older implementations
- Community and maintenance matter more than raw technology capabilities
