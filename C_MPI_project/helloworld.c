#define _BSD_SOURCE
#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
#include <stdlib.h>

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
	fscanf(file, "%s", hostname);
	fclose(file);	

	printf("Rank: %d, Commsize: %d, host: %s\n", rank, commsize, hostname);

	MPI_Finalize();

	return 0;
}
