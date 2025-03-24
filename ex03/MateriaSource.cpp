#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = src;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->templates[i])
            delete this->templates[i];
}

MateriaSource & MateriaSource::operator=(const MateriaSource & rhs)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
            if (this->templates[i])
                delete this->templates[i];
                for (int i = 0; i < 4; i++)
            this->templates[i] = rhs.templates[i] ? rhs.templates[i]->clone() : NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!this->templates[i])
        {
            this->templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
        if (this->templates[i] && this->templates[i]->getType() == type)
            return this->templates[i]->clone();
    
    return NULL;
}
