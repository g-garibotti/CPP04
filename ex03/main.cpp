#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void basicTest()
{
    std::cout << "\n==== BASIC TEST ====" << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void advancedTest()
{
    std::cout << "\n==== ADVANCED TEST ====" << std::endl;
    
    std::cout << "\n--- Testing MateriaSource ---" << std::endl;
    MateriaSource *src = new MateriaSource();
    
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    std::cout << std::endl;
    
    // Create materias
    AMateria *m1 = src->createMateria("ice");
    AMateria *m2 = src->createMateria("cure");
    AMateria *m3 = src->createMateria("unknown");
    
    std::cout << "M1 type: " << m1->getType() << std::endl;
    std::cout << "M2 type: " << m2->getType() << std::endl;
    std::cout << "M3: " << (m3 ? m3->getType() : "NULL") << std::endl;
    
    std::cout << "\n--- Testing Character ---" << std::endl;
    Character *hero = new Character("hero");

    hero->equip(m1);
    hero->equip(m2);
    
    Character *c2 = new Character("enemy");
    
    hero->use(0, *c2);
    hero->use(1, *c2);
    hero->use(2, *c2);
    hero->use(3, *c2); 
    hero->use(-1, *c2); 
    
    std::cout << "\n--- Testing Unequip ---" << std::endl;
    AMateria *m4 = src->createMateria("ice");
    hero->equip(m4);
    hero->use(2, *c2);
    
    hero->unequip(2); 
    hero->use(2, *c2);
    
    std::cout << "\n--- Testing Deep Copy ---" << std::endl;
    Character *antihero = new Character(*hero);
    
    hero->use(0, *c2);
    antihero->use(0, *c2);
    
    hero->unequip(0);
    hero->use(0, *c2);
    antihero->use(0, *c2);

    delete m4;
    delete antihero;
    delete c2;
    delete hero;
    delete src;
}

int main()
{
    basicTest();
    advancedTest();
    
    return 0;
}