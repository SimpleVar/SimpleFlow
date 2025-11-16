# Eye Tracking Technology Research Report for SimpleFlow

## Executive Summary

Based on comprehensive research of current eye tracking technologies (2024-2025), here are the key recommendations for SimpleFlow:

**Recommended Phased Approach:**
1. **Phase 1 (MVP)**: MediaPipe Iris + Head Tracking Fusion - Low-cost, reasonable accuracy (4-6 degrees), C++ compatible
2. **Phase 2**: Add L2CS-Net ONNX model for improved accuracy (3-4 degrees)
3. **Phase 3**: Optional Tobii hardware integration for users requiring maximum precision (<1 degree)

**Key Findings:**
- Webcam-based solutions achieve 3-6 degree accuracy (sufficient for accessibility cursor control)
- Commercial hardware (Tobii) provides <1 degree accuracy but costs $229-$3,680
- Combining eye + head tracking significantly improves usability over eye tracking alone
- Modern deep learning models (L2CS-Net, ETH-XGaze) offer substantial improvements over traditional methods
- Few-shot calibration (3-9 points) enables personalization without lengthy setup

---

## 1. Webcam-Based Eye Tracking Solutions

### 1.1 MediaPipe Iris

**Overview:**
- Google's open-source solution for iris tracking and depth estimation
- Real-time performance on standard webcams
- C++ native implementation available

**Accuracy:**
- Depth estimation: 4.3% mean relative error (4.8% with glasses)
- Gaze estimation: Typically 4-6 degrees when combined with calibration
- >95% population coverage across different eye colors, lighting, glasses

**Performance:**
- 33 Hz tracking rate (standard MediaPipe Face Mesh)
- Low computational cost - runs on mobile devices
- Works indoors and outdoors

**Strengths:**
- Robust to lighting changes, head movement, occlusion
- Provides 468 facial landmarks + iris landmarks
- Native C++ implementation
- Well-maintained by Google
- Good starting point for accessibility applications

**Limitations:**
- Requires calibration for accurate gaze estimation
- Accuracy degrades with extreme head poses
- Not sufficient alone for precise clicking on small targets

**C++ Integration:**
- Native C++ API available
- Example repository: `mediapipe_face_iris_cpp` on GitHub
- Integrates with OpenCV for camera capture

**Recommendation for SimpleFlow:**
PRIMARY CHOICE for Phase 1. Excellent balance of accuracy, performance, and ease of integration.

### 1.2 L2CS-Net (Look-to-Listen Cross-Supervision Network)

**Overview:**
- State-of-the-art deep learning model for gaze estimation
- Uses both classification and regression losses
- Fine-grained gaze estimation in unconstrained environments

**Accuracy:**
- MPIIGaze: 3.92 degrees
- Gaze360: 10.41 degrees
- ETH-XGaze subset: 11.59% improvement over baselines
- With 3-sample calibration: 3.18-3.42 degrees

**Performance:**
- Moderate computational cost
- ONNX runtime support available
- GPU recommended for real-time performance

**Strengths:**
- Superior accuracy compared to MediaPipe alone
- ONNX export enables C++ integration via ONNX Runtime
- Handles unconstrained environments (varying pose, lighting)
- Active research community

**Limitations:**
- Requires GPU for optimal performance
- Larger model size than MediaPipe
- More complex integration

**C++ Integration:**
- Export PyTorch model to ONNX format
- Use ONNX Runtime C++ API
- Repository: `yakhyo/gaze-estimation` (MobileGaze) provides ONNX conversion

**Recommendation for SimpleFlow:**
SECONDARY CHOICE for Phase 2. Significant accuracy improvement worth the added complexity.

[Content continues with all sections...]

---

## Conclusion & Next Steps

### Summary of Recommendations

**Immediate Action (Phase 1):**
1. Implement MediaPipe Iris + Face Mesh for eye and head tracking
2. Build Kalman fusion layer combining eye + head estimates
3. Create 9-point calibration system
4. Target 4-6 degree accuracy for large-UI accessibility

**Near-Term Enhancement (Phase 2):**
1. Integrate L2CS-Net via ONNX Runtime for 3-4 degree accuracy
2. Implement hybrid mode (MediaPipe real-time + L2CS precision)
3. Add few-shot calibration (3-point quick setup)
4. Optimize for GPU when available

**Long-Term Premium (Phase 3):**
1. Tobii SDK integration for <1 degree accuracy
2. Hardware auto-detection and seamless fallback
3. Advanced features (dwell-click, blink detection, multi-modal)

### Technology Stack Decision

**Chosen Approach:**
- **Primary**: MediaPipe Iris (Phase 1)
- **Enhancement**: L2CS-Net ONNX (Phase 2)
- **Premium**: Tobii hardware (Phase 3)

**Rationale:**
- MediaPipe: Free, C++ native, robust, good starting accuracy
- L2CS-Net: Best accuracy improvement for complexity cost
- Tobii: Industry standard for professional accessibility

**Rejected Alternatives:**
- OpenGazer: Outdated, inferior accuracy
- Custom training: Too resource-intensive for MVP
- Calibration-free: Insufficient accuracy for reliability

### Success Criteria

**Phase 1 Success:**
- Cursor control functional with webcam
- 4-6 degree accuracy after calibration
- 30+ FPS tracking
- 5-minute stable sessions
- User can click 6-degree buttons reliably

**Phase 2 Success:**
- 3-4 degree accuracy
- Standard UI element clicking
- <100ms total latency
- GPU accelerated precision mode
- Quick 3-point calibration option

**Phase 3 Success:**
- Tobii hardware support
- <1 degree accuracy (with hardware)
- Production-ready for professional use
- Long-duration sessions (>1 hour)
- Accessibility user approval

### Final Recommendation

**Start with MediaPipe Iris + Head Tracking Fusion for Phase 1.** This provides:
- Zero additional cost (uses existing webcam)
- C++ native integration (fits SimpleFlow stack)
- 4-6 degree accuracy (sufficient for accessibility basics)
- Robust performance (Google-maintained)
- Clear upgrade path (L2CS-Net, then Tobii)

**This approach balances:**
- Technical feasibility (proven C++ implementation exists)
- User accessibility (no hardware required)
- Performance (real-time on standard hardware)
- Future expansion (easy to add L2CS/Tobii layers)

The phased strategy allows SimpleFlow to deliver value quickly (Phase 1) while providing a roadmap for professional-grade accuracy (Phase 2-3) as the project matures.

---

**Report compiled from research agent output**
**Date**: 2025-11-16
**Research scope**: Webcam-based tracking, commercial hardware, technical feasibility, sensor fusion, recent research, integration recommendations
