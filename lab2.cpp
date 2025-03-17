
#include <iostream>
double A;
bool mem_uzywane=0;
double suma() {
	return A + B;
}

double roznica() {
	return A-B;
}
double mnozenie() {
	return A*B;
}

double dzielenie() {

	if (B) {
		return A / B;
	}
	else {
		std::cout << "dzielenie przez zero";
		return A;
	}
}

double modulo() {
		return A - (int)(A / B) * B;
}
void kasuj() {
	A = 0;
	mem_uzywane = 0;
}
void menu() {
	int wybor;
	std::cout << "Wpisz 1 - dodawanie \n 2 - odejmowanie \n 3 - mnozenie \n 4 - dzielenie \n 5 - modulo \n 6 - kasuj \n";
	std::cin >> wybor;
	if (mem_uzywane) {
		switch (wybor) {
		case 1:
			A=suma(); break;
		case 2:
			A=roznica(); break;
		case 3:
			A=mnozenie(); break;
		case 4:
			A=dzielenie(); break;
		case 5:
			A=modulo(); break;
		case 6:
			kasuj(); break;
		}
	}

}

int main()
{
	menu();
	std::cout << A;
	return 0;
}

