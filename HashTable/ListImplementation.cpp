#include <iostream>
#include <list>

using namespace std;
int main()
{
    list<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    myList.push_front(100);

    list<int>::iterator it = myList.begin();
    advance(it, 2);
    myList.insert(it, 69);

    myList.pop_back();
    myList.pop_front();

    cout << "Elements for the list: ";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}