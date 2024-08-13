#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int numProcs = 5;
	pid_t* pid = (pid_t*)malloc(sizeof(pid_t));

	// Fork exactly numProcs times, populating the pid array with the child PID 
	// in the index order of forking
	for (int i = 0; i < numProcs; i++) {
		pid[i] = fork();
		if (pid[i] == 0) {
			printf("Child process %d\n", i);
			exit(0);
		}
	}

	// Wait for em all
	for (int i = 0; i < numProcs; i++) {
		waitpid(pid[i], NULL, 0);
	}

	// Free the pid array!
	free(pid);
	return 0;
}

