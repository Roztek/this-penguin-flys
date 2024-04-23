# This Penguin Flys!

### Project Information
- **Name:** George Rostek
- **Email:** [grost570@mtroyal.ca](mailto:grost570@mtroyal.ca)
- **Course:** COMP 2659-001
- **Professor:** Paul Pospisil
- **Project:** This Penguin Flys

### Source Files
   SUPER.S&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- GLOBALS.H  
   PENGUIN.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- PENGUIN.H  
   FSM.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- FSM.H  
   RASTER.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- RASTER.H  
   RAST_ASM.S&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   BITMAP.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- BITMAP.H  
   SPLASH1.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   SPLASH2.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   SPLASH3.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   SPLASH4.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   SPLASH5.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   SPLASH6.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   SPLASH7.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   MODEL.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- MODEL.H  
   EVENTS.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- EVENTS.H  
   RANDOM.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- RANDOM.H  
   RENDER.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- RENDER.H  
   PSG.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- PSG.H  
   MUSIC.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- MUSIC.H  
   EFFECTS.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- EFFECTS.H  
   ISR.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- ISR.H  
   ISR_ASM.S&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
   KEYBOARD.C&nbsp;&nbsp;&nbsp;--- KEYBOARD.H  
   MOUSE.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- MOUSE.H  


### Directory Information

This is the working directory for the game which includes a `MAKEFILE` that can build the entire project utilizing the `COMPILE.G` file. (Beware: total of 13 splash bitmaps - slow compile times).

### Game Overview

Welcome to *This Penguin Flys!* - a captivating remake of the classic Flappy Bird game with a chilly twist. Developed for the Atari ST platform, this game challenges players to guide a friendly-flying penguin through a series of icy posts that scroll across the screen. Players use the spacebar to control the penguin’s vertical movement, aiming to navigate through gaps and avoid collisions. 

Crafted with C and Assembly on the legendary Motorola MC68000 microprocessor, this project is not only a tribute to the classic gaming but a challenge to the Atari ST's performance limits. It blends nostalgic elements with new challenges, ensuring a familiar yet fresh gameplay experience.


### Key Features

- **Optimized Performance:** Finely tuned using C and Assembly to ensure smooth frame rates and responsive controls on the Motorola MC68000 microprocessor.
- **Finite State Machine (FSM):** Robust FSM governs game logic, enabling seamless transitions between various game states such as start, play, and game over scenarios.
- **Custom Interrupt Service Routines (ISRs):** Hand tailored ISRs for handling game events and user input, ensuring precise and efficient game state updates without impacting the fluidity of gameplay.
- **Enhanced Mechanics:** Experience features like gravity simulation, continuous lift (hold the spacebar), and seamless movement at the screen’s top edge.
- **Multiple Modes:** Choose from Normal or Hard Mode, with posts moving in both horizontal and vertical directions for added challenge.
- **Sound Design:** Enjoy retro-inspired soundtrack and sound effects that resonate with the Atari era.
