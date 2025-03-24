#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const std::string &type) : Animal(type)
{
    std::cout << "Cat parametrized constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*cat.brain);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &cat)
    {
        Animal::operator=(cat);
        delete this->brain;
        this->brain = new Brain(*cat.brain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return this->brain->getIdea(index);
}