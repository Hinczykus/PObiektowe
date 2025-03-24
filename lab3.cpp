
#include <iostream>

class kalkulator {
	double MEM, B;
	double suma() {
		std::cout << "Druga liczba: ";
		std::cin >> B;
		return MEM = (MEM + B);
	};
	double roznica() {
		std::cout << "Druga liczba: ";
		std::cin >> B;
		return MEM = (MEM - B);
	};
	double mnozenie() {
		std::cout << "Druga liczba: ";
		std::cin >> B;
		return MEM = (MEM * B);
	};
	double dzielenie() {
		std::cout << "Druga liczba: ";
		std::cin >> B;
		if (B) {
			return MEM = (MEM / B);
		}
		else {
			std::cout << "dzielenie przez zero, try again: \n";
			return dzielenie();
		}
	};
	double modulo() {
		std::cout << "Druga liczba: ";
		std::cin >> B;
		if (B) {
			return MEM = (MEM - (int)(MEM / B) * B);
		}
		else {
			std::cout << "dzielenie przez zero, try again: \n";
			return modulo();
		}
	};
	void kasuj() {
		MEM = 0;
		std::cout << "Pierwsza liczba: ";
		std::cin >> MEM;
	};
public:
	double getmemstate() {
		return bool(MEM);
	};
	void menu() {
		std::cout << "Pierwsza liczba: \n";
		std::cin >> MEM;
		int wybor;
		do {
			std::cout << "Wybor:\n 1) + \n 2) - \n 3) * \n 4) / \n 5) % \n 6) clear \n 0 - EXIT \n";
			std::cin >> wybor;
			switch (wybor) {
			case 1:
				suma(); break;
			case 2:
				roznica(); break;
			case 3:
				mnozenie(); break;
			case 4:
				dzielenie(); break;
			case 5:
				modulo(); break;
			case 6:
				kasuj(); break;
			}
			std::cout << MEM << std::endl;
		} while (wybor != 0);
	};
};


int main()
{
	kalkulator kalkulator1;
	kalkulator1.menu();
	return 0;
}

