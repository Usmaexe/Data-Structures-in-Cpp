#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

std::unordered_map<int, int> memo;

int maxPrimeFactors(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    int maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }
    if (n > 2) {
        maxPrime = n;
    }

    memo[n] = maxPrime;
    return maxPrime;
}

void remove(int a, int b, int c) {
    if (a == b) {
        if (c == b) {
            std::cout << "1 1 1" << std::endl;
        } else {
            std::cout << "0 0 1" << std::endl;
        }
    } else {
        if (c == b) {
            std::cout << "1 0 0" << std::endl;
        } else if (a == c) {
            std::cout << "0 1 0" << std::endl;
        } else {
            int a_prime = maxPrimeFactors(a);
            int b_prime = maxPrimeFactors(b);
            int c_prime = maxPrimeFactors(c);
            remove(a / a_prime, b / b_prime, c / c_prime);
        }
    }
}

int main() {
    int a;
    std::cin >> a;

    std::vector<std::vector<int>> b(a, std::vector<int>(3));

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> b[i][j];
        }
    }

    for (int i = 0; i < a; ++i) {
        remove(b[i][0], b[i][1], b[i][2]);
    }

    return 0;
}