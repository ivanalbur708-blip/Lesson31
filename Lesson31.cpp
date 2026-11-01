#include <iostream>

class Animal {
protected:
    std::string name;
public:
    Animal(std::string name) :name(name) {}
    void setName(std::string newName) {
        name = newName;
    }
    std::string getName() const {
        return name;
    }
    virtual void EatFood(std::string food) const = 0;
};

class Monkey :public Animal {
public:
    Monkey(std::string name) : Animal(name) {}
    void EatFood(std::string food) const {
        std::cout << "Monkey " << name << " eats " << food << '\n';
    }
    void StealMoneyFromTourists() {
        std::cout << "Stealing money...\n";
    }
};

class Lion :public Animal {
public:
    Lion(std::string name) :Animal(name) {}
    void EatFood(std::string food) const {
        std::cout << "Lion " << name << " eats " << food << '\n';
    }
};

class ZooWorker {
public:
    void FeedAnimal(const Animal& animal) {
        std::string food = "";

        std::string type = typeid(animal).name();

        if (type == typeid(Monkey).name()) {
            food = "banana";
        }
        else if (type == typeid(Lion).name()) {
            food = "meat";
        }

        animal.EatFood(food);
    }
};

int main()
{
    //int number = static_cast<int>(15.65);

    //int* number = new int(10);

    //double* d = static_cast<double*>(number);

    //delete number;

    Lion lion("Anton");
    Animal& animal = lion;
    ////animal.set

    //Animal& animalNotConst = const_cast<Animal&>(animal);

    //animalNotConst.setName("Oleg");

    //std::cout << lion.getName() << '\n';

    try {
        Monkey& monkey = reinterpret_cast<Monkey&>(animal);
        monkey.StealMoneyFromTourists();
    }
    catch (const std::bad_cast& e) {
        std::cout << e.what() << '\n';
    }

    //Animal* animal = new Lion("Anton");


    //Monkey* monkeyPtr = reinterpret_cast<Monkey*>(animal);

    //if (monkeyPtr)
    //{
    //    monkeyPtr->StealMoneyFromTourists();
    //}

    ////std::cout << typeid(*animal).name() << '\n';

    //delete animal;
}