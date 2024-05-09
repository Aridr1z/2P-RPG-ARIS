//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"
#include <iostream>
#include <cmath>

using namespace std;

Player::Player(char _name[40], int _health, int _attack,int _maxHealth, int _defense, int _speed) : Character(_name, _health,_maxHealth, _attack, _defense, _speed, true) {
    level = 1;
    experience = 0;
}

/// agregar constructor sobrecargado para agregar parametros

void Player::doAttack(Character *target) {
    target->takeDamage(attack);
}

void Player::doDefense(int defense) {
    defense = static_cast<int>(std::round(defense * 1.2));

    cout << name << " has been upgraded to "  <<  defense << " defense" << endl;
}

void Player::takeDamage(int damage) {
    int trueDamage = damage - defense;

    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;

    if(health <= 0) {
        cout << name << "has been defeated!" << endl;
    }
}

void Player::levelUp() {
    level++;
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100-experience;
    }
}

Character* Player::selectTarget(vector<Enemy*> possibleTargets) {
    int selectedTarget = 0;
    cout << "Select a target: " << endl;
    for (int i = 0; i < possibleTargets.size(); i++) {
        cout << i << ". " << possibleTargets[i]->getName() << endl;
    }

    //TODO: Add input validation
    cin >> selectedTarget;
    return possibleTargets[selectedTarget];
}




Character* Player::selectPlayer(vector<Enemy*> possiblePlayers) {
    int selectedPlayer = 0;
    for (int i = 0; i < possiblePlayers.size(); i++) {
    }
    //TODO: Add input validation
    return possiblePlayers[selectedPlayer];
}




Action Player::takeAction(vector<Enemy*> enemies) {
    int action = 0;
    cout << "Select an action: " << endl;
    cout << "1. Attack" << endl;
    cout << "2. Defense" << endl;

    //TODO: Validate input
    cin >> action;
    Action currentAction;
    Character* target = nullptr;

    /////
    switch(action) {
        case 1:
            target = selectTarget(enemies);
            currentAction.target = target;
            currentAction.action = [this, target](){
                doAttack(target);

                Enemy* tilin = ((Enemy*)target);
                getHealth(tilin->getExperience());

            };
            currentAction.speed = getSpeed();




            ////chcaer si murio el enemigo y dale el exp al enemigo
            break;



        case 2:

            target = this;
            currentAction.target = target;
            currentAction.action = [this, target](){
                doDefense(defense);
            };
            currentAction.speed = getSpeed();

            break;


        case 3:
            //doLevelUp


            break;

        default:
            cout << "Invalid action" << endl;
            break;
    }

    return currentAction;
}



