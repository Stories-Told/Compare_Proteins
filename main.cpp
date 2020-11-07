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

    // Delete all link lists
    newProtein01.genAcids.DeleteAllAcidLinkList();

    return 0;
}
