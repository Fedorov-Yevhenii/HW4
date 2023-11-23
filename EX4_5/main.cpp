/*
 * Написати програму,
 * яка отримує інформацію про комп'ютер, на якому виконується.
*/

#include <cstdio>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char computerName[256];
    struct utsname uts;

    if (gethostname(computerName, sizeof(computerName)) == 0) { // записує ім'я мережі в рядок name.
        printf("Ім'я комп'ютера: %s\n", computerName);
    } else {
        perror("Помилка під час спроби отримання імені комп'ютера");
        return 1;
    }

    if (uname(&uts) == 0) { // записує інформацію про комп'ютер у структуру, на яку вказує параметр name
        printf("ОС: %s\n", uts.sysname);
        printf("Версія: %s\n", uts.release);
        printf("Ревізія: %s\n", uts.version);
        printf("Архітектура: %s\n", uts.machine);
    } else {
        perror("Помилка отримання інформації про комп'ютер");
        return 1;
    }

    return 0;
}