#include <iostream>
#include <fstream>
#include "Utils.h"
#include "vec3.h"
#include "Acid.h"

using namespace std;

// Constructor
Acid::Acid()
{
    id = 1;
    position = vec3(1.0, 2.0, 5.4);
    lastX = 0;
    isTwoConnections = false;
    isThreeConnections = false;
    shouldFileClose = false;
    aNext = NULL;
    bondList[0] = NULL;
    bondList[1] = NULL;
    bondList[2] = NULL;
    countBonds = 0;
}

// Deconstructor
Acid::~Acid()
{
    //dtor
}

// Function that creates the orginial protein
// made up of multiple acids that are randomly generated.
// Acids position data is randomly generated for x,y,z
// and stored in a vec3(x,y,z), id of acid is stored as well
void Acid::GenerateOriginalAcidPositions()
{
    // For loop to create 20 acids
    for (int i = 0; i < 20; i++)
    {
        // Create a new acid each loop
        aCurrent = new Acid;

        // Set each acid instance's id and position
        aCurrent->Setid(i);
        aCurrent->Setposition(vec3(Utils::GenerateRandomX() + GetLastX(), Utils::GenerateRandomY(),
            Utils::GenerateRandomZ()));

        // Stores the previous value of x in order to be added to the
        // next acid position. Makes sure that the protein is always
        // going up in value along the x-axis
        SetLastX(aCurrent->Getposition().x);

        // if statement to check if head is NULL
        // meaning if it is NULL then that is the first spot
        // in the linked list and store the first acid there
        if (aHead == NULL)
        {
            aHead = aCurrent;
            aPrevious = aCurrent;
        }
        // After the first loop this else statement will execute
        // where it will move forward to the next link list spot
        else
        {
            aPrevious->aSetNext(aCurrent);
            aPrevious = aPrevious->aGetNext();
        }
    }
}

// Stores instances of Acid inside array linked list
void Acid::AddBond(Acid* acid)
{
    if (countBonds == 0)
    {
        bondList[0] = acid;
    }
    else if (countBonds == 1)
    {
        bondList[1] = acid;
    }
    else
    {
        bondList[2] = acid;
    }

    // Iteriate to the next array block
    countBonds++;
}

// Adds connections to the acids
// Calls AddBond() in order to save connections inside
// an array linked list
void Acid::AddConnections()
{
    aCurrent = aHead;
    while (aCurrent != NULL)
    {
        // Checks to see if a bond will be created
        // based off a random number generator
        bool createBond = Utils::CreateAcidBond();
        if (createBond == true)
        {
            aConnectionNode = aCurrent;

            // Already determined that a bond will be made
            // Now checks to see how many connections that bond will have
            // Based off a random number generator
            int connectionsToMake = Utils::HowManyConnectionsToMake();
            // Rolled for 2 connections
            if (connectionsToMake == 2)
            {
                // First connection
                if (aConnectionNode != NULL)
                {
                    // Checks to see how far ahead in the link this
                    // the connection will be made
                    // based between 2-4 random number generator
                    int countAhead = Utils::AmountToCountAhead();

                    for (int i = 0; i < countAhead; i++)
                    {
                        aConnectionNode = aConnectionNode->aGetNext();
                        if (aConnectionNode == NULL) { break; }
                    }
                    // Stores the connections in a array
                    if (aConnectionNode != NULL)
                    {
                        aCurrent->AddBond(aConnectionNode);
                    }
                }

                // Second connection
                if (aConnectionNode != NULL)
                {
                    // Checks to see how far ahead in the link this
                    // the connection will be made
                    // based between 2-4 random number generator
                    int countAhead = Utils::AmountToCountAhead();

                    for (int i = 0; i < countAhead; i++)
                    {
                        aConnectionNode = aConnectionNode->aGetNext();
                        if (aConnectionNode == NULL) { break; }
                    }
                    // Stores the connections in a array
                    if (aConnectionNode != NULL)
                    {
                        aCurrent->AddBond(aConnectionNode);
                    }
                }
                aCurrent->SetIsTwoConnections(true);
            }
            // Rolled for 3 connections
            else if (connectionsToMake == 3)
            {
                // First connection
                if (aConnectionNode != NULL)
                {
                    // Checks to see how far ahead in the link this
                    // the connection will be made
                    // based between 2-4 random number generator
                    int countAhead = Utils::AmountToCountAhead();

                    for (int i = 0; i < countAhead; i++)
                    {
                        aConnectionNode = aConnectionNode->aGetNext();
                        if (aConnectionNode == NULL) { break; }
                    }

                    if (aConnectionNode != NULL)
                    {
                        aCurrent->AddBond(aConnectionNode);
                    }
                }

                // Second connection
                if (aConnectionNode != NULL)
                {
                    // Checks to see how far ahead in the link this
                    // the connection will be made
                    // based between 2-4 random number generator
                    int countAhead = Utils::AmountToCountAhead();

                    for (int i = 0; i < countAhead; i++)
                    {
                        aConnectionNode = aConnectionNode->aGetNext();
                        if (aConnectionNode == NULL) { break; }
                    }

                    if (aConnectionNode != NULL)
                    {
                        aCurrent->AddBond(aConnectionNode);
                    }
                }

                // third connection
                if (aConnectionNode != NULL)
                {
                    // Checks to see how far ahead in the link this
                    // the connection will be made
                    // based between 2-4 random number generator
                    int countAhead = Utils::AmountToCountAhead();

                    for (int i = 0; i < countAhead; i++)
                    {
                        aConnectionNode = aConnectionNode->aGetNext();
                        if (aConnectionNode == NULL) { break; }
                    }

                    if (aConnectionNode != NULL)
                    {
                        aCurrent->AddBond(aConnectionNode);
                    }
                }
                aCurrent->SetIsThreeConnections(true);
            }
        }

        aCurrent = aCurrent->aGetNext();
    }
}


