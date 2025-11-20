#include <iostream>
#include <vector>
#include <memory>

// Базовый класс
class Detail {
protected:
    Detail() {
        std::cout << "Detail created\n";
    }

    Detail(const Detail&) = default;
    Detail& operator=(const Detail&) = default;

public:
    virtual ~Detail() {
        std::cout << "Detail destroyed\n";
    }

    virtual void print() const {
        std::cout << "This is a Detail\n";
    }

    // Объявляем шаблонную функцию другом
    template<typename T, typename... Args>
    friend std::unique_ptr<T> createDetail(Args&&... args);
};

class Assembly : public Detail {
private:
    std::string name;

protected:
    Assembly(const std::string& n) : name(n) {
        std::cout << "Assembly '" << name << "' created\n";
    }


    Assembly(const Assembly&) = default;
    Assembly& operator=(const Assembly&) = default;

public:
    ~Assembly() override {
        std::cout << "Assembly '" << name << "' destroyed\n";
    }

    void print() const override {
        std::cout << "This is Assembly: " << name << "\n";
    }

    const std::string& getName() const {
        return name;
    }
    template<typename T, typename... Args>
    friend std::unique_ptr<T> createDetail(Args&&... args);
};

template<typename T, typename... Args>
std::unique_ptr<T> createDetail(Args&&... args) {
    //new, так как make_unique не может получить доступ к протектед конструкторам
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
    std::vector<std::unique_ptr<Detail>> storage;

    storage.push_back(createDetail<Detail>());
    storage.push_back(createDetail<Assembly>("Engine"));
    storage.push_back(createDetail<Assembly>("Transmission"));
    storage.push_back(createDetail<Assembly>("Chassis"));

    std::cout << "\nObjects in storage:\n";
    for (const auto& obj : storage) {
        obj->print();
    }

    std::cout << "\nCleaning up...\n";
    // unique_ptr автоматом удалит объекты

    return 0;
}
