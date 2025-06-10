// TITLE          :       BITWISE PERMISSIONS MANAGER         
// AUTHOR         :       ichimaru001
// DATE           :       10/06/25
// 
// DESCRIPTION    :       USERS HAVE PERMISSIONS.
//                        PERMISSIONS SET BY FLIPPING BITS.
// 2hr 23min

#define ADD_BITS 0
#define SUBTRACT_BITS 1

#include <stdio.h>

typedef enum {
  READ_FILES = 0b1,
  WRITE_FILES = 0b10,
  DELETE_FILES = 0b100,
  CREATE_FILES = 0b100,
  EXECUTE_FILES = 0b1000,
  SUM_NUM_PERMISSIONS,
} permissions;
int addSubtractPermissions();
void checkAndPrintPermissions();

int main() {
  unsigned int flagPermissions = 0b00000000;

  int userChoice = 0;


  char permissionsNames[][50] = {
      "Read files",
      "Write files",
      "Delete files",
      "Create files",
      "Execute files"
  };
  char menuOptions[][50] = {
    "Grant permissions",
    "Revoke permissions",
    "Check permissions",
    "Exit"
  };
  int numberOfMenuOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);


  do
  {
    // *** MAIN MENU
    printf("\n*** BITWISE PERMISSIONS MANAGER ***\n");
    for (int i = 1; i <= numberOfMenuOptions; i++)
    {
      printf("%d. %s\n", i, menuOptions[i]);
    }
    if (userChoice == 1) {
      printf("\n** GRANTING PERMISSION **\n");
      int userGrantChoice = 0;

      for (int i = 1; i <= SUM_NUM_PERMISSIONS; i++)
      {
        printf("%d. %s\n", i, permissionsNames[i]);

      }
      printf("Enter your choice: ");
      scanf(" %d", &userGrantChoice);

      flagPermissions = addSubtractPermissions(ADD_BITS, userChoice, &flagPermissions);
    }
    if (userChoice == 2) {
      printf("\n** REVOKING PERMISSION **\n");
      int userGrantChoice = 0;

      for (int i = 1; i <= SUM_NUM_PERMISSIONS; i++)
      {
        printf("%d. %s\n", i, permissionsNames[i]);

      }
      printf("Enter your choice: ");
      scanf(" %d", &userGrantChoice);

      flagPermissions = addSubtractPermissions(SUBTRACT_BITS, userChoice, &flagPermissions);
    }
    if (userChoice == 3) {
      printf("\n** VIEWING USER PERMISSIONS **\n");
    }


  } while (userChoice != 4);





}

int addSubtractPermissions(int flagAddSubtract, int userChoice, int *flagPermissions) {
  switch (userChoice)
  {
  case 1:
    return (flagAddSubtract == 0) ? (*flagPermissions |= READ_FILES) : (*flagPermissions &= ~READ_FILES);
    break;
  case 2:
    return (flagAddSubtract == 0) ? (*flagPermissions |= WRITE_FILES) : (*flagPermissions &= ~WRITE_FILES);
    break;
  case 3:
    return (flagAddSubtract == 0) ? (*flagPermissions |= DELETE_FILES) : (*flagPermissions &= ~DELETE_FILES);
    break;
  case 4:
    return (flagAddSubtract == 0) ? (*flagPermissions |= CREATE_FILES) : (*flagPermissions &= ~CREATE_FILES);
    break;
  case 5:
    return (flagAddSubtract == 0) ? (*flagPermissions |= EXECUTE_FILES) : (*flagPermissions &= ~EXECUTE_FILES);
    break;
  default:
    printf("\nUser choice was invalid!\n");
    break;
  }
};

// void checkAndPrintPermissions(int *flagPermissions) {
//   int startingBit = 0b1;

//   for (int i = 1; i <= SUM_NUM_PERMISSIONS; i++)
//   {
//     printf("%s : %d. %s\n", (), );
//     startingBit<<1;
//   }

// }