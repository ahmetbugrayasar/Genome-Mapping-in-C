#include"genome.h"
void genome_to_fastq(struct Genome genome, char* description, char* quality) {
    if (genome.sequence == NULL) {
        return;
    }
    char filename[128];
    sprintf_s(filename, 128, "%s.fastq", description);
    FILE* file;
    errno_t error = fopen_s(&file, filename, "w");
    if (error != 0) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return;
    }
    fprintf(file, "@%s\n%s\n+\n%s\n", description, genome.sequence, quality);
    fclose(file);
} 