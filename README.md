#Filip Lenart 287116#
Prosty kalkulator wykonany w QT.

[1]Najważniejsze funkcje: 
- dodawanie (+)
- odejmowanie (-)
- dzielenie (/)
- mnożenie (x)
- modulo (%)
- zmiana znaku (+/-)
    *dostępna tylko PO wpisaniu liczby - próba zmiany znaku dla WYNIKU intencjonalnie niczym nie skutkuje
- konwersja z systemu dziesiątkowego na ósemkowy
    *(Help->Konwersje Systemów-> "10->8")
    *(Wyłącznie informacyjne, brak obsługi działań matematycznych)
    
[2]Info do obsługi:
Kalkulator obsługuje "chainowanie" tych samych/innych operacji matematycznych na otrzymanym wyniku.
Ta funkcjonalność nie wymaga powtórnego naciśnięcia operatora [1].
Przykład: '2' -> '+' -> '2' -> 'x' -> '2' -> '='(x) -> '2' '='(x) -> '3' -> '=' -> 48.

Podgląd obecnego stanu wyniku operacji jest widoczny w mniejszym wyświetlaczu.
Obecnie używany operator jest wyświetlany na najmniejszym z wyświetlaczy.
[3] Pliki:
obliczenia.cpp i obliczenia.h zawierają funkcje matematyczne do obsługi operatorów.
