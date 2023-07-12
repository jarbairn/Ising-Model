#pragma once
#define ISINGSIZE 16
#include "isingparticle.h"
#ifndef STATISTICS_H
#define STATISTICS_H

class statistics {
private:
	int n;
	double sum;
	double sumsq;
	double varsq;
	double var;
public:
	statistics();
	int getNumber() const;
	double getAverage() const;
	double getSqAverage() const;
	void add(double x);
	double getVarSq() const;
	double getVar() const;
};
#endif