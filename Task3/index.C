#include <stdio.h>
#include <windows.h>

void foundMinTemp(int*, int*);

int main() {
    //виставляю кодировку виводу консолі в UTF-8
    SetConsoleOutputCP(65001);

    // Завдання 3. Телеметричний датчик орбітального модуля передає послідовність
    // з 24 цілочисельних температурних показників. Послідовність передається по
    // одному числу. Напишіть функцію, яка без збереження всієї послідовності
    // знаходить мінімальну температуру та її порядковий номер у потоці.

    int minTemp = 0, index = 0;
    foundMinTemp(&minTemp, &index);
    printf("Мінімальна температура: %d, порядковий номер: %d\n", minTemp, index);

    return 0;
}

void foundMinTemp(int* minTemp, int* index) {
    for (int i = 0; i < 24; i++) {
        int temp;
        printf("Введіть температуру %d: ", i + 1);
        scanf("%d", &temp);

        if (i == 0 || temp < *minTemp) {
            *minTemp = temp;
            *index = i + 1;
        }
    }   
}