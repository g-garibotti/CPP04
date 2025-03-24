#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *brain;

public:
    Dog();
    Dog(const std::string &type);
    Dog(const Dog &dog);
    virtual ~Dog();

    Dog &operator=(const Dog &dog);

    virtual void makeSound() const;
    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif