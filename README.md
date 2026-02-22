 SoundInSpace

**Interactive Spatial Software Synthesizer**

---

## Project Overview
SoundInSpace is an interactive software synthesizer that turns mouse movement into real-time sound. Moving the cursor vertically changes the volume and pitch, while horizontal movement and spatial zones activate different sound voices. The project explores spatial interaction as a tool for music creation.

---

## Features
- Real-time sound generation using multiple synthesized voices
- Spatial interaction: sound responds dynamically to mouse movement
- Visual feedback: circle grows/shrinks based on pitch and volume
- Modular object-oriented structure for easy extension

---

## Controls
- **Move the mouse**: vertical position controls volume and pitch  
- **Spatial zones**: trigger different sound voices  
- **Drag the cursor**: continuously modify sound and visuals  
- **Press ESC**: exit the application  

---

## Files and Structure

src/
├── audio/
│
│ ├── SineVoice.h
│ └── SquareVoice.h
│ └── SynthEngine.h
├── interaction/
│ └── SpatialMapper.h
├── ofApp.h
├── ofApp.cpp
└── main.cpp

bin/data/ <- Any required sound files or images


---

## Installation / Setup
1. Install **Visual Studio 2022** with C++ build tools.  
2. Download and set up **openFrameworks v0.12.1**.  
3. Open `SoundInSpace.sln` in Visual Studio.  
4. **Build → Rebuild Solution**.  
5. Run the program.  

---

## Team
- **Felicia:** 
- **Vanessa:**  

---

  
---
