#include <iostream>
using namespace std;

class Animal {
public:
  string species;
  string name;
  int age;
};

void increamentAge(Animal &animal_ref) {
  cout << &animal_ref << endl;
  animal_ref.age += 1;
}

int main() {
  int max_size = 4;
  string animal_names[] = {"lex", "Shadow", "Jazz", "Lesy"};
  Animal *animals = new Animal[max_size];
  for (int i = 0; i < max_size; i++) {
    animals[i].age = i;
    if (i % 2 == 0) {
      animals[i].species = "Dog";
    } else {
      animals[i].species = "Cat";
    }
    animals[i].name = animal_names[i];
  }

  for (int i = 0; i < max_size; i++) {
    cout << "NAME: " << animals[i].name << endl;
    cout << "SPECIES: " << animals[i].species << endl;
    cout << "AGE: " << animals[i].age << endl;

    cout << &(animals[i]) << endl;
    increamentAge(animals[i]);

    cout << "AGE: " << animals[i].age << endl;

    cout << endl;
  }
}