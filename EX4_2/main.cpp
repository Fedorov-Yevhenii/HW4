/*
 * Написати програму, яка надає заданій змінній оточенню зазначене значення,
 * потім перевіряє щойно встановлену змінну та виводить отриману пару змінна -
 * значення стандартного потоку виведення. Якщо під час запуску програми необхідна інформація не вказана,
 * то вивести рекомендацію щодо використання програми.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Змінна: %s <environment_variable_name> <value>\n", argv[0]);
        return 1;
    }

    char* varName = argv[1];
    char* varValue = argv[2];

    if (setenv(varName, varValue, 1) == 0) {
        printf("Змінну оточення '%s' встановлено на '%s'\n", varName, varValue);
    } else {
        printf("Помилка при встановленні змінної оточення '%s'\n", varName);
        return 1;
    }

    char* newVarValue = getenv(varName);
    if (newVarValue != nullptr) {
        printf("Після встановлення, '%s=%s'\n", varName, newVarValue);
    } else {
        printf("Змінна оточення '%s' не знайдена після встановлення\n", varName);
    }

    return 0;
}