// Function to copy all the original protein's linked list data
// into a new linked list for the first random acid 
// (useful so that we don't have to make changes to the original linked list)
void Acid::CreateFirstNewAcids()
{
    // Used to give random protein chronological order numbering
    int i = 0;

    // Set original current to original head (starts from the first node)
    aCurrent = aHead;
    while (aCurrent != NULL)
    {
        // Check to see if a selection is made from the original linked list
        // Based off a random number generator
        bool selectFromLinkedList = Utils::SelectFromLinkedList();
        if (selectFromLinkedList == true)
        {
            // Create new acid instances each loop for the new linked list
            aCurrentFirstNew = new Acid;

            // Takes the data from the original linked list and sets
            // that data to the new acid instances
            aCurrentFirstNew->Setid(i);
            aCurrentFirstNew->Setposition(aCurrent->Getposition());

            // creates a new linked list head
            if (aHeadFirstNew == NULL)
            {
                aHeadFirstNew = aCurrentFirstNew;
                aPreviousFirstNew = aCurrentFirstNew;
            }
            // Creates the rest of the new linked list nodes
            else
            {
                aPreviousFirstNew->aSetNext(aCurrentFirstNew);
                aPreviousFirstNew = aPreviousFirstNew->aGetNext();
            }
            // Increase acid numbering by 1
            i++;

            //-----------------------------------------------------//

            // Add the bonds for the copied acid
            // Check if the state of the amount of bonds is 2
            if (aCurrent->GetIsTwoConnections() == true)
            {
                aCopiedConnectionNode = aCurrentFirstNew;

                // First connection
                if (aCopiedConnectionNode != NULL)
                {
                    //aCopiedConnectionNode = aCopiedConnectionNode->aGetNext();
                    if (aCopiedConnectionNode != NULL)
                    {
                        aCopiedConnectionNode->copiedBondList[0] = aCurrent->bondList[0];
                    }
                }

                // Second connection
                if (aCopiedConnectionNode != NULL)
                {
                    //aCopiedConnectionNode = aCopiedConnectionNode->aGetNext();
                    if (aCopiedConnectionNode != NULL)
                    {

                        aCopiedConnectionNode->copiedBondList[1] = aCurrent->bondList[1];
                    }
                }
            }
            // Check if the state of the amount of bonds is 3
            else if (aCurrent->GetIsThreeConnections() == true)
            {
                aCopiedConnectionNode = aCurrentFirstNew;

                // First connection
                if (aCopiedConnectionNode != NULL)
                {
                    if (aCopiedConnectionNode != NULL)
                    {
                        aCopiedConnectionNode->copiedBondList[0] = aCurrent->bondList[0];
                    }
                }

                // Second connection
                if (aCopiedConnectionNode != NULL)
                {
                    if (aCopiedConnectionNode != NULL)
                    {
                        aCopiedConnectionNode->copiedBondList[1] = aCurrent->bondList[1];
                    }
                }

                // Third connection
                if (aCopiedConnectionNode != NULL)
                {
                    if (aCopiedConnectionNode != NULL)
                    {
                        aCopiedConnectionNode->copiedBondList[2] = aCurrent->bondList[2];
                    }
                }
            }
        }
        
        // Iteirate through the original linked list
        aCurrent = aCurrent->aGetNext();
    }

}

