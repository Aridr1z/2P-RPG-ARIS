//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#pragma once
#include "../Character/Character.h"
#include "../Player/Player.h"
#include <vector>
#include "../Combat/Action.h"

class Player;

class Enemy: public Character{
private:
    int experience;
public:
    Enemy(char _name[40], int _health,int _maxHealth, int _attack, int _defense, int _speed, int _experience);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void doDefense(int defense) override;


    Character* selectTarget(vector<Player*> possibleTargets);
    Action takeAction(vector<Player*> partyMembers);

    int getExperience();

    void increaseEnemyStats();


};


#endif //RPG_ENEMY_H
