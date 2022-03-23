#include <iostream>
#include <typeinfo> 
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
        T add() 
        {
            //cout<<"Got caracter "<<(typeid(num1) == typeid('a'))<<endl;
            /*if((typeid(num1) == typeid('a')) == 1)
            {
                cout<<"Got caracter "<<(typeid(num1) == typeid('a'))<<endl;
                return strcat(num1,num2);
            }
            */
            return num1 + num2;
        }
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

template <class T = char ,class S = char*>
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
        S add() 
        {
            //cout<<"Got caracter "<<(typeid(num1) == typeid('a'))<<endl;
            /*if((typeid(num1) == typeid('a')) == 1)
            {
                cout<<"Got caracter "<<(typeid(num1) == typeid('a'))<<endl;
                return strcat(num1,num2);
            }
            */
            return ;
        }
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

int main()
{
    Calculation<int> intcalc(2,1);
    Calculation<float> floatcalc(2.5,4.1);
    Calculation<char> charcalc('a','b');        //Bug wihtout the template functoin conditioning

    cout<<"Int Results"<<endl;
    intcalc.displayResult();

    cout<<"\n\nFloat Results"<<endl;
    floatcalc.displayResult();     

    cout<<"\n\nChar Results"<<endl;
    charcalc.displayResult();                   //Bug adds the ASCII values, RECTIFIED!
}