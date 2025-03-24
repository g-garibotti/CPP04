#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const std::string &type);
    Dog(const Dog &dog);
    virtual ~Dog();

    Dog &operator=(const Dog &dog);

    virtual void makeSound() const;
};

#endif