#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;

enum CodeKeyArrow {
    LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, ESC = 27, ENTER = 13
};

void displayMenu(const vector<string>& options, int selected) {
    for (size_t i = 0; i < options.size(); ++i) {
        cout << "\t\t"; // Табуляція перед кожним пунктом меню
        if (i == selected) {
            cout << "> " << options[i] << " <" << endl; // Виділення активного пункту
        }
        else {
            cout << options[i] << endl;
        }
    }
}

void printAsciiArt() {
    cout << R"(
          :::::::::::      :::    :::       :::        ::::::::::    :::   :::       :::    :::       ::::::::
             :+:          :+:    :+:       :+:        :+:           :+:   :+:       :+:   :+:       :+:    :+:
            +:+          +:+    +:+       +:+        +:+            +:+ +:+        +:+  +:+        +:+    +:+
           +#+          +#+    +:+       +#+        :#::+::#        +#++:         +#++:++         +#+    +:+
          +#+          +#+    +#+       +#+        +#+              +#+          +#+  +#+        +#+    +#+
     #+# #+#          #+#    #+#       #+#        #+#              #+#          #+#   #+#       #+#    #+#
     #####            ########        ########## ###              ###          ###    ###       ########

)";
}

int main() {
    vector<string> options = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Option 4",
        "Option 5",
        "Exit"
    };
    int selected = 0;

    while (true) {
        system("cls"); // Очищаємо консоль
        printAsciiArt(); // Виводимо ASCII кожного разу
        displayMenu(options, selected); // Виводимо меню з вибором

        int key = _getch(); // Отримуємо ввід

        // Перевірка на спеціальні клавіші
        if (key == 0 || key == 224) {
            switch (_getch()) {
            case UP:
                selected = (selected > 0) ? selected - 1 : options.size() - 1;
                break;
            case DOWN:
                selected = (selected + 1) % options.size();
                break;
            }
        }
        else if (key == ENTER) {
            break; // Виходимо з меню при ENTER
        }
    }

    // Обробка вибору
    system("cls");
    printAsciiArt();
    if (selected == options.size() - 1) {
        cout << "Exiting..." << endl;
    }
    else {
        cout << "You selected: " << options[selected] << endl;
    }

    return 0;
}
