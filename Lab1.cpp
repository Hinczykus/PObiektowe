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

int main()
{
    unsigned int n;
    std::cin >> n;
    Z1f(n);
    return 0;
}