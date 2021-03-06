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
		case SIGFPE:
			printf("signal 3\n");
			fflush(stdout);
			int *p;
			p = 0x1234;
		case SIGSEGV:
			printf("signal 4\n");
			fflush(stdout);
			abort();
		case SIGABRT:
			printf("signal 5\n");
			fflush(stdout);
			system("dir");
		case SIGSYS:
			printf("signal 6\n");
			fflush(stdout);
			exit(1);
	}
}

int main()
{
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
	signal (SIGFPE, sig_handler);
    signal (SIGSEGV, sig_handler);
	signal (SIGABRT , sig_handler);
	signal (SIGSYS, sig_handler);
	if (!(fork())) {
		exit(1);
	}
	wait(NULL);
}

// In the main we creating a zombie process so the SIGCHLD case turns on.
// #1 Now we are in the SIGCHLD case and we raise SIGUSR1 so the SIGUSR1 turns on..
// #2 Now we are in the SIGUSR1 case and we dividing by 0 so the SIGFPE signal turns on.
// #3 Now we are in the SIGFPE case and we giving out variable p a invalid adress memory reference so the SIGSEGV signal turns on.
// #4 Now we are in the SIGSEGV case and we calling abort() so the SIGABRT signal turns on.
// #5 Now we are in the SIGABRT case and we giving system a invalid commans so the SIGSYS signal turns on.
// #6 Now we are in the SIGSYS case and we exiting.