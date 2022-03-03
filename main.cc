#include "Vector3D.h"
#include "SolarSystem.h"
#include "VelocityVerlet.h"
#include "StormerVerlet.h"

#include <iostream>

using namespace std;
int main(int argv, char *argc[])
{
    string analisi = argc[1];
    
    if (analisi == "velocity")
    {
        string name1 = "Input/earth_initial_data.txt";
        SolarSystem planets_earth;
        planets_earth.ReadInitialData(name1);
        VelocityVerlet velver_earth;
        velver_earth.compute(&planets_earth);
    }

    if (analisi == "stormer")
    {
        string name1 = "Input/earth_initial_data.txt";
        SolarSystem planets_earth;
        planets_earth.ReadInitialData(name1);
        StormerVerlet stormer_earth;
        stormer_earth.compute(&planets_earth);
    }

    return 0;
}
