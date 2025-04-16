#include "obliczenia.h"
double obliczenia::suma(double storedValue, double B) {
    return storedValue + B;
	};

double obliczenia::roznica(double storedValue, double B) {
    return storedValue - B;
	};

double obliczenia::mnozenie(double storedValue, double B) {
    return storedValue*B;
	};

double obliczenia::dzielenie(double storedValue, double B) {
    if(B==0){
        error(1);
        return 0;
    }
    return storedValue/B;
	};

double obliczenia::modulo(double storedValue, double B) {
    if(B==0){
        error(1);
        return 0;
    }
    return std::fmod(storedValue, B);
    };

double obliczenia::oblicz(QString operatr, double storedValue, double B)
{
    if (operatr == "+")
        return suma(storedValue, B);
    else if (operatr == "-")
        return roznica(storedValue, B);
    else if (operatr == "x")
        return mnozenie(storedValue, B);
    else if (operatr == "/")
        return dzielenie(storedValue, B);
    else if (operatr == "%")
        return modulo(storedValue,B);
    return 0;
}

void obliczenia::error(int kodbledu){
    switch(kodbledu)
    {
    case 1:
        error_type = 1;
        break;
    default:
        error_type = 2;
        break;
    }
}
double obliczenia::getstoredValue() const{
    return storedValue;
};
void obliczenia::setstoredValue(double value){
    storedValue=value;
};

QString obliczenia::decimalToOctal(int value) {
    if (value == 0) return "0";

    QString result = "";

    while (value > 0) {
        int remainder = value % 8;
        result.prepend(QString::number(remainder));
        value /= 8;
    };
    return result;
};
