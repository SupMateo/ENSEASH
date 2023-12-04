# ENSEASH / SUPRANO MATEO 2G1 TD1 TP1
## _Description : Development of a shell in C, Practice Work of System Programming at **ENSEA**_
## _Session 1 : Nov 27 2023_
### 1. Introduction to write() :
The initial task is to demonstrate the use of the **write()** function for printing content in the terminal.

### 2. Main Loop and Program Structure :
The **core structure of the program**, including the creation of the main loop and the crucial utilization of **fork()** to maintain the shell's continuity while other processes (e.g., fortune) may exit.

### 3. Program Termination Feature :
Implementation of a feature allowing the user to quit the program gracefully.

### 4. Display Prompt Enhancement :
Addressing a challenge in question 4 by introducing a new function, **display_prompt()**, to handle the prompt and **be reactive to the last exited process**. The **use of strlen() replaces sizeof()** to avoid unexpected characters after the shell prompt when a previous process was running.

### 5. Time Calculation and Display :
similar to question 4, I used the **clock_gettime()** function and performed calculations to **display the execution time of the last process exited**. An additional argument, execution_time, is introduced in the display_prompt() function to facilitate this feature.

## _Session 2 : Dec 4 2023_

### Rework of Questions 2 & 3 :
I have added exit functionality using the shortcut **Ctrl+D** and have allowed all commands installed on the machine (not limited to just fortune as in the first session).

### 6. Command with Arguments :
This question prompts us to consider the method for **parsing** and organizing commands. I chose to structure this in the function **execute_command(command)**. It became less challenging once I understood the use of **strtok()**.

### 7. Redirection with '<' and '>' :
This question posed a challenge because a special character occurs during the parsing method discussed in **Question 6**, which can lead to errors. A condition needs to be added to the parsing loop to **exclude the element after the redirection symbol** (<>) from the parsed arguments and use this element in a different logic. I created two functions, **redirect_in()** and **redirect_out()**, to handle redirection of the input and output of the program.

### 8. Attempted :
I **attempted** to address this question using my `redirect_in/out` functions with a **FIFO file descriptor created with mkfifo**. I thought it was wise to use a **fork()** to allow the first command (first process) to send its output to the FIFO, which could then be used by the second command (second process). Unfortunately, I was unable to accomplish this question. To ensure that the **shell continue to work**, I decided to **omit my attempts at this question** from the code.
