#pragma once
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>

class Dane {
private:
	double dane[150][5];
public:
	Dane();
	void wypisz();
	double* zwroc_wektor(int);
	void wektoryzuj();
};