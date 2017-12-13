As MPI (Message Passing Interface) is a standard for programming distributed memory systems, the actual implementation may vary from vendor to vendor of HPC systems. It is also possible for developing/testing purposes to run MPI on say a laptop (e.g. MPICH implementation). To run a MPI programm, usually the command 'mpirun -np 4 helloworld' has to be executed. The parameter '-np' is followed by the amount of processors used for running the program.  