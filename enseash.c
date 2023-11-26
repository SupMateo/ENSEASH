#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE_COMMAND 30

int main(int argc, char **argv)
{
	char command[BUFSIZE_COMMAND];

	write(1,"Welcome to ENSEA's Shell.\n",sizeof("Welcome to ENSEA's Shell.\n"));
	write(1,"Write 'exit' to stop the program\n",sizeof("Write 'exit' to stop the program\n")-1);
	prompt(command);

	
}

//FUNCTIONS

void prompt(char command[BUFSIZE_COMMAND])
{
	write(1,"ENSEASH %% ",sizeof("ENSEASH %% ")-1);
	fscanf(stdin,"%s",command);
}

