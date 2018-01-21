#include "Perceptron.h";

Perceptron::Perceptron(){
	wspolczynnik = 1.0;
	ilosc = 31;
	x[0] = 1.;
}

void Perceptron::ustal_wagi() {
	srand(time(NULL));
	for(int i = 0; i < ilosc; i++)
	w[i] = ((std::rand() % 20) - 10) / 10.;
}

void Perceptron::wypisz_wagi() {
	for (int i = 0; i < ilosc; i++)
		std::cout << "waga " << i + 1 << " = " << w[i] << std::endl;
}

void Perceptron::wypisz_wejscia() {
	for (int i = 0; i < ilosc; i++)
		std::cout << "wejscie " << i + 1 << " = " << x[i] << std::endl;
}

void Perceptron::ustal_wejscie(std::string tmp) {
	for (int i = 1; i < ilosc; i++)
		x[i] = tmp.at(i - 1) - 48;
}

double Perceptron::aktywacja() {
	double tmp = 0.;
	for (int i = 0; i < ilosc; i++)
		tmp += w[i] * x[i];
	tmp = 1. / (1. + exp(-tmp));
	//std::cout << tmp << std::endl;
	return tmp;
}

void Perceptron::zmien_wagi(bool tmp) {
	if (tmp == true)
		for (int i = 0; i < ilosc; i++)
			w[i] += x[i] * wspolczynnik;
	else
		for (int i = 0; i < ilosc; i++)
			w[i] -= x[i] * wspolczynnik;
}

void Perceptron::licz(bool tmp) {
	if (aktywacja() >= 0.9 && tmp == false)
		zmien_wagi(false);
	else if (aktywacja() <= 0.9 && tmp == true)
		zmien_wagi(true);
}

bool Perceptron::sprawdz(Tester test, int tmp) {
	for (int i = 0; i < 5; i++) {
		if (tmp == i)
			continue;
		if (sprawdz_bool(test.tab[i]) == true)
			return false;
	}
	if (sprawdz_bool(test.tab[tmp]) == false)
		return false;
	return true;
}

bool Perceptron::sprawdz_bool(std::string tmp) {
	ustal_wejscie(tmp);
	if (aktywacja() >= 0.9)
		return true;
	else
		return false;
}