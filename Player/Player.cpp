//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"
#include <iostream>
#include <cmath>
#include <time.h>

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
    int point = 5;
    int select;

    cout << name << " jose has leveled up, choose a skill to increase it " << endl;

    while (point >= 0 ){

        cout << "1. Health" << endl;
        cout << "2. Attack" << endl;
        cout << "3. Defense" << endl;
        cout << "4. Speed" << endl;

        cin >> select;


        switch (select) {
            case 1:
                health++;
                cout << "Health increased by 1." << endl;
                point--;
                break;
            case 2:
                attack++;
                cout << "Attack increased by 1." << endl;
                point--;
                break;
            case 3:
                defense++;
                cout << "Defense increased by 1." << endl;
                point--;
                break;
            case 4:
                speed++;
                cout << "Speed increased by 1." << endl;
                point--;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                point--;
                break;
        }


    }


    for (Enemy* enemy : enemies) {
        enemy->increaseEnemyStats(); // Llamar al método para aumentar las estadísticas del enemigo
    }



}




void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100-experience;
        cout << name << " has upgraded" << endl;
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
    Action currentAction;
    Character* target = nullptr;



    do {


        cout << "Select an action: " << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defense" << endl;
        cout << "3. Check Stats" << endl;
        cout << "4. Save Game" << endl;
        cout << "5. Load Game" << endl;


        //TODO: Validate input
        cin >> action;


        switch (action) {
            case 1:
                target = selectTarget(enemies);
                currentAction.target = target;
                currentAction.action = [this, target]() {
                    doAttack(target);

                    if (target->getHealth() <= 0) {

                        this->gainExperience(100);

                    }

                };
                currentAction.speed = getSpeed();


                ////chcaer si murio el enemigo y dale el exp al enemigo
                break;


            case 2:

                target = this;
                currentAction.target = target;
                currentAction.action = [this, target]() {
                    doDefense(defense);
                };
                currentAction.speed = getSpeed();

                break;

            case 3:
                cout << "Name: " << getName() << endl;
                cout << "Level: " << getLevel() << endl;
                cout << "Health: " << getHealth() << endl;
                cout << "Attack: " << getAttack() << endl;
                cout << "Defense: " << getDefense() << endl;
                cout << "Speed: " << getSpeed() << endl;


                break;

            case 4:
                saveToFile("player_stats.txt");
                cout << "Player stats saved successfully." << endl;
                break;

            case 5:
                if (!loadFromFile("player_stats.txt")) {
                    cout << "Failed to load player stats. Starting a new game." << endl;
                    // Inicializar el jugador con estadísticas predeterminadas
                } else {
                    cout << "Player stats loaded successfully." << endl;
                }
                break;




            default:
                cout << "Invalid action" << endl;
                break;
        }

    }while (action == 3 || action == 4 || action == 5 || action == 6
            || action == 7 || action == 8);

    return currentAction;
}


int Player::getLevel() {
    return level;
}



