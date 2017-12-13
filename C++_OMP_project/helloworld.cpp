#include <iostream>
#include <omp.h>

int main(int argc, char** argv)
{
	if(argc < 2 || argc > 3)
	{
		std::cout << "You must enter the number of threads as cl argument" << std::endl;
		exit(1);
	}

	int num_of_threads = atoi(argv[1]);
	omp_set_num_threads(num_of_threads);

	int thread_id, num_threads;

	double start_time = omp_get_wtime();

	#pragma omp parallel private(thread_id)
	{
		thread_id = omp_get_thread_num();
		std::cout << "Thread " << thread_id << " running" << std::endl;

		//useless to ask omp environment for num of threads in this case ;-)
		if(thread_id == 0)
		{
			num_threads = omp_get_num_threads();
			 std::cout << "Number of threads: " << num_threads << std::endl;
		}
	}

	double time_total = omp_get_wtime() - start_time;

	 std::cout << "Runtime of program: " << time_total << std::endl;

	return 0;
}
