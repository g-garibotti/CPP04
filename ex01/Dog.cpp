#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const std::string &type) : Animal(type)
{
    std::cout << "Dog parametrized constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*dog.brain); // Deep copy
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &dog)
    {
        Animal::operator=(dog);
        delete this->brain;
        this->brain = new Brain(*dog.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return this->brain->getIdea(index);
}