#include <stdio.h>
#include <string.h>
#include "time.h"
#include "workouts.h"

#define MAX_EFFORT_DEFAULT 1
#define SETS_DEFAULT 4
#define FLUFF_REP_DEFAULT 15
#define AUX_REP_DEFAULT 10
#define SUPP_REP_DEFAULT 5


char * bench_variations[4] =
{
  "close grip bench",
  "football bar floor press",
  "paused bench press",
  "floor press"
};

char * deadlift_variations[3] =
{
  "2-inch deficit",
  "2-inch block pull",
  "deadlift"
};

char * squat_variations[3] =
{
  "cambered bar box squat",
  "buffalo bar / squat bar box squat",
  "safety squat bar box squat"
};

char * gm_variations[3] = 
{
  "cambered bar gm",
  "buffalo bar gm",
  "anderson gm"
};

char * upper_supplementary_matrix[4] =
{
  "Close Grip Bench\0",
  "JM Press\0"
};

char * hamstrings[3] = 
{
  "standing leg curl\0",
  "db rdl\0",
  "seated leg curl"
};

char * lowback[1] = 
{
  "45 degree back raise\0"
};

char * quads[3] =
{
  "leg extension\0",
  "db squats\0",
  "lunges"
};

char * abs[2] =
{
  "sit-up\0",
  "standing abs\0"
};


void buildDeLower(WORKOUT_T* workout, LIFTER_T* p_lifter)
{
  workout->ex[0].name = squat_variations[1];
  workout->ex[1].name = deadlift_variations[2];

  workout->ex[2].name = hamstrings[rand() % 3];
  workout->ex[3].name = quads[rand() % 3];
  workout->ex[4].name = lowback[rand () % 1];
  workout->ex[5].name = abs[rand() % 2];
}

WORKOUT_T buildMeLower(WORKOUT_T* workout)
{

}

void setWorkoutDifficulty(WORKOUT_T* p_workout, LIFTER_T* p_lifter)
{
  int main_sets = -1;
  int main_reps = -1;
  int supp_sets, supp_reps, aux_sets, aux_reps, fluff_sets, fluff_reps;

  switch(p_lifter->readiness)
  {
    case AWFUL:
      switch(p_lifter->day)
      {
        case ME_LOWER:
          break;
        case ME_UPPER:
          break;
        case DE_LOWER:
          main_sets = 5;
          main_reps = 2;
          supp_sets = 5;
          supp_reps = 1;
          break;
        case DE_UPPER:
          break;
        default:
          break;
      }
      
      // aux work (skip)
      aux_sets = 0; // drop sets
      aux_reps = 0; // double reps (lighter)
      // fluff work
      fluff_sets = SETS_DEFAULT - 2;
      fluff_reps = 25; // default to 25 reps
      break;
    case BAD:

      break;
    case NORMAL:
      switch(p_lifter->day)
      {
        case ME_LOWER:
          break;
        case ME_UPPER:
          break;
        case DE_LOWER:
          main_sets = 10;
          main_reps = 2;
          supp_sets = 10;
          supp_reps = 1;
          break;
        case DE_UPPER:
          break;
        default:
          break;
      }
      
      // aux work (skip)
      aux_sets = SETS_DEFAULT; // drop sets
      aux_reps = AUX_REP_DEFAULT; // double reps (lighter)
      // fluff work
      fluff_sets = SETS_DEFAULT;
      fluff_reps = FLUFF_REP_DEFAULT; // default to 25 reps
      break;
    case GREAT:

      break;
    default:
      break;
  }


  int i = 0;
  for(i; i < MAX_EX; i++)
  {
    switch(i)
    {
      case 0:
        p_workout->ex[i].sets = main_sets;
        p_workout->ex[i].reps = main_reps;
        break;
      case 1:
        p_workout->ex[i].sets = supp_sets;
        p_workout->ex[i].reps = supp_reps;
        break;
      case 2:
      case 3:
        p_workout->ex[i].sets = aux_sets;
        p_workout->ex[i].reps = aux_reps;
        break;
      default:
        p_workout->ex[i].sets = fluff_sets;
        p_workout->ex[i].reps = fluff_reps;
        break;
    }
  }
}

WORKOUT_T getExercises(LIFTER_T* p_lifter)
{
  // init random numbers
  srand(time(NULL));

  WORKOUT_T workout;

  switch(p_lifter->day) // what day are we doing?
  {
    case ME_LOWER:
      break;
    case ME_UPPER:
      break;
    case DE_LOWER:
      buildDeLower(&workout, p_lifter);
      break;
    case DE_UPPER:
      break;
    default:
      printf("wrong entry\n");
      break;
  }

  return workout;
}