#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>  //für stream
using namespace std;


/*****************************+AUFGABE1: einfaches C++ Programm*********************/
bool isTriangular(int n) {
	int sum = 0;
	for (int i = 1; sum < n; i++) {
		sum = sum + i;
	}
	if (sum == n) { return true; }
	else return false;
}

/*********************Aufgabe 1b: Einlesen einer Zahl uns ausgeben mit Fallunterscheidung*************************/
void aufgabe1b() {
	int n = 0;
	cout << "Bitte geben Sie eine ganze positive Zahl ein:   ";
	cin >> n;

	if (0 == isTriangular(n)) {
		cout << endl << " Die Zahl " << n << " ist nicht Triangular" << endl;
	}
	else {
		cout << endl << " Die Zahl " << n << " ist Triangular" << endl;
	}

}

void initRandom(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = (rand() % 9) - 4;
	}
}

string toString(int a[], int n) {
	stringstream s;
	s << endl << "_________Arraybeginn_________" << endl;
	for (int i = 0; i < n; i++) {
		s << "Element a[" << i << "]= " << a[i] << endl;
	}
	s << "__________________________________" << endl;
	return s.str();
}
int points(int diff) {
	if (diff > 0) { return 3; }
	if (diff < 0) { return 0;  }
	else return 1;

}
void calculate(int a[], int n, int &allPoints, int &maxDiff) {
	allPoints = 0;
	maxDiff = 0;
	for (int i = 0; i < n; i++) {
		allPoints = allPoints  + points(a[i]);
		maxDiff = maxDiff + a[i];
		}
	

}

/*****************Die main von Aufgabe 2************************/
void aufgabe2() {
	int a[50];
	int n = 0;
	int gesamtpunkte = 2;
	int Diffmax = 2;
	do {
		cout << "Geben Sie die Anzahl der Tordifferenzen ein (<50)  " << endl;
		cin >> n;
	} while (n > 50);
	initRandom(a, n);
	cout << toString(a, n);
	calculate(a, n, gesamtpunkte, Diffmax);
	cout << endl << "Gesamtpunkte: " << gesamtpunkte << endl << "Maximale Differenz: " << Diffmax << endl;
}

/***************************Aufgabe3:OOP****************************************************/
class Article {
private:
	double price;
	int amount;
	string place;
	string name;
public:
	Article();
	Article(double pr, int amount, string pl, string name);
	~Article() {};
	double getPrice() { return price; }
	string getPlace() { return place; }
	int getAmount() { return amount; }
	string toString();
	bool subtract(Article a2);

};

Article::Article() {
	name = "Stift";
	amount = 2;
	price = 1;
	cout << "Ort: ";
	cin >> place;
}

Article::Article(double pr, int amount, string pl, string name) {
	price = pr;
	this->amount = amount;
	place = pl;
	this->name = name;
}

string Article::toString() {
	stringstream s;
	s << endl << "__________artikel___________" << endl
		<< "Name: " << name << endl
		<< "Preis: " << price << endl
		<< "Anzahl: " << amount << endl
		<< "Ort: " << place << endl
		<< "________________________________" << endl;
	return s.str();

}
bool Article::subtract(Article a2) {
	if (0 == name.compare(a2.name)) {
		if (amount >= a2.getAmount()) {
			amount = amount - a2.getAmount();
			return true;
		}
		else return false;
	}
	else return false;

}
double capital(Article articles[], int number, string pl) {
	double sum = 0;
	for (int i = 0; i < number; i++) {
		if (0 == articles[i].getPlace().compare(pl)) {
			sum = sum + articles[i].getPrice();
		}
	}
	return sum;

}

void aufgabe3() {
	Article art1;
	Article art2(art1.getPrice(), art1.getAmount(), art1.getPlace(), "Stift");
	cout << "Artikel1" << art1.toString() << endl;
	cout << "Artikel2" << art2.toString() << endl;
	if (true == art1.subtract(art2)) {
		cout << "art1: " << art1.toString();
	}
	else cout << endl << "Keine Subtraktion möglich";
	////////////////Aufgabenteil e /////////////////////////////
	int n = 0;
	cout << "Anzahl Artikel eingeben: ";
	cin >> n;
	Article *warehouse = new Article[n];
	cout << "Gesamtkaptial in MD: " << capital(warehouse, n, "MD") << endl;
}
int main() {
	//aufgabe1b();
	//aufgabe2();
	//aufgabe3();

	/////////////////////PRIMZAHLEN//////////////////////////////////////////
	int abfrage = 0; //vom Benutzer festzulegen
	int zaehler = 0; // zählt die anzahl der primzahlen
	int aktuelleZahl = 2; //aktuelle zu prüfende Zahl
	int divisor = 2; // Zahl mit der geprüft wird, ob von zwei bis aktuelle zahl teilbar
	bool primzahl = true;
	cout<<"wieviele Primzahlen wollen Sie haben?  ";
	cin >> abfrage;
	cout << endl;
	while (zaehler<abfrage) { // bis genügend primzahlen gefunden wurden
		primzahl = true;
		divisor = 2;
		while (divisor < aktuelleZahl) { // von 2 bis aktuelle zahl teilen, wenn nicht teilbar dann primzahl

			if (aktuelleZahl%divisor == 0) {
				primzahl = false;
			}
			divisor++; //nächster divisor, bis aktuelle zahl erreicht
		}
		if (true == primzahl) {
			cout << aktuelleZahl << " ";
			zaehler++;
		}

		aktuelleZahl++; //nächste Zahl
	}
	
	system("pause");
	return 0;
}



