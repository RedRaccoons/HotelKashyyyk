#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define USER_PROPERTIES 4 // (e.g) ID, First Name, Surname

typedef char* BookingID; // Last name could be 20 & ID is 4
typedef char User[USER_PROPERTIES + 1][20]; // 20 is the Max Length of Name

char* genID(char lastName[21])
{
  char randomID[5] = { "" };
  for (int i = 0; i < 4; ++i) randomID[i] = rand() % 10 + '0';
  strcat(lastName, randomID);
  return lastName;
}

int main()
{

  srand(time(NULL));

  char firstName[21]; // Do NOT make 20. The reason for it being 20 + 1 is because C adds a character itself
  char lastName[21];

  printf("Please enter your name (e.g John Doe)\n");
  scanf("%20s %20s", firstName, lastName);

  BookingID id = genID(lastName);

  User user1 = { *id, *firstName, *lastName };
  printf("%s", user1[0]);
  printf("%s", id);
  return 0;
}
