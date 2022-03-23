#include <iostream>
#include <cstring>

using namespace std;


//template class
template <class T>
class Calculation
{
    private : 
        T num1,num2;
    public :
        Calculation()
        {
            num1 = 1;
            num2 = 2;
        }
        Calculation(T n1,T n2)
        {
            num1 = n1;
            num2 = n2;
        }
        T add() { return num1 + num2; }
        T subtract() { return num1 - num2;}
        T multiply() {return num1 * num2;}

        void displayResult()
        {
            cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
            cout << num1 << " + " << num2 << " = " << add() << endl;
            cout << num1 << " - " << num2 << " = " << subtract() << endl;
            cout << num1 << " * " << num2 << " = " << multiply() << endl;   
        }
};

extern template class Calculation<int>; 

int main()
{

    Calculation<int> intcalc();
    Calculation<int>().displayResult();
    //Calculation<float> floatcalc(2.5,4.1);

    //cout<<"Int Results"<<endl;
    //intcalc.displayResult();

    //cout<<"\n\nFloat Results"<<endl;
    //floatcalc.displayResult();
    
   return 0;
}