#include"genome.h"

int main(void)
{
	struct Genome genome1;

	initialize_genome(&genome1, "ATGATGC");
	print_genome(genome1);

	printf("T count: &d\n", count_nucleotide(genome1, 'T'));

	char* copy = replicate_genome(genome1);

	printf("Copy: %s\n", copy);

	free(copy);

	char* fastq = genome_to_fastq(genome1, "Genome_1", "IIIIIIII");
	printf("FastQ: %s\n", fastq);
}