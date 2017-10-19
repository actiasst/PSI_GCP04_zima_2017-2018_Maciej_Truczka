#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tester.h"

class Perceptron {
private: 
	double w[3];
	double x[2];
	double wspolczynnik;
public:
	Perceptron();
	void ustal_wagi(double, double, double);
	void wypisz_wagi();
	void ustal_wejscie(double, double);
	double aktywacja();
	void licz_ext(double, double, double);
	void licz(double, double, double);
	void licz(Subtester);
	void sprawdz(double,double);
	bool sprawdz_bool(double, double);
	double *losuj();
	bool zrob_test();
};