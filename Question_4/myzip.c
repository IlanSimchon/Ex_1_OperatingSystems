#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Declare two pipes
    int pipe1[2];
    int pipe2[2];

    // fdarry THIS ARRARY DOES NOT EXIST
    // fd[0] = STDIN
    // fd[1] = STDOUT
    // fd[2] = STDERR
    // fd[3] = pipefdone[0];
    // fd[4] = pipefdone[1];
    // fd[5] = pipefdtwo[0];
    // fd[6] = pipefdtwo[1];

    // Check if pipes are created successfully
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        printf("An error has occurred");
        return 1;
    }

    pid_t child_pid;

    // First child process: tar
    child_pid = fork();
    if (child_pid == -1) {
        printf("Error occurred during fork");
        return 1;
    } else if (child_pid == 0) {
        // Close unnecessary ends of the pipes
        close(pipe1[0]);
        dup2(pipe1[1], 1); // Redirect stdout to pipe1
        close(pipe1[1]);
        close(0); // Close stdin
        close(pipe2[0]);
        close(pipe2[1]);
        // Execute 'tar' command with arguments
        execlp("tar", "tar", "cf", "-", argv[1], NULL);
        perror("exec tar"); // Print error if execlp fails
        return 1;
    }

// Second child process: gzip
    child_pid = fork();
    if (child_pid == -1) {
        printf("Error occurred during fork");
        return 1;
    } else if (child_pid == 0) {
        close(pipe1[1]);
        dup2(pipe1[0], 0); // Redirect stdin to pipe1
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);
        // Execute 'gzip' command with arguments
        execlp("gzip", "gzip", "-c", "-", NULL);  // Use -cf to force compression and write to the file
        perror("exec gzip");
        return 1;
    }

    // Third child process: gpg
    child_pid = fork();
    if (child_pid == -1) {
        printf("Error occurred during fork");
        return 1;
    } else if (child_pid == 0) {
        close(pipe2[1]);
        dup2(pipe2[0], 0); // Redirect stdin to pipe2
        close(pipe2[0]);
        close(pipe1[0]);
        close(pipe1[1]);
        // Execute 'gpg' command with arguments
        execlp("gpg", "gpg", "--symmetric", "--passphrase", argv[2], "-o", "compressed.gpg", "-", NULL);
        perror("exec gpg");
        return 1;
    }

    // Close unused ends of the pipes in the parent process
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);


    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Compression completed. Output saved to 'compressed.gpg'\n");
    return 0;
}
