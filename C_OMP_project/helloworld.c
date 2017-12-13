#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv)
{
	if(argc < 2 || argc > 3)
	{
		printf("You must enter the number of threads as cl argument\n");
		exit(1);
	}

	int num_of_threads = atoi(argv[1]);
	omp_set_num_threads(num_of_threads);

	int thread_id, num_threads;

	double start_time = omp_get_wtime();

	#pragma omp parallel private(thread_id)
	{
		thread_id = omp_get_thread_num();
		printf("Thread %d running\n", thread_id);

		//useless to ask omp environment for num of threads in this case ;-)
		if(thread_id == 0)
		{
			num_threads = omp_get_num_threads();
			printf("Number of threads: %d\n", num_threads);
		}
	}

	double time_total = omp_get_wtime() - start_time;

	printf("Runtime of program: %f\n", time_total);

	return 0;
}
