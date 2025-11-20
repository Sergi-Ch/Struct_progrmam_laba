#include <iostream>
#include <stdexcept>

using namespace std;


class ProgramError {
public:
    virtual ~ProgramError() = default;
    virtual void print() const = 0;
};

class InsufficientPrivileges : public ProgramError {
public:
    void print() const override {
        std::cout << "Error: Insufficient privileges\n";
    }
};

class ConversionError : public ProgramError {
public:
    void print() const override {
        std::cout << "Error: Conversion error\n";
    }
};

class ValueConversionImpossible : public ProgramError {
public:
    void print() const override {
        std::cout << "Error: Value conversion impossible\n";
    }
};

class InterfaceCastImpossible : public ProgramError {
public:
    void print() const override {
        std::cout << "Error: Interface cast impossible\n";
    }
};

template <typename T>
class PointerArray {
    T** arr;
    size_t n;
public:
    PointerArray(size_t size) : n(size) {
        arr = new T * [n];
        for (size_t i = 0; i < n; ++i)
            arr[i] = nullptr;
    }

    ~PointerArray() {
        for (size_t i = 0; i < n; ++i)
            delete arr[i];
        delete[] arr;
    }

    T*& operator[](size_t i) {
        if (i >= n)
            throw out_of_range("Index out of range");
        return arr[i];
    }
};

// Доп. задание 4
void test_underflow() {
    throw underflow_error("Underflow occurred");
}


int main() {
    cout << "Creating array of ProgramError pointers (size = 4)\n";
    PointerArray<ProgramError> arr(4);

    cout << "Storing different error objects...\n";
    arr[0] = new InsufficientPrivileges();
    arr[1] = new ConversionError();
    arr[2] = new ValueConversionImpossible();
    arr[3] = new InterfaceCastImpossible();

    cout << "Stored objects:\n";
    for (size_t i = 0; i < 4; ++i) {
        cout << "  [" << i << "] ";
        arr[i]->print();
    }


     //cout << "\nTrying to access arr[10]...\n";
     //arr[10] = new ConversionError(); 

   cout << "\n Handling underflow_error (task 4) \n";
    try {
        test_underflow();
    }
    catch (const underflow_error& e) {
        cout << "Caught underflow_error: " << e.what() << endl;
    }

    cout << "\nProgram finished successfully \n";
    return 0;
}