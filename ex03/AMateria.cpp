#include "AMateria.hpp"

AMateria::AMateria() : type("")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
     std::cout << "AMateria parametric constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &amateria)
{
     std::cout << "AMateria copy constructor called" << std::endl;
    *this = amateria;
}

AMateria::~AMateria()
{
     std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &amateria)
    {
        this->type = amateria.type;
    }
    return *this;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}
