#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "file_io.h"

void saveWorkoutLog(WORKOUT_T* p_workout)
{
  FILE * p_file;

  char * mode = "a";

  switch(p_workout->day)
  {
    case DEADLIFT_DAY:
      p_file = fopen("deadlifts.log", mode);
      break;
    case HEAVY_BENCH_DAY:
      p_file = fopen("heavy_bench.log", mode);
      break;
    case SQUAT_DAY:
      p_file = fopen("squats.log", mode);
      break;
    case VOLUME_BENCH_DAY:
      p_file = fopen("volume_bench.log", mode);
      break;
    default:
      break;
  }

  fprintf(p_file, p_workout->ex[0].name);
  fprintf(p_file, "\n");

  fclose(p_file);
}

int checkDuplicateMainLift(WORKOUT_T* p_workout)
{
  FILE * p_file;
  char * mode = "r+";

  int buffer_len = 64;
  char line[buffer_len];
  char buffer[3][buffer_len]; // only care about 3 weeks worth of info at a time
  
  switch(p_workout->day)
  {
    case DEADLIFT_DAY:
      p_file = fopen("deadlifts.log", mode);
      break;
    case HEAVY_BENCH_DAY:
      p_file = fopen("heavy_bench.log", mode);
      break;
    case SQUAT_DAY:
      p_file = fopen("squats.log", mode);
      break;
    case VOLUME_BENCH_DAY:
      p_file = fopen("volume_bench.log", mode);
      break;
    default:
      break;
  }

  // FUCK SEG FAULTS FROM FILE IO
  if(p_file == NULL)
  {
    return 0;
  }

  // Read 3 lines at a time until end
  // This isn't efficient but we're not doing big data shit
  int line_count = 0;
  while(fgets(line, buffer_len, p_file) != NULL)
  {
    line[strcspn(line, "\n")] = 0;
    strcpy(buffer[line_count], line);
    line_count++;
    if(line_count >= 3)
    {
      line_count = 0;
    }
  }

  char name[64];
  strcpy(name, p_workout->ex[0].name);

  int i = 0;
  int duplicate = 0;

  if(line_count > 0)
  {
    for(i; i < 4; i++)
    {
      if(strncmp(name, buffer[i], 64) == 0) // found duplicate
      {
        duplicate = 1;
      }
    }
  }

  fclose(p_file);

  return duplicate;
}