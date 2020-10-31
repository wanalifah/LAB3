#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{
	void sigint_handler(int sig);
	char s[200];
	
	if (signal(SIGINT,sigint_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	
	void sigtstp_handler(int sig);
	char m[200];
	
	if (signal(SIGTSTP,sigtstp_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	
	void sigquit_handler(int sig);
	char n[200];
	
	if (signal(SIGQUIT,sigint_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}

	
	printf("Enter a string:\n");
	
	if (fgets(s,200,stdin) == NULL)
		perror("gets");
	else
		printf("You entered: %s\n",s);
	
	return(0);
	
}

void sigint_handler(int sig)
{
	printf(" This is a special signal handler for SIGINT\n");
}

void sigtstp_handler(int sig)
{
	printf(" This is a special signal handler for SIGTSTP\n");
}

void sigquit_handler(int sig)
{
	printf(" This is a special signal handler for SIGQUIT\n");
}


