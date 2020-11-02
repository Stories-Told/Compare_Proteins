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
void Protein::CreateRandomProtein()
{
    // Variable that calls function to generate
    // a random protein name
    name = Utils::GenerateRandomName();
    cout << "Copied Protein Name: " << name << endl;

    genAcids.CopyLinkedListContents();
    genAcids.aCurrentNewAcid = genAcids.aHeadNewAcid;
    while (genAcids.aCurrentNewAcid != NULL)
    {
        genAcids.aCurrentNewAcid->DisplayAcidPosition();
        genAcids.aCurrentNewAcid = genAcids.aCurrentNewAcid->aGetNext();
    }
}