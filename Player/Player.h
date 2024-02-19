
#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include "../Character/Character.h"

class Player : public Character {
private:
    int level;
    int experience;

    void levelUp();

public:
    Player(std::string _name, int _health, int _attack, int _defense, int _speed);
    ~Player(); // Destructor

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;

    void gainExperience(int exp);
};

#endif // RPG_PLAYER_H
