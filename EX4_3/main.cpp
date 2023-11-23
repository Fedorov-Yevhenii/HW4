/*
 * Напишіть програму, яка видаляє вказану змінну з оточення.
 * Якщо ім'я змінної, яку потрібно видалити, не вказано при запуску програми, видалити все оточення.
 * Після цього вивести поточне оточення стандартний потік виведення.
*/

#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        if (unsetenv(argv[1]) == 0) { // видаляє змінну з назвою NAME з оточення
            printf("Змінну оточення '%s' видалено\n", argv[1]);
        } else {
            printf("Помилка при видаленні змінної оточення '%s'\n", argv[1]);
            return 1;
        }
    } else if (argc == 1) {
        if (clearenv() == 0) { // очищення всього оточення
            printf("Оточення було очищено\n");
        } else {
            printf("Помилка при очищенні оточення\n");
            return 1;
        }
    } else {
        printf("Usage: %s [environment_variable_name]\n", argv[0]);
        return 1;
    }

    extern char** environ;
    for (char** env = environ; *env != nullptr; env++) {
        printf("%s\n", *env);
    }

    return 0;
}
