#include <iostream>
#include "Neuron.h"
#include "Dane.h"
#include <Windows.h>

using namespace std;

int main()
{
	Neuron tab[10];
	for (int i = 0; i < 10; i++) {
		tab[i] = Neuron(to_string(i+1));
		Sleep(1000);
	}
	Dane d = Dane();
	d.wektoryzuj();

	cout << "Poczatkowe wagi" << endl;
	for (int i = 0; i < 10; i++)
		tab[i].wypisz();

	int zapamietana;
	for (int i = 0; i < 150; i++) {
		zapamietana = 0;
		for (int j = 0; j < 10; j++)
			tab[j].ustaw_wektor(d.zwroc_wektor(i));

		for (int j = 1; j < 10; j++)
			if (tab[zapamietana].aktywacja() < tab[j].aktywacja())
				zapamietana = j;

		tab[zapamietana].uaktualnij_wagi();
		for(int z = 0 ; z < 10 ; z++)
			tab[z].zmniejsz_wspolczynnik();
	}
	
	cout << "Wagi na koniec" << endl;
	for (int i = 0; i < 10; i++)
		tab[i].wypisz();


	double* tab1;
	for (int i = 0; i < 150; i++) {
		tab1 = d.zwroc_wektor(i);
		zapamietana = 0;
		for (int j = 0; j < 10; j++)
			tab[j].ustaw_wektor(tab1);
		zapamietana = 0;
		for (int j = 1; j < 10; j++)
			if (tab[zapamietana].aktywacja() < tab[j].aktywacja())
				zapamietana = j;
		cout << endl << "Neutron " << zapamietana + 1 << endl;
	}


	
	
	system("Pause");
}

//http://www.uci.agh.edu.pl/uczelnia/tad/inteligencja_obliczeniowa/09%20-%20Sieci%20Kohonena.pdf
//http://zsi.tech.us.edu.pl/~nowak/wi/som.pdf