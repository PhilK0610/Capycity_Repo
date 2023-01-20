//============================================================================
// Name        : Capycity.cpp
// Author      : Philip Keidel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int laenge;
	int breite;
	int menuepunkt;
	bool runner = true;

	enum Field {
		EMPTY, WINDKRAFT, WASSERKRAFT, SOLARPANELE
	};
	Field art;

	cout << "Laenge eingeben: " << endl;
	cin >> breite;
	cout << "Breite eingeben: " << endl;
	cin >> laenge;

	Field baubereich[laenge][breite];

	for (int i = 0; i < laenge; i++) {
		for (int j = 0; j < breite; j++) {
			baubereich[i][j] = EMPTY;
		}
	}

	while (runner) {
		cout << "------Menue-----" << endl;
		cout << "\t 1) Gebauede setzen" << endl;
		cout << "\t 2) Bereich loeschen" << endl;
		cout << "\t 3) Ausgabe Baubereich" << endl;
		cout << "\t 4) Ende" << endl;
		cout << "Menuepunkt eingeben:" << endl;
		cin >> menuepunkt;
		cout << "-------------------------" << endl;

		switch (menuepunkt) {
		case 1:
			char eingabe;
			int lenGebaeude, breGebaeude, posx, posy;
			cout
					<< "Eingabe von Art, Laenge, Breite, x- u. y-Position: \n "
							"Moegliche Werte für Art: 'e' fuer empty, 'h' fuer wasserkraft, "
							"'w' fuer windkraft, 's' fuer solar" << endl;
			cin >> eingabe;
			cin >> lenGebaeude;
			cin >> breGebaeude;
			cin >> posx;
			cin >> posy;
			switch (eingabe) {
			case 'h':
				art = Field::WASSERKRAFT;
				break;
			case 'w':
				art = Field::WINDKRAFT;
				break;
			case 's':
				art = Field::SOLARPANELE;
				break;
			default:
				art = Field::EMPTY;
				break;
			}

			if ((posx + lenGebaeude) > laenge
					|| (posy + breGebaeude) > breite) {
				cout
						<< "Gebaeude konnte nicht gesetzt werden. Angaben liegen ausserhalb des Baubereiches";
			} else {
				for (int i = posy; i < posy + lenGebaeude; i++) {
					for (int j = posx; j < posx + breGebaeude; j++) {
						if (baubereich[i][j] == 1) {
							cout << "Gebaeude hier bereits vorhanden" << endl;
							break;
						} else
							baubereich[i][j] = art;
					}
				}
			}
			break;
			//---------------------------------------
			//case2 : Loeschen
		case 2:
			int deletePosx, deletePosy;
			cout << "Bitte x- u. y-Koordinate des Gebaeudes eingeben" << endl;
			cin >> deletePosx;
			cin >> deletePosy;

			if (deletePosx  > laenge || deletePosy > breite) {
				cout << "Gebaeude konnte nicht gelöscht werden. "
						"Angaben liegen ausserhalb des Baubereiches";
			} else {
				for (int i = 0; i < laenge; i++) {
					for (int j = 0; j < breite; j++) {
						if(i == deletePosy && j == deletePosx) {
							baubereich[i][j] = Field::EMPTY;
						}
					}
				}
			}
			break;
			//--------------------------------------
			//case3: Ausgabe Plan
		case 3:
			for (int i = 0; i < breite; i++) {
				for (int j = 0; j < laenge; j++) {
					cout << "[" << baubereich[i][j] << "]";
				}
				cout << endl;
			}
			break;
		case 4:
			runner = false;
			break;
		default:
			cout << "Menuepunkt nicht vorhanden!" << endl;
			break;
		}
		cin.clear();
	}

	return 0;
}
