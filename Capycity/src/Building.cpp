/*
 * Building.cpp
 *
 *  Created on: 20.01.2023
 *      Author: Philip
 */

#ifndef BUILDING_CPP_
#define BUILDING_CPP_

# include <iostream>
# include <string>
# include <vector>

#include "Material.cpp"
using namespace std;

class Building {
public:
	double getPrice();
	string getLabel();

private:
	double grundpreis;
	string label;
};

class Wasserkraftwerk: public Building {
public:
	Wasserkraftwerk() {
		grundpreis = 125;
		label = "WAK";
		materials.push_back(Holz());
		materials.push_back(Metall());
		materials.push_back(Metall());
	}
//	~Wasserkraftwerk();
	double getPrice() {
		return grundpreis;
	}
	string getLabel() {
		return label;
	}

	vector<Material> getMaterials() {
		return materials;
	}

	double getGesamtPreisGebauede() {
		double materialPreise = 0;
		for (auto const &value : materials) {
			Material m = value;
			materialPreise += m.getPrice();
		}
		cout << grundpreis + materialPreise << endl;
		return grundpreis + materialPreise;
	}

	void printMaterialien() {
		int anzMetall = 0;
		int anzHolz = 0;
		int anzKunststoff = 0;
		for (auto const &value : materials) {
			Material m = value;
			switch (m.getBezeichner()) {
			case 0:
				anzHolz++;
				break;
			case 1:
				anzMetall++;
				break;
			default:
				anzKunststoff++;
				break;
			}
		}
		cout << "Materialien Wasserkraftwerk [Holz, Metall , Kunststoff]: ["
				<< anzHolz << ", " << anzMetall << ", " << anzKunststoff << "]" << endl;
	}

private:
	string label;
	double grundpreis;
	vector<Material> materials;
};

class Windkraftwerk: public Building {
public:
	Windkraftwerk() {
		grundpreis = 125;
		label = "WIK";
		materials.push_back(Metall());
		materials.push_back(Metall());
		materials.push_back(Metall());
	}
//	~Windkraftwerk();
	double getPrice() {
		return grundpreis;
	}
	string getLabel() {
		return label;
	}

	vector<Material> getMaterials() {
		return materials;
	}

	double getGesamtPreisGebauede() {
		double materialPreise = 0;
		for (auto const &value : materials) {
			Material m = value;
			materialPreise += m.getPrice();
		}
		cout << grundpreis + materialPreise << endl;
		return grundpreis + materialPreise;
	}
	void printMaterialien() {
		int anzMetall = 0;
		int anzHolz = 0;
		int anzKunststoff = 0;
		for (auto const &value : materials) {
			Material m = value;
			switch (m.getBezeichner()) {
			case 0:
				anzHolz++;
				break;
			case 1:
				anzMetall++;
				break;
			default:
				anzKunststoff++;
				break;
			}
		}
		cout << "Materialien Windkraftwerk [Holz, Metall , Kunststoff]: ["
				<< anzHolz << ", " << anzMetall << ", " << anzKunststoff << "]" << endl;
	}

private:
	string label;
	double grundpreis;
	vector<Material> materials;
};

class Solar: public Building {
public:
	Solar() {
		grundpreis = 125;
		label = "SOL";
		materials.push_back(Kunststoff());
		materials.push_back(Metall());
		materials.push_back(Metall());
	}
//	~Solar();
	double getPrice() {
		return grundpreis;
	}
	string getLabel() {
		return label;
	}

	vector<Material> getMaterials() {
		return materials;
	}

	double getGesamtPreisGebauede() {
		double materialPreise = 0;
		for (auto const &value : materials) {
			Material m = value;
			materialPreise += m.getPrice();
		}
		cout << grundpreis + materialPreise << endl;
		return grundpreis + materialPreise;
	}
	void printMaterialien() {
		int anzMetall = 0;
		int anzHolz = 0;
		int anzKunststoff = 0;
		for (auto const &value : materials) {
			Material m = value;
			switch (m.getBezeichner()) {
			case 0:
				anzHolz++;
				break;
			case 1:
				anzMetall++;
				break;
			default:
				anzKunststoff++;
				break;
			}
		}
		cout << "Materialien Solar [Holz, Metall , Kunststoff]: [" << anzHolz
				<< ", " << anzMetall << ", " << anzKunststoff << "]" << endl;
	}

private:
	string label;
	double grundpreis;
	vector<Material> materials;
};

class Empty: public Building {
public:
	Empty() {
		grundpreis = 125;
		label = "EMP";
		materials.push_back(Metall());
		materials.push_back(Metall());
		materials.push_back(Metall());
	}
//	~Empty();
	double getPrice() {
		return grundpreis;
	}
	string getLabel() {
		return label;
	}

	vector<Material> getMaterials() {
		return materials;
	}

	double getGesamtPreisGebauede() {
		double materialPreise = 0;
		for (auto const &value : materials) {
			Material m = value;
			materialPreise += m.getPrice();
		}
		cout << grundpreis + materialPreise << endl;
		return grundpreis + materialPreise;
	}

private:
	string label;
	double grundpreis;
	vector<Material> materials;
};

#endif



