#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signum)
{
	int i=5;
	int j=0;
	int k;
	switch (signum) {
		case SIGCHLD:
			printf("signal 1\n");
			fflush(stdout);
			raise(SIGUSR1);
		case SIGUSR1: 
			printf("signal 2\n");
			fflush(stdout);
			k=i/j;
			printf("lalala\n");
			fflush(stdout);
			break;
		case SIGFPE:
			printf("signal 3\n");
			fflush(stdout);
            raise(SIGINT);
        case SIGINT:
            printf("signal 4\n");
            fflush(stdout);
            raise(SIGABRT);
        case SIGABRT:
            printf("signal 5\n");
            fflush(stdout);
            exit(1);
	}
}
int main()
{
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
	signal (SIGFPE, sig_handler);
    signal (SIGINT, sig_handler);
    signal (SIGABRT , sig_handler);
	if (!(fork())) {
		exit(1);
	}
	wait(NULL);

}
