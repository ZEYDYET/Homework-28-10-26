#include <stdio.h>
#include <windows.h>


void change_in_procedure (double*, double*, double*);

int main() {
    //виставляю кодировку виводу консолі в UTF-8
    SetConsoleOutputCP(65001);

    // Завдання 2. Серверний балансувальник проводить аналіз навантаження CPU на
    // трьох вузлах дата-центру (S1, S2, S3, значення у відсотках типу double). Напишіть
    // функцію, яка впорядковує їхні значення за зростанням так, щоб задовольнялася
    // умова S1< S2< S3. Використання оператора return заборонено.

    double S1, S2, S3;
    printf("Введіть навантаження CPU на трьох вузлах (S1, S2, S3) у відсотках: ");
    scanf("%lf %lf %lf", &S1, &S2, &S3);

    if (S1 < 0 || S1 > 100 || S2 < 0 || S2 > 100 || S3 < 0 || S3 > 100) {
        printf("Некоректні дані. Значення повинні бути у відсотках (0-100).\n");
        return 1;
    }

    change_in_procedure(&S1, &S2, &S3);

    printf("Впорядковані значення навантаження CPU: S1 = %.2lf, S2 = %.2lf, S3 = %.2lf\n", S1, S2, S3);

    return 0;
}

void change_in_procedure (double* S1, double* S2, double* S3) {
    if (S1 == NULL || S2 == NULL || S3 == NULL) {
        printf("Некоректні вхідні дані. Вказівники не повинні бути NULL.\n");
    }
    else {
        double temp;
        if (*S1 > *S2) {
            temp = *S1;
            *S1 = *S2;
            *S2 = temp;
        }
        if (*S1 > *S3) {
            temp = *S1;
            *S1 = *S3;
            *S3 = temp;
        }
        if (*S2 > *S3) {
            temp = *S2;
            *S2 = *S3;
            *S3 = temp;
        }
    }
}