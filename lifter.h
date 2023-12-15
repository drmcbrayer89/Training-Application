
typedef enum
{
  BOTTOM,
  MID,
  TOP
} WEAKPOINT_T;

typedef enum
{
  AWFUL = 1,
  BAD,
  NORMAL,
  GREAT
} READINESS_T;

typedef struct
{
  float squat;
  float bench;
  float deadlift;
} PRIMARY_LIFT_MAX_T;

typedef struct
{
  PRIMARY_LIFT_MAX_T maxes;
  WEAKPOINT_T weakpoint_squat;
  WEAKPOINT_T weakpoint_bench;
  WEAKPOINT_T weakpoint_dl;
  float speed_waves[3][3];
  READINESS_T readiness;
  int day;
  int week;
} LIFTER_T;