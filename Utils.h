#ifndef Utils
#define Utils

#include "Protein.h"
#include "Utils.h"

double GenerateRandomX();
double GenerateRandomY();
double GenerateRandomZ();

bool SelectFromLinkedList();
bool CreateAcidBond();
int HowManyConnectionsToMake();

std::string GenerateRandomName();

void CompareProteins(Protein firstProtein, Protein secondProtein);

#endif // Utils

