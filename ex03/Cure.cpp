#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
     std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
     std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
     std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &cure)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    if (this != &cure)
    {
        AMateria::operator=(cure);
    }
    return *this;
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}