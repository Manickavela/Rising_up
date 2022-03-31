#include <iostream>
int main()
{
    #pragma omp parallel
    {
        std::cout << "Hello World" << std::endl;
    }
    return 0;
}

//Execute the above with below cmd
//cmd   :   g++ race_condition.cpp -fopenmp
//openMP works at compile time and specifing it will 
//treat the compilation accordingly for openMP

//Above prog demonstrates Race condition w.r.t parallel processing