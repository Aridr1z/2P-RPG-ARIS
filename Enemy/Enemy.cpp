#include "Enemy.h"
#include "../Utils.h"
#include <iostream>


using namespace std;
using namespace combat_utils;

Enemy::Enemy(string _name, int _health, int _attack, double _defense, int _speed, int _experience) : Character(_name, _health, _attack, _defense, _speed, false) {
    experience = _experience;
}


///// marcador
void Enemy::doAttack(Character *target) {
    target->takeDamage(getRolledAttack(attack));
}


/// marcador
void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;
    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;
}

int Enemy::getExperience() {
    return experience;
}







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


void Enemy::doDefense(Character *target1) {
    target1->takeDefense(defense);

}

void Enemy::takeDefense(double protect) {
    protect = (defense * 0.20);

    defense += protect;


    cout << name << "incresese his defense by 20%, his defense is " << defense << endl;


}