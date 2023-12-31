/*
Написати програму, яка виводить повний перелік змінних оточення.
------------
Написати програму, яка виводить у стандартний потік виведення значення певної конкретної змінної оточення,
вказаної під час виклику програми.
Якщо ім'я змінної оточення не вказано під час виклику програми, вивести інформацію про використання програми.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Змінна: %s\n", argv[0]);
        return 1;
    }

    char *varName = argv[1];
    char *varValue = getenv(varName); /*
     * Шукає в оточенні рядок із заданим ім'ям і повертає значення, асоційоване із цим ім'ям.
     * Вона поверне NULL, якщо потрібна змінна не Існує.
     * Якщо змінна є, але її значення не встановлено, функція getenv завершиться успішно і поверне порожній рядок, у якому перший байт дорівнює null.*/

    if (varValue != nullptr) {
        printf("%s = %s\n", varName, varValue);
    } else {
        printf("Змінна оточення '%s' не знайдена\n", varName);
    }

    return 0;
}