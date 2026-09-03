#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "types.h"

#define print_spacer printf("\n\n===================================================\n\n")

#ifdef _WIN32
#include <windows.h>
#endif

Person* person = NULL;
World* world = NULL;

Luck dice() {
    return (Luck) rand() % 5;
}

char* get_health_description(int health) {
    if(health > 90) {
        return "здоров как бык";
    } else if (health > 60) {
        return "средненький по здоровью";
    } else if (health > 40) {
        return "часто болеющий";
    } else {
        return "совсем хиленький и слабенький";
    }
}

char* get_economy_status_description(EconomyStatus status) {
    char* returns;
    switch (status)
    {
    case ESTATUS_DEFOLT:
        returns = "дефолт";
        break;
    case ESTATUS_CRISIS:
        returns = "падение";
        break;
    case ESTATUS_NORMAL:
        returns = "нормальное состояние";
        break;
    case ESTATUS_RISE:
        returns = "рост";
        break;
    case ESTATUS_PERFECT:
        returns = "лучшие времени";
        break;
    }
    return returns;
}


char* get_world_status_description(WorldStatus status) {
    char* returns;
    switch (status)
    {
    case STATUS_WAR:
        returns = "наихудшем";
        break;
    case STATUS_CRISIS:
        returns = "кризисном";
        break;
    case STATUS_NORMAL:
        returns = "нормальном";
        break;
    case STATUS_RISE:
        returns = "растущем";
        break;
    case STATUS_PERFECT_WORLD:
        returns = "лучшем";
        break;
    }
    return returns;
}

char* get_mood_description(MoodType mood) {
    char* returns;
    switch (mood)
    {
    case MOOD_AWFUL:
        returns = "отвратительное";
        break;
    case MOOD_BAD:
        returns = "плоховатое";
        break;
    case MOOD_NORMAL:
        returns = "обычное";
        break;
    case MOOD_GOOD:
        returns = "приподнятное";
        break;
    case MOOD_PERFECT:
        returns = "отличное";
        break;
    }
    return returns;
}

void simulate() {

}

int scan_input_in_range(int min, int max, char* msg) {
    bool runflag = true;
    int dest = 0;
    while (runflag) {
        printf(msg);
        scanf("%d", &dest);
        if (dest < min || dest > max) {
            printf("Неверно!");
            dest = min-1;
            continue;
        }
        runflag = false;
    }
    return dest;
}

void setup_person() {
    person->age = scan_input_in_range(16, 30, "\nВведите возраст от 16 до 30 лет: ");
    char name[50];
    printf("Введите имя: ");
    scanf("%s", name);
    strcpy(person->name, name);

    person->money = (int)dice() * (person->age - 15) * 500;
    person->health = (int)dice() * 30;
    person->mood = (MoodType) dice();

    printf("\nВашего персонажа зовут: %s\nЕму/ей %d лет. С рождения по здоровью он/она был(а) %s\nВ кармане оставалось %d рублей. \
        \nНа момент начала событий его/её настроение: %s", person->name, person->age, get_health_description(person->health), person->money, get_mood_description(person->mood));
}

void setup_world() {
    world->year = scan_input_in_range(2000, 2026, "\nВведите желемый год старта от 2000 до 2026: ");
    
    world->end_year = world->year + scan_input_in_range(1, 30, "\nУкажите какое количество лет вы желаете симулировать (не меньше 1 и не больше 30): ");

    world->events_per_year = scan_input_in_range(1, 10, "\nУкажите желаемое количество событий в год (не меньше 1 и не больше 10): ");

    world->economy = (EconomyStatus) dice();
    world->status = (WorldStatus) dice();

    printf("\nСейчас %d год.\nВаш персонаж проживет в мире еще %d счастливых или не очень лет, и каждый год с ним будет происходить %d событий.\
        \nСам мир находится в %s состоянии.\nЭкономика мира переживает %s", world->year, world->end_year-world->year, world->events_per_year,\
    get_world_status_description(world->status), get_economy_status_description(world->economy));
}

int main() {
    srand(time(NULL));
    world = malloc(sizeof(World));
    person = malloc(sizeof(Person));

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    print_spacer;
    printf("\nДобро пожаловать в симулятор жизни! Для начала вам требуется настроить игровой мир...");
    setup_world();
    print_spacer;
    printf("\nОтлично! Теперь настройте своего персонажа...");
    setup_person();
    return 0;
}