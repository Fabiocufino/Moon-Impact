#include "StormerVerlet.h"

void StormerVerlet::compute(SolarSystem *planets)
{

    vector<Vector3D> r_1;
    vector<Vector3D> r_n1;

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

    string foutName = "Output/Dist/stormer.txt";
    dout.open(foutName);
    if (!dout)
        cout << "Errore Lettura" << endl;

    vector<Vector3D> forza_0 = compute_f_tot(planets); // calcola la f su tutti al tempo 0
    for (int i = 0; i < N; i++)
    {
        // a questo punto ho già la posizione al tempo 0
        // Calcolo la posizione al tempo 1, conseguentemente userò queste ultime per calcolare la posizione al tempo 2
        Vector3D r_i_1;
        r_i_1.xv = planets->all_corp[i].p.xv + (planets->all_corp[i].v.xv * (delta_t)) + ((forza_0[i].xv * pow(delta_t, 2)) * (1.0 / (2.0 * planets->all_corp[i].mass)));
        r_i_1.yv = planets->all_corp[i].p.yv + (planets->all_corp[i].v.yv * (delta_t)) + ((forza_0[i].yv * pow(delta_t, 2)) * (1.0 / (2.0 * planets->all_corp[i].mass)));
        r_i_1.zv = planets->all_corp[i].p.zv + (planets->all_corp[i].v.zv * (delta_t)) + ((forza_0[i].zv * pow(delta_t, 2)) * (1.0 / (2.0 * planets->all_corp[i].mass)));

        r_1.push_back(r_i_1);
    }

    for (int k = 0; k < n_steps; k++)
    {
        SolarSystem planets_n; // serve nel ciclo for di dopo
        planets_n.n_corp = planets->n_corp;

        for (int i = 0; i < N; i++)
        {
            SolarSystem::dynamic temp;
            temp.mass = planets->all_corp[i].mass;
            planets_n.all_corp.push_back(temp);
            planets_n.all_corp[i].p.xv = r_1[i].xv;
            planets_n.all_corp[i].p.yv = r_1[i].yv;
            planets_n.all_corp[i].p.zv = r_1[i].zv;
        }
        // calcolo distanza tra sonda e luna
        Vector3D dist(planets->all_corp[11].p.xv - planets->all_corp[4].p.xv,
                      planets->all_corp[11].p.yv - planets->all_corp[4].p.yv,
                      planets->all_corp[11].p.zv - planets->all_corp[4].p.zv);

        dout << k << " " << dist.mod() - moon_radius << endl;

        vector<Vector3D> forza_n = compute_f_tot(&planets_n); // calcola la f su tutti al tempo 1
        for (int i = 0; i < N; i++)
        {

            Vector3D r_i_n1;
            r_i_n1.xv = 2 * r_1[i].xv - planets->all_corp[i].p.xv + ((forza_n[i].xv * pow(delta_t, 2)) / planets->all_corp[i].mass);
            r_i_n1.yv = 2 * r_1[i].yv - planets->all_corp[i].p.yv + ((forza_n[i].yv * pow(delta_t, 2)) / planets->all_corp[i].mass);
            r_i_n1.zv = 2 * r_1[i].zv - planets->all_corp[i].p.zv + ((forza_n[i].zv * pow(delta_t, 2)) / planets->all_corp[i].mass);

            r_n1.push_back(r_i_n1);

            fout[i].precision(15);
            if (k % frame_rate == 0)
            {
                fout[i] << k * delta_t << "  " << r_i_n1.xv << "  " << r_i_n1.yv << "  " << r_i_n1.zv << endl;
                // Sposto sistema di riferimento sulla terra
                if (i == Earth || i == Moon || i == Chang)
                {
                    eout[i] << k * delta_t << "  " << planets->all_corp[i].p.xv - planets->all_corp[Earth].p.xv << "  " << planets->all_corp[i].p.yv - planets->all_corp[Earth].p.yv << "  " << planets->all_corp[i].p.zv - planets->all_corp[Earth].p.zv << endl;
                }
            }

            planets->all_corp[i].p = r_1[i];
            r_1[i] = r_n1[i];
        }
        r_1.clear();
        r_n1.clear();
        forza_0.clear();
        forza_n.clear();
    }
}
