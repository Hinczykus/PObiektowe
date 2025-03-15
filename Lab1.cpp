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

int main()
{
    unsigned int n;
    std::cin >> n;
    Z1c(n);
    return 0;
}