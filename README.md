# Multithread
Program written to test capabilitis of c++11 threading.
It calcuate approximation of PI using Monte Carlo algorithm. More calculations improve accuracy.

# Arguments
Program needs to by run with 2 arguments. 
First is total number of threads that will make calculations. 
Secound is number of calculation that will be made on each thread

# Calculation distribution and program speed
I written simple Python script to mesure how much time program needs to perform calculations with diffrent amoumnt of threads and number of calculations.

```python
# -*- coding: utf-8 -*-
import subprocess
import time

overall_thread_number = 5
overall_calculation_number = 30
calculation_tick = 50000000

Matrix = [[0 for x in range(overall_thread_number)] for y in range(overall_calculation_number)]

for foo in range(1,overall_calculation_number+1).__reversed__():
    amount_of_calculation = calculation_tick*foo
    for amount_of_threads in range(1,overall_thread_number+1):
        amount_of_calculation_per_thread = int(amount_of_calculation/amount_of_threads)
        start = time.time()
        value = subprocess.call("Multithread.exe {} {}".format(amount_of_threads, amount_of_calculation_per_thread))
        end = time.time()
        
        Matrix[int(amount_of_calculation/calculation_tick)-1][amount_of_threads-1] = end-start
        print("Program Multithread.exe started {} threads with {} calculation each. Returned value {} within {} seconds".format(amount_of_threads, amount_of_calculation_per_thread, value, end - start))

file = open("data{}.txt".format(calculation_tick), 'w')
for foo in Matrix:
    for bar in foo:
        file.write("{} ".format(bar))
    file.write("\n")
```

https://plot.ly/~InsoPL/8/
