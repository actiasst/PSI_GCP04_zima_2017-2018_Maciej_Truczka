#include "Neuron.h"

Neuron::Neuron() {
	wspolczynnik = 0.5;
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		w[i] = ((rand() % 21) - 10) / 10.;
		x[i] = 0;
	}
	x[4] = 1;
}

Neuron::Neuron(std::string tmp) {
	wspolczynnik = 2.3;
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		w[i] = ((rand() % 21) - 10) / 10.;
		x[i] = 0;
	}
	nazwa = tmp;
}

void Neuron::wypisz(){
	std::cout << nazwa << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << "X" << i + 1 << " " << x[i] << " waga " << w[i] << std::endl;
	std::cout<<std::endl;
}

void Neuron::ustaw_wektor(double* tab) {
	x[0] = tab[0];
	x[1] = tab[1];
	x[2] = tab[2];
	x[3] = tab[3];
}

double Neuron::aktywacja() {
	double tmp = 0;
	for (int i = 0; i < 4; i++)
		tmp += (x[i] - w[i])*(x[i] - w[i]);
	return 1/sqrt(tmp);
}

void Neuron::uaktualnij_wagi() {
	for (int i = 0; i < 4; i++)
		w[i] += wspolczynnik*(x[i] - w[i]);
}

void Neuron::zmniejsz_wspolczynnik() {
	wspolczynnik -= 0.01;
}