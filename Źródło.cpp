#include <iostream>
#include "perceptron.h"
#include <fstream>

using namespace std;

int main() {
	Perceptron p = Perceptron();
	Tester t = Tester();


	double *tab = p.losuj();
	p.ustal_wagi(tab[0], tab[1], tab[2]);

	int z = 0, i = 0;

	while (true) {
		z = rand() % 4;
		p.licz(t.tab[z]);
		if (p.zrob_test())
			break;
		i++;
	}
	cout << "Udalo sie za " << i << " podejsciem!" << endl;


	p.wypisz_wagi();
	
	p.sprawdz(1, 1);
	p.sprawdz(1, 0);
	p.sprawdz(0, 1);
	p.sprawdz(0, 0);
	system("pause");
}