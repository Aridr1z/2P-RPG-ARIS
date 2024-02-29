#include "Character.h"

Character::Character(std::string _name, int _health, int _attack, double _defense, int _speed,bool _isPLayer)
        : name(_name), health(_health), attack(_attack), defense(_defense), speed(_speed), isPlayer(_isPLayer) {}



string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    return "Name: " + name + "\nHealth: " + std::to_string(health) + "\nAttack: " + std::to_string(attack) + "\nDefense: " + std::to_string(defense) + "\nSpeed: " + std::to_string(speed);
}


bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::flee(Character*target){
    if(this->speed > target ->speed)
        return true;

    int chance = rand()%100;
    return chance > 30;

}