// Function to copy all the original protein's linked list data
// into a new linked list for the second random acid 
// (useful so that we don't have to make changes to the original linked list)
void Acid::CreateSecondNewAcids()
{
    // Used to give random protein chronological order numbering
    int i = 0;

    // Set original current to original head (starts from the first node)
    aCurrent = aHead;
    while (aCurrent != NULL)
    {
        bool selectFromLinkedList = Utils::SelectFromLinkedList();
        if (selectFromLinkedList == true)
        {
            // Create new acid instances each loop for the new linked list
            aCurrentSecondNew = new Acid;

            // Takes the data from the original linked list and sets
            // that data to the new acid instances
            aCurrentSecondNew->Setid(i);
            aCurrentSecondNew->Setposition(aCurrent->Getposition());

            // creates a new linked list head
            if (aHeadSecondNew == NULL)
            {
                aHeadSecondNew = aCurrentSecondNew;
                aPreviousSecondNew = aCurrentSecondNew;
            }
            // Creates the rest of the new linked list nodes
            else
            {
                aPreviousSecondNew->aSetNext(aCurrentSecondNew);
                aPreviousSecondNew = aPreviousSecondNew->aGetNext();
            }
            // Increase acid numbering by 1
            i++;

            //-----------------------------------------------------//

            // Add the bonds for the copied acid
            // Check if the state of the amount of bonds is 2
            if (aCurrent->GetIsTwoConnections() == true)
            {
                aCopiedConnectionNode = aCurrentSecondNew;

                // First connection
                if (aCopiedConnectionNode != NULL)
                {
                    //aCopiedConnectionNode = aCopiedConnectionNode->aGetNext();
                    if (aCopiedConnectionNode != NULL)
                    {
                        aCopiedConnectionNode->copiedBondList[0] = aCurrent->bondList[0];
                    }
                }

                // Second connection
                if (aCopiedConnectionNode != NULL)
                {
                    //aCopiedConnectionNode = aCopiedConnectionNode->aGetNext();
                    if (aCopiedConnectionNode != NULL)
                    {

                        aCopiedConnectionNode->copiedBondList[1] = aCurrent->bondList[1];
                    }
                }
            }
            // Check if the state of the amount of bonds is 3
            else if (aCurrent->GetIsThreeConnections() == true)
            {
                aCopiedConnectionNode = aCurrentSecondNew;

                // First connection
                if (aCopiedConnectionNode != NULL)
                {
                    if (aCopiedConnectionNode != NULL)
                    {
                        aCopiedConnectionNode->copiedBondList[0] = aCurrent->bondList[0];
                    }
                }

                // Second connection
                if (aCopiedConnectionNode != NULL)
                {
                    if (aCopiedConnectionNode != NULL)
                    {
                        aCopiedConnectionNode->copiedBondList[1] = aCurrent->bondList[1];
                    }
                }

                // Third connection
                if (aCopiedConnectionNode != NULL)
                {
                    if (aCopiedConnectionNode != NULL)
                    {
                        aCopiedConnectionNode->copiedBondList[2] = aCurrent->bondList[2];
                    }
                }
            }
        }

        // Iteirate through the original linked list
        aCurrent = aCurrent->aGetNext();
    }
}

// Function that displays the original protein data
void Acid::DisplayAcidPosition()
{
    cout << "Acid #: " << id << " at ";
    Getposition().Display();
    cout << "Connections List: " << endl;

    for (int i = 0; i < 3; i++)
    {
        if (bondList[i] != NULL)
        {
            cout << "Bond: " << bondList[i]->Getid() << " ";
            cout << "Position: "; 
            bondList[i]->Getposition().Display();
        }
    }
    cout << "--------" << endl;
}

// Function that displays the random created protein data
void Acid::DisplayCopiedAcidPosition()
{
    cout << "Acid #: " << id << " at ";
    Getposition().Display();
    cout << "Connections List: " << endl;

    for (int i = 0; i < 3; i++)
    {
        if (copiedBondList[i] != NULL)
        {
            cout << "Bond: " << copiedBondList[i]->Getid() << " ";
            cout << "Position: ";
            copiedBondList[i]->Getposition().Display();
        }
    }
    cout << "--------" << endl;
}

