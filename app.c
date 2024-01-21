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
  WORKOUT_DAYS_ENUM day;
  // User selection
  printf("What kind of workout?\n");
  printf("---------------------\n");
  printf("\
    1 - Max Effort Lower\n\
    2 - Max Effort Upper\n\
    3 - Dynamic Effort Lower\n\
    4 - Dynamic Effort Upper\n");
  printf("selection: ");
  scanf("%d", &day);
  
  printf("\n");

  // Generate workout
  WORKOUT_T workout = getExercises(day - 1); // fix index from menu
  setRepSchemes(&workout);
  printWorkout(&workout);
}



