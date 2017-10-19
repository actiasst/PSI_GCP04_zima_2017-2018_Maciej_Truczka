#include "Perceptron.h";

Perceptron::Perceptron(){
	w[0] = 0;
	w[1] = 0;
	w[2] = 0;

	x[0] = 0;
	x[1] = 0;
	wspolczynnik = 1.0;
}

void Perceptron::ustal_wagi(double w1, double w2, double w3) {
	w[0] += w1;
	w[1] += w2;
	w[2] += w3;
}

void Perceptron::wypisz_wagi() {
	std::cout << "Waga 1 = " << w[0] << std::endl;
	std::cout << "Waga 2 = " << w[1] << std::endl;
	std::cout << "Waga 3 = " << w[2] << std::endl << std::endl;
}

void Perceptron::ustal_wejscie(double x1, double x2) {
	x[0] = x1;
	x[1] = x2;
}

double Perceptron::aktywacja() {
	return w[0] + w[1] * x[0] + w[2] * x[1];
}

void Perceptron::licz_ext(double x1, double x2, double oczekiwany_wynik) {
	double obecny_wynik;
	ustal_wejscie(x1, x2);
	std::cout << "oczekiwany wynik: " << oczekiwany_wynik << std::endl;
	std::cout << "x1: " << x[0] << std::endl << "x2: " << x[1] << std::endl;
	std::cout << "aktywacja: " << aktywacja() << std::endl;
	if (aktywacja() >= 0)
		obecny_wynik = 1;
	else
		obecny_wynik = 0;
	std::cout << "obecny wynik:" << obecny_wynik << std::endl;

	if (obecny_wynik > oczekiwany_wynik) {
		std::cout << "zmniejszam wagi" << std::endl;
		ustal_wagi(-1*wspolczynnik, -x[0]*wspolczynnik, -x[1]*wspolczynnik);
	}
	else if (obecny_wynik < oczekiwany_wynik) {
		std::cout << "zwiekszam wagi" << std::endl;
		ustal_wagi(1 * wspolczynnik, x[0] * wspolczynnik, x[1] * wspolczynnik);
	}
}

void Perceptron::licz(double x1, double x2, double oczekiwany_wynik) {
	double obecny_wynik;
	ustal_wejscie(x1, x2);
	if (aktywacja() >= 0)
		obecny_wynik = 1;
	else
		obecny_wynik = 0;

	if (obecny_wynik > oczekiwany_wynik)
		ustal_wagi(-1 * wspolczynnik, -x[0] * wspolczynnik, -x[1] * wspolczynnik);
	else if (obecny_wynik < oczekiwany_wynik) 
		ustal_wagi(1 * wspolczynnik, x[0] * wspolczynnik, x[1] * wspolczynnik);
}

void Perceptron::sprawdz(double x1, double x2) {
	double tmp1 = x1, tmp2 = x2;
	ustal_wejscie(x1, x2);
	
	if (aktywacja() >= 0)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;

	ustal_wejscie(tmp1, tmp2);
}

bool Perceptron::sprawdz_bool(double x1, double x2) {
	double tmp1 = x1, tmp2 = x2;
	ustal_wejscie(x1, x2);

	if (aktywacja() >= 0) {
		ustal_wejscie(tmp1, tmp2);
		return true;
	}
	else {
		ustal_wejscie(tmp1, tmp2);
		return false;
	}
}

double* Perceptron::losuj() {
	srand(time(NULL));
	double *tab = new double[3];
	tab[0] = ((std::rand() % 20)-10)/10.;
	tab[1] = ((std::rand() % 20)-10)/10.;
	tab[2] = ((std::rand() % 20)-10)/10.;
	return tab;
}

void Perceptron::licz(Subtester test) {
	double obecny_wynik;
	ustal_wejscie(test.x1, test.x2);
	if (aktywacja() >= 0)
		obecny_wynik = 1;
	else
		obecny_wynik = 0;

	if (obecny_wynik > test.wynik)
		ustal_wagi(-1 * wspolczynnik, -x[0] * wspolczynnik, -x[1] * wspolczynnik);
	else if (obecny_wynik < test.wynik)
		ustal_wagi(1 * wspolczynnik, x[0] * wspolczynnik, x[1] * wspolczynnik);
}

bool Perceptron::zrob_test() {
	if(sprawdz_bool(1, 1));
	else 
		return false;
	if(!sprawdz_bool(1, 0));
	else 
		return false;
	if (!sprawdz_bool(0, 1));
	else
		return false;
	if (!sprawdz_bool(0, 0));
	else
		return false;
	
	return true;
}