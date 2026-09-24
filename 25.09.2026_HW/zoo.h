#pragma once

#include <string>
#include <iostream>

class Animal
{
public:
    virtual void AskForSleep();
    virtual void AskForFood();
    virtual int ChangeState();

    Animal(int food_state, std::string name);
    virtual ~Animal();
    Animal(const Animal &other);
    Animal(Animal &&other);
    Animal &operator=(const Animal &other);
    Animal &operator=(Animal &&other);

protected:
    int food_state_animal_;
    std::string name_;
};

// --------------Жираф---------------

class Giraffe : public Animal
{
public:
    virtual void AskForSleep() override;
    virtual void AskForFood() override;
    virtual int ChangeState() override;

    Giraffe();
    ~Giraffe();
    Giraffe(const Giraffe &other);
    Giraffe(Giraffe &&other);
    Giraffe &operator=(const Giraffe &other);
    Giraffe &operator=(Giraffe &&other);
};

// --------------Страус---------------

class Ostrich : public Animal
{
public:
    virtual void AskForSleep() override;
    virtual void AskForFood() override;
    virtual int ChangeState() override;

    Ostrich();
    ~Ostrich();
    Ostrich(const Ostrich &other);
    Ostrich(Ostrich &&other);
    Ostrich &operator=(const Ostrich &other);
    Ostrich &operator=(Ostrich &&other);
};

// --------------Бегемот---------------

class Hippo : public Animal
{
public:
    virtual void AskForSleep() override;
    virtual void AskForFood() override;
    virtual int ChangeState() override;

    Hippo();
    ~Hippo();
    Hippo(const Hippo &other);
    Hippo(Hippo &&other);
    Hippo &operator=(const Hippo &other);
    Hippo &operator=(Hippo &&other);
};

// --------------Лев---------------

class Lion : public Animal
{
public:
    virtual void AskForSleep() override;
    virtual void AskForFood() override;
    virtual int ChangeState() override;

    Lion();
    ~Lion();
    Lion(const Lion &other);
    Lion(Lion &&other);
    Lion &operator=(const Lion &other);
    Lion &operator=(Lion &&other);
};

// --------------Слон---------------

class Elephant : public Animal
{
public:
    virtual void AskForSleep() override;
    virtual void AskForFood() override;
    virtual int ChangeState() override;

    Elephant();
    ~Elephant();
    Elephant(const Elephant &other);
    Elephant(Elephant &&other);
    Elephant &operator=(const Elephant &other);
    Elephant &operator=(Elephant &&other);
};