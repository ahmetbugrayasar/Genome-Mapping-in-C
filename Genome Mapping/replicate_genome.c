#include"genome.h"
#include<stdlib.h>

char* replicate_genome(struct Genome genome) {
    if (genome.sequence == NULL || genome.length == 0) {
        return NULL;
    }
    char* copy = malloc((genome.length + 1) * sizeof(char));
    strcpy(copy, genome.sequence);
    return copy;
}
