#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 200
#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[]) {
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];
	int fd[2];
	char *inputFile = argv[1];
	char *outputFile = argv[2];
	pid_t pid;

	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}
	/* fork a child process */
	pid = fork();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	if (pid > 0) { /* parent process */
		/* close the unused end of the pipe */
		close(fd[READ_END]);
		int input = open(inputFile, O_RDONLY);
		ssize_t num_bytes = read(input, read_msg, sizeof(read_msg));
		/* write to the pipe */
		write(fd[WRITE_END], read_msg, num_bytes);
		close(fd[WRITE_END]);
	}
	else { /* child process */
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);
		ssize_t num_bytes_child = read(fd[READ_END], write_msg, sizeof(write_msg));
		int output = open(outputFile, O_CREAT | O_WRONLY);
		write(output, write_msg, num_bytes_child);
	}

	return 0;
}
