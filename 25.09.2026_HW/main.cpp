#include <iostream>

#include "zoo.h"

int main()
{
    Animal all_zoo(20, "All");
    all_zoo.AskForSleep();
    all_zoo.AskForFood();
    std::cout << all_zoo.ChangeState() << std::endl;
    std::cout << all_zoo.ChangeState() << std::endl;
    std::cout << "-------------------" << std::endl;

    Giraffe girafe_1;
    girafe_1.AskForSleep();
    girafe_1.AskForFood();
    std::cout << girafe_1.ChangeState() << std::endl;
    std::cout << girafe_1.ChangeState() << std::endl;
    std::cout << "-------------------" << std::endl;

    Ostrich ostrich_1;
    ostrich_1.AskForSleep();
    ostrich_1.AskForFood();
    std::cout << ostrich_1.ChangeState() << std::endl;
    std::cout << ostrich_1.ChangeState() << std::endl;
    std::cout << "-------------------" << std::endl;

    Hippo hippo_1;
    hippo_1.AskForSleep();
    hippo_1.AskForFood();
    std::cout << hippo_1.ChangeState() << std::endl;
    std::cout << hippo_1.ChangeState() << std::endl;
    std::cout << "-------------------" << std::endl;

    Lion lion_1;
    lion_1.AskForSleep();
    lion_1.AskForFood();
    std::cout << lion_1.ChangeState() << std::endl;
    std::cout << lion_1.ChangeState() << std::endl;
    std::cout << "-------------------" << std::endl;

    Elephant elephant_1;
    elephant_1.AskForSleep();
    elephant_1.AskForFood();
    std::cout << elephant_1.ChangeState() << std::endl;
    std::cout << elephant_1.ChangeState() << std::endl;
    std::cout << "-------------------" << std::endl;

    return 0;
}