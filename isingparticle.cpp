#include <iostream>
#include <cmath>
#include "isingparticle.h"

using namespace std;

IsingParticle::IsingParticle() { spin = 1; }
void IsingParticle::flipSpin() { spin = -spin; }
int IsingParticle::spinValue() const { return spin; }
