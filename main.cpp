#include <iostream>
#include "Acid.h"
#include "Protein.h"
#include "vec3.h"
#include "Utils.h"

using namespace std;

int main()
{
    // Protein 01
    cout << "PROTEIN 01" << endl;
    Protein newProtein01;
    newProtein01.CreateOriginalProtein();
    cout << endl;
    newProtein01.CreateRandomProtein();
    cout << endl;

    // Protein 02
    cout << "PROTEIN 02" << endl;
    Protein newProtein02;
    newProtein02.CreateOriginalProtein();
    cout << endl;
    newProtein02.CreateRandomProtein();

    // Compares the two non-original random proteins
    //CompareProteins(newProtein01, newProtein02);

    // Delete all link lists
    newProtein01.genAcids.DeleteAllAcidLinkList();
    newProtein02.genAcids.DeleteAllAcidLinkList();

    return 0;
}
