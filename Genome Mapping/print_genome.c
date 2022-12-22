#include"genome.h"

void print_genome(struct Genome genome)
{
	printf("Genome Sequence: %s\n", genome.sequence);
	printf("Genome Length: %d\n", genome.length);
}