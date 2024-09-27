#include <stdio.h>

int is_prime(int n) {
    if (n < 2) return 0; // 0 и 1 не являются простыми числами
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; // если делится на i, то не простое
    }
    return 1; // число простое
}

int largest_prime_factor(int n) {
    int largest = 1; // инициализируем наибольший делитель

    // Проверяем простые числа от 2 до n
    for (int i = 2; i <= n; i++) {
        // Пока n делится на i, то i - это простой делитель
        while (n > 1 && n % i == 0) {
            largest = i; // обновляем наибольший простой делитель
            n = n - (n / i); // уменьшение n, чтобы избежать использования деления
        }
    }
    return largest;
}

int main() {
    int number;

    printf("Введите число: ");
    scanf("%d", &number);

    if (number <= 1) {
        printf("Введите число больше 1.\n");
    } else {
        int result = largest_prime_factor(number);
        printf("Наибольший простой делитель: %d\n", result);
    }

    return 0;
}
