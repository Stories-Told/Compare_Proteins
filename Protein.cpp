#include <iostream>
#include <string>
#include "Utils.h"
#include "Acid.h"
#include "Protein.h"

using namespace std;

Protein::Protein()
{
    name = "Default";
}

Protein::~Protein()
{
    //dtor
}

// Creates the original protein for further random proteins
// to be made from the position data stored in this instance's
// linked list
void Protein::CreateOriginalProtein()
{
    // Variable that calls function to generate
    // a random protein name
    name = Utils::GenerateRandomName();
    cout << "Protein Name: " << name << endl;

    // Functions called from the acid class to
    // create and display the protein
    genAcids.GenerateOriginalAcidPositions();
    genAcids.AddConnections();

    genAcids.aCurrent = genAcids.aHead;
    while (genAcids.aCurrent != NULL)
    {
        genAcids.aCurrent->DisplayAcidPosition();
        genAcids.aCurrent = genAcids.aCurrent->aGetNext();
    }
}

// Takes random acid positions from the original protein
// and creates a new protein
void Protein::CreateFirstRandomProtein()
{
    // Variable that calls function to generate
    // a random protein name
    name = Utils::GenerateRandomName();
    cout << "Random Protein Name: " << name << endl;

    genAcids.CreateFirstNewAcids();

    genAcids.aCurrentFirstNew = genAcids.aHeadFirstNew;
    while (genAcids.aCurrentFirstNew != NULL)
    {
        genAcids.aCurrentFirstNew->DisplayCopiedAcidPosition();
        genAcids.aCurrentFirstNew = genAcids.aCurrentFirstNew->aGetNext();
    }
}

// Takes random acid positions from the original protein
// and creates a new protein
void Protein::CreateSecondRandomProtein()
{
    // Variable that calls function to generate
    // a random protein name
    name = Utils::GenerateRandomName();
    cout << "Random Protein Name: " << name << endl;

    genAcids.CreateSecondNewAcids();

    genAcids.aCurrentSecondNew = genAcids.aHeadSecondNew;
    while (genAcids.aCurrentSecondNew != NULL)
    {
        genAcids.aCurrentSecondNew->DisplayCopiedAcidPosition();
        genAcids.aCurrentSecondNew = genAcids.aCurrentSecondNew->aGetNext();
    }
}

// Writes out the data of all the proteins in a side by side manner
void Protein::WriteOutData()
{
    genAcids.WriteOutAllAcidData();
}

