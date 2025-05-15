#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string id;
public:
    Employee(const string& n = "", const string& i = "") : name(n), id(i) {}

    virtual void getdata() {
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee ID: ";
        cin >> id;
    }

    virtual void putdata() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
    }

    virtual float calculatePay() const = 0;

    virtual ~Employee() {}
};

class SalariedEmployee : public Employee {
private:
    float weeklySalary;
public:
    SalariedEmployee(const string& n = "", const string& i = "", float salary = 0.0)
        : Employee(n, i), weeklySalary(salary) {}

    void getdata() override {
        Employee::getdata();
        cout << "Enter weekly salary: $";
        cin >> weeklySalary;
    }

    void putdata() const override {
        Employee::putdata();
        cout << "Weekly Salary: $" << weeklySalary << endl;
        cout << "Weekly Pay: $" << calculatePay() << endl;
    }

    float calculatePay() const override {
        return weeklySalary;
    }
};

class HourlyEmployee : public Employee {
private:
    float hourlyRate;
    float hoursWorked;
public:
    HourlyEmployee(const string& n = "", const string& i = "",
                  float rate = 0.0, float hours = 0.0)
        : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}

    void getdata() override {
        Employee::getdata();
        cout << "Enter hourly rate: $";
        cin >> hourlyRate;
        cout << "Enter hours worked: ";
        cin >> hoursWorked;
    }

    void putdata() const override {
        Employee::putdata();
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Weekly Pay: $" << calculatePay() << endl;
    }

    float calculatePay() const override {
        if (hoursWorked <= 40)
            return hourlyRate * hoursWorked;
        else
            return (hourlyRate * 40) + (hourlyRate * 1.5 * (hoursWorked - 40));
    }
};

int main() {
    Employee* employees[100];
    int n = 0;
    char choice;

    do {
        cout << "Enter employee type (s-salaried/h-hourly): ";
        cin >> choice;

        if (choice == 's')
            employees[n] = new SalariedEmployee;
        else
            employees[n] = new HourlyEmployee;

        employees[n++]->getdata();

        cout << "Enter another employee (y/n)? ";
        cin >> choice;
    } while (choice == 'y');

    cout << "\nPayroll Information:\n";
    for (int j = 0; j < n; j++) {
        cout << "\nEmployee " << j + 1 << ":\n";
        employees[j]->putdata();
    }

    for (int j = 0; j < n; j++)
        delete employees[j];

    return 0;
}
