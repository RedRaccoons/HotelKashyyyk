#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define USER_PROPERTIES 20 // (e.g) ID, First Name, Surname

typedef char* BookingID; // Last name could be 20 & ID is 4

char* genID(char lName[21])
{
  char* tmp = malloc(sizeof(char) * 24);
  char randomID[5] = { "" };

  for (int i = 0; i < 4; ++i) randomID[i] = rand() % 10 + '0';

  strcat(tmp, lName);
  strcat(tmp, randomID);
  
  return tmp;
}

int main()
{

  srand(time(NULL));

  char firstName[21]; // Do NOT make 20. The reason for it being 20 + 1 is because C adds a terminating character 
  char lastName[21];

  printf("Please enter your name (e.g John Doe)\n");
  scanf("%20s %20s", firstName, lastName);

  BookingID id = genID(lastName);

  printf("%s", id);

  return 0;
}
