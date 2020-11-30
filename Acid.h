#ifndef ACID_H
#define ACID_H

#include "vec3.h"
#include <cstddef>

class Acid
{
public:
    // Linked List pointers
    // Link lists that hold vec3(x,y,z) values and acid id
    Acid* acid;
    Acid* aNext;
    Acid* bondList[2];
    Acid* copiedBondList[2];
    
    // Original protein linked list
    Acid* aHead = NULL;
    Acid* aCurrent = NULL;
    Acid* aPrevious = NULL;
    Acid* aConnectionNode = NULL;

    // Random protein creation linked list
    Acid* aHeadNewAcid = NULL;
    Acid* aCurrentNewAcid = NULL;
    Acid* aPreviousNewAcid = NULL;
    Acid* aCopiedConnectionNode = NULL;

    // Counter for acid connections
    int countBonds;

    Acid();
    virtual ~Acid();

    // ----- Gets and Sets ------ //

    vec3 Getposition() { return position; }
    void Setposition(vec3 val) { position = val; }

    int Getid() { return id; }
    void Setid(int val) { id = val; }

    double GetLastX() { return lastX; }
    void SetLastX(double val) { lastX = val; }

    bool GetIsTwoConnections() { return isTwoConnections; }
    void SetIsTwoConnections(bool val) { isTwoConnections = val; }

    bool GetIsThreeConnections() { return isThreeConnections; }
    void SetIsThreeConnections(bool val) { isThreeConnections = val; }

    Acid* aGetNext() { return aNext; }
    void aSetNext(Acid* h) { aNext = h; }

    // ----- Functions ----- //

    void GenerateOriginalAcidPositions();
    void AddBond(Acid* acid);
    void AddConnections();
    void CopyLinkedListContents();
    void DisplayAcidPosition();
    void DisplayCopiedAcidPosition();
    void DeleteAllAcidLinkList();

private:
    vec3 position;
    int id;
    double lastX;

    bool isTwoConnections;
    bool isThreeConnections;
};

#endif // ACID_H


