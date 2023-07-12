#include <iostream>
#include <cmath>
#include "isingsystem.h"
#include "isingparticle.h"

using namespace std;

IsingSystem::IsingSystem()
{
    current_column = 0;
    current_row = 0;
    printf("fuck you bloodshed\n\n");
}
void IsingSystem::choose()
{
    current_row = rand() % ISINGSIZE;
    current_column = rand() % ISINGSIZE;
    //cout << "("<<current_column<< ","<<current_row<<")"<<endl;
}
void IsingSystem::perturb()
{
    //cout << "Spin initially is: "<<particles[current_column][current_row].spinValue() << endl;
    particles[current_column][current_row].flipSpin();
    //cout << "Spin finally is: "<<particles[current_column][current_row].spinValue() << endl; 
}
void IsingSystem::print()
{
    int j, k;
    for (j = 0; j < ISINGSIZE; j++)
    {
        for (k = 0; k < ISINGSIZE; k++)
        {
            if (particles[j][k].spinValue() > 0)
            {
                printf("+");
            }
            else printf("-");
        }
        printf("\n");
    }
}
void IsingSystem::find_neighbours()
{
    left_column = current_column - 1;
    if (left_column < 0)
    {
        left_column = ISINGSIZE - 1;
    }
    right_column = current_column + 1;
    if (right_column == ISINGSIZE)
    {
        right_column = 0;
    }
    up_row = current_row - 1;
    if (up_row < 0)
    {
        up_row = ISINGSIZE - 1;
    }
    down_row = current_row + 1;
    if (down_row == ISINGSIZE)
    {
        down_row = 0;
    }
}
double IsingSystem::localEnergy()
{
    double up_energy;
    double down_energy;
    double right_energy;
    double left_energy;
    double LE;
    find_neighbours();
    if (particles[current_column][current_row].spinValue() == particles[current_column][up_row].spinValue())
    {
        up_energy = -1;
    }
    else up_energy = 1;
    if (particles[current_column][current_row].spinValue() == particles[current_column][down_row].spinValue())
    {
        down_energy = -1;
    }
    else down_energy = 1;
    if (particles[current_column][current_row].spinValue() == particles[left_column][current_row].spinValue())
    {
        left_energy = -1;
    }
    else left_energy = 1;
    if (particles[current_column][current_row].spinValue() == particles[right_column][current_row].spinValue())
    {
        right_energy = -1;
    }
    else right_energy = 1;

    LE = up_energy + down_energy + right_energy + left_energy;
    return LE;
}
double IsingSystem::magnetisation()
{
    int x, y;
    double spin_i = 0;
    double N_s = ISINGSIZE * ISINGSIZE;
    double M;
    for (x = 0; x < ISINGSIZE; x++)
    {
        for (y = 0; y < ISINGSIZE; y++)
        {
            spin_i += particles[x][y].spinValue();
        }
    }
    spin_i = abs(spin_i);
    M = spin_i / N_s;
    return M;
}
double IsingSystem::totalEnergy()
{
    int J = 1;
    double S_i = 0;
    double TE = 0;

    for (current_column = 0; current_column < ISINGSIZE; current_column++)
    {
        for (current_row = 0; current_row < ISINGSIZE; current_row++)
        {
            S_i += localEnergy();
        }
    }

    TE = ((J)*S_i) / 2;
    return TE;
}