#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *brain;

public:
    Cat();
    Cat(const std::string &type);
    Cat(const Cat &cat);
    virtual ~Cat();

    Cat &operator=(const Cat &cat);

    virtual void makeSound() const;
    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif