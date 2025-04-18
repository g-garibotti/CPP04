#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const std::string &type);
    WrongCat(const WrongCat &wrongCat);
    ~WrongCat();

    WrongCat &operator=(const WrongCat &wrongCat);

    void makeSound() const;
};
#endif