#include "zoo.h"

void Animal::AskForSleep()
{
    std::cout << name_ << " hotyat spat" << std::endl;
};

void Animal::AskForFood()
{
    std::cout << name_ << " hotyat kushats" << std::endl;
};

int Animal::ChangeState()
{
    return food_state_animal_++;
};

Animal::Animal(int food_state, std::string name) : food_state_animal_(food_state), name_(name) {}

Animal::~Animal() = default;

Animal::Animal(const Animal &other) = default;

Animal::Animal(Animal &&other) = default;

Animal &Animal::operator=(const Animal &other)
{
    food_state_animal_ = other.food_state_animal_;
    name_ = other.name_;
    return *this;
};

Animal &Animal::operator=(Animal &&other)
{
    food_state_animal_ = std::move(other.food_state_animal_);
    name_ = std::move(other.name_);
    return *this;
};

// --------------Жираф---------------

void Giraffe::AskForSleep()
{
    std::cout << name_ << " hotyat spat" << std::endl;
};

void Giraffe::AskForFood()
{
    std::cout << name_ << " hotyat kushats" << std::endl;
};

int Giraffe::ChangeState()
{
    food_state_animal_ += 450;
    return food_state_animal_;
};

Giraffe::Giraffe() : Animal(100, "Giraffe") {};

Giraffe::~Giraffe() = default;

Giraffe::Giraffe(const Giraffe &other) = default;

Giraffe::Giraffe(Giraffe &&other) = default;

Giraffe &Giraffe::operator=(const Giraffe &other)
{
    food_state_animal_ = other.food_state_animal_;
    name_ = other.name_;
    return *this;
}

Giraffe &Giraffe::operator=(Giraffe &&other)
{
    food_state_animal_ = std::move(other.food_state_animal_);
    name_ = std::move(other.name_);
    return *this;
};

// --------------Страус---------------

void Ostrich::AskForSleep()
{
    std::cout << name_ << " hotyat spat" << std::endl;
};

void Ostrich::AskForFood()
{
    std::cout << name_ << " hotyat kushats" << std::endl;
};

int Ostrich::ChangeState()
{
    food_state_animal_ += 150;
    return food_state_animal_;
};

Ostrich::Ostrich() : Animal(5, "Ostrich") {};

Ostrich::~Ostrich() = default;

Ostrich::Ostrich(const Ostrich &other) = default;

Ostrich::Ostrich(Ostrich &&other) = default;

Ostrich &Ostrich::operator=(const Ostrich &other)
{
    food_state_animal_ = other.food_state_animal_;
    name_ = other.name_;
    return *this;
}

Ostrich &Ostrich::operator=(Ostrich &&other)
{
    food_state_animal_ = std::move(other.food_state_animal_);
    name_ = std::move(other.name_);
    return *this;
};

// --------------Бегемот---------------

void Hippo::AskForSleep()
{
    std::cout << name_ << " hotyat spat" << std::endl;
};

void Hippo::AskForFood()
{
    std::cout << name_ << " hotyat kushats" << std::endl;
};

int Hippo::ChangeState()
{
    food_state_animal_ += 750;
    return food_state_animal_;
};

Hippo::Hippo() : Animal(5, "Hippo") {};

Hippo::~Hippo() = default;

Hippo::Hippo(const Hippo &other) = default;

Hippo::Hippo(Hippo &&other) = default;

Hippo &Hippo::operator=(const Hippo &other)
{
    food_state_animal_ = other.food_state_animal_;
    name_ = other.name_;
    return *this;
}

Hippo &Hippo::operator=(Hippo &&other)
{
    food_state_animal_ = std::move(other.food_state_animal_);
    name_ = std::move(other.name_);
    return *this;
};

// --------------Лев---------------

void Lion::AskForSleep()
{
    std::cout << name_ << " hotyat spat" << std::endl;
};

void Lion::AskForFood()
{
    std::cout << name_ << " hotyat kushats" << std::endl;
};

int Lion::ChangeState()
{
    food_state_animal_ += 500;
    return food_state_animal_;
};

Lion::Lion() : Animal(5, "Lion") {};

Lion::~Lion() = default;

Lion::Lion(const Lion &other) = default;

Lion::Lion(Lion &&other) = default;

Lion &Lion::operator=(const Lion &other)
{
    food_state_animal_ = other.food_state_animal_;
    name_ = other.name_;
    return *this;
}

Lion &Lion::operator=(Lion &&other)
{
    food_state_animal_ = std::move(other.food_state_animal_);
    name_ = std::move(other.name_);
    return *this;
};

// --------------Слон---------------

void Elephant::AskForSleep()
{
    std::cout << name_ << " hotyat spat" << std::endl;
};

void Elephant::AskForFood()
{
    std::cout << name_ << " hotyat kushats" << std::endl;
};

int Elephant::ChangeState()
{
    food_state_animal_ += 1500;
    return food_state_animal_;
};

Elephant::Elephant() : Animal(5, "Elephant") {};

Elephant::~Elephant() = default;

Elephant::Elephant(const Elephant &other) = default;

Elephant::Elephant(Elephant &&other) = default;

Elephant &Elephant::operator=(const Elephant &other)
{
    food_state_animal_ = other.food_state_animal_;
    name_ = other.name_;
    return *this;
}

Elephant &Elephant::operator=(Elephant &&other)
{
    food_state_animal_ = std::move(other.food_state_animal_);
    name_ = std::move(other.name_);
    return *this;
};