#include <iostream>
#include <string>

using namespace std;

class Animal
{
    public :
        string colour;
        virtual void reproduce()
        {
            cout<<"Animal can reproduce"<<endl;
        }
        void eat()
        {
            cout<<"Animal can eat"<<endl;
        }
        void sleep()
        {
            cout<<"Animal can sleep"<<endl;
        }
        void setColour(string clr)
        {
            colour = clr;
        }
        string getColour()
        {
            return colour;
        }

    protected :
    string type;

};

class Dog : public Animal
{
    public :
        void reproduce()
        {
            cout<<"Dog can reproduce"<<endl;
        }
        void eat()
        {
            cout<<"Dog can eat"<<endl;
        }
        void setType(string tp)
        {
            type = tp;
        }
        void displayInfo(string c)
        {
            cout<<"I am a "<<type<<endl;
            cout<<"Colour : "<<c<<endl;
        }
        void bark()
        {
            cout<<"Dog can Bark"<<endl;
        }
};

int main()
{
    Dog dog;

    dog.eat();
    dog.sleep();
    dog.setColour("Brown");

    dog.bark();
    dog.setType("Mammal");

    dog.displayInfo(dog.getColour());

    //Virtual Function
    cout<<"\n\nVirtual Functions"<<endl;
    cout<<"==================="<<endl;
    Animal *pani;
    Dog *pdog;
    pani = &dog;
    pdog = &dog;

    pani->eat();       //early binding
    pdog->eat();
    pani->reproduce(); //late binding
    pdog->reproduce();
    //pani->displayInfo();  ERROR
    pdog->displayInfo("White");
    
    return 0;
}