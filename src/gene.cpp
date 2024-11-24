/**
 * @file        gene.cpp
 * @description Implements the Gene class.
 * @course      2. A.
 * @assignment  Assignment 1.
 * @date        2024-11-22.
 * @author      Mustafa Masri.
 */

#include "gene.h"
using namespace std;

Gene::Gene(char val) : value(val) {}

char Gene::getValue() const {
    return value;
}

void Gene::setValue(char val) {
    value = val;
}
