#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "--- Normal Animal Test ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- Wrong Animal Test ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound();
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;

    return 0;
}
