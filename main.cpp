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

    // Create a new Protein instance
    // and create the original protein made up of acids
    Protein newProtein01;
    newProtein01.CreateOriginalProtein();
    cout << endl;

    // Create the first random protein originating from the
    // original protein
    newProtein01.CreateFirstRandomProtein();
    cout << endl;

    // Create the second random protein originating from the
    // original protein
    newProtein01.CreateSecondRandomProtein();
    cout << endl;

    // Writes all data out to file
    newProtein01.WriteOutData();

    // Delete all link lists
    newProtein01.genAcids.DeleteAllAcidLinkList();

    return 0;
}
