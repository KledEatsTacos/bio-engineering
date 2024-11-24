/**
 * @file        dna.cpp
 * @description Implements the DNA class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#include "dna.h"
#include <fstream>
#include <sstream>
#include <iostream>

DNA::DNA() : head(nullptr), tail(nullptr) {}

DNA::~DNA() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void DNA::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open file\n";
        return;
    }

    string line;
    int chromosomeCount = 0; // Debugging statement
    while (getline(file, line)) {
        cout << "Reading line: " << line << endl;
        Chromosome chromosome;
        istringstream iss(line);
        char geneValue;
        while (iss >> geneValue) {
            cout << "Adding gene: " << geneValue << endl;
            chromosome.addGene(geneValue);
        }

        Node* newNode = new Node(chromosome);
        if (head == NULL) {
            head = tail = newNode;
            cout << "Added first chromosome to DNA.\n";
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            cout << "Added new chromosome to DNA.\n";
        }
        chromosomeCount++; // Debugging statement
        cout << "Number of chromosomes: " << chromosomeCount << endl; // Debugging statement
        cout << "Current DNA state:\n";
        printAll(); // Debugging statement to print current state of DNA
    }
    file.close();
    cout << "File reading completed.\n";
}

void DNA::printAll() const {
    Node* current = head;
    int count = 0;
    while (current) {
        cout << "Chromosome " << count++ << ":\n";
        current->chromosome.display();
        current = current->next;
        if (current == nullptr) {
            cout << "Reached end of DNA list.\n";
        }
    }
    cout << "End of DNA state.\n";
}