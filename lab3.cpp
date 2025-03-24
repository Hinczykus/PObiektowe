
#include <iostream>

class kalkulator {
	double A;
	double suma() {
		double B;
		std::cout << "Druga liczba: ";
		std::cin >> B;
		return A = (A + B);
	};
	double roznica() {
		double B;
		std::cout << "Druga liczba: ";
		std::cin >> B;
		return A = (A - B);
	};
	double mnozenie() {
		double B;
		std::cout << "Druga liczba: ";
		std::cin >> B;
		return A = (A * B);
	};
	double dzielenie() {
		double B;
		std::cout << "Druga liczba: ";
		std::cin >> B;
		if (B) {
			return A = (A / B);
		}
		else {
			std::cout << "dzielenie przez zero, try again: \n";
			return dzielenie();
		}
	};
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
	};
	void kasuj() {
		A = 0;
		std::cout << "Pierwsza liczba: ";
		std::cin >> A;
	};
public:
	void menu() {
		std::cout << "Pierwsza liczba: \n";
		std::cin >> A;
		int wybor;
		do {
			std::cout << "Wybor:\n 1) + \n 2) - \n 3) * \n 4) / \n 5) % \n 6) clear \n 0 - EXIT \n";
			std::cin >> wybor;
			switch (wybor) {
			case 1:
				std::cout << "Wynik: " << suma(); break;
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
			std::cout << std::endl;
		} while (wybor != 0);
	};
};


int main()
{
	kalkulator kalkulator1;
	kalkulator1.menu();
	return 0;
}

