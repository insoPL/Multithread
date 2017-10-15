# -*- coding: utf-8 -*-
import subprocess
import time
import tools


overall_thread_number = 5
overall_calculation_number = 30
calculation_tick = 5000000

matrix = tools.make_matrix(overall_thread_number, overall_calculation_number)

for foo in range(1,overall_calculation_number+1):
    amount_of_calculation = calculation_tick*foo
    for amount_of_threads in range(1,overall_thread_number+1):
        amount_of_calculation_per_thread = int(amount_of_calculation/amount_of_threads)

        start = time.time()
        value = subprocess.call("Multithread.exe {} {}".format(amount_of_threads, amount_of_calculation_per_thread))
        end = time.time()

        matrix[int(amount_of_calculation / calculation_tick) - 1][amount_of_threads - 1] = end - start
        print("Program Multithread.exe started {} threads with {} calculation each. Returned value {} within {} seconds".format(amount_of_threads, amount_of_calculation_per_thread, value, end - start))
tools.save_to_file(matrix)
