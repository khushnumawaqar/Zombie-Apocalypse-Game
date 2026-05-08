#include "ZombieEventLibrary.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "========================\n";
    cout << "ZOMBIE SURVIVAL GAME\n";
    cout << "========================\n\n";

    string name;
    cout << "Enter your name: ";
    cin >> name;

    
    ZombieEvent player(name);

   
    cout << "\nYour survivor: " << player << endl;

    
    player.play();

    
    cout << "\nFinal stats: " << player << endl;

    
    cout << "\n===== OPERATOR OVERLOADING DEMO =====\n";

    ZombieEvent player2("Hero", 80, 5);
    cout << "Player 1: " << player << endl;
    cout << "Player 2: " << player2 << endl;

    
    ZombieEvent combined = player + player2;
    cout << "\nCombined (player1 + player2): " << combined << endl;

    
    ZombieEvent difference = player - player2;
    cout << "Difference (player1 - player2): " << difference << endl;

    
    if (player > player2) {
        cout << "\n" << player.getName() << " has MORE health than " << player2.getName() << endl;
    }
    else {
        cout << "\n" << player2.getName() << " has MORE health than " << player.getName() << endl;
    }

    

    cout << "\n===== GAME OVER =====\n";

    return 0;
}