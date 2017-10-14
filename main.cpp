#include <iostream>
#include <queue>
#include <random>
#include <future>

int amount_of_threads;
int amount_of_calculations;

using namespace std;

int thread_function(int thread_number)
{
    mt19937 generator ( time( NULL ) + thread_number*100);
    // using thread_number as additional source of entropy

    uniform_real_distribution<> distribution(-1,1);

    int inside_circle=0;
    for(int foo = 0 ; foo < amount_of_calculations; foo++)
    {
        long double x = distribution(generator);
        long double y = distribution(generator);

        long double r = sqrt(x*x+y*y);
        if(r<=1)
        {
            inside_circle++;
        }
    }
    return inside_circle;
}


int main(int argc, char **argv)
{
    if(argc==1){
        amount_of_threads = 2;
        amount_of_calculations = 200000;
    }else{
        amount_of_threads = atoi(argv[1]);
        amount_of_calculations = atoi(argv[2]);
    }

    //Calculating PI using monte carlo method
    queue<future<int>> thread_list;

    for (int foo = 0; foo < amount_of_threads; foo++)
    {
        thread_list.push( async(launch::async,thread_function, foo));
    }

    int inside_circle = 0;
    while(!thread_list.empty())
    {
        inside_circle += thread_list.front().get();
        thread_list.pop();
    }
    double average = inside_circle/amount_of_threads;

    return average/amount_of_calculations*4.0*100000;
}
