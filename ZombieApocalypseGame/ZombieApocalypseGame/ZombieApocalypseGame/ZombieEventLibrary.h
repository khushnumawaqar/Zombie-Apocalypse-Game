#ifndef ZOMBIEEVENTLIBRARY_H
#define ZOMBIEEVENTLIBRARY_H

#include <iostream>
#include <string>
using namespace std;

class ZombieEvent {
private:
    string playerName;
    int health;
    int ammo;

public:
   
    ZombieEvent();
    ZombieEvent(string name);
    ZombieEvent(string name, int h, int a);

   
    void fight();                    
    void fight(int bullets);         
    void fight(string action, int val); 

   
    void play();

    
    string getName() const { return playerName; }
    int getHealth() const { return health; }
    int getAmmo() const { return ammo; }

    
    ZombieEvent operator+(const ZombieEvent& other);
    ZombieEvent operator-(const ZombieEvent& other);
    bool operator>(const ZombieEvent& other);
    friend ostream& operator<<(ostream& os, const ZombieEvent& ze);
};


ZombieEvent::ZombieEvent() {
    playerName = "Survivor";
    health = 100;
    ammo = 10;
}

ZombieEvent::ZombieEvent(string name) {
    playerName = name;
    health = 100;
    ammo = 10;
}

ZombieEvent::ZombieEvent(string name, int h, int a) {
    playerName = name;
    health = h;
    ammo = a;
}


void ZombieEvent::fight() {
    
    static int counter = 0;
    counter++;
    int zombies = (counter % 3) + 1;  

    cout << "\n " << zombies << " zombie(s) attacked!\n";

    if (zombies == 1) {
        health = health - 10;
        cout << "You lost 10 health!\n";
    }
    else if (zombies == 2) {
        health = health - 20;
        cout << "You lost 20 health!\n";
    }
    else {
        health = health - 35;
        cout << "You lost 35 health!\n";
    }

    cout << "Health: " << health << endl;
}


void ZombieEvent::fight(int bullets) {
    if (ammo >= bullets) {
        ammo = ammo - bullets;
        int zombiesKilled = bullets * 2;
        health = health - 5;

        cout << "\n You shot " << bullets << " bullets!\n";
        cout << "Killed " << zombiesKilled << " zombies!\n";
        cout << "Lost 5 health\n";
        cout << "Health: " << health << " | Ammo left: " << ammo << endl;
    }
    else {
        cout << "\n Not enough ammo! You have " << ammo << " bullets\n";
    }
}


void ZombieEvent::fight(string action, int val) {
    if (action == "heal") {
        health = health + val;
        if (health > 100) {
            health = 100;
        }
        cout << "\n You healed " << val << " health!\n";
        cout << "Health: " << health << endl;
    }
    else if (action == "ammo") {
        ammo = ammo + val;
        cout << "\n You found " << val << " bullets!\n";
        cout << "Ammo: " << ammo << endl;
    }
}


void ZombieEvent::play() {
    int choice;
    bool alive = true;
    int turn = 0;

    cout << "\n===== ZOMBIE SURVIVAL GAME =====\n";
    cout << "Welcome " << playerName << "!\n";
    cout << "Health: " << health << " | Ammo: " << ammo << "\n\n";

    while (alive == true && health > 0) {
        cout << "\n------------------------\n";
        cout << "What to do?\n";
        cout << "1. Fight zombies (random)\n";
        cout << "2. Shoot zombies (use ammo)\n";
        cout << "3. Search for ammo\n";
        cout << "4. Heal yourself\n";
        cout << "5. Quit game\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            fight();  
        }
        else if (choice == 2) {
            int bullets;
            cout << "How many bullets? (1-5): ";
            cin >> bullets;
            if (bullets >= 1 && bullets <= 5) {
                fight(bullets);  
            }
            else {
                cout << "Use 1-5 bullets only!\n";
            }
        }
        else if (choice == 3) {
            fight("ammo", 5);  
        }
        else if (choice == 4) {
            fight("heal", 20);  
        }
        else if (choice == 5) {
            cout << "\nThanks for playing!\n";
            alive = false;
        }
        else {
            cout << "Invalid choice! Pick 1-5\n";
        }

      
        if (health <= 0) {
            cout << "\n YOU DIED! GAME OVER \n";
            cout << "Play again? (1=Yes, 0=No): ";
            int again;
            cin >> again;
            if (again == 1) {
                health = 100;
                ammo = 10;
                turn = 0;
                cout << "\n*** GAME RESTARTED ***\n";
            }
            else {
                alive = false;
            }
        }

   
        turn = turn + 1;
        if (turn % 2 == 0 && health > 0 && alive == true) {
            cout << "\n🎁 You found 3 bonus bullets!\n";
            ammo = ammo + 3;
        }
    }
}

ZombieEvent ZombieEvent::operator+(const ZombieEvent& other) {
    int newHealth = this->health + other.health;
    int newAmmo = this->ammo + other.ammo;
    return ZombieEvent("Combined", newHealth, newAmmo);
}

ZombieEvent ZombieEvent::operator-(const ZombieEvent& other) {
    int diffHealth = this->health - other.health;
    if (diffHealth < 0) {
        diffHealth = 0;
    }
    return ZombieEvent("Difference", diffHealth, 0);
}

bool ZombieEvent::operator>(const ZombieEvent& other) {
    if (this->health > other.health) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(ostream& os, const ZombieEvent& ze) {
    os << "[ " << ze.playerName << " | Health: " << ze.health << " | Ammo: " << ze.ammo << " ]";
    return os;
}

#endif