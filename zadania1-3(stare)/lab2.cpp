
#include <iostream>
double A;
double suma() {
	double B;
	std::cout << "Druga liczba: ";
	std::cin >> B;
	return A=(A + B);
}
double roznica() {
	double B;
	std::cout << "Druga liczba: ";
	std::cin >> B;
	return A=(A-B);
}
double mnozenie() {
	double B;
	std::cout << "Druga liczba: ";
	std::cin >> B;
	return A=(A*B);
}
double dzielenie() {
	double B;
	std::cout << "Druga liczba: ";
	std::cin >> B;
	if (B) {
		return A=(A / B);
	}
	else {
		std::cout << "dzielenie przez zero, try again: \n";
		return dzielenie();
	}
}
double modulo() {
	double B;
	std::cout << "Druga liczba: ";
	std::cin >> B;
	if (B) {
		return A = (A - (int)(A / B) * B);
	}
	else {
		std::cout << "dzielenie przez zero, try again: \n";
		return modulo();
	}
}
void kasuj() {
	A = 0;
	std::cout << "\nPierwsza liczba: ";
	std::cin >> A;	
}
void menu() {
	std::cout << "Pierwsza liczba: ";
	std::cin >> A;
	int wybor;
	do {
		std::cout << "\nWybor:\n 1 - dodawanie \n 2 - odejmowanie \n 3 - mnozenie \n 4 - dzielenie \n 5 - modulo \n 6 - kasuj/anuluj \n 0 - EXIT \n";
		std::cin >> wybor;
		switch (wybor) {
		case 1:
			std::cout<< "Wynik: " << suma(); break;
		case 2:
			std::cout << "Wynik: " << roznica(); break;
		case 3:
			std::cout << "Wynik: " << mnozenie(); break;
		case 4:
			std::cout << "Wynik: " << dzielenie(); break;
		case 5:
			std::cout << "Wynik: " << modulo(); break;
		case 6:
			kasuj(); break;
		}
	} while (wybor != 0);

}

int main()
{
	menu();
	return 0;
}

