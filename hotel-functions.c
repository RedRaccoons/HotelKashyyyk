#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hotel-functions.h"


char* genID(char lName[21])
{
  srand(time(NULL));
  char* tmp = malloc(sizeof(char) * 24);
  char randomID[5] = { "" };

  for (int i = 0; i < 4; ++i) randomID[i] = rand() % 10 + '0';

  strcat(tmp, lName);
  strcat(tmp, randomID);
  
  return tmp;
  free(tmp);
}
