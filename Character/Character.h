
#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>

using namespace std;

class Character {
protected:
    string name;
    int health;
    int attack;
    double defense;
    int speed;
    bool isPlayer;
public:
    Character(string _name, int _health, int _attack, double _defense, int _speed, bool _isPlayer);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    ////
    virtual void doDefense(Character *target1) = 0;
    virtual void takeDefense(double protect) = 0;


    ////


    //TODO: Implementar metodo de defensa
    //Incrementar la defensa un 20% solo por el turno actual

    bool flee(Character* target);
    string getName();
    int getHealth();
    int getAttack();
    int getDefense();
    bool getIsPlayer();
    int getSpeed();
    string toString();
};


#endif //RPG_CHARACTER_H
