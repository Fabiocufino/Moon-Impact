#include "Analisys.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

vector<Vector3D> Analisys::compute_f_tot(SolarSystem *planets)
{

    vector<Vector3D> f_to;

    double d;
    double dx;
    double dy;
    double dz;

    for (int i = 0; i < planets->n_corp; i++)
    {
        Vector3D f_i;
        f_i.xv = 0.0;
        f_i.yv = 0.0;
        f_i.zv = 0.0;

        for (int j = 0; j < planets->n_corp; j++)
        {
            if (planets->all_corp[i].mass == planets->all_corp[j].mass)
            {
                continue;
            }
            else
            {

                dx = planets->all_corp[j].p.xv - planets->all_corp[i].p.xv;
                dy = planets->all_corp[j].p.yv - planets->all_corp[i].p.yv;
                dz = planets->all_corp[j].p.zv - planets->all_corp[i].p.zv;
                d = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
                f_i.xv = f_i.xv + G * planets->all_corp[i].mass * planets->all_corp[j].mass * dx / pow(d, 3);
                f_i.yv = f_i.yv + G * planets->all_corp[i].mass * planets->all_corp[j].mass * dy / pow(d, 3);
                f_i.zv = f_i.zv + G * planets->all_corp[i].mass * planets->all_corp[j].mass * dz / pow(d, 3);
            }
        }
        f_to.push_back(f_i);
    }
    return f_to;
}
