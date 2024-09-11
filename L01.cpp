#include <iostream>
#include "AthleteStorage.h"

void showMenu() {
    std::cout << "1. Add athlete\n";
    std::cout << "2. Display all athletes\n";
    std::cout << "3. Read athletes from file\n";
    std::cout << "4. Write athletes to file\n";
    std::cout << "5. Clear the list of athletes\n";
    std::cout << "0. Exit\n";
}

int main() {
    AthleteStorage storage;
    int choice;
    std::string filename;
    //system('chcp 1251');
  
    do {
        showMenu();
        std::cout << "Choose an action: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            storage.addAthlete();
            break;
        case 2:
            storage.displayAthletes();
            break;
        case 3:
            std::cout << "Enter filename for reading: ";
            std::cin >> filename;
            storage.readFromFile(filename);
            break;
        case 4:
            std::cout << "Enter filename for writing: ";
            std::cin >> filename;
            storage.writeToFile(filename);
            break;
        case 5:
            storage.clear();
            std::cout << "The list of athletes has been cleared.\n";
            break;
        case 0:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
