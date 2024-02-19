#include "Character.h"

Character::Character(std::string _name, int _health, int _attack, int _defense, int _speed)
        : name(_name), health(_health), attack(_attack), defense(_defense), speed(_speed) {}

Character::~Character() {}

void Character::takeDamage(int damage) {
    int trueDamage = damage - defense;
    if (trueDamage > 0) {
        health -= trueDamage;
    }
    if (health < 0) {
        health = 0;
    }
}

bool Character::isAlive() const {
    return health > 0;
}

std::string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getAttack() const {
    return attack;
}

int Character::getDefense() const {
    return defense;
}

int Character::getSpeed() const {
    return speed;
}

std::string Character::toString() const {
    return "Name: " + name + "\nHealth: " + std::to_string(health) + "\nAttack: " + std::to_string(attack) + "\nDefense: " + std::to_string(defense) + "\nSpeed: " + std::to_string(speed);
}
