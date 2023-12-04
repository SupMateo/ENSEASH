#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

#define BUFSIZE_COMMAND 1024
#define FD_TERMINAL_OUT 1
#define FD_TERMINAL_IN 0

#define EXIT_INT 0
#define SIGN_INT 1
#define NO_INT -1

void display_time();
void display_prompt(int type, int value, long execution_time);
void execute_command(char *command);

int main(int argc, char **argv)
{
    char command[BUFSIZE_COMMAND];
    int ret, status;
    pid_t pid;
    int last_type = NO_INT;
    int last_value = NO_INT;
    long execution_time;

    struct timespec start, end;

    write(FD_TERMINAL_OUT, "Welcome to ENSEA's Shell.\n", strlen("Welcome to ENSEA's Shell.\n"));
    write(FD_TERMINAL_OUT, "Write 'exit' to stop the program\n", strlen("Write 'exit' to stop the program\n"));

    while (1)
    {
        display_prompt(last_type, last_value, execution_time);
        ret = read(FD_TERMINAL_IN, command, BUFSIZE_COMMAND - 1);
        command[ret - 1] = 0;
        

        if (strcmp(command, "exit") == 0)
        {
            write(FD_TERMINAL_OUT, "Bye bye :)\n", strlen("Bye bye :)\n"));
            exit(EXIT_SUCCESS);
        }

        if ((pid = fork()) == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        clock_gettime(CLOCK_MONOTONIC, &start);

        if (pid != 0)
        {
            wait(&status);
            clock_gettime(CLOCK_MONOTONIC, &end);
            execution_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

            if (WIFEXITED(status))
            {
                last_type = EXIT_INT;
                last_value = WEXITSTATUS(status);
            }
            else if (WIFSIGNALED(status))
            {
                last_type = SIGN_INT;
                last_value = WTERMSIG(status);
            }
        }
        else
        {
            if (!command[0])
            {
                display_time();
                exit(EXIT_SUCCESS);
            }
            else
            {
                execute_command(command);
            }
        }
    }
}

void display_time()
{
    char buffer_time[BUFSIZE_COMMAND];
    struct tm *t;
    time_t stamp;
    time_t timestamp = time(NULL);
    memset(buffer_time, 0, sizeof(buffer_time));
    strftime(buffer_time, sizeof(buffer_time), "%a %b %d %H:%M:%S CET %Y\n", localtime(&timestamp));
    write(FD_TERMINAL_OUT, buffer_time, BUFSIZE_COMMAND);
}

void display_prompt(int type, int value, long execution_time)
{
    char s[BUFSIZE_COMMAND];
    if (type == EXIT_INT)
    {
        sprintf(s, "ENSEASH [exit %d | %dms] %% ", value, execution_time);
        write(FD_TERMINAL_OUT, s, strlen(s));
    }
    else if (type == SIGN_INT)
    {
        sprintf(s, "ENSEASH [sign %d | %dms] %% ", value, execution_time);
        write(FD_TERMINAL_OUT, s, strlen(s));
    }
    else if (type == NO_INT)
    {
        write(FD_TERMINAL_OUT, "ENSEASH %% ", strlen("ENSEASH %% "));
    }
}

void execute_command(char *command)
{
    char *arg;
    char *args[BUFSIZE_COMMAND];
    int i = 0;

    arg = strtok(command, " ");
    while (arg != NULL)
    {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (execvp(args[0], args) == -1)
    {
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}
