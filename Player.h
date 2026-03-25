#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int health;
    vector<string> inventory;

public:
    Player(string name, int health);

    void addItem(const string& item);
    void showInventory() const;
    void takeDamage(int damage);
    bool isAlive() const;

    string getName() const;
    int getHealth() const;
};

#endif