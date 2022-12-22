#include"genome.h"
void genome_to_fastq(struct Genome genome, char* description, char* quality) {
    if (genome.sequence == NULL) {
        return;
    }
    char filename[128];
    sprintf(filename, "%s.fastq", description);
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return;
    }
    fprintf(file, "@%s\n%s\n+\n%s\n", description, genome.sequence, quality);
    fclose(file);
}