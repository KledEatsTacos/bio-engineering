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

int main() {
    cout << "Loading DNA data from file...\n";
    DNA dna;
    dna.loadFromFile("Dna.txt");
    cout << "DNA data loaded successfully.\n";

    dna.printAll();

    return 0;
}