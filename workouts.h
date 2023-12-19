#include "lifter.h"

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
  DEADLIFT_DAY = 1,
  HEAVY_BENCH_DAY,
  SQUAT_DAY,
  VOLUME_BENCH_DAY
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
extern void setRepSchemes(WORKOUT_T* p_workout, LIFTER_T* p_lifter);
