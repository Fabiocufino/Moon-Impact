#include "SolarSystem.h"

#include <iostream>

using namespace std;


void SolarSystem::ReadInitialData(std::string &name)
{
    file = new ifstream(name.c_str());

    *file >> n_corp;

    // inizializzo il vettore
    for (int i = 0; i < n_corp; i++)
    {
        SolarSystem::dynamic *temp = new SolarSystem::dynamic;
        *file >> temp->mass;
        *file >> temp->p.xv >> temp->p.yv >> temp->p.zv;
        *file >> temp->v.xv >> temp->v.yv >> temp->v.zv;
    

        all_corp.push_back(*temp);
        delete temp;
    }
}
