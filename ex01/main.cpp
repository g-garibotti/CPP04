#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ANIMAL_COUNT 4

void testDeepCopy()
{
    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog *originalDog = new Dog();
    originalDog->setIdea(0, "I want to chase the ball!");
    originalDog->setIdea(1, "I'm hungry!");
    Dog *copyDog = new Dog(*originalDog);
    std::cout << std::endl;

    std::cout << "Original dog idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Copy dog idea 0: " << copyDog->getIdea(0) << std::endl;
    copyDog->setIdea(0, "I want to sleep!");
    std::cout << "After changing copy, original dog idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "After changing copy, copy dog idea 0: " << copyDog->getIdea(0) << std::endl;
    std::cout << std::endl;
    
    delete originalDog;
    delete copyDog;
}

int main()
{
    Animal *animals[ANIMAL_COUNT];
    for (int i = 0; i < ANIMAL_COUNT / 2; i++)
        animals[i] = new Dog();
    for (int i = ANIMAL_COUNT / 2; i < ANIMAL_COUNT; i++)
        animals[i] = new Cat();
    std::cout << "\n--- Animal Array Sounds ---" << std::endl;
    for (int i = 0; i < ANIMAL_COUNT; i++)
        animals[i]->makeSound();
    
    std::cout << "\n--- Deleting Animal Array ---" << std::endl;
    for (int i = 0; i < ANIMAL_COUNT; i++)
        delete animals[i];
    
    std::cout << "\n--- Brain Test ---" << std::endl;
    Dog *dog = new Dog();
    dog->setIdea(0, "I want the baballe!");
    
    Cat *cat = new Cat();
    cat->setIdea(0, "I want to sleep all day long");
    std::cout << std::endl;
    std::cout << "Dog's idea: " << dog->getIdea(0) << std::endl;
    std::cout << "Cat's idea: " << cat->getIdea(0) << std::endl;
    std::cout << std::endl;
    delete dog;
    delete cat;
    
    testDeepCopy();
    
    return 0;
}