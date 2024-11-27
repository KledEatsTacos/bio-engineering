/**
 * @file        chromosome.hpp
 * @description Declares the Chromosome class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include "gene.hpp"
#include <iostream>

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
    Chromosome(const Chromosome& other);
    ~Chromosome();

    void addGene(char val);
    void mutateGene(int index);
    void display(ostream& out = cout) const;
    int getLength() const { return length; }
    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }
    void findAndPrintSmallest() const;
    
    friend class DNA;
};

#endif