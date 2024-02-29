#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#pragma once
#include "../Character/Character.h"
#include "../Player/Player.h"
#include <vector>
class Player;

class Enemy: public Character{
private:
    int experience;
public:
    Enemy(string _name, int _health, int _attack, double _defense, int _speed, int _experience);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* selectTarget(vector<Player*> possibleTargets);

    void doDefense(Character *target1) override;
    void takeDefense(double protect) override;

    int getExperience();
};


#endif //RPG_ENEMY_H
