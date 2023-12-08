#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int num_pipes = 3;
    int *pipe_fd = malloc(num_pipes * 2 * sizeof(int));

    // Création des trois pipes et stockage de leurs descripteurs dans le tableau
    int i = 0;
    while (i < num_pipes) {
        if (pipe(pipe_fd + (i * 2)) == -1) {
            perror("Error creating pipe");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    // Affichage des descripteurs pour chaque pipe
    i = 0;
    while (i < num_pipes) {
        printf("Pipe %d: Lecture -> %d, Ecriture -> %d\n", i, i * 2, i * 2 + 1);
        i++;
    }

    free(pipe_fd);

    return 0;
}


