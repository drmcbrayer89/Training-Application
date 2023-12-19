#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "workouts.h"


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
  WORKOUT_T workout;
  // User selection
  printf("What kind of workout?\n");
  printf("---------------------\n");
  printf("\
    1 - deadlifts\n\
    2 - heavy bench\n\
    3 - squat\n\
    4 - volume bench\n");
  printf("selection: ");
  scanf("%d", &workout.day);
  
  printf("\n");

  // Generate workout
  workout = getExercises(workout.day);
  setRepSchemes(&workout);
  printWorkout(&workout);
}
