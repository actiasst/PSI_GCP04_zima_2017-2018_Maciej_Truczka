#include "Dane.h"

Dane::Dane() {
	std::fstream plik;
	plik.open("plik.txt", std::ios::in);
	std::string tmp;
	for (int i = 0; i < 150; i++) {
		std::getline(plik, tmp, ',');
		dane[i][0] = stod(tmp);
		std::getline(plik, tmp, ',');
		dane[i][1] = stod(tmp);
		std::getline(plik, tmp, ',');
		dane[i][2] = stod(tmp);
		std::getline(plik, tmp, ',');
		dane[i][3] = stod(tmp);
		std::getline(plik, tmp);
		if (tmp == "Iris-setosa")
			dane[i][4] = 1;
		else if(tmp == "Iris-versicolor")
			dane[i][4] = 2;
		else if(tmp == "Iris-virginica")
			dane[i][4] = 3;
	}
	plik.close();
}

void Dane::wypisz() {
	for (int i = 0; i < 150; i++)
		std::cout << dane[i][0] << " " << dane[i][1] << " " << dane[i][2] << " " << dane[i][3] << " " << dane[i][4] << std::endl;
}

double* Dane::zwroc_wektor(int tmp) {
	double* tab = new double[4];
	tab[0] = dane[tmp][0];
	tab[1] = dane[tmp][1];
	tab[2] = dane[tmp][2];
	tab[3] = dane[tmp][3];
	return tab;
}

void Dane::wektoryzuj() {
	double suma = 0;
	for (int i = 0; i < 150; i++) {
		suma = pow(dane[i][0], 2) + pow(dane[i][1], 2) + pow(dane[i][2], 2) + pow(dane[i][3], 2);
		suma = sqrt(suma);
		dane[i][0] /= suma;
		dane[i][1] /= suma;
		dane[i][2] /= suma;
		dane[i][3] /= suma;
		suma = 0;
	}
}