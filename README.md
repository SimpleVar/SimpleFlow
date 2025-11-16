# SimpleFlow

Accessibility software enabling fluid computer interaction for people with motor impairments.

## Why This Exists

People with physical disabilities face significant barriers when using computers. Current accessibility tools are fragmented, require frequent context switching, and break user flow—especially during complex tasks like programming. A developer with limited hand mobility shouldn't need to fight their tools to write code.

SimpleFlow aims to make disabled users as capable as anyone else, while being so effective that non-disabled users adopt it as an enhancement.

## Core Challenges

### 1. Input Diversity
**Problem:** Motor impairments vary widely—tremors, limited range of motion, paralysis, fatigue.

**Solution:** Multiple input modalities (eye tracking, head tracking, voice) that users can combine and switch between. Configurable sensitivity and filtering to accommodate both coarse and fine motor control.

### 2. Maintaining Flow State
**Problem:** Accessibility tools interrupt concentration. Frequent mode switches, calibration pauses, and error corrections break mental momentum.

**Solution:** Context-aware predictions, smooth transitions between input modes, and intelligent action inference that minimizes explicit commands.

### 3. Complex Task Support
**Problem:** Programming requires precise cursor control, rapid text input, and complex command sequences—traditionally impossible without fine motor skills.

**Solution:** Semantic understanding of IDE context, gesture-to-action mapping, word/code prediction, and macro recording. The system understands "go to definition" not just "click at coordinates."

### 4. Fatigue Management
**Problem:** Alternative input methods can be more tiring than keyboard/mouse.

**Solution:** Adaptive dwell times, fatigue detection, efficiency optimizations that reduce required movements, and multiple text input methods so users can rest specific muscle groups.

### 5. Accuracy vs. Speed
**Problem:** Webcam-based tracking is less accurate than specialized hardware but more accessible.

**Solution:** Support both consumer webcams and professional eye trackers (Tobii). Precision modes, grid navigation, and smart targeting that corrects for tracking noise.

## Required Expertise

### Computer Vision & Machine Learning
- Face mesh detection and head pose estimation
- Gaze estimation from webcam images
- Temporal filtering and prediction
- Model optimization for real-time performance
- Calibration algorithms

### Human-Computer Interaction (HCI)
- Accessibility research and standards (WCAG)
- Fitts' Law and motor control theory
- Cognitive load minimization
- User interface design for limited input
- Dwell-click interaction patterns

### Speech Recognition & NLP
- Acoustic modeling for offline recognition
- Language models for prediction
- Command parsing and intent detection
- Code-aware language understanding
- Speaker adaptation

### Systems Programming
- Low-level OS integration (Win32, X11/Wayland)
- Real-time performance constraints
- Cross-platform abstraction layers
- IPC mechanisms (WebSocket servers)
- Resource management under load

### Assistive Technology
- Existing AT standards and integration
- Screen reader compatibility
- Switch access patterns
- Tobii/specialized hardware APIs
- Legal/compliance requirements (ADA, Section 508)

### Software Engineering
- IDE extension development (VS Code API)
- Browser extension architecture
- Plugin systems and extensibility
- Configuration management
- Testing accessibility software

### Medical/Rehabilitation
- Understanding motor impairments (CP, ALS, RSI, spinal injuries)
- Occupational therapy principles
- Fatigue patterns and management
- User testing with disabled participants
- Ethical considerations in assistive tech

### Signal Processing
- Noise filtering and smoothing
- Kalman filters for tracking
- Gesture recognition
- Time-series analysis
- Adaptive thresholding

### User Experience Research
- Longitudinal studies with target users
- A/B testing alternative input methods
- Workflow analysis for programming tasks
- Error rate and efficiency metrics
- Qualitative feedback integration

## Architecture Overview

```
┌─────────────┐     ┌──────────────┐     ┌─────────────┐
│   Camera    │────▶│   Tracking   │────▶│   Cursor    │
│   Input     │     │   (MediaPipe)│     │   Control   │
└─────────────┘     └──────────────┘     └─────────────┘
                           │
                           ▼
                    ┌──────────────┐
                    │   Filter &   │
                    │   Predict    │
                    └──────────────┘
                           │
        ┌──────────────────┼──────────────────┐
        ▼                  ▼                  ▼
┌──────────────┐   ┌──────────────┐   ┌──────────────┐
│  Text Input  │   │  IDE Plugin  │   │   Browser    │
│  (Voice/Kbd) │   │  (VS Code)   │   │  Extension   │
└──────────────┘   └──────────────┘   └──────────────┘
```

## License

The Unlicense - Public domain dedication.
