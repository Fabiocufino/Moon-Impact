#ifndef Analisys_H
#define Analisys_H

#include "SolarSystem.h"
#include "Vector3D.h"

#include <math.h>

using namespace std;

//base class
class Analisys
{
public:
    const double G = 6.67292 * pow(10, -20);  //un fattore di 0.00032 
    // 30 sono 3900 km
    // 33 sono 30000 km 
    // 29 sono 600km, più preciso stormer
    // 28 sono 12000km, più preciso verlet
    // 6.67287 sono 4600 più preciso verlet
    // 6.67292 sono 290 più preciso stormer

    const double moon_radius = 1737.400;

    double n_steps = 200 * 10000;
    int frame_rate = 10000/24; 
    double delta_t = 86400 / 10000; 

    enum corps
    {
        Sun,
        Mercury,
        Venus,
        Earth,
        Moon,
        Mars,
        Jupiter,
        Saturn,
        Uranus,
        Neptune,
        Pluto,
        Chang
    };

    virtual void compute(SolarSystem *planets) = 0;

//private:
    // Calcola la forza che tutti i pianeti esercitano su uno, e la mette in un vettore.
    vector<Vector3D> compute_f_tot(SolarSystem *planets);


    //// Energia
    // double calcolo_energ_potenziale(DataContainer solar, vector<vect> all_plan_r)
    //{
    //     double en_pot = 0.;
    //     for (int i = 0; i < all_plan_r.size(); i++)
    //     {
    //         for (int j = 0; i < all_plan_r.size(); i++)
    //         {
    //             if (i != j)
    //             {
    //                 double dist = sqrt(pow((all_plan_r[i].vec1 - all_plan_r[j].vec1), 2) + pow((all_plan_r[i].vec2 - all_plan_r[j].vec2), 2) + pow((all_plan_r[i].vec3 - all_plan_r[j].vec3), 2));
    //                 en_pot = en_pot - 6.67 * pow(10, -11) * (solar.mass[i] * solar.mass[j]) / dist;
    //             }
    //         }
    //     }
    //     return en_pot;
    // }
    // double calcolo_energ_cin(DataContainer solar, vector<vect> all_plan_v)
    //{
    //     double en_cin = 0.;
    //     for (int i = 0; i < all_plan_v.size(); i++)
    //     {
    //         double vel = sqrt(pow(all_plan_v[i].vec1, 2) + pow(all_plan_v[i].vec2, 2) + pow(all_plan_v[i].vec3, 2));
    //         en_cin = en_cin + ((1. / 2.) * solar.mass[i] * pow(vel, 2));
    //     };
    //     return en_cin;
    // }
};

#endif