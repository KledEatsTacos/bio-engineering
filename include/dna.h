/**
 * @file        dna.h
 * @description Declares the DNA class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#ifndef DNA_H
#define DNA_H

#include "chromosome.h"
#include <string>

using namespace std;

class DNA {
private:
    struct Node {
        Chromosome chromosome;
        Node* next;
        Node* prev;
        Node(Chromosome c) : chromosome(c), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    DNA();
    ~DNA();

    void loadFromFile(const string& filename);
    void printAll() const;
};

#endif