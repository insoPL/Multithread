# Multithread
Program written to test capabilitis of c++11 thread handling.
It calcuate approximation of PI using Monte Carlo algorithm. More calculations improve accuracy.

# Arguments
Program needs to by run with 2 arguments. 
First is total number of threads that will make calculations. 
Secound is number of calculation that will be made on each thread

# Calculation distribution and program speed
TSimple Python script (Multithread_test.py) mesures time which program needs to perform calculations with diffrent amoumnt of threads and number of calculations. As expected distributing calculation to more threads greatly enhanced performance of program (tests were performed on 4 core porcessor). I exported data and build 3d graph:
https://plot.ly/~InsoPL/8.embed
