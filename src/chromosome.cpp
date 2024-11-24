/**
 * @file        chromosome.cpp
 * @description Implements the Chromosome class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#include "chromosome.h"
#include <iostream>

Chromosome::Chromosome() : head(nullptr), tail(nullptr), length(0) {}

Chromosome::~Chromosome() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void Chromosome::addGene(char val) {
    Node* newNode = new Node(Gene(val));
    if (!head) {
        head = tail = newNode;
        cout << "Added first gene to chromosome: " << val << endl;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        cout << "Added new gene to chromosome: " << val << endl;
    }
    length++;
}

void Chromosome::display() const {
    Node* current = head;
    while (current) {
        cout << current->gene.getValue() << " ";
        current = current->next;
        if (current == nullptr) {
            cout << "Reached end of chromosome.\n";
        }
    }
    cout << "\n";
}