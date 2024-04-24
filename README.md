# This Penguin Flys!

### Project Information
&nbsp;&nbsp;&nbsp;&nbsp;**Name:**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;George Rostek  
&nbsp;&nbsp;&nbsp;&nbsp;**Email:**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[grost570@mtroyal.ca](mailto:grost570@mtroyal.ca)  
&nbsp;&nbsp;&nbsp;&nbsp;**Course:**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;COMP 2659-001  
&nbsp;&nbsp;&nbsp;&nbsp;**Professor:**&nbsp;&nbsp;Paul Pospisil  
&nbsp;&nbsp;&nbsp;&nbsp;**Project:**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This Penguin Flys!  

### Source Files
&nbsp;&nbsp;&nbsp;&nbsp;SUPER.S&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- GLOBALS.H  
&nbsp;&nbsp;&nbsp;&nbsp;PENGUIN.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- PENGUIN.H  
&nbsp;&nbsp;&nbsp;&nbsp;FSM.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- FSM.H  
&nbsp;&nbsp;&nbsp;&nbsp;RASTER.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- RASTER.H  
&nbsp;&nbsp;&nbsp;&nbsp;RAST_ASM.S&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;BITMAP.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- BITMAP.H  
&nbsp;&nbsp;&nbsp;&nbsp;SPLASH1.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;SPLASH2.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;SPLASH3.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;SPLASH4.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;SPLASH5.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;SPLASH6.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;SPLASH7.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;MODEL.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- MODEL.H  
&nbsp;&nbsp;&nbsp;&nbsp;EVENTS.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- EVENTS.H  
&nbsp;&nbsp;&nbsp;&nbsp;RANDOM.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- RANDOM.H  
&nbsp;&nbsp;&nbsp;&nbsp;RENDER.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- RENDER.H  
&nbsp;&nbsp;&nbsp;&nbsp;PSG.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- PSG.H  
&nbsp;&nbsp;&nbsp;&nbsp;MUSIC.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- MUSIC.H  
&nbsp;&nbsp;&nbsp;&nbsp;EFFECTS.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- EFFECTS.H  
&nbsp;&nbsp;&nbsp;&nbsp;ISR.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- ISR.H  
&nbsp;&nbsp;&nbsp;&nbsp;ISR_ASM.S&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;---&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"  
&nbsp;&nbsp;&nbsp;&nbsp;KEYBOARD.C&nbsp;&nbsp;&nbsp;--- KEYBOARD.H  
&nbsp;&nbsp;&nbsp;&nbsp;MOUSE.C&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- MOUSE.H  


### Directory Information

The '*penguin*' directory is the working directory for the game. It includes all source files listed above, as well as a `MAKEFILE` that can build the entire project by utilizing the `COMPILE.G` file. (Beware: total of 13 splash bitmaps - slow compile times).

### Game Overview

Welcome to *This Penguin Flys!* - a captivating remake of the classic Flappy Bird game with a chilly twist. Developed for the Atari ST platform, this game challenges players to guide a friendly-flying penguin through a series of icy posts that scroll across the screen. Players use the spacebar to control the penguin’s vertical movement, aiming to navigate through gaps and avoid collisions. 

Crafted with C and Assembly on the legendary Motorola MC68000 microprocessor, this project is not only a tribute to classic gaming but also challenges the Atari ST's performance limits. It blends nostalgic elements with new challenges, ensuring a familiar yet fresh gameplay experience.


### Key Features

- **Optimized Performance:** Finely tuned using C and Assembly to ensure smooth frame rates and responsive controls on the Motorola MC68000 microprocessor.
- **Robust Finite State Machine (FSM):** Dynamic and efficient FSM governs game logic, enabling seamless transitions between various game states such as start, play, and game over scenarios.
- **Custom Interrupt Service Routines (ISRs):** Hand tailored ISRs, featuring a custom vertical blank for optimized rendering, and an ISR for handling user input, ensure precise and efficient updates to the game state without compromising gameplay fluidity.
- **Enhanced Mechanics:** Experience features like simulated gravity, continuous lift (hold the spacebar), and seamless movement at the screen’s top edge.
- **Multiple Modes:** Choose from Normal or Hardmode, with the extra challenge of posts moving in both the horizontal and vertical direction.
- **Sound Design:** Enjoy retro-inspired soundtrack and sound effects that resonate with the Atari era.
