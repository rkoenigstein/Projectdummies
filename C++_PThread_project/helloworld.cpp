#include <iostream>
#include <pthread.h>
#include <stdlib.h>

void *printRank(void *thread_rank)
{
	long thread_id;
	thread_id = (long) thread_rank;
	std::cout << "Thread " << thread_id << " running" << std::endl;
	return NULL;
}

int main(int argc, char* argv[])
{

	if(argc < 2 || argc > 3)
  {
    std::cout << "You must enter the number of threads as cl argument" << std::endl;
    exit(1);
  }

  int num_of_threads = atoi(argv[1]);
  pthread_t threads[num_of_threads];

	int error_code;
	for(long i = 0; i < num_of_threads; i++)
	{
		error_code = pthread_create(&threads[i], NULL, printRank, (void *) i);
		if(error_code)
		{
			std::cout << "Error creating pthread: " << error_code << std::endl;
			exit(-1);
		}
	}

	for(long i = 0; i < num_of_threads; i++)
  {
		error_code = pthread_join(threads[i], NULL);
		if(error_code)
		{
			std::cout << "Error joining pthread: " << error_code << std::endl;
			exit(-1);
		}
  }

	pthread_exit(NULL);

	return 0;
}
