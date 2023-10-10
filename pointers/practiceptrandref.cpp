#include<iostream>
using namespace std;

// Pass by reference
void refMethod(int &value2){
    cout<<endl;
    cout<<"Pass by reference"<<endl;
    value2=value2-10;
    cout<<"Address of value2: "<<&value2<<endl;
    cout<<"Value of value2: "<<value2<<endl;
}

// Pass by pointer
void ptrMethod(int *value3){
    cout<<endl;
    cout<<"Pass by pointer"<<endl;
    *value3=*value3-10;
    cout<<"Address of value3: "<<&value3<<endl;
    cout<<"Address stored by value3: "<<value3<<endl;
    cout<<"Value of value3: "<<*value3<<endl;
}

// Pass by Value
void normalMethod(int value4){ //Parameters
    cout<<endl;
    cout<<"Pass by Value"<<endl;
    value4=value4-10;
    cout<<"Address of value4: "<<&value4<<endl;
    cout<<"Value of value4: "<<value4<<endl;
}

int main()
{
    int value1=100;
    cout<<"Address of value1: "<<&value1<<endl;
    cout<<"Value of value1: "<<value1<<endl;
    
    // Arguments
    refMethod(value1);
    ptrMethod(&value1);
    normalMethod(value1);
    return 0;
}
