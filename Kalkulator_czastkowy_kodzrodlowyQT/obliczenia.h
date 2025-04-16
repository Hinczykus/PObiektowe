#pragma once
#include <QString>
class obliczenia {
private:
    double storedValue=0;
    double suma(double storedValue, double B);
    double roznica(double storedValue, double B);
    double mnozenie(double storedValue, double B);
    double dzielenie(double storedValue, double B);
    double modulo(double storedValue, double B);
    void error(int kodbledu);
public:
    int error_type=0;
    double oblicz(QString operatr, double storedValue, double B);  // dostęp do private
    double getstoredValue() const;
    void setstoredValue(double value);
    QString decimalToOctal(int value);
};
