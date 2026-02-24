# 🎵 SoundInSpace

**Interactive Spatial Software Synthesizer**

An OpenFrameworks-based synthesizer that transforms mouse movement into real-time sound, exploring spatial interaction as a creative tool for music generation.

---

## 📖 Project Overview

SoundInSpace is an interactive software synthesizer where spatial position directly controls sound synthesis. By moving your mouse cursor across the screen, you control pitch, volume, and timbre in real time. Different regions of the screen activate different synthesizer voices, creating an intuitive instrument that merges visual space with audio expression.

The project demonstrates clean object-oriented programming through modular audio components and spatial mapping systems, making it easy to extend with new voices or interaction patterns.

---

## ✨ Features

- **Real-time Sound Synthesis** — Three distinct synthesizer voices (Sine, Square, Noise) with unique timbres
- **Spatial Interaction** — Mouse position dynamically controls multiple sound parameters
- **Visual Feedback** — Circle size and color respond to pitch and volume changes
- **Modular Architecture** — Clean OOP design with separated audio and interaction layers
- **Low-Latency Performance** — Optimized audio callback for responsive playback

---

## 🎮 Controls

| Input | Action |
|-------|--------|
| **Move mouse up** | Increases volume and pitch (circle grows) |
| **Move mouse down** | Decreases volume and pitch (circle shrinks) |
| **Move mouse horizontally** | Triggers different spatial zones and voices |
| **Drag cursor** | Creates continuous sound modulation |
| **ESC** | Exit application |

---

## 🏗️ Project Structure
```
SoundInSpace/
├── src/
│   ├── audio/
│   │   ├── SineVoice.h         # Pure sine wave oscillator
│   │   ├── NoiseVoice.h        # Filtered noise generator
│   │   └── SynthEngine.h       # Audio engine coordinator
│   ├── interaction/
│   │   └── SpatialMapper.h     # Maps screen space to audio parameters
│   ├── ofApp.h                 # Main application controller
│   ├── ofApp.cpp               # Application implementation
│   └── main.cpp                # Entry point
├── bin/
│   └── data/                   # Assets (if any)
├── SoundInSpace.sln            # Visual Studio solution
└── README.md
```

---

## 🚀 Installation & Setup

### Prerequisites
- **Visual Studio 2022** (with C++ Desktop Development workload)
- **OpenFrameworks v0.12.1** ([download here](https://openframeworks.cc/download/))
- **Windows 10/11 or macOS 13 and above** (64-bit) 

### Steps

1. **Install OpenFrameworks**
```
   Extract openFrameworks to C:\openFrameworks\
```

2. **Place Project in openFrameworks**
```
   Copy SoundInSpace folder to:
   C:\openFrameworks\apps\myApps\SoundInSpace\
```

3. **Open in Visual Studio**
```
   Double-click SoundInSpace.sln
```

4. **Build the Project**
```
   Build → Rebuild Solution (or Ctrl+Shift+B)
```

5. **Run**
```
   Press F5 or click "Local Windows Debugger"
```

### Troubleshooting

**"Cannot open include file 'ofMain.h'"**
- Verify OpenFrameworks is installed correctly
- Check project properties → C/C++ → Additional Include Directories

**No sound output**
- Check Windows audio settings
- Ensure default audio device is enabled
- Try adjusting system volume

---

## 🎨 Object-Oriented Design

### Class Relationships

**1. Inheritance (IS-A)**
```
Voice (abstract base)
├── SineVoice
├── SquareVoice
└── NoiseVoice
```
All voice types inherit common synthesis behavior (frequency, amplitude, envelope) from a base `Voice` class, enabling polymorphic management.

**2. Composition (HAS-A)**
```
SynthEngine
├── owns → SineVoice
├── owns → SquareVoice
└── owns → NoiseVoice

ofApp
├── owns → SynthEngine
└── owns → SpatialMapper
```
The `SynthEngine` owns and manages the lifetime of all voice instances. The main `ofApp` owns both the audio engine and spatial mapping logic.

---

## 👥 Team Capricorn

**Felicia Odai Bonney** — Lead Developer
- Audio engine implementation
- Spatial interaction system
- Visual feedback and UI
- Project architecture

**Vanessa** — Testing & QA
- Cross-device testing
- User experience feedback
- Sound response validation
- Documentation review

---

## 📚 Technical Details

**Audio System**
- Sample Rate: 44,100 Hz
- Buffer Size: 512 samples
- Output: Stereo (2 channels)
- Synthesis: Real-time waveform generation

**Spatial Mapping**
- X-axis: Horizontal position (zone selection)
- Y-axis: Pitch (20 Hz – 2000 Hz range)
- Y-axis: Amplitude (0.0 – 1.0 normalized)

---

## 🎓 Course Information

**Coding Camp II: Interactivity**  
**Project 2 — Interactive Audio Systems**  
**Q1 2026**

---

## 📝 License

This project was created for educational purposes as part of Coding Camp II.

---

## 🙏 Acknowledgments

- OpenFrameworks community for excellent documentation
- Course instructors for guidance on OOP design patterns
- Team Capricorn for collaborative problem-solving

---

**Built with OpenFrameworks 0.12.1 | Visual Studio 2022 | C++17**