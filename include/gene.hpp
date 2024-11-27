/**
 * @file        gene.hpp
 * @description Declares the Gene class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#ifndef GENE_HPP
#define GENE_HPP

#include <iostream>
using namespace std;

class Gene {
private:
    char value;

public:
    Gene(char val = ' ');
    char getValue() const;
    void setValue(char val);
};

#endif