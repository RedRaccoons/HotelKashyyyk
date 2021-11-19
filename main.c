#include <stdio.h>
#include <time.h>
#include <string.h>
#include "hotel-functions.h"

typedef char* BookingID;

int main (int argc, char *argv[])
{
  printf("%s", genID("clem"));
  return 0;
}
