#include <stdio.h>
#include <string.h>
#include "time.h"
#include "workouts.h"

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

char * gm_variations[3] = 
{
  "cambered bar gm",
  "buffalo bar gm",
  "anderson gm"
};

char * upper_supplementary_matrix[4] =
{
  "Close Grip Bench",
  "JM Press"
};

char * shoulders[3] =
{
  "db bench press",
  "db incline press",
  "db military press"
};

char * triceps[3] =
{
  "close grip pin press",
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


void buildSquatDay(WORKOUT_T* p_workout, LIFTER_T* p_lifter)
{
  p_workout->ex[0].name = squat_variations[rand() % 4];
  p_workout->ex[1].name = quads[rand() % 3];
  p_workout->ex[2].name = core[rand() % 2];
}

void buildVolumeBench(WORKOUT_T* p_workout, LIFTER_T* p_lifter)
{
  p_workout->ex[0].name = bench_variations[0]; // close grip ftw
  p_workout->ex[1].name = triceps[rand() % 3];
  p_workout->ex[2].name = upper_back[rand() % 3];
}

void buildDeadliftDay(WORKOUT_T* p_workout, LIFTER_T* p_lifter)
{
  p_workout->ex[0].name = deadlift_variations[rand() % 4];
  p_workout->ex[1].name = hamstrings[rand() % 3];
  p_workout->ex[2].name = core[rand() % 3];
}

void buildHeavyBench(WORKOUT_T* p_workout, LIFTER_T* p_lifter)
{
  p_workout->ex[0].name = bench_variations[rand() % 4];
  p_workout->ex[1].name = shoulders[rand() % 3];
  p_workout->ex[2].name = lats[rand() % 3];
}

void setRepSchemes(WORKOUT_T* p_workout, LIFTER_T* p_lifter)
{

  if(p_lifter->day == VOLUME_BENCH_DAY)
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

WORKOUT_T getExercises(LIFTER_T* p_lifter)
{
  // init random numbers
  srand(time(NULL));

  WORKOUT_T workout;

  switch(p_lifter->day) // what day are we doing?
  {
    case DEADLIFT_DAY:
      buildDeadliftDay(&workout, p_lifter);
      break;
    case HEAVY_BENCH_DAY:
      buildHeavyBench(&workout, p_lifter);
      break;
    case SQUAT_DAY:
      buildSquatDay(&workout, p_lifter);
      break;
    case VOLUME_BENCH_DAY:
      buildVolumeBench(&workout, p_lifter);
      break;
    default:
      printf("wrong entry\n");
      break;
  }

  return workout;
}