void Acid::WriteOutAllAcidData()
{
    // Create variables for the output files
    fstream foutOriginal;
    fstream foutFirstRandom;
    fstream foutSecondRandom;

    // Open the output files to begin writing too
    foutOriginal.open("Position Data Original.txt", ios::out);
    foutFirstRandom.open("Position Data Random One.txt", ios::out);
    foutSecondRandom.open("Position Data Random Two.txt", ios::out);

    // Wrie out original protein data
    aCurrent = aHead;
    while (aCurrent != NULL)
    {
        foutOriginal << "Acid #: " << aCurrent->Getid()
            << " X: " << aCurrent->Getposition().x
            << " Y: " << aCurrent->Getposition().y
            << " Z: " << aCurrent->Getposition().z << endl;

        for (int i = 0; i < 3; i++)
        {
            if (aCurrent->bondList[i] != NULL)
            {
                foutOriginal << "Bond: " << aCurrent->bondList[i]->Getid() << " ";
                foutOriginal << "Position: "
                    << "X: " << aCurrent->bondList[i]->Getposition().x
                    << "Y: " << aCurrent->bondList[i]->Getposition().y
                    << "Z: " << aCurrent->bondList[i]->Getposition().z
                    << endl;
            }
        }
        foutOriginal << "--------" << endl;

        aCurrent = aCurrent->aGetNext();
    }

    // Write out first random protein data
    aCurrentFirstNew = aHeadFirstNew;
    while (aCurrentFirstNew != NULL)
    {
        foutFirstRandom << "Acid #: " << aCurrentFirstNew->Getid()
            << " X: " << aCurrentFirstNew->Getposition().x
            << " Y: " << aCurrentFirstNew->Getposition().y
            << " Z: " << aCurrentFirstNew->Getposition().z << endl;

        for (int i = 0; i < 3; i++)
        {
            if (aCurrentFirstNew->copiedBondList[i] != NULL)
            {
                foutFirstRandom << "Bond: " << aCurrentFirstNew->copiedBondList[i]->Getid() << " ";
                foutFirstRandom << "Position: "
                    << "X: " << aCurrentFirstNew->copiedBondList[i]->Getposition().x
                    << "Y: " << aCurrentFirstNew->copiedBondList[i]->Getposition().y
                    << "Z: " << aCurrentFirstNew->copiedBondList[i]->Getposition().z
                    << endl;
            }
        }
        foutFirstRandom << "--------" << endl;

        aCurrentFirstNew = aCurrentFirstNew->aGetNext();
    }

    // Write out Second random protein data
    aCurrentSecondNew = aHeadSecondNew;
    while (aCurrentSecondNew != NULL)
    {
        foutSecondRandom << "Acid #: " << aCurrentSecondNew->Getid()
            << " X: " << aCurrentSecondNew->Getposition().x
            << " Y: " << aCurrentSecondNew->Getposition().y
            << " Z: " << aCurrentSecondNew->Getposition().z << endl;

        for (int i = 0; i < 3; i++)
        {
            if (aCurrentSecondNew->copiedBondList[i] != NULL)
            {
                foutSecondRandom << "Bond: " << aCurrentSecondNew->copiedBondList[i]->Getid() << " ";
                foutSecondRandom << "Position: "
                    << "X: " << aCurrentSecondNew->copiedBondList[i]->Getposition().x
                    << "Y: " << aCurrentSecondNew->copiedBondList[i]->Getposition().y
                    << "Z: " << aCurrentSecondNew->copiedBondList[i]->Getposition().z
                    << endl;
            }
        }
        foutSecondRandom << "--------" << endl;

        aCurrentSecondNew = aCurrentSecondNew->aGetNext();
    }

    // Close all files
    foutOriginal.close();
    foutFirstRandom.close();
    foutSecondRandom.close();
}

// Function to delete all the linked lists
void Acid::DeleteAllAcidLinkList()
{
    // Deletes the original linked lists
    aCurrent = aHead;
    while (aCurrent != NULL)
    {
        aHead = aCurrent->aGetNext();
        delete aCurrent;
        aCurrent = aHead;
    }
    delete aHead;

    // Deletes the first random protein
    aCurrentFirstNew = aHeadFirstNew;
    while (aCurrentFirstNew != NULL)
    {
        aHeadFirstNew = aCurrentFirstNew->aGetNext();
        delete aCurrentFirstNew;
        aCurrentFirstNew = aHeadFirstNew;
    }
    delete aHeadFirstNew;

    // Deletes the second random protein
    aCurrentSecondNew = aHeadSecondNew;
    while (aCurrentFirstNew != NULL)
    {
        aHeadSecondNew = aCurrentSecondNew->aGetNext();
        delete aCurrentSecondNew;
        aCurrentSecondNew = aHeadSecondNew;
    }
    delete aHeadSecondNew;
}
