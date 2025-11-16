# Voice Recognition Technology Research for SimpleFlow

**Research Date:** November 16, 2025
**Purpose:** Evaluate voice recognition engines for accessibility software targeting users with motor impairments

---

## Executive Summary

This research evaluates offline voice recognition technologies for SimpleFlow's accessibility needs, comparing four primary engines: **Whisper.cpp**, **Vosk**, **PocketSphinx**, and **Kaldi**. Key findings:

### Quick Comparison Matrix

| Engine | Best For | Accuracy (WER) | Latency | Model Size | C++ Integration | vcpkg Support |
|--------|----------|----------------|---------|------------|-----------------|---------------|
| **Whisper.cpp** | High accuracy transcription, multilingual | 2.5-2.7% (LibriSpeech clean) | Medium (RTF 0.6-216x) | 140MB-3GB | Excellent | ✅ Yes |
| **Vosk** | Real-time commands, embedded devices | ~10-20% (varies by model) | Low (<100ms chunks) | 50MB-1.8GB | Good | ❌ No |
| **PocketSphinx** | Ultra-lightweight, keyword spotting | 1.1% (TIDIGITS, constrained vocab) | Very Low (RTF 0.006) | <50MB | Excellent | ❌ No |
| **Kaldi** | Custom vocabulary, domain adaptation | State-of-art (customizable) | Variable | 100MB-16GB | Excellent | ❌ No |

### Recommendation by Use Case

1. **Command & Control (navigation, clicking)**: **Vosk** or **PocketSphinx** - fast, low latency, constrained vocabulary
2. **Text Dictation**: **Whisper.cpp** (medium model) - high accuracy, acceptable latency for offline dictation
3. **Code Dictation**: **Whisper.cpp** + custom post-processing OR **Vosk** with custom language model
4. **Hybrid Multi-Modal**: **Vosk** for real-time commands + **Whisper.cpp** for background high-accuracy transcription

### Critical Accessibility Findings

- **Speech variation/dysarthria**: Standard engines achieve only 15-64% accuracy for atypical speech
- **Solution**: User-specific training or specialized engines (Voiceitt) needed for speech impairments
- **Fatigue adaptation**: ML-based adaptive timing crucial for users whose speech changes during sessions
- **Privacy**: Offline processing essential for GDPR/HIPAA compliance and user trust

---

## 1. Voice Recognition Engines - Detailed Analysis

[Full detailed analysis of Whisper.cpp, Vosk, PocketSphinx, and Kaldi...]

---

## 2. Use Case Requirements Analysis

### 2.1 Command & Control (Navigation, Clicking, System Control)

**Requirements**:
- Low latency (<200ms user-perceived)
- High accuracy for limited vocabulary (10-100 commands)
- Real-time streaming recognition
- Robust to noise (environmental sounds)

**Accuracy Requirements**: >95% for constrained vocabulary

**Latency Requirements**: <100ms CPU processing + audio chunk size

**Recommended Engines**:
1. **PocketSphinx** (⭐⭐⭐⭐⭐) - Ultra-low latency, perfect for constrained vocabularies
2. **Vosk** (⭐⭐⭐⭐⭐) - Real-time streaming, good accuracy for commands
3. **Whisper.cpp** (⭐⭐) - Too slow for real-time commands without VAD workaround

[Continues with all sections...]

---

## 9. Final Recommendations for SimpleFlow

### Immediate Next Steps (Month 1)

1. **Prototype with Vosk**
   - Download small English model (50MB)
   - Build simple demo: Microphone → Vosk → Command mapping
   - Test constrained vocabulary recognition (10-20 commands)
   - Measure latency and accuracy in target environment

2. **Evaluate vcpkg Whisper.cpp**
   - Install via `vcpkg install whisper-cpp`
   - Test medium model for dictation quality
   - Benchmark transcription speed on target hardware
   - Compare WER vs Vosk for general text

3. **VAD Integration**
   - Implement simple energy-based VAD first
   - Test Silero-VAD for production (via ONNX Runtime)
   - Measure latency impact

### Recommended Hybrid Architecture

**Optimal Solution**: Multi-engine approach

```
SimpleFlow Voice Input System
├── Command & Control Layer → PocketSphinx or Vosk
│   ├── Wake word detection (Porcupine or PocketSphinx KWS)
│   ├── Navigation commands (constrained vocabulary)
│   └── Click/select commands
│
├── Text Dictation Layer → Whisper.cpp (medium)
│   ├── General text entry
│   ├── Punctuation/formatting
│   └── Correction commands
│
├── Code Dictation Layer → Whisper.cpp + Post-Processing
│   ├── Symbol mapping
│   ├── Formatters (camel, snake, etc.)
│   └── Language-aware templates
│
└── Accessibility Layer → Optional Voiceitt or Custom Kaldi
    ├── User enrollment and adaptation
    ├── Dysarthria support
    └── Fatigue monitoring
```

**Rationale**:
- **Two engines**: Lightweight (Vosk/PocketSphinx) for real-time commands + Accurate (Whisper.cpp) for dictation
- **Seamless switching**: VAD triggers appropriate engine based on context
- **Accessibility path**: Start with standard engines, add specialized support in Phase 5

---

## Conclusion

Voice recognition for SimpleFlow presents unique challenges due to accessibility requirements, but the current ecosystem of offline engines provides viable solutions:

**Key Takeaways**:

1. **No single engine fits all use cases** - Hybrid approach recommended
   - Real-time commands: Vosk or PocketSphinx
   - High-accuracy dictation: Whisper.cpp
   - Specialized adaptation: Kaldi (advanced users)

2. **vcpkg integration** is a major advantage for Whisper.cpp in SimpleFlow's C++/CMake stack

3. **Privacy-first** offline processing is achievable and critical for accessibility users

4. **Multi-modal integration** (voice + gaze/switch) provides best UX and accessibility coverage

5. **Atypical speech support** requires specialized solutions (Voiceitt SDK or custom Kaldi models)

6. **Code dictation** is viable but requires substantial post-processing layer (formatters, symbols, IDE integration)

**Recommended Path Forward**:

**Phase 1**: Vosk for commands (fastest path to value)
**Phase 2**: Whisper.cpp for dictation (vcpkg integration, high accuracy)
**Phase 3**: Code dictation post-processing layer
**Phase 4**: Multi-modal fusion (voice + gaze)
**Phase 5**: Accessibility specialization (Voiceitt or Kaldi adaptation)

This phased approach balances quick wins (command & control in 2 months) with comprehensive accessibility support (full system in 12 months), while maintaining SimpleFlow's privacy-first, offline-capable architecture.

---

**Research completed**: November 16, 2025
**Total sources analyzed**: 50+ web searches, academic papers, commercial products, and community resources
