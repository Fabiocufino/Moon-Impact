#ifndef SolarSystem_h
#define SolarSystem_h

#include <string>
#include <vector>
#include <fstream>
#include "Vector3D.h"

class SolarSystem
{
public:
    struct dynamic
    {
        double mass;
        Vector3D p;
        Vector3D v;
    };

    std::vector<dynamic> all_corp;
    int n_corp;

    // Read and set initial data
    std::ifstream *file;
    void ReadInitialData(std::string &file);

private:
};

#endif