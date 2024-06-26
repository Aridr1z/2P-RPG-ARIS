//
// Created by Victor Navarro on 15/02/24.
//

#include "Enemy.h"
#include "../Utils.h"
#include <iostream>
#include <cmath>


using namespace std;
using namespace combat_utils;

Enemy::Enemy ( char _name[40], int _health,int _maxHealth, int _attack, int _defense, int _speed, int _experience) : Character(_name, _health, _maxHealth, _attack, _defense, _speed, false) {
    experience = _experience;
}

int t = 0;

void Enemy::doAttack(Character *target) {
    target->takeDamage(getRolledAttack(attack));

}

void Enemy::doDefense(int defense) {
    defense = static_cast<int>(std::round(defense * 1.2));
    cout << name << " has been upgraded to "  <<  defense << " defense" << endl;
}

////////
void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;
    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;
    if(health <= 0) {
        cout << name << "enemy has been defeated!" << endl;
    }
}


/////



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

    if (getHealth() >= (0.15 * getMaxHealth()) ||  t==1) {

        Action currentAction;
        currentAction.speed = getSpeed();

        Character *target = selectTarget(partyMembers);
        currentAction.target = target;
        currentAction.action = [this, target]() {

            /////
            doAttack(target);
        };

        return currentAction;

    } else if(t!=1) {



        t=1;
        Action currentAction;
        currentAction.speed = getSpeed();
        Character *target = nullptr;
        //Character *target = selectTarget(partyMembers);

        target = this;
        currentAction.target = target;
        currentAction.action = [this,target]() {
            doDefense(defense);

        };

        return currentAction;
    }


}


void Enemy::increaseEnemyStats() {


    int levels = 5;

    for (int i = 0; i < levels; i++) {

        int opcion = rand() % 4;

        switch (opcion) {
            case 0:
                health++;

                break;
            case 1:
                attack++;

                break;
            case 2:
                defense++;

                break;
            case 3:
                speed++;
                break;
        }


    }

}

