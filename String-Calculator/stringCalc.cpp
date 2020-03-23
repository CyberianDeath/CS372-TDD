//Chaweinta Hale
// Started:     March, 21 2020
// Modified:    March, 22 2020
// TDD practice with String Calculator
// Based on www.peterprovost.org/blog/2012/05/02/kata-the-only-way-to-learn-tdd/

#include "stringCalc.h"
#include "catch.hpp"

int Add(std::string numbers){
    if (numbers == ""){
        return 0;
    }
    int val;
    std::istringstream sis (numbers);
    sis >> val;
    return val;

}
