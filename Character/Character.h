//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>

using namespace std;

class Character {
protected:
    string name;
    int health;
    int maxHealth;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
public:
    Character(char _name[40], int _health, int _maxHealth, int _attack, int _defense, int _speed, bool _isPlayer);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;
    virtual void doDefense(int defense) = 0;

    //TODO: Implementar metodo de defensa
    //Incrementar la defensa un 20% solo por el turno actual
    void defend();

    bool flee(Character* target);
    string getName();
    int getHealth();
    int getMaxHealth();
    int getAttack();
    int getDefense();
    bool getIsPlayer();
    int getSpeed();
    string toString();
};


#endif //RPG_CHARACTER_H
