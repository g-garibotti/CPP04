
#include "Character.hpp"

Character::Character() : name("unnamed")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string const & name) : name(name)
{
    std::cout << "Character parametric constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character & src)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = src;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->inventory[i])
            delete this->inventory[i];
}

Character & Character::operator=(const Character & rhs)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        for (int i = 0; i < 4; i++)
            if (this->inventory[i])
                delete this->inventory[i];
        for (int i = 0; i < 4; i++)
            this->inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
    }
    return *this;
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx]->use(target);
}
