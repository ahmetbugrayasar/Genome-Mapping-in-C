#include"genome.h"
#include<stdlib.h>

void initialize_genome(struct Genome* genome, char* sequence) {
    if (sequence == NULL) {
        fprintf(stderr, "Error: NULL sequence\n");
        exit(1);
    }
    if (sequence[strlen(sequence)] != '\0') {
        fprintf(stderr, "Error: non-null-terminated sequence\n");
        exit(1);
    }
    genome->sequence = sequence;
    genome->length = strlen(sequence);
}
