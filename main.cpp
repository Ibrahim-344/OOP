#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
using namespace std;
template<typename T>
class DataContainer {
    vector<T> data;

public:
    void add(T item) { data.push_back(item); }

    T get(size_t index) {
        if (index >= data.size()) throw out_of_range("Index out of bounds");
        return data[index];
    }
};

int main() {
    try {
        DataContainer<int> container;
        container.add(42);

        auto printer = [](const auto &value) {
            cout << "Value: " << value << endl;
        };

        shared_ptr<int> ptr = make_shared<int>(100);
        printer(*ptr);
        printer(container.get(0));

        // This will throw an exception
        container.get(1);
    } catch (const exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}
