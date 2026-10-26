#include <stdio.h>
#include <windows.h>

bool tradeCheck(unsigned short*, unsigned short, unsigned short*, unsigned short);

int main() {
    //виставляю кодировку виводу консолі в UTF-8
    SetConsoleOutputCP(65001);

    // Завдання 1. У грі на певному рівні два гравці можуть виконати обмін зброєю.
    // Відомі характеристики обох гравців:
    // • dmg1, dmg2 – сила зброї 1-го та 2-го гравців, числа типу беззнакового
    // цілого (допустимий діапазон: від 1 до 500
    // • level1, level2 – рівні 1-го та 2-го гравців , числа типу беззнакового цілого
    // (допустимий діапазон від 1 до 50) ;
    // • dmg2 (шкода зброї 2-го гравця) та (рівень 2-го гравця).
    // Персонаж може взяти зброю іншого лише тоді, коли шкода нової зброї не
    // перевищує рівень гравця, помножений на 10:
    // сила чужої зброї ≤ рівень гравця × 10
    // Необхідно написати функцію, яка перевіряє можливість обміну та здійснює
    // його тільки за умови, що обидва гравці спроможні взяти нову зброю.

    unsigned short dmg1, dmg2, level1, level2;
    
    printf("Введіть силу зброї (1 - 500) та рівень 1-го гравця (1 - 50): ");
    scanf("%hu %hu", &dmg1, &level1);

    if (dmg1 < 1 || dmg1 > 500 || level1 < 1 || level1 > 50) {
        printf("Некоректні дані для 1-го гравця.\n");
        return 1;
    }

    printf("Введіть силу зброї (1 - 500) та рівень 2-го гравця (1 - 50): ");
    scanf("%hu %hu", &dmg2, &level2);

    if (dmg2 < 1 || dmg2 > 500 || level2 < 1 || level2 > 50) {
        printf("Некоректні дані для 2-го гравця.\n");
        return 1;
    }

    bool result = tradeCheck(&dmg1, level1, &dmg2, level2);

    if (result) {
        printf("Обмін успішний! Нові значення:\n");
        printf("1-й гравець: dmg1 = %hu, level1 = %hu\n", dmg1, level1);
        printf("2-й гравець: dmg2 = %hu, level2 = %hu\n", dmg2, level2);
    } else {
        printf("Обмін не відбувся. Перевірте умови обміну.\n");
    }

    return 0;
}

bool tradeCheck(unsigned short* dmg1, unsigned short level1, unsigned short* dmg2, unsigned short level2) {
    if (dmg1 == NULL || dmg2 == NULL || level1 <= 0 || level2 <= 0 || *dmg1 <= 0 || *dmg2 <= 0) {
        return false;
    }

    if (*dmg1 == *dmg2) {
        return false;
    }

    if (*dmg2 <= level1 * 10 && *dmg1 <= level2 * 10) {
        *dmg1 = *dmg1 + *dmg2;
        *dmg2 = *dmg1 - *dmg2;
        *dmg1 = *dmg1 - *dmg2;
        return true;
    }

    return false;
}