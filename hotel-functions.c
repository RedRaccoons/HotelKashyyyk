#include "hotel-functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *genID(char lastname[21]) {
  srand(time(NULL));
  char *tmp = malloc(sizeof(char) * 24);
  char randomID[5] = {""};

  for (int i = 0; i < 4; ++i)
    randomID[i] = rand() % 10 + '0';
  strncpy(tmp, lastname, 3);
  strcat(tmp, randomID);

  return tmp;
}
