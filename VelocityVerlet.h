#ifndef VelocityVerlet_H
#define VelocityVerlet_H

#include "Analisys.h"

using namespace std;

class VelocityVerlet : public Analisys
{
public:
    // calcola le posizioni e le velocità al tempo +1 e le scrive su file
    void compute(SolarSystem *planets) override;
    
private:
    // va calcolata solamente qui che serve la velocità, e va calcolate per ogni passo.
    void vel_cm(SolarSystem *planets);
};

#endif