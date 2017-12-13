#define _BSD_SOURCE
#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
	int rank;
	int commsize;
	char hostname[80];
	FILE *file;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &commsize);

	file = popen("cat /proc/sys/kernel/hostname", "r");
	if(fscanf(file, "%s", hostname) != 1)
		std::cout << "Failed to read host" << std::endl;
	fclose(file);

	std::cout << "Rank: " << rank << ", Commsize: " << commsize << ", host: " << hostname << std::endl;

	MPI_Finalize();

	return 0;
}
