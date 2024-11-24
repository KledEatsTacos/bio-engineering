/**
 * @file        chromosome.h
 * @description Declares the Chromosome class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "gene.h"

using namespace std;

class Chromosome {
private:
    struct Node {
        Gene gene;
        Node* next;
        Node* prev;
        Node(Gene g) : gene(g), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    int length;

public:
    Chromosome();
    ~Chromosome();

    void addGene(char val);
    void display() const;
};

#endif