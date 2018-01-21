#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tester.h"
#include <string>
#include <cmath>

class Perceptron {
private: 
	double w[31];
	double x[31];
	double wspolczynnik;
	double ilosc;
public:
	Perceptron();
	void ustal_wagi();
	void wypisz_wagi();
	void ustal_wejscie(std::string);
	void wypisz_wejscia();
	double aktywacja();
	void licz(bool);
	void zmien_wagi(bool);
	bool sprawdz(Tester,int);
	bool sprawdz_bool(std::string);
};