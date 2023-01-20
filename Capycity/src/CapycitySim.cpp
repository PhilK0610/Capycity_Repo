//============================================================================
// Name        : Capycity.cpp
// Author      : Philip Keidel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include "Material.cpp"
#include "Building.cpp"
using namespace std;

int main() {
	int laenge;
	int breite;
	int menuepunkt;
	bool runner = true;
	double gesamtpreis = 0;
	double preisWAK = Wasserkraftwerk().getGesamtPreisGebauede();
	double preisWIK = Windkraftwerk().getGesamtPreisGebauede();
	double preisSOL = Solar().getGesamtPreisGebauede();
	string art;

	cout << "Laenge eingeben: " << endl;
	cin >> breite;
	cout << "Breite eingeben: " << endl;
	cin >> laenge;

	string baubereich[laenge][breite];

	for (int i = 0; i < laenge; i++) {
		for (int j = 0; j < breite; j++) {
			baubereich[i][j] = Empty().getLabel();
		}
	}

	while (runner) {
		//Menue
		cout << "------Menue-----" << endl;
		cout << "\t 1) Gebauede setzen" << endl;
		cout << "\t 2) Bereich loeschen" << endl;
		cout << "\t 3) Ausgabe Baubereich" << endl;
		cout << "\t 4) Ende" << endl;
		cout << "Menuepunkt eingeben:" << endl;
		cin >> menuepunkt;
		cout << "-------------------------" << endl;

		switch (menuepunkt) {
		//Fall 1 : Gebaeude setzen
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
			//Auswahl, des Labels
			case 'h':
				art = Wasserkraftwerk().getLabel();
				gesamtpreis += (lenGebaeude * breGebaeude * preisWAK);
			break;
			case 'w':
				art = Windkraftwerk().getLabel();
				gesamtpreis += (lenGebaeude * breGebaeude * preisWIK);
				break;
			case 's':
				art = Solar().getLabel();
				gesamtpreis += (lenGebaeude * breGebaeude * preisSOL);
				break;
			default:
				art = Empty().getLabel();
				break;
			}

			if ((posx + lenGebaeude) > laenge
					|| (posy + breGebaeude) > breite) {
				cout
						<< "Gebaeude konnte nicht gesetzt werden. Angaben liegen ausserhalb des Baubereiches";
			} else {
				for (int i = posy; i < posy + lenGebaeude; i++) {
					for (int j = posx; j < posx + breGebaeude; j++) {
						if (baubereich[i][j] != "EMP") {
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

			if (deletePosx > laenge || deletePosy > breite) {
				cout << "Gebaeude konnte nicht gelöscht werden. "
						"Angaben liegen ausserhalb des Baubereiches";
			} else {
				for (int i = 0; i < laenge; i++) {
					for (int j = 0; j < breite; j++) {
						if (i == deletePosy && j == deletePosx) {
							string zuLoeschendesGebaeude = baubereich[i][j];

							if(zuLoeschendesGebaeude == "WAK")
								gesamtpreis -= preisWAK;
							else if (zuLoeschendesGebaeude == "WIK")
								gesamtpreis -= preisWIK;
							else
								gesamtpreis -= preisSOL;
							baubereich[i][j] = Empty().getLabel();
						}
					}
				}
			}
			break;
			//--------------------------------------
			//case3: Ausgabe Plan
		case 3:
			cout << "--------Ausgabe Plan--------" << endl;
			for (int i = 0; i < breite; i++) {
				for (int j = 0; j < laenge; j++) {
					cout << "[" << baubereich[i][j] << "]";
				}
				cout << endl;
			}
			cout << "--------Ausgabe Benötigte Materialien--------" << endl;
			Wasserkraftwerk().printMaterialien();
			Windkraftwerk().printMaterialien();
			Solar().printMaterialien();

			cout << "--------Ausgabe Einzelpreis Gebauede--------" << endl;
			cout << "Preis Wasserkraftwerk: " << preisWAK << endl;
			cout << "Preis Windkraftwerk: " << preisWIK << endl;
			cout << "Preis Solar: " << preisSOL << endl;

			cout << "--------Ausgabe Gesamtpreis--------" << endl;
			cout << "Gesamtpreis: " << gesamtpreis << "\n" << endl;
			break;
		//Fall 4 : Beenden
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
