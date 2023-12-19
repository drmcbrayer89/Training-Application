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
  FILE *p_file = fopen("input.txt", "a+");
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

void printWorkout(WORKOUT_T* workout)
{
  int i = 0;
  
  char * message = "\
  %i. Exercise: %s\n\
      - %s\n";
  
  char * free_time = "\
  4. Free Time\n\
      - 2-5x15+\n";
  
  printf("WORKOUT OF THE DAY\n");
  printf("----------------------------\n");
  for(i; i < 3; i++)
  {
    if(workout->ex[i].name[0] != '\0')
    {
      printf(message, i+1, workout->ex[i].name, workout->ex[i].description);
    }
  }
  printf(free_time);
}

int main(void)
{
  LIFTER_T *p_lifter = malloc(sizeof(LIFTER_T));
  // Get the lifter's current maximum contest lift values
  importLifterFile(p_lifter);
  
  // User selection
  printf("What kind of workout?\n");
  printf("\
    1 - deadlifts\n\
    2 - heavy bench\n\
    3 - squat\n\
    4 - volume bench\n");
  printf("selection: ");
  scanf("%d", &p_lifter->day);
  
  printf("\n");
  
  // Generate workout
  WORKOUT_T workout = getExercises(p_lifter);
  setRepSchemes(&workout, p_lifter);
  printWorkout(&workout);
}
