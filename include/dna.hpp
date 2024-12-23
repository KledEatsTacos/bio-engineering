/**
 * @file        dna.hpp
 * @description Declares the DNA class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#ifndef DNA_HPP
#define DNA_HPP

#include "chromosome.hpp"
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
    void crossover(int index1, int index2);
    void mutate(int chromIndex, int geneIndex);
    void printAll() const;
    void automatedOperations(const string& filename);
};

#endif