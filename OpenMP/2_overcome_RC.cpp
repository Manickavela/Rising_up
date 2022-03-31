#include <iostream>
#include <omp.h>
#include <unistd.h>

#define THREAD_NUM 4

using namespace std;

int main()
{
    omp_set_num_threads(THREAD_NUM);
    //sets number of threads which was taken directly from the 
    //enviornment variable in the previous program

    #pragma omp parallel
    {
        usleep(5000 * omp_get_thread_num());
        //to prevent race condition 

        cout<<"Number of available threads : "<<omp_get_num_threads()<<endl;
        cout<<"Current thread number: "<<omp_get_thread_num()<<endl;
        cout<<"Hello Wordk without Race"<<endl;

        
    } 
    return 0;
}

//Compiling the prog must mention openmp explicitly
//cmd  : g++ race_condition.cpp -fopenmp