#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "types.h"

#ifdef _WIN32
#include <windows.h>
#endif

Person* person = NULL;
int events_per_year = 8;


Luck dice() {
    return (Luck) rand() % 5;
}

char* get_health_explanation(int health) {
    if(health > 90) {
        return "здоров как бык";
    } else if (health > 60) {
        return "средненький по здоровью";
    } else if (health > 40) {
        return "часто болеет";
    } else {
        return "совсем хиленький и слабенький";
    }
}

void simulate() {

}

void setup_person() {
    if(person != NULL) {
        free(person);
    }
    person = malloc(sizeof(Person));
    
    int age;
    bool runflag = true;
    while (runflag) {
        printf("Введите возраст от 16 до 30 лет: ");
        scanf("%d", &age);
        if (age < 16 || age > 30) {
            printf("Неверно!");
            continue;
        }
        runflag = false;
    }

    person->age = age;

    char name[50];
    printf("Введите имя: ");
    scanf("%s", name);
    strcpy(person->name, name);

    person->money = (int)dice() * (age - 15) * 500;
    person->health = (int)dice() * 30;
    person->mood = MOOD_NORMAL;

    printf("Вашего персонажа зовут: %s\nЕму/ей %d лет. С рождения по здоровью он/она был(а) %s\nВ кармане оставалось %d рублей.", name, age, get_health_explanation(person->health), person->money);
}

int main() {
    srand(time(NULL));
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    setup_person();



    return 0;
}