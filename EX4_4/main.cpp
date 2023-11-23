/*
 * Написати програму, яка отримує інформацію про користувача, який її запустив.
*/

#include <cstdio>
#include <pwd.h>
#include <csignal>

int main() {

    struct passwd *currentUser = getpwuid(getuid());
    if (currentUser != nullptr) {
        printf("Ім'я користувача: %s\n", currentUser->pw_name);
        printf("Повне ім'я: %s\n", currentUser->pw_gecos);
        printf("Домашній каталог: %s\n", currentUser->pw_dir);
        printf("Шлях до оболонки: %s\n", currentUser->pw_shell);
    } else {
        printf("Помилка при отриманні інформації про поточного користувача\n");
    }

    struct passwd *rootUser = getpwnam("root");
    if (rootUser != nullptr) {
        printf("\nІнформація про користувача 'root':\n");
        printf("Ім'я користувача: %s\n", rootUser->pw_name);
        printf("Повне ім'я: %s\n", rootUser->pw_gecos);
        printf("Домашній каталог: %s\n", rootUser->pw_dir);
        printf("Шлях до оболонки: %s\n", rootUser->pw_shell);
    } else {
        printf("\nПомилка при отриманні інформації про користувача 'root'\n");
    }

    return 0;
}