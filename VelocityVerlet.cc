#include "VelocityVerlet.h"

void VelocityVerlet::compute(SolarSystem *planets)
{

    vector<Vector3D> r_i;
    vector<Vector3D> v_i;

    int N = planets->n_corp;
    ofstream fout[N];
    for (int i = 0; i < N; i++)
    {
        string foutName = "Output/All/object" + to_string(i) + ".dat";
        fout[i].open(foutName);
        if (!fout)
            cout << "Errore Lettura" << endl;
    }

    ofstream eout[N];
    for (int i = 0; i < N; i++)
    {
        if (i == Earth || i == Moon || i == Chang)
        {
            string e_foutName = "Output/Earth/e_object" + to_string(i) + ".dat";
            eout[i].open(e_foutName);
            if (!eout)
                cout << "Errore Lettura" << endl;
        }
    }

    ofstream dout;

    string foutName = "Output/Dist/veclocity.txt";
    dout.open(foutName);
    if (!dout)
        cout << "Errore Lettura" << endl;

    for (int k = 0; k < n_steps; k++)
    {
        vector<Vector3D> forza = compute_f_tot(planets); // calcola la f su tutti al tempo 0
        for (int i = 0; i < N; i++)
        {

            fout[i].precision(15);
            if (k % frame_rate == 0)
            {

                fout[i] << k * delta_t << "  " << planets->all_corp[i].p.xv << "  " << planets->all_corp[i].p.yv << "  " << planets->all_corp[i].p.zv << endl;
                // Sposto sistema di riferimento sulla terra
                if (i == Earth || i == Moon || i == Chang)
                {
                    eout[i] << k * delta_t << "  " << planets->all_corp[i].p.xv - planets->all_corp[Earth].p.xv << "  " << planets->all_corp[i].p.yv - planets->all_corp[Earth].p.yv << "  " << planets->all_corp[i].p.zv - planets->all_corp[Earth].p.zv << endl;
                }
            }

            // sottraggo la velocità del centro di massa
            vel_cm(planets);

            Vector3D r_i_1;
            r_i_1.xv = planets->all_corp[i].p.xv + (planets->all_corp[i].v.xv * (delta_t)) + ((forza[i].xv * pow(delta_t, 2)) * (1.0 / (2.0 * planets->all_corp[i].mass)));
            r_i_1.yv = planets->all_corp[i].p.yv + (planets->all_corp[i].v.yv * (delta_t)) + ((forza[i].yv * pow(delta_t, 2)) * (1.0 / (2.0 * planets->all_corp[i].mass)));
            r_i_1.zv = planets->all_corp[i].p.zv + (planets->all_corp[i].v.zv * (delta_t)) + ((forza[i].zv * pow(delta_t, 2)) * (1.0 / (2.0 * planets->all_corp[i].mass)));
            r_i.push_back(r_i_1);
        }

        // calcolo distanza tra sonda e luna
        Vector3D dist(planets->all_corp[11].p.xv - planets->all_corp[4].p.xv,
                      planets->all_corp[11].p.yv - planets->all_corp[4].p.yv,
                      planets->all_corp[11].p.zv - planets->all_corp[4].p.zv);

        dout << k << " " << dist.mod() - moon_radius << endl;

        SolarSystem planets_1; // serve nel ciclo for di dopo
        planets_1.n_corp = planets->n_corp;

        for (int i = 0; i < N; i++)
        {

            SolarSystem::dynamic temp;
            temp.mass = planets->all_corp[i].mass;
            planets_1.all_corp.push_back(temp);
            planets_1.all_corp[i].p.xv = r_i[i].xv;
            planets_1.all_corp[i].p.yv = r_i[i].yv;
            planets_1.all_corp[i].p.zv = r_i[i].zv;
        }

        vector<Vector3D> forza_1 = compute_f_tot(&planets_1); // calcola la f su tutti al tempo 1
        for (int i = 0; i < N; i++)
        {

            Vector3D v_i_1;

            v_i_1.xv = planets->all_corp[i].v.xv + ((forza[i].xv + forza_1[i].xv) * (delta_t / (2.0 * planets->all_corp[i].mass)));
            v_i_1.yv = planets->all_corp[i].v.yv + ((forza[i].yv + forza_1[i].yv) * (delta_t / (2.0 * planets->all_corp[i].mass)));
            v_i_1.zv = planets->all_corp[i].v.zv + ((forza[i].zv + forza_1[i].zv) * (delta_t / (2.0 * planets->all_corp[i].mass)));
            v_i.push_back(v_i_1);

            planets->all_corp[i].v = v_i[i];
            planets->all_corp[i].p = r_i[i];
        }
        r_i.clear();
        v_i.clear();
        forza.clear();
        forza_1.clear();
    }
}

void VelocityVerlet::vel_cm(SolarSystem *planets)
{
    double num_1 = 0.0;
    double num_2 = 0.0;
    double num_3 = 0.0;
    double sum_mass = 0.0;

    for (int i = 0; i < planets->n_corp; i++)
    {
        sum_mass = sum_mass + planets->all_corp[i].mass;
        num_1 = num_1 + (planets->all_corp[i].mass * planets->all_corp[i].v.xv);
        num_2 = num_2 + (planets->all_corp[i].mass * planets->all_corp[i].v.yv);
        num_3 = num_3 + (planets->all_corp[i].mass * planets->all_corp[i].v.zv);
    }
    Vector3D velcm(num_1 / sum_mass, num_2 / sum_mass, num_3 / sum_mass);
    for (int i = 0; i < planets->n_corp; i++)
    {
        planets->all_corp[i].v.xv = planets->all_corp[i].v.xv - velcm.xv;
        planets->all_corp[i].v.yv = planets->all_corp[i].v.yv - velcm.yv;
        planets->all_corp[i].v.zv = planets->all_corp[i].v.zv - velcm.zv;
    }
}