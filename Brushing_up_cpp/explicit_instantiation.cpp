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

//template class Calculation<int>;
extern template class Calculation<float>; 

int main()
{

    Calculation<int> intcalc(2,3);
    Calculation<float> floatcalc(2.5,4.1);
    Calculation<char> charcalc('a','b');

    cout<<"Int Results"<<endl;
    intcalc.displayResult();

    cout<<"\n\nFloat Results"<<endl;
    floatcalc.displayResult();
    //The above call throws the error , as it is yet to defined with explicit call on Float type
    
    cout<<"\n\nString Results"<<endl;
    charcalc.displayResult();
    
   return 0;
}



/*
template <class T>
class Calculation<char>
{
    private:
        char *a,*b;
    public : 
        Calculation()
        {
            a = "ab";
            b = "cd";
        }
        char *add()
        {
            return strcat(a,b);
        }
        void displayResult()
        {
            cout << "Strings: " << a << " and " << b << "." << endl;
            cout << a << " + " << b << " = " << add() << endl;
            
        }

};
*/
