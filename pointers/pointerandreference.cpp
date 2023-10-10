// Pointer: variable that holds address of another variable
/* reference : it is a alias that is another name to exiting variable,
               it can be thought as a constant pointer that cannot be changed
               i.e. it cannot change the variable it refers to once intiatized to a address*/
#include <iostream>
using namespace std;
int main(){
    // variable ptr points to address of x,
    // i.e it store the address of variable x as value in another address.
    // you can see the address by simply printing it.
    // to see value use * operator.
    // can be NULL.
    int x=10;
    int *ptr=&x;
    cout<<"Pointer"<<endl;
    cout<<"Deferencing pointer: "<<*ptr<<endl;
    cout<<"Address of pointer: "<<&ptr<<endl;
    cout<<"Address stored by pointer: "<<ptr<<endl;
    cout<<"Address of variable x: "<<&x<<endl;
    *ptr=16;
    cout<<"Changing value of x using Deferencing: "<<x<<endl;
    cout<<endl;
    cout<<"Reference"<<endl;
    
    int a=3;
    // variable b refers to a 
    // i.e. b has same address as variable a , same thing differnt name.
    // to see Address use & operator
    //connot be NULL
    int &b=a;
    cout<<"value of variable a: "<<a<<endl;
    cout<<"Address of variable a: "<<&a<<endl;
    cout<<"Address of variable b: "<<&b<<endl;
    cout<<"Changing value of b=4"<<endl;
    b=4;
    cout<<"value of variable b: "<<b<<endl;
    cout<<"value of variable a: "<<b<<endl;

}
