#include"genome.h"
struct Genome read_genome_from_fastq(char* filename)
{
    struct Genome genome;
    genome.sequence = NULL;
    genome.length = 0;

    FILE* file;
    errno_t error = fopen_s(&file, filename, "r");
    if (error != 0) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return genome;
    }

    char line[1024];
    int line_number = 0;
    while (fgets(line, 1024, file)) {
        line_number++;
        if (line_number == 1) {
            // First line: description
            continue;
        }
        if (line_number == 2) {
            // Second line: sequence
            genome.length = strlen(line) - 1;  // -1 to remove the newline character
            genome.sequence = (char*)malloc(genome.length + 1);  // +1 for the null terminator
            strncpy_s(genome.sequence, genome.length + 1, line, genome.length);
        }
        if (line_number == 4) {
            // Fourth line: quality scores
            break;
        }
    }

    fclose(file);
    return genome;
}