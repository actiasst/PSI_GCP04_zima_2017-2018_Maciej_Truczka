#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>

class Neuron {
private:
	double wspolczynnik;
	double w[4];
	double x[4];
	std::string nazwa;
public:
	Neuron();
	Neuron(std::string);
	void wypisz();
	void ustaw_wektor(double*);
	double aktywacja();
	void uaktualnij_wagi();
	void zmniejsz_wspolczynnik();
};