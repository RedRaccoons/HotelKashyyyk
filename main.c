#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 4

#define ARRAY_LEN(arr) (size_t)(sizeof(arr)/sizeof((arr)[0]))
#define PARTY_SIZE(party) ((int) *users[party][2] + (int) *users[party][3]) - '0' - '0'

typedef char BookingID[7];

float isUser(BookingID id);

char tables[4][10] = {"Endor", "Naboo", "Tatooine"};
int sittings[2] = {1700, 1900};
int tableAvailable[ARRAY_LEN(sittings)][ARRAY_LEN(tables) - 1] = { 0 }; // 0 Means is Free, 1 not Free 

/* Format
* 1 User:
*   [0 - 5] BookingID
*   [6-15] DOB 
*   [16] Amount of Children
*   [17] Amount of Adults
*   [18-19] Board Type 
*   [20] Newpape
*   [21] Booking
*/
//                           BookingID    DOB       Kids  Adults Board
char users[100][9][11] = { { "tob123", "21/06/2005", "1", "2", "HB", "A", "B"}, { "dav461" } };
int main() {
  BookingID id;
  printf("\033cPlease enter your Booking ID\t(e.g doe123)\n");
  fgets(id, 7, stdin);

  int userDataIndex = isUser(id);

  // Check if Valid User
  if(userDataIndex == -1)
  {
    printf("Not a Valid Booking ID!");
    return 1;
  }

  // Check if Full / Half Board
  if(strcmp(users[userDataIndex][4], "HB") != 0 && strcmp(users[userDataIndex][4], "FB") != 0)
  {
    printf("You cannot book a table!");
    return 1;
  }

  // Check if theres a free table
  printf("\n\nSeats Available\t\tParty Size - %d\n\t\tTimes\n\t17:00\t\t19:00\n\n", PARTY_SIZE(userDataIndex));
  for (int table = 0; table < ARRAY_LEN(tables) - 1; table++)
  {
    // Set Color

    char *color;
    if(tableAvailable[0][table] == 0 && MAX_SEATS >= PARTY_SIZE(userDataIndex)) color = "\033[0;32m";      // Green
    if(tableAvailable[0][table] == 1 || MAX_SEATS < PARTY_SIZE(userDataIndex)) color = "\033[0;31m";   // Red

    table != (ARRAY_LEN(tableAvailable))-1 ? printf("\t%s%d. %s\t", color, table + 1, tables[table]) : printf("\t%s%d. %s\t", color, table + 1, tables[table]);

    if(tableAvailable[1][table] == 0 && MAX_SEATS >= PARTY_SIZE(userDataIndex)) color = "\033[0;32m";      // Green
    if(tableAvailable[1][table] == 1 || MAX_SEATS < PARTY_SIZE(userDataIndex)) color = "\033[0;31m";   // Red

    printf("%s%lu. %s\n", color, table + ARRAY_LEN(tables), tables[table]);

    // Reset Color
   if(table == (ARRAY_LEN(tables)) - 2) printf("\033[0m\n");

  }


  printf("Which Table would you like to Book?\t(0 to exit)\n\n");
  char tableNum[ARRAY_LEN(tables[0])];
  fflush(stdin);
  fgets(tableNum, ARRAY_LEN(tables[0]) , stdin);

  char* end;
  int tn = strtol(tableNum, &end, 10);
  // printf("%d, %lu", tn, ARRAY_LEN(tables)-2);
  if(tn - 1 > ARRAY_LEN(tables) - 2)
  {
    if(tableAvailable[1][tn - ARRAY_LEN(tables)] == 1){
      printf("Sorry, that table has already been booked!\n");
    } else {
      tableAvailable[1][tn - ARRAY_LEN(tables)] = 1;
      printf("Booked %s for 19:00", tables[ tn - (ARRAY_LEN(tables)) ]);
    }
  } else {
    if(tableAvailable[0][tn-1] == 1){
      printf("Sorry, that table has already been booked!\n");
    } else {
      tableAvailable[0][tn-1] = 1;
      printf("Booked %s for 17:00", tables[tn-1]);
    }
  }
}

// Return the User Index of a Valid User
float isUser(BookingID id) {
  // If is user, return the index it is at
  // Else, return -1

  for (int user_count = 0; user_count < ARRAY_LEN(users); user_count++){
    if(users[user_count][0][0] == 0) return -1; // Just the initialised value
    if(strcmp(users[user_count][0], id) == 0) return user_count; // Found User
  }
  return -1;
}
