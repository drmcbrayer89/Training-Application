#define MAX_EX 6

typedef enum
{
  PRIMARY,
  SUPPLEMENTAL,
  AUX
} EXERCISE_TYPES_ENUM;

typedef struct
{
  char *name;
  char *description;
  EXERCISE_TYPES_ENUM type;
} EXERCISE_T;

typedef enum
{
  MAX_LOWER,
  MAX_UPPER,
  SPEED_LOWER,
  SPEED_UPPER
} WORKOUT_DAYS_ENUM;

typedef struct
{
  EXERCISE_T ex[MAX_EX];
  WORKOUT_DAYS_ENUM day;
} WORKOUT_T;

extern WORKOUT_T getExercises(WORKOUT_DAYS_ENUM day);
extern void setRepSchemes(WORKOUT_T* p_workout);
