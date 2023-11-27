#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "enseash.h"

#define BUFSIZE_COMMAND 1024
#define FD_TERMINAL_OUT 1
#define FD_TERMINAL_IN 0

int main(int argc, char **argv)
{
	char command[BUFSIZE_COMMAND];
	
	int ret;

	write(FD_TERMINAL_OUT,"Welcome to ENSEA's Shell.\n",sizeof("Welcome to ENSEA's Shell.\n"));
	write(FD_TERMINAL_OUT,"Write 'exit' to stop the program\n",sizeof("Write 'exit' to stop the program\n")-1);

	while(1){
		
		write(FD_TERMINAL_OUT,"ENSEASH %% ",sizeof("ENSEASH %% ")-1);
		ret = read(FD_TERMINAL_IN,command,BUFSIZE_COMMAND-1);
		command[ret-1] = 0;
		if (strcmp(command,"fortune")==0){
			write(FD_TERMINAL_OUT,"Today is what happenened yesterday.\n", sizeof("Today is what happenened yesterday.\n"));
		}else if(!command[0]){
			display_time();
		}else if(strcmp(command,"exit") ==0 ){
			write(FD_TERMINAL_OUT,"Bye bye :)\n",sizeof("Bye bye :)\n"));
			exit(EXIT_SUCCESS);
		}
	}
}

void display_time(){
	char buffer_time[BUFSIZE_COMMAND]; 
	struct tm * t;
	time_t stamp;
	time_t timestamp = time(NULL);
	memset(buffer_time, 0, sizeof(buffer_time));
	strftime(buffer_time, sizeof(buffer_time), "%a %b %d %H:%M:%S CET %Y\n", localtime(&timestamp)); 
	write(FD_TERMINAL_OUT,buffer_time,BUFSIZE_COMMAND);
}

