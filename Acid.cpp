#include <iostream>
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
    // For loop to create 10 acids
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

    countBonds++;
}


void Acid::AddConnections()
{
    aCurrent = aHead;
    while (aCurrent != NULL)
    {
        bool createBond = Utils::CreateAcidBond();
        if (createBond == true)
        {
            aConnectionNode = aCurrent;

            int connectionsToMake = Utils::HowManyConnectionsToMake();
            if (connectionsToMake == 2)
            {
                // First connection
                if (aConnectionNode != NULL)
                {

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
                aCurrent->SetIsTwoConnections(true);
            }
            else if (connectionsToMake == 3)
            {
                // First connection
                if (aConnectionNode != NULL)
                {
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
// into a new linked list (useful so that we don't have to make changes to
// the original linked list)
void Acid::CopyLinkedListContents()
{
    // Set original current to original head (starts from the first node)
    aCurrent = aHead;
    while (aCurrent != NULL)
    {
        bool selectFromLinkedList = Utils::SelectFromLinkedList();
        if (selectFromLinkedList == true)
        {
            // Create new acid instances each loop for the new linked list
            aCurrentNewAcid = new Acid;

            // Takes the data from the original linked list and sets
            // that data to the new acid instances
            aCurrentNewAcid->Setid(aCurrent->Getid());
            aCurrentNewAcid->Setposition(aCurrent->Getposition());


            // creates a new linked list head
            if (aHeadNewAcid == NULL)
            {
                aHeadNewAcid = aCurrentNewAcid;
                aPreviousNewAcid = aCurrentNewAcid;
            }
            // Creates the rest of the new linked list nodes
            else
            {
                aPreviousNewAcid->aSetNext(aCurrentNewAcid);
                aPreviousNewAcid = aPreviousNewAcid->aGetNext();
            }

            //-----------------------------------------------------//

            // Add the bonds for the copied acid
            if (aCurrent->GetIsTwoConnections() == true)
            {
                aCopiedConnectionNode = aCurrentNewAcid;

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
            else if (aCurrent->GetIsThreeConnections() == true)
            {
                aCopiedConnectionNode = aCurrentNewAcid;

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

// Function that displays the original protein data
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

    // Deletes the random protein
    aCurrentNewAcid = aHeadNewAcid;
    while (aCurrentNewAcid != NULL)
    {
        aHeadNewAcid = aCurrentNewAcid->aGetNext();
        delete aCurrentNewAcid;
        aCurrentNewAcid = aHeadNewAcid;
    }
    delete aHeadNewAcid;
}
