#include <iostream>
#include <omp.h>

using namespace std;

#define ARRAY_SIZE 100000000
#define ARRAY_VALUE 1231

int main()
{
    int *arr = new int[ARRAY_SIZE];
    fill_n(arr, ARRAY_SIZE, ARRAY_VALUE);
    omp_set_num_threads(4);
    #pragma omp parallel for
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        // do some relatively long operation
        arr[i] = arr[i] / arr[i] + arr[i] / 5 - 14;
    }
    return 0;
}

//compile cmd : g++ 3_wihtout_omp_array.cpp -fopenmp
//time exec   : time ./a.out

//comparing the time it took for exec , omp optimization can be realized
