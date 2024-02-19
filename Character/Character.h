#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int attack;
    int defense;
    int speed;

public:
    Character(std::string _name, int _health, int _attack, int _defense, int _speed);
    virtual ~Character(); // Destructor virtual para asegurar llamada apropiada a los destructores de clases derivadas

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage);
    bool isAlive() const;

    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getSpeed() const;
    std::string toString() const;
};

#endif // RPG_CHARACTER_H
