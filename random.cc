/* File: random.cc
 * Implements the randomize functions needed by the program
 * Valtteri Ranta, 6.6.2018
 */

#include "random.hh"
#include <cstdlib>
#include <ctime>

int RandomInteger(int min, int max) {
    //Initialize random seed:
    srand (time(NULL));

    //generate number between min and max
    int randomInteger = rand() % max + min;

    return randomInteger;
}



