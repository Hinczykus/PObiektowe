#include <iostream>

void Z1a(unsigned int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i % 2;
    }
}
int main()
{
    unsigned int n;
    std::cin >> n;
    Z1a(n);
    return 0;
}

