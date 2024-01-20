#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include "file_io.h"
#include "workouts.h"

char * rep_schemes[3] =
{
  "Top set of 1-5 reps",
  "3-5x5-8",
  "3-5x8-15"
};

/*
  LOWER BODY EXERCISES
*/

char * max_lower[4] =
{
  "buffalo bar low box squat",
  "2-inch deficit deadlift",
  "cambered bar low box squat",
  "pin 3 rackpull"
};

char * low_back_heavy[4] =
{
  "cambered bar GM",
  "romanian deadlift",
  "buffalo bar GM",
  "stiff leg deadlift"
};

char * low_back_light[2] =
{
  "reverse hypers",
  "45 degree back raise"
};

char * quads[2] =
{
  "leg extension",
  "db squats"
};

char * core[3] =
{
  "sit-up",
  "standing abs",
  "weighted sit-up"
};


/*
  UPPER BODY EXERCISES
*/
char * max_upper[4] =
{
  "close grip bench",
  "football bar bench press",
  "paused bench press",
  "floor press"
};

char * shoulders[4] =
{
  "db bench press",
  "db incline press",
  "db military press",
  "cambered bar bench press"
};

char * triceps_heavy[3] =
{
  "close grip bench",
  "close grip 2 board",
  "close grip 3 board"
};

char * triceps_light[4] = 
{
  "rolling DB extensions",
  "ez bar extensions",
  "football bar extensions",
  "tate press"
};

char * triceps_pump[2] =
{
  "rope pushdown",
  "ez bar pushdown"
};

char * lats[3] = 
{
  "pulldowns",
  "barbell rows",
  "db shrugs"
};

char * biceps[3] =
{
  "hammer curls",
  "ez bar curls",
  "db curls"
};

char * upper_back[3] =
{
  "upright row",
  "rear delt raises",
  "face pulls"
};

char * kettlebells[3] =
{
  "double hand swing",
  "alternating swing",
  "kettlebell squat"
};

void buildMaxLower(WORKOUT_T* p_workout)
{
  p_workout->ex[0].name = max_lower[rand() % 4];
  p_workout->ex[1].name = low_back_heavy[rand() % 4];
  p_workout->ex[2].name = lats[rand() % 3];
  p_workout->ex[3].name = core[rand() % 3];

  while(checkDuplicateMainLift(p_workout))
  {
    printf("Retrying...\n");
    p_workout->ex[0].name = max_lower[rand() % 4];
  }
}

void buildMaxUpper(WORKOUT_T* p_workout)
{
  p_workout->ex[0].name = max_upper[rand() % 4];
  p_workout->ex[1].name = shoulders[rand() % 3];
  p_workout->ex[2].name = triceps_light[rand() % 4];
  p_workout->ex[3].name = triceps_pump[rand() % 2];
  p_workout->ex[4].name = upper_back[rand() % 3];
  p_workout->ex[5].name = biceps[rand() % 3];

  while(checkDuplicateMainLift(p_workout))
  {
    printf("Retrying...\n");
    p_workout->ex[0].name = max_upper[rand() % 4];
  }
}

void buildSpeedLower(WORKOUT_T* p_workout)
{
  p_workout->ex[0].name = "box squat";
  p_workout->ex[1].name = low_back_light[rand() %2];
  p_workout->ex[2].name = quads[rand() % 2];
  p_workout->ex[3].name = core[rand() % 2];
}

void buildSpeedUpper(WORKOUT_T* p_workout)
{
  p_workout->ex[0].name = "ultra-wide bench press";
  p_workout->ex[1].name = triceps_heavy[rand() % 3];
  p_workout->ex[2].name = triceps_pump[rand() % 2];
  p_workout->ex[3].name = upper_back[rand() % 3];
}

void setRepSchemes(WORKOUT_T* p_workout)
{

  // if(p_workout->day == VOLUME_BENCH_DAY)
  // {
  //   p_workout->ex[0].description = rep_schemes[SUPPLEMENTAL];
  //   p_workout->ex[1].description = rep_schemes[SUPPLEMENTAL];
  // }
  // else
  // {
  //   p_workout->ex[0].description = rep_schemes[PRIMARY];
  //   p_workout->ex[1].description = rep_schemes[AUX];
  // }

  // p_workout->ex[2].description = rep_schemes[AUX];
}

WORKOUT_T getExercises(WORKOUT_DAYS_ENUM day)
{
  // init random numbers
  srand(time(NULL));

  WORKOUT_T * p_workout;
  // preserve this til i stop being lazy
  p_workout->day = day;

  switch(day)
  {
    case MAX_LOWER:
      buildMaxLower(p_workout);
      break;
    case MAX_UPPER:
      buildMaxUpper(p_workout);
      break;
    case SPEED_LOWER:
      buildSpeedLower(p_workout);
      break;
    case SPEED_UPPER:
      buildSpeedUpper(p_workout);
      break;
    default:
      printf("wrong entry\n");
      break;
  }

  saveWorkoutLog(p_workout);
  
  return (*p_workout);
}