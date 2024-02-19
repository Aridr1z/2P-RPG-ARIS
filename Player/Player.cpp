#include "Player.h"

Player::Player(std::string _name, int _health, int _attack, int _defense, int _speed)
        : Character(_name, _health, _attack, _defense, _speed), level(1), experience(0) {}

Player::~Player() {}

void Player::doAttack(Character *target) {
    target->takeDamage(attack);
}

void Player::takeDamage(int damage) {
    int trueDamage = damage - defense;
    if (trueDamage > 0) {
        health -= trueDamage;
    }
    if (health < 0) {
        health = 0;
    }
}

void Player::levelUp() {
    level++;
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100 - experience;
    }
}
