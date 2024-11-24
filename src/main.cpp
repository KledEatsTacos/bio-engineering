/**
 * @file        main.cpp
 * @description The main file of the program.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#include "dna.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\nDNA Operations Menu:\n";
    cout << "1. Crossover\n";
    cout << "2. Mutation\n";
    cout << "3. Automated Operations\n";
    cout << "4. Print to Screen\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    cout << "Loading DNA data from file...\n";
    DNA dna;
    dna.loadFromFile("Dna.txt");
    cout << "DNA data loaded successfully.\n";

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int index1, index2;
                cout << "Enter first chromosome index: ";
                cin >> index1;
                cout << "Enter second chromosome index: ";
                cin >> index2;
                dna.crossover(index1, index2);
                break;
            }
            case 2: {
                int chromIndex, geneIndex;
                cout << "Enter chromosome index: ";
                cin >> chromIndex;
                cout << "Enter gene index: ";
                cin >> geneIndex;
                dna.mutate(chromIndex, geneIndex);
                break;
            }
            case 3:
                dna.automatedOperations("Islemler.txt");
                break;
            case 4:
                dna.printAll();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}