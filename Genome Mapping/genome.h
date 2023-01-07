
#ifndef GENOME_H
#define GENOME_H
#include<stdio.h>
/// <summary>
/// Basic Genome structure with a Nucleotide sequence and length of the sequence.
/// </summary>
struct Genome {
	char* sequence;
	int length;
};

/// <summary>
/// Initializes a Genome structure with the given sequence.
/// 
/// This function checks the sequence argument to make sure it is not NULL and is null-terminated.
/// If either of these checks fails, the function exits with an error message.
/// Otherwise, it initializes the sequence and length fields of the Genome structure with the given values.
/// </summary>
/// 
/// <param name="genome">Pointer to a Genome structure to be initialized.</param>
/// <param name="sequence">Null-terminated string containing the genome's sequence.</param>
void initialize_genome(struct Genome* genome, char* sequence);

/// <summary>
/// Prints the sequence and length of a Genome structure to the console.
/// 
/// This function prints the sequence and length of the given Genome structure to the console,
/// using the following format: "Sequence: {sequence}\nLength: {length}\n".
/// </summary>
/// 
/// <param name="genome">Genome structure to be printed.</param>
void print_genome(struct Genome genome);

/// <summary>
/// Counts the number of occurrences of a given nucleotide in a Genome structure.
/// 
/// This function counts the number of occurrences of the given nucleotide in the sequence field of the given Genome structure.
/// The nucleotide is specified as a single character, and can be 'A', 'C', 'G', or 'T'.
/// If the nucleotide is not one of these four characters, the function returns 0.
/// </summary>
/// 
/// <param name="genome">Genome structure to be searched.</param>
/// <param name="nucleotide">Nucleotide to be counted ('A', 'C', 'G', or 'T').</param>
/// 
/// <returns>
/// Number of occurrences of the given nucleotide in the genome's sequence.
/// </returns>
int count_nucleotide(struct Genome genome, char nucleotide);

/// <summary>
/// Replicates a Genome structure by creating a copy of its sequence.
/// 
/// This function creates a copy of the sequence field of the given Genome structure,
/// allocates memory for the copy using malloc, and returns a pointer to the copy.
/// The caller is responsible for freeing the allocated memory when it is no longer needed.
/// 
/// If the given Genome structure has a NULL sequence or a length of 0, the function returns NULL.
/// </summary>
/// 
/// <param name="genome">Genome structure to be replicated.</param>
/// 
/// <returns>
/// Pointer to a copy of the genome's sequence, or NULL if the genome has a NULL sequence or a length of 0.
/// </returns>
char* replicate_genome(struct Genome genome);

/// <summary>
/// Converts a Genome structure to a FastQ record and writes it to a file.
/// 
/// This function creates a FastQ record for the given Genome structure by
/// concatenating the fields of the record in the following format:
/// 
/// "@{description}\n{sequence}\n+\n{quality}\n"
/// 
/// The description field is specified as a null-terminated string, and the quality field is specified as an array of characters.
/// Both the description and quality fields should be no longer than the length of the genome's sequence.
/// 
/// The function writes the FastQ record to a file with a name based on the `description` parameter.
/// The file name is created by concatenating the `description` string with the `".fastq"` string.
/// If the file cannot be opened for writing, an error message is printed to `stderr`.
/// 
/// If the given Genome structure has a NULL sequence, the function does nothing.
/// </summary>
/// 
/// <param name="genome">Genome structure to be converted.</param>
/// <param name="description">Null-terminated string containing the FastQ record's description field.</param>
/// <param name="quality">Array of characters containing the FastQ record's quality field.</param>
void genome_to_fastq(struct Genome genome, char* description, char* quality);

/*
 * <summary>
 * Reads a genome from a FASTQ file.
 *
 * This function reads a FASTQ file and stores the data in a Genome structure.
 * The FASTQ file is expected to have the following format:
 *
 * "@{description}\n{sequence}\n+\n{quality}\n"
 *
 * The function reads the first, second, and fourth lines of the file and stores the data as follows:
 * - The first line (description) is ignored.
 * - The second line (sequence) is stored as the Genome structure's sequence field. The newline character is removed.
 * - The fourth line (quality) is ignored.
 *
 * If the file cannot be opened for reading, an error message is printed to `stderr`.
 * </summary>
 *
 * @param filename The name of the FASTQ file to read.
 * @return The genome read from the file. If an error occurs, the genome's sequence field is set to NULL.
 */
struct Genome read_genome_from_fastq(char* filename);
#endif