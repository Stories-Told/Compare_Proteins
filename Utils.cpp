#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include "Acid.h"
#include "Protein.h"
#include "Utils.h"

using namespace std;

// Global seed for random generator
const unsigned int seed = time(0);
// Random number generator
mt19937_64 rGen(seed);

// Generates a number from 0 -> 20
double GenerateRandomX()
{
    uniform_real_distribution<double> randomX(0.0, 20.0);

    return randomX(rGen);
}

// Generates a number from -20 -> 20
double GenerateRandomY()
{
    uniform_real_distribution<double> randomY(-20.0, 20.0);

    return randomY(rGen);
}

// Generates a number from -20 -> 20
double GenerateRandomZ()
{
    uniform_real_distribution<double> randomZ(-20.0, 20.0);

    return randomZ(rGen);
}

// Determines if node in linked list is selected for
// creating random protein :: true = yes && false = no
bool SelectFromLinkedList()
{
    uniform_int_distribution<int> randomNumber(0, 100);
    int rollRandomNum = randomNumber(rGen);

    if (rollRandomNum >= 50) { return true; }
    else { return false; }
}

bool CreateAcidBond()
{
    uniform_int_distribution<int> randomNumber(0, 100);
    int rollRandomNum = randomNumber(rGen);

    if (rollRandomNum >= 50) { return true; }
    else { return false; }
}

int HowManyConnectionsToMake()
{
    uniform_int_distribution<int> randomNumber(2, 3);
    int rollRandomNum = randomNumber(rGen);

    return rollRandomNum;
}

int AmountToCountAhead()
{
    uniform_int_distribution<int> randomNumber(2, 4);
    int rollRandomNum = randomNumber(rGen);

    return rollRandomNum;
}

// Generates a random protein name
string GenerateRandomName()
{
    // Distributions based off the ASCII codes
    // 65-90 = Upper case alphabet
    // 97-122 = Lower case alphabet
    // 48-57 = 0-9 numbers
    uniform_int_distribution<int> randomUpperCase(65, 90);
    uniform_int_distribution<int> randomLowerCase(97, 122);
    uniform_int_distribution<int> randomNumberAlphabet(48, 57);

    string proteinName;
    char randomChar;

    // Create random protein name
    for (int i = 0; i < 7; i++)
    {
        // Adds a upper case letter for the first letter
        if (i == 0) { randomChar = randomUpperCase(rGen); }
        // Adds a '-'
        else if (i == 4) { randomChar = 45; }
        // Adds two random numbers for the last two chars
        else if (i > 4) { randomChar = randomNumberAlphabet(rGen); }
        // Adds random lower case letters
        else { randomChar = randomLowerCase(rGen); }

        proteinName += randomChar;
    }

    return proteinName;
}

// Shows the two new random proteins on a fresh wiped
// console screen for easier comparing
void CompareProteins(Protein firstProtein, Protein secondProtein)
{

}
