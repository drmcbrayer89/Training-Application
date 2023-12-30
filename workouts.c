#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include "file_io.h"

char * rep_schemes[3] =
{
  "Top set of 1-5 reps",
  "3-5x5-8",
  "3-5x8-15"
};

char * bench_variations[4] =
{
  "close grip bench",
  "football bar bench press",
  "paused bench press",
  "floor press"
};

char * deadlift_variations[4] =
{
  "2-inch deficit",
  "2-inch block pull",
  "deadlift",
  "4-inch deficit"
};

char * squat_variations[4] =
{
  "cambered bar box squat",
  "squat bar box squat",
  "safety squat bar box squat",
  "buffalo bar box squat"
};

char * shoulders[3] =
{
  "db bench press",
  "db incline press",
  "db military press"
};

char * triceps[3] =
{
  "close grip 4 board",
  "close grip 2 board",
  "close grip 3 board"
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

char * hamstrings[3] = 
{
  "standing leg curl",
  "good mornings",
  "45 degree back raise"
};

char * quads[3] =
{
  "leg extension",
  "db squats",
  "lunges"
};

char * core[3] =
{
  "sit-up",
  "standing abs",
  "weighted sit-up"
};

char * kettlebells[3] =
{
  "double hand swing",
  "alternating swing",
  "kettlebell squat"
};


void buildSquatDay(WORKOUT_T* p_workout)
{
  p_workout->ex[0].name = squat_variations[rand() % 4];
  p_workout->ex[1].name = quads[rand() % 3];
  p_workout->ex[2].name = core[rand() % 2];

  while(checkDuplicateMainLift(p_workout))
  {
    printf("Retrying...\n");
    p_workout->ex[0].name = squat_variations[rand() % 4];
  }
}

void buildVolumeBench(WORKOUT_T* p_workout)
{
  p_workout->ex[0].name = bench_variations[0]; // close grip ftw
  p_workout->ex[1].name = triceps[rand() % 3];
  p_workout->ex[2].name = upper_back[rand() % 3];
}

void buildDeadliftDay(WORKOUT_T* p_workout)
{
  p_workout->ex[0].name = deadlift_variations[rand() % 4];
  p_workout->ex[1].name = hamstrings[rand() % 3];
  p_workout->ex[2].name = core[rand() % 3];

  while(checkDuplicateMainLift(p_workout))
  {
    printf("Retrying...\n");
    p_workout->ex[0].name = deadlift_variations[rand() % 4];
  }
}

void buildHeavyBench(WORKOUT_T* p_workout)
{
  p_workout->ex[0].name = bench_variations[rand() % 4];
  p_workout->ex[1].name = shoulders[rand() % 3];
  p_workout->ex[2].name = lats[rand() % 3];

  while(checkDuplicateMainLift(p_workout))
  {
    printf("Retrying...\n");
    p_workout->ex[0].name = bench_variations[rand() % 4];
  }
}

void setRepSchemes(WORKOUT_T* p_workout)
{

  if(p_workout->day == VOLUME_BENCH_DAY)
  {
    p_workout->ex[0].description = rep_schemes[SUPPLEMENTAL];
    p_workout->ex[1].description = rep_schemes[SUPPLEMENTAL];
  }
  else
  {
    p_workout->ex[0].description = rep_schemes[PRIMARY];
    p_workout->ex[1].description = rep_schemes[AUX];
  }

  p_workout->ex[2].description = rep_schemes[AUX];
}

WORKOUT_T getExercises(WORKOUT_DAYS_ENUM day)
{
  // init random numbers
  srand(time(NULL));

  WORKOUT_T * p_workout;
  // preserve this til i stop being lazy
  p_workout->day = day;

  switch(day) // what day are we doing?
  {
    case DEADLIFT_DAY:
      buildDeadliftDay(p_workout);
      break;
    case HEAVY_BENCH_DAY:
      buildHeavyBench(p_workout);
      break;
    case SQUAT_DAY:
      buildSquatDay(p_workout);
      break;
    case VOLUME_BENCH_DAY:
      buildVolumeBench(p_workout);
      break;
    default:
      printf("wrong entry\n");
      break;
  }

  saveWorkoutLog(p_workout);
  
  return (*p_workout);
}