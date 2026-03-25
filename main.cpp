#include <fstream>
#include <sstream>
#include <vector>
#include "LinkedList.h"
#include "Player.h"

void introduction() {
    cout << "Welcome to the Castle Adventure!\n";
    cout << "You will navigate through various rooms in the castle, encountering challenges and making decisions that will determine your path.\n";
    cout << "Choose your actions wisely. Let's start your journey!\n\n";
}

// Additional function 1
void pickUpItem(Player& player, const Room& room) {
    player.addItem(room.getItem());
}

// Additional function 2
void showPlayerStatus(const Player& player) {
    cout << "\nPlayer Status\n";
    cout << "Name: " << player.getName() << endl;
    cout << "Health: " << player.getHealth() << endl;
    player.showInventory();
    cout << endl;
}

int main() {
    LinkedList castleRooms;
    ifstream file("rooms.csv");
    string line;

    // Read rooms from CSV file
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name, description, actionsStr, item;
            vector<string> actions;

            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, actionsStr, ',');
            getline(ss, item);

            stringstream actionStream(actionsStr);
            string action;
            while (getline(actionStream, action, ';')) {
                actions.push_back(action);
            }

            Room newRoom(name, description, actions, item);
            castleRooms.addRoom(newRoom);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1;
    }

    // Create player
    Player player("Hero", 100);

    // Introduction
    introduction();

    // Interaction with rooms
    auto current = castleRooms.getHead();
    while (current != nullptr && player.isAlive()) {
        cout << current->room.toString() << endl;

        // Display original room actions
        int actionNum = 1;
        for (const auto& action : current->room.getActions()) {
            cout << actionNum++ << ". " << action << endl;
        }

        // Additional options
        cout << actionNum++ << ". Pick up item" << endl;
        cout << actionNum++ << ". Show player status" << endl;

        int totalRoomActions = current->room.getActions().size();

        int choice;
        cout << "Choose an action (1-" << totalRoomActions + 2 << "): ";
        cin >> choice;

        if (choice < 1 || choice > totalRoomActions + 2) {
            cout << "Invalid choice. Try again.\n";
        }
        else if (choice == totalRoomActions + 1) {
            pickUpItem(player, current->room);
        }
        else if (choice == totalRoomActions + 2) {
            showPlayerStatus(player);
        }
        else {
            cout << "You chose: " << current->room.getActions()[choice - 1] << endl;

            // Example game improvement: risky action causes damage
            if (current->room.getActions()[choice - 1] == "Open chest") {
                cout << "The chest was trapped!\n";
                player.takeDamage(10);
            }

            // Move to next room if last built-in action is chosen
            if (choice == totalRoomActions) {
                current = current->next;
            }
        }
    }

    if (!player.isAlive()) {
        cout << "You lost all your health. Game over!\n";
    } else {
        cout << "You have reached the end of your adventure!\n";
    }

    return 0;
}
