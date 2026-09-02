typedef enum Luck {
    LUCK_CRITICAL,
    LUCK_BAD,
    LUCK_NORMAL,
    LUCK_GOOD,
    LUCK_PERFECT
} Luck;

typedef enum MoodType {
    MOOD_PERFECT,
    MOOD_GOOD,
    MOOD_NORMAL,
    MOOD_BAD,
    MOOD_AWFUL
} MoodType;

typedef struct Person {
    char* name;
    int age;
    Luck luck;
    int money;
    int health;
    MoodType mood;
} Person;
