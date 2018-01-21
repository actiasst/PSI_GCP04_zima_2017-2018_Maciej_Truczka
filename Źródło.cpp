#include <iostream>
#include "perceptron.h"
using namespace std;


int main() {
	Tester t = Tester();
	const int ilosc = 48;

	Perceptron siec[ilosc];
	for (int i = 0; i < ilosc; i++) {
		siec[i] = Perceptron();
		siec[i].ustal_wagi();
	}

	int tmp, licznik = 0, flaga = 0;
	while (true) {
		tmp = rand() % ilosc;
		
		for (int i = 0; i < ilosc; i++) {
			siec[i].ustal_wejscie(t.tab[tmp]);
			if (i != tmp)
				siec[i].licz(false);
			else
				siec[i].licz(true);
		}

		for (int i = 0; i < ilosc; i++)
			if (siec[i].sprawdz(t, i))
				flaga++;
		if (flaga == ilosc)
			break;
		licznik++;
		flaga = 0;
	}
	int tmpTest = ilosc;
	string best_idea_ever = "ABCDEFGHIJKLMNOPRSTUWXYZ";
	best_idea_ever += "abcdefghijklmnoprstuwxyz";
	cout << "Udalo sie za " << licznik << " podejsciem!" << endl;

	for (int i = 0; i < ilosc; i++) {
		cout << "Test dla " << best_idea_ever.at(i) << ":" << endl;
		for (int j = 0; j < ilosc; j++) {
			cout << best_idea_ever.at(j) << ":" << siec[i].sprawdz_bool(t.tab[j]) << endl;
		}
		cout << endl;
	}
	//for (int i = 0; i < ilosc; i++) {
	//	t.wypiszLiterke(i);
	//	cout << endl;
	//}

	t.wypisz_kilka_literek(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
	cout << endl;
	t.wypisz_kilka_literek(15, 16, 17, 18, 19, 20, 21, 22, 23, 48, 48, 48, 48, 48, 48);
	cout << endl;
	t.wypisz_kilka_literek(24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38);
	cout << endl;
	t.wypisz_kilka_literek(39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 48, 48, 48, 48, 48);
	cout << endl;

	t.wypiszLiterke(t.tabTest[0]);
	for (int i = 0; i < ilosc; i++) 
		siec[i].ustal_wejscie(t.tabTest[0]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[1]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[1]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[2]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[2]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[3]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[3]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[4]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[4]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[5]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[5]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[6]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[6]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[7]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[7]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[8]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[8]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	t.wypiszLiterke(t.tabTest[9]);
	for (int i = 0; i < ilosc; i++)
		siec[i].ustal_wejscie(t.tabTest[9]);

	for (int i = 0; i < ilosc; i++) {
		cout << best_idea_ever.at(i) << ": " << siec[i].aktywacja() << endl;
	}

	system("pause");
}





