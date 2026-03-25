#include "Player.h"

Player::Player(string name, int health) : name(name), health(health) {}

void Player::addItem(const string& item) {
    if (item != "None" && item != "") {
        inventory.push_back(item);
        cout << item << " added to inventory.\n";
    } else {
        cout << "There is no item to pick up.\n";
    }
}

void Player::showInventory() const {
    cout << "\nInventory:\n";
    if (inventory.empty()) {
        cout << "Empty\n";
        return;
    }

    for (const auto& item : inventory) {
        cout << "- " << item << endl;
    }
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    cout << "You lost " << damage << " health.\n";
}

bool Player::isAlive() const {
    return health > 0;
}

string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}