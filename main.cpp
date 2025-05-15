#include<iostream>
#include<string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {
    }

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }
};

int main() {
    Person person("John Doe", 25);
    person.displayInfo();

    person.setName("Jane Doe");
    person.setAge(30);
    person.displayInfo();

    return 0;
}
