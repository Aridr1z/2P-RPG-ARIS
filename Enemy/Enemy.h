#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#include "../Character/Character.h"



class Enemy : public Character {
private:
    int experience;

public:
    Enemy(std::string _name, int _health, int _attack, int _defense, int _speed, int _experience);
    //~Enemy();

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    int getExperience() const;


};

#endif // RPG_ENEMY_H
