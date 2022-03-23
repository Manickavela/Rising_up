#include <iostream>
using namespace std;


// base class
class A {
    public:
      void display() {
          cout<<"Base class content.";
      }
};
// derived class 
class B : public A {};
class C : public B {};


// base class
class Mammal 
{
    public:
        Mammal() 
        {
            cout << "Mammals can give direct birth." << endl;
        }
};

class WingedAnimal 
{
    public:
    WingedAnimal() 
    {
        cout << "Winged animal can flap." << endl;
    }
};

// derived class 
class Bat: public Mammal, public WingedAnimal {};


// base class
class Animal {
   public:
    void info() {
        cout << "I am an animal." << endl;
    }
};
// derived class 
class Dog : public Animal {
   public:
    void bark() {
        cout << "I am a Dog. Woof woof." << endl;
    }
};

// derived class 
class Cat : public Animal {
   public:
    void meow() {
        cout << "I am a Cat. Meow." << endl;
    }
};

int main()
{
    cout<<"Multilevel Inheritence   "<<endl;
    cout<<"======================"<<endl;
    C obj;
    obj.display();
    cout<<"\n\nMulitple  Inheritence    "<<endl;
    cout<<"========================="<<endl;
    Bat b1;
    cout<<"\n\nHierarchical Inheritance "<<endl;
    cout<<"============================ "<<endl;
    // Create object of Dog class
    Dog dog1;
    cout << "Dog Class:" << endl;
    dog1.info();  // Parent Class function
    dog1.bark();

    // Create object of Cat class
    Cat cat1;
    cout << "\nCat Class:" << endl;
    cat1.info();  // Parent Class function
    cat1.meow();
    return 0;
}