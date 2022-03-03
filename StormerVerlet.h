#ifndef StormerVerlet_H
#define StormerVerlet_H

#include "Analisys.h"


using namespace std;

class StormerVerlet: public Analisys
{
public:
    //calcola le posizioni e le velocità al tempo +1 e le scrive su file
    void compute(SolarSystem *planets) override;

private:

};

#endif