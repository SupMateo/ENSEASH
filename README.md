# ENSEASH / SUPRANO MATEO 2G1 TD1 TP1
## _Description : Development of a shell in C, Practice Work of System Programming at **ENSEA**_

### 1. Introduction to write():
The initial task is to demonstrate the use of the **write()** function for printing content in the terminal.

### 2. Main Loop and Program Structure:
The **core structure of the program**, including the creation of the main loop and the crucial utilization of **fork()** to maintain the shell's continuity while other processes (e.g., fortune) may exit.

### 3. Program Termination Feature:
Implementation of a feature allowing the user to quit the program gracefully.

### 4. Display Prompt Enhancement:
Addressing a challenge in question 4 by introducing a new function, **display_prompt()**, to handle the prompt and **be reactive to the last exited process**. The **use of strlen() replaces sizeof()** to avoid unexpected characters after the shell prompt when a previous process was running.

### 5. Time Calculation and Display:
similar to question 4, I used the **clock_gettime()** function and performed calculations to **display the execution time of the last process exited**. An additional argument, execution_time, is introduced in the display_prompt() function to facilitate this feature.

#### Work In Progress. 
date : Nov 27 2023
