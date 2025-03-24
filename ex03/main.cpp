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

// Additional tests to cover more functionality
void advancedTest()
{
    std::cout << "\n==== ADVANCED TEST ====" << std::endl;
    
    // Test MateriaSource functionality
    std::cout << "\n--- Testing MateriaSource ---" << std::endl;
    MateriaSource *src = new MateriaSource();
    
    // Learn materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Try to learn more than 4 (should have no effect)
    src->learnMateria(new Ice());
    
    // Create materias
    AMateria *m1 = src->createMateria("ice");
    AMateria *m2 = src->createMateria("cure");
    AMateria *m3 = src->createMateria("unknown"); // Should return NULL
    
    std::cout << "M1 type: " << m1->getType() << std::endl;
    std::cout << "M2 type: " << m2->getType() << std::endl;
    std::cout << "M3: " << (m3 ? m3->getType() : "NULL") << std::endl;
    
    // Test Character functionality
    std::cout << "\n--- Testing Character ---" << std::endl;
    Character *hero = new Character("hero");
    
    // Equip materias
    hero->equip(m1);
    hero->equip(m2);
    
    // Create another character for target
    Character *c2 = new Character("enemy");
    
    // Use equipped materias
    hero->use(0, *c2);
    hero->use(1, *c2);
    hero->use(2, *c2); // Should do nothing (no materia at index 2)
    hero->use(3, *c2); // Should do nothing (no materia at index 3)
    hero->use(-1, *c2); // Should do nothing (invalid index)
    
    // Test unequip
    std::cout << "\n--- Testing Unequip ---" << std::endl;
    AMateria *m4 = src->createMateria("ice");
    hero->equip(m4);
    hero->use(2, *c2); // Should use ice
    
    hero->unequip(2); // Unequip m4
    hero->use(2, *c2); // Should do nothing
    
    // Test deep copy of Character
    std::cout << "\n--- Testing Deep Copy ---" << std::endl;
    Character *c3 = new Character(*hero); // Copy constructor
    
    hero->use(0, *c2); // Hero uses ice
    c3->use(0, *c2); // Copy also uses ice
    
    hero->unequip(0); // Unequip in original
    hero->use(0, *c2); // Should do nothing
    c3->use(0, *c2); // Copy still has it
    
    // Clean up unequipped materia
    delete m4;
    
    // Clean up
    delete c3;
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