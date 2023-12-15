#include "lifter.h"

#define MAX_EX 6

typedef struct
{
  char *name;
  char *description;
  int weight;
  int sets;
  int reps;
  int rpe;
  char *sets_s;
  char *reps_s;
} EXERCISE_T;

typedef enum
{
  SQUAT,
  BENCH,
  DEADLIFT
} PRIMARY_LIFTS_T;

typedef enum
{
  MAX_EFFORT,
  DYNAMIC_EFFORT
} WORKOUT_TYPE_T;

typedef enum
{
  ME_LOWER = 1,
  ME_UPPER,
  DE_LOWER,
  DE_UPPER
} WORKOUT_DAYS_ENUM;

extern char* max_effort_lower_matrix[4];
extern char* max_effort_upper_matrix[4];
extern char* dynamic_lower_matrix[4];
extern char* dynamic_upper_matrix[2];

typedef struct
{
  EXERCISE_T ex[MAX_EX];
} WORKOUT_T;

typedef struct
{

} MAX_WORKOUT_T;

extern WORKOUT_T getExercises(LIFTER_T* p_lifter);
extern void setWorkoutDifficulty(WORKOUT_T* p_workout, LIFTER_T* p_lifter);
