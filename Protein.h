#ifndef PROTEIN_H
#define PROTEIN_H

#include "Acid.h"

class Protein
{
public:
    // Acid class accessor
    // Allows us a variable that has access to the
    // Acid class
    Acid genAcids;

    // ----- Gets and Sets -----
    Protein();
    virtual ~Protein();

    std::string Getname() { return name; }
    void Setname(std::string val) { name = val; }

    // ----- Functions -----
    void CreateOriginalProtein();
    void CreateRandomProtein();

private:
    std::string name;

};

#endif // PROTEIN_H

