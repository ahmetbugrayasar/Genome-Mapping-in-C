#include"genome.h"
int count_nucleotide(struct Genome genome, char nucleotide) {
	int count = 0;

	for (int i = 0; i < genome.length; i++)
	{
		if (genome.sequence[i] == nucleotide)
		{
			count++;
		}
	}

	return count;
}