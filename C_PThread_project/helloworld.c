#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *printRank(void *thread_rank)
{
	long thread_id;
	thread_id = (long) thread_rank;
	printf("Thread %ld running\n", thread_id);
	return NULL;
}

int main(int argc, char* argv[])
{

	if(argc < 2 || argc > 3)
  {
    printf("You must enter the number of threads as cl argument\n");
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
			printf("Error creating pthread: %d\n", error_code);
			exit(-1);
		}
	}

	for(long i = 0; i < num_of_threads; i++)
  {
		error_code = pthread_join(threads[i], NULL);
		if(error_code)
		{
			printf("Error joining pthread: %d\n", error_code);
			exit(-1);
		}
  }

	pthread_exit(NULL);

	return 0;
}
