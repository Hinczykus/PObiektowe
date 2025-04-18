#include <iostream>

void Z1a(unsigned int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i % 10;
    }
}
void Z1b(unsigned int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i % 2;
    }
}
void Z1c(unsigned int n) {

    for (int i = 0; i < n; i++) {
        std::cout << i % 4;
    }
}
void Z1d(unsigned int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "0123";
    }
}
void Z1e(unsigned int n) {
    for (int i = 1; i < n; i++) {
        std::cout << "0123456789";
    }
    std::cout << "0123";
}
void Z1f(unsigned int n) {
    if (n % 2) {
        for (int i = 0; i < n/2; i++) {
            std::cout << "37";
        }
        std::cout << "3";
    }
    else {
        for (int i = 0; i < n/2; i++) {
            std::cout << "37";
        }
    }
}
void Z2a(unsigned int n) {
    for (int i = n; i <= n and i > 0; i--) {
        for (int j = n; j <= n and j > 0; j--) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}
void Z2b(unsigned int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}
void Z2c(unsigned int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            for (int j = 1; j <= i; j++) {
                std::cout << "3";
            }
        }
        else 
            for (int j = 1; j <= i; j++) {
                std::cout << "7";
            }
        std::cout << std::endl;
    }
}

void Z2d(unsigned int n) {
    for (int i = 1; i <= n and i>0; i++) {
        for (int j = n; j >= i; j--) {
            std::cout << j;
        }
        std::cout << std::endl;
   }
}

void Z2e(unsigned int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j<=n; j++) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

void Z2f(unsigned int n) {
    for (int i = 0; i < n; i++) {
        for (int s = i; s<n; s++) {
            std::cout << " ";
        }
        for (int j = (n - i); j <= n; j++) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}
void Z2g(unsigned int n) {
    for (int i = 0; i < n; i++) {
        for (int s = (n-i); s <= n; s++) {
            std::cout << " ";
        }
        for (int j = (n-i) ; j>0; j--) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}
int Z3(unsigned int n) {
    int suma=0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            suma += i;
        }
    }
    return suma;
}

void Z4(unsigned int a, unsigned int b) {
    int ilosc = 0;
    for (int i = a; i <= b; i++) {
        if (i % 7 == 0) {
            std::cout << i << "  ";
            ilosc++;
        }
    }
    std::cout << std::endl << "ilosc tego to: " << ilosc;
}

bool Z5(unsigned int n) {
    int sumadzielnikow = 1;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            sumadzielnikow += i;
        }
    }
    return (sumadzielnikow == n);
}

int Z6(unsigned int n) {
    for (int i = n;; i++) {
        if (Z5(i)) return i;
    }
}
//troche dlugo schodzi powyzej 8128 ale kiedys powinno wyjsc 

int main(){
    unsigned int n; // b;
    std::cin >> n;  //>> b;
                    //std::cout << Z3(n);
                    //Z4(n, b);
    std::cout << Z6(n);

    return 0;
}
