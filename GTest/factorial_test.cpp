#include <iostream>
#include <gtest/gtest.h>

using namespace std;

double Factorial(const double num)
{
    if( num < 0)
        return -1;
    double factorial = 1.0;
    for(int i = 1; i <= num ;i++)
    {
        factorial = factorial*i;
    }
    cout<<"Factorial : "<<factorial<<endl;
    return factorial;
}

TEST(FactorialTest, PositiveNos) { 
    ASSERT_EQ(120.0, Factorial(5.0));
    ASSERT_EQ(120.0, Factorial(5.0));
}
 
TEST(FactorialTest, NegativeNos) {
    ASSERT_EQ(1.0, Factorial(-15.0));
    ASSERT_EQ(-1.0, Factorial(-0.2));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//Compiling and running 
//cmake CMakeLists.txt
//make
//./runTests