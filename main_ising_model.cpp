#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include "isingparticle.h"
#include "isingsystem.h"
#include "statistics.h"
//#define _CRT_SECURE_NO_WARNINGS
//#define _AFX_SECURE_NO_WARNINGS
//#define _ATL_SECURE_NO_WARNINGS

using namespace std;


int main(void)
{
	printf("fuck you bloodshed\n\n");
	IsingSystem particle1;
	cout << "Magnetisation initially is: " << particle1.magnetisation() << endl;
	cout << "Total energy initially is: " << particle1.totalEnergy() << endl;

	printf("\n");

	ofstream outfile("heatcapacityerr8check.csv");
	if (!outfile)
	{
		cerr << "error: unable to open file" << endl;
	}

	double T = 0.01;
	int N_MCS = 0;
	int N_MAX = 1000000;//number of Monte Carlo Simulations
	int N_S = ISINGSIZE * ISINGSIZE;
	double Cv = 0;
	double r = 0;
	double mag_err = 0;
	double Cv_err = 0;
	double E_i = 0;
	double E_i_err = 0;
	double E_i_sq = 0;
	double E_i_sq_err = 0;

	//METROPOLIS ALGORITHM

	for (T = 0.01; T <= 8; T += 0.01)
	{
		statistics mag;

		for (N_MCS = 0; N_MCS <= N_MAX; N_MCS++)
		{
			r = (double)rand() / RAND_MAX;
			particle1.choose();
			particle1.perturb();
			particle1.perturb();
			double dE = -2 * (particle1.localEnergy());
			if (r < exp((-dE) / T))
			{
				particle1.perturb();
			}
			if (N_MCS > (N_MAX / 2) && N_MCS % N_S == 0)
			{
				//mag.add(particle1.magnetisation());
				mag.add(particle1.totalEnergy());
				E_i_err = mag.getVar();
				E_i_sq_err = mag.getVarSq();
			}
			//if (N_MCS % 100000 == 0) { printf("100000 done\n\n"); }
		}
		printf("%lf\n\n", T);

		Cv = ((mag.getSqAverage() - (mag.getAverage() * mag.getAverage())) / ((double)N_S * (T * T)));
		Cv_err = sqrt((E_i_err * E_i_err) + (E_i_sq_err * E_i_sq_err)) / sqrt(mag.getNumber());
		//mag_err = (sqrt(mag.getSqAverage() - (mag.getAverage())*(mag.getAverage())))/sqrt(mag.getNumber());

		//printf("T: %lf Cv is: %lf  Error attempt is: %lf\n", T, Cv, Cv_err);

		outfile << T << "," << Cv << "," << Cv_err << endl;
	}

	printf("\n");

	outfile.close();
	system("pause");
	return 0;
}