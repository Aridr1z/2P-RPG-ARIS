//
// Created by Victor Navarro on 15/02/24.
//
#pragma once
#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"
#include <vector>
#include <fstream>
#include <sstream>


class Enemy;

class Player: public Character {
    //TODO: Implement Classes (Mage, Warrior, Rogue, etc..)
    //TODO: Implement Inventory
private:
    int level;
    int experience;


public:
    Player(char _name[40], int _health,int _maxHealth, int _attack, int _defense, int _speed);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void doDefense(int defense) override;
    int getLevel();


    Character* selectTarget(vector<Enemy*> possibleTargets);
    Character* selectPlayer(vector<Enemy*> possiblePlayers);
    Action takeAction(vector<Enemy*> enemies);

    void levelUp();
    void levelUp(std::vector<Enemy*> enemies);
    std::vector<Enemy*> enemies;

    void gainExperience(int exp);

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << name << std::endl;
            file << health << std::endl;
            file << attack << std::endl;
            file << defense << std::endl;
            file << speed << std::endl;
            file << level << std::endl;
            file << experience << std::endl;
            file.close();
        }
    }

    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            if (std::getline(file, line)) name = line;
            if (std::getline(file, line)) health = std::stoi(line);
            if (std::getline(file, line)) attack = std::stoi(line);
            if (std::getline(file, line)) defense = std::stoi(line);
            if (std::getline(file, line)) speed = std::stoi(line);
            if (std::getline(file, line)) level = std::stoi(line);
            if (std::getline(file, line)) experience = std::stoi(line);
            file.close();
            return true; // Devolver true si la carga del archivo fue exitosa
        }
        return false; // Devolver false si la carga del archivo falló
    }





    //TODO: Implement use object
};


#endif //RPG_PLAYER_H
