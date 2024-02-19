#include "Enemy.h"
#include "../Utils.h"

using namespace std;
using namespace combat_utils;

Enemy::Enemy(string _name, int _health, int _attack, int _defense, int _speed, int _experience) : Character(_name, _health, _attack, _defense, _speed) {
    experience = _experience;
}

//Enemy::~Enemy() {}

void Enemy::doAttack(Character *target) {
    target->takeDamage(getRolledAttack(attack)); // Utilizamos la función getRolledAttack del archivo Utils.h para obtener un ataque aleatorio
}

void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;
    if (trueDamage > 0) {
        health -= trueDamage;
    }
    if (health < 0) {
        health = 0;
    }
}

int Enemy::getExperience() const {
    return experience;
}
