#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
    std::cout << "WrongCat parametrized constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &wrongCat)
    {
        WrongAnimal::operator=(wrongCat);
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat says: Meow! Meow!" << std::endl;
}