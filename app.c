#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "workouts.h"

void importLifterFile(LIFTER_T *lifter)
{
  char *found[3];
  char *input;
  char buff[16];
  // Read starting numbers
  FILE *p_file = fopen("/home/ryanm/eclipse-workspace/Training Application/input.txt", "a+");
  if (p_file != NULL)
  {
    fscanf(p_file, "%s", buff);
  }
  else
  {
    printf("null file");
  }

  int i = 0;
  input = buff;
  while ((found[i] = strsep(&input, ",")) != NULL)
  {
    i++;
  }

  lifter->maxes.squat = atoi(found[0]) * 5 * 0.0333 + atoi(found[0]);
  lifter->maxes.bench = atoi(found[1]) * 5 * 0.0333 + atoi(found[1]);
  lifter->maxes.deadlift = atoi(found[2]) * 5 * 0.0333 + atoi(found[2]);
}

void setDynamicWeights(LIFTER_T *lifter)
{
  int i;
  float week1 = 0.6;
  for (i = 0; i < 3; i++)
  {
    lifter->speed_waves[SQUAT][i] = lifter->maxes.squat * week1;
    lifter->speed_waves[BENCH][i] = lifter->maxes.bench * week1;
    lifter->speed_waves[DEADLIFT][i] = lifter->maxes.deadlift * week1;

    week1 = week1 + 0.05;
  }
}

void printWorkout(WORKOUT_T* workout)
{
  int i = 0;

  for(i; i < MAX_EX; i++)
  {
    if(workout->ex[i].sets != 0)
    {
      printf("\
      Exercise: %s\n\
      -- %i x %i\n",
      workout->ex[i].name, workout->ex[i].sets, workout->ex[i].reps);
    }
  }
}

int main(void)
{
  LIFTER_T *p_lifter = malloc(sizeof(LIFTER_T));
  // Get the lifter's current maximum contest lift values
  importLifterFile(p_lifter);
  
  printf("What kind of workout?\n");
  printf("\
    1 - max effort lower\n\
    2 - max effort upper\n\
    3 - dynamic lower\n\
    4 - dynamic upper\n");
  printf("selection: ");
  scanf("%d", &p_lifter->day);
  
  printf("\n");

  printf("How do you feel?\n");
  printf("\
    1 - AWFUL\n\
    2 - BAD\n\
    3 - NORMAL\n\
    4 - GREAT\n");
  printf("selection: ");
  scanf("%d", &p_lifter->readiness);
  printf("\n");
  
  printf("What week of training? (1 - 6)");
  scanf("%d", &p_lifter->week);

  // Handle dynamic days being on 3 week waves, but max effort being on 4 week waves
  if(p_lifter->day == DE_LOWER || p_lifter->day == DE_UPPER)
  {
    if(p_lifter->week > 3)
    {
      p_lifter->week = p_lifter->week - 3;
    }
  }

  WORKOUT_T workout = getExercises(p_lifter);
  setWorkoutDifficulty(&workout, p_lifter);
  printWorkout(&workout);
}
