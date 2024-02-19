#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"


using namespace std;

// Función para determinar quién gana el combate
void determineWinner(Player* player, Enemy* enemy) {
    if (player->isAlive() && !enemy->isAlive()) {
        cout << "¡El jugador ha ganado!" << endl;
    } else if (!player->isAlive() && enemy->isAlive()) {
        cout << "¡El enemigo ha ganado!" << endl;
    } else {
        cout << "¡Ha ocurrido un empate!" << endl;
    }
}

int main() {
    // Crear jugador y enemigo
    Player *player = new Player("Aris", 100, 8, 4, 10);
    Enemy *enemy = new Enemy("Un vago", 100, 10, 2, 5, 10);

    cout << "Comienza el combate:" << endl;

    // Bucle de combate
    // Bucle de combate
    while (player->isAlive() && enemy->isAlive()) {
        // Turno del jugador
        player->doAttack(enemy);
        cout << "Vida del jugador: " << player->getHealth() << endl;
        cout << "Vida del enemigo: " << enemy->getHealth() << endl;
        cout << "-------------------------------------" << endl;

        // Si el enemigo sigue vivo, turno del enemigo
        if (enemy->isAlive()) {
            enemy->doAttack(player);
            cout << "Vida del jugador: " << player->getHealth() << endl;
            cout << "Vida del enemigo: " << enemy->getHealth() << endl;
            cout << "-------------------------------------" << endl;
        }
    }


    // Determinar el ganador
    determineWinner(player, enemy);

    // Liberar memoria
    delete player;
    delete enemy;

    return 0;
}

