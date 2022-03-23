#include <iostream>
using namespace std;

template <class T, class U, class V = char>
class ClassTemplate {
   private:
    T var1;
    U var2;
    V var3;

   public:
    ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}  // constructor

    void printVar() {
        cout<<"var1 = "<<var1<<endl;
        cout<<"var2 = "<<var2<<endl;
        cout<<"var2 = "<<var2<<endl;
        cout<<"var3 = "<<var3<<endl;
    }
};

int main() 
{

    ClassTemplate<int,double> obj1(2, 7.7, 'a');
    cout<<"obj1 : \n"<<endl;
    obj1.printVar();

    ClassTemplate<double,char,bool> obj2(2.14, 'a', true);
    cout<<"\n\nobj2 : "<<endl;
    obj2.printVar();

    return 0;
}