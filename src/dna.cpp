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

using namespace std;

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
    int chromosomeCount = 0;
    while (getline(file, line)) {
        Chromosome chromosome;
        istringstream iss(line);
        char geneValue;
        while (iss >> geneValue) {
            chromosome.addGene(geneValue);
        }

        Node* newNode = new Node(chromosome);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        chromosomeCount++;
    }
    file.close();
    cout << "Number of chromosomes: " << chromosomeCount << endl;
    cout << "File reading completed.\n";
}

void DNA::crossover(int index1, int index2) {
    Node* chrom1 = head;
    Node* chrom2 = head;

    for (int i = 0; i < index1 && chrom1; ++i) {
        chrom1 = chrom1->next;
    }
    for (int i = 0; i < index2 && chrom2; ++i) {
        chrom2 = chrom2->next;
    }

    if (!chrom1 || !chrom2) {
        cerr << "Invalid chromosome indices\n";
        return;
    }

    int len1 = chrom1->chromosome.getLength();
    int len2 = chrom2->chromosome.getLength();
    int mid1 = len1 / 2;
    int mid2 = len2 / 2;

    Chromosome newChrom1;
    Chromosome newChrom2;
    
    auto current1 = chrom1->chromosome.getHead();
    for (int i = 0; i < mid1 && current1; ++i) {
        newChrom1.addGene(current1->gene.getValue());
        current1 = current1->next;
    }
    
    if (len1 % 2 != 0 && current1) {
        current1 = current1->next;
    }
    
    auto current2 = chrom2->chromosome.getHead();
    for (int i = 0; i < mid2 && current2; ++i) {
        current2 = current2->next;
    }
    if (len2 % 2 != 0 && current2) {
        current2 = current2->next;
    }
    while (current2) {
        newChrom1.addGene(current2->gene.getValue());
        current2 = current2->next;
    }

    current2 = chrom2->chromosome.getHead();
    for (int i = 0; i < mid2 && current2; ++i) {
        newChrom2.addGene(current2->gene.getValue());
        current2 = current2->next;
    }
    
    if (len2 % 2 != 0 && current2) {
        current2 = current2->next;
    }
    
    current1 = chrom1->chromosome.getHead();
    for (int i = 0; i < mid1 && current1; ++i) {
        current1 = current1->next;
    }
    if (len1 % 2 != 0 && current1) {
        current1 = current1->next;
    }
    while (current1) {
        newChrom2.addGene(current1->gene.getValue());
        current1 = current1->next;
    }

    Node* newNode1 = new Node(newChrom1);
    Node* newNode2 = new Node(newChrom2);

    if (!head) {
        head = tail = newNode1;
    } else {
        tail->next = newNode1;
        newNode1->prev = tail;
        tail = newNode1;
    }

    tail->next = newNode2;
    newNode2->prev = tail;
    tail = newNode2;
}

void DNA::mutate(int chromIndex, int geneIndex) {
    Node* current = head;
    for (int i = 0; i < chromIndex && current; ++i) {
        current = current->next;
    }
    if (current) {
        current->chromosome.mutateGene(geneIndex);
    } else {
        cerr << "Chromosome index out of range\n";
    }
}

void DNA::printAll() const {
    Node* current = head;
    while (current) {
        current->chromosome.findAndPrintSmallest();
        current = current->next;
    }
    cout << endl;
}

void DNA::automatedOperations(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open operations file\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        char operation;
        iss >> operation;

        if (operation == 'C') {
            int index1, index2;
            iss >> index1 >> index2;
            crossover(index1, index2);
        } 
        else if (operation == 'M') {
            int chromIndex, geneIndex;
            iss >> chromIndex >> geneIndex;
            mutate(chromIndex, geneIndex);
        }
    }
    file.close();
    cout << "Automated operations completed.\n";
}