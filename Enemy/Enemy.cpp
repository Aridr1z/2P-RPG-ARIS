//
// Created by Victor Navarro on 15/02/24.
//

#include "Enemy.h"
#include "../Utils.h"
#include <iostream>
#include <cmath>


using namespace std;
using namespace combat_utils;

Enemy::Enemy(string _name, int _health,int _maxHealth, int _attack, int _defense, int _speed, int _experience) : Character(_name, _health, _maxHealth, _attack, _defense, _speed, false) {
    experience = _experience;
}

void Enemy::doAttack(Character *target) {
    target->takeDamage(getRolledAttack(attack));
}

void Enemy::doDefense(int defense) {
    defense = static_cast<int>(std::round(defense * 1.2));
    cout << name << " has been upgraded to "  <<  defense << " defense" << endl;
}

void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;
    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;
    if(health <= 0) {
        cout << name << " has been defeated!" << endl;
    }
}

int Enemy::getExperience() {
    return experience;
}

//////
Character* Enemy::selectTarget(vector<Player*> possibleTargets) {
    //target with less health
    int lessHealth = 9999999;
    Character* target = nullptr;
    for(auto character : possibleTargets) {
        if(character->getHealth() < lessHealth) {
            lessHealth = character->getHealth();
            target = character;
        }
    }
    return target;
}

//////
Action Enemy::takeAction(vector<Player*> partyMembers) {
    int t = 0;
    if (getHealth()>=(0.15* getMaxHealth())){

        Action currentAction;
        currentAction.speed = getSpeed();

        Character* target = selectTarget(partyMembers);
        currentAction.target = target;
        currentAction.action = [this, target](){

            /////
            doAttack(target);
        };

        return currentAction;

    } else{
        for(t=0; t <= 1;t++){
            doDefense(defense);
        }

    }
}