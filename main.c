#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hotel-functions.h"

#define MAX_SEATS 4
#define USER_PROPERTIES 4

typedef char* BookingID;
typedef int Table;

/* ## Book a dinner table */
/* There are 3 dining tables: Endor, Naboo and Tatooine that each seat 4 people. */
/* Meals are served at 2 sittings: 7pm and 9pm, every day of the week. */
/* Your program should: */
/* - Ask for the guest’s BookingID and, if it exists in the system (i.e. they are a current guest), it should */
/* check: */
/*   - Whether they are staying FB or HB. If not, they cannot book a table. */
/*   - Then, it must check if there is a free table for the number of people in that party (looked up */
/*   from the booking data) */
/* - Display options showing the table names and the times that have space OR output an unavailable */
/* message if no options exist */
/* - It should then ask the user to input which table & time they want to book. */
/* - If successful, it should give the user a message saying their table is booked and update the tables */
/* available in that area for that sitting time */

char* toLowerCase(char* str);
char* getUserInfo(BookingID id, char* prop);
char* getInput(int maxLength);
int isValidUser(BookingID id);
void removeUser(BookingID id);

// Tables (0 means not available, 1 means available)
const char* tables[9] = { "endor", "naboo", "tatooine" };

// Different Times
int times[2] = { 1900, 2100 };
float boardTimes[2] = { 1, 0.5 }; // 1 meaning full board, 0.5 meaning half board

// Users Array
char* users[12][USER_PROPERTIES][20] = { { "toby1234", "toby", "bridle" }, { "doe1234", "john", "doe" } };
int main (int argc, char *argv[])
{
  char* id;
  char* boardType;
  
  // Get Booking ID
  printf("Booking ID: ");
  id = getInput(19); // Get Input (19 Chars MAXIMUM)
  /* printf("%s", getUserInfo(id, "index")); */
  if(!isValidUser(id)) // If not in Array of Users
  {
    printf("Sorry, it looks like you haven't booked!");
    return 0;
  }
  free(id); // Free the Memory that `id` took up


  // Get Board Type
  printf("Board Type:\t(Full, Half)\n");
  boardType = toLowerCase(getInput(4));
  for(int i = 0; i < sizeof(boardType); ++i) boardType[i] = tolower(boardType[i]);

  if(strcmp(boardType, "full") != 0 && strcmp(boardType, "half") != 0)
  {
    printf("Please enter a valid board type!");
    return 0;
  }

  return 0;
}


char* getInput(int maxLength)
{

  char *tmp = calloc(maxLength + 1, sizeof(char));

  int c;
  int i = 0;
  while( (c = getchar() ) != '\n' && c != EOF && i < maxLength)
  {
    tmp[i] = (char) c;
    i++;
  }

  tmp[maxLength + 1] = 0;
  fflush(stdin); // Clears the input
  return tmp;
}

int isValidUser(BookingID id)
{
  // Return 0 if not a valid user
  // Return 1 if a valid user
  if((int) *id == 0) return 0;
  for (int user = 0; user < 12; ++user)
  {
    if (strcmp(*users[user][0], id) == 0) return 1;
  }
  return 0;
}

char* getUserInfo(BookingID id, char* prop)
{
  if(isspace(*id)) printf("Whitespace!!!!!");
  // Return 0 if not a valid user
  // Return 1 if a valid user
  char *tmp = malloc(sizeof(char) * 3);
  for (int user = 0; user < 12; ++user)
  {
    if (strcmp(*users[user][0], id) == 0)
    {
      switch(*prop)
      {
        case *"firstname":
          return *users[user][1];
        case *"lastname":
          return *users[user][2];
        case *"index":
          sprintf(tmp, "%d", user);
          return (char*) tmp;
      }
    }
  }
  return "Invalid User";
}

char* toLowerCase(char* str)
{
  char* tmp = calloc(strlen(str), sizeof(char));
  for(int ch = 0; ch < sizeof(str); ++ch) tmp[ch] = tolower(str[ch]);
  tmp[strlen(str)] = 0;

  return tmp;
}
