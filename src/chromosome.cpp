/**
 * @file        chromosome.cpp
 * @description Implements the Chromosome class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#include "chromosome.hpp"
#include <iostream>

Chromosome::Chromosome() : head(nullptr), tail(nullptr), length(0) {}

Chromosome::Chromosome(const Chromosome& other) : head(nullptr), tail(nullptr), length(0) {
    Node* current = other.head;
    while (current) {
        addGene(current->gene.getValue());
        current = current->next;
    }
}

Chromosome::~Chromosome() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = tail = nullptr;
    length = 0;
}

void Chromosome::addGene(char val) {
    Node* newNode = new Node(Gene(val));
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

void Chromosome::mutateGene(int index) {
    if (index < 0 || index >= length) {
        cerr << "Index out of range\n";
        return;
    }
    Node* current = head;
    for (int i = 0; i < index && current; ++i) {
        current = current->next;
    }
    if (current) {
        current->gene.setValue('X');
    }
}

void Chromosome::findAndPrintSmallest() const {
    if (!head) return;
    
    char firstGene = head->gene.getValue();
    Node* current = tail;
    char smallestFound = firstGene;
    bool foundSmaller = false;
    
    while (current) {
        if (current->gene.getValue() < firstGene) {
            smallestFound = current->gene.getValue();
            foundSmaller = true;
            break;
        }
        current = current->prev;
    }
    
    cout << (foundSmaller ? smallestFound : firstGene) << " ";
}

void Chromosome::display(ostream& out) const {
    Node* current = head;
    while (current) {
        out << current->gene.getValue() << " ";
        current = current->next;
    }
    out << "\n";
}