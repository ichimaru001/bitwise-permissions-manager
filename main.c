// TITLE          :       BITWISE PERMISSIONS MANAGER         
// AUTHOR         :       ichimaru001
// DATE           :       10/06/25
// -
// DESCRIPTION    :       USERS HAVE PERMISSIONS.
//                        PERMISSIONS SET BY FLIPPING BITS.
// -
// TIME TAKEN     :       1HR 11MIN
// TO COMPLETE

#define ADD_BITS 0
#define SUBTRACT_BITS 1

#include <stdio.h>

typedef enum {
  READ_FILES = 0b00000001,
  WRITE_FILES = 0b00000010,
  DELETE_FILES = 0b00000100,
  CREATE_FILES = 0b000001000,
  EXECUTE_FILES = 0b000010000,
  SUM_NUM_PERMISSIONS,
} permissions;
char permissionsNames[][50] = {
    "Read files",
    "Write files",
    "Delete files",
    "Create files",
    "Execute files"
};
int addSubtractPermissions();
void checkAndPrintPermissions();

int main() {
  unsigned int flagPermissions = 0b00000000;

  int userChoice = 0;


  char menuOptions[][50] = {
    "Grant permissions",
    "Revoke permissions",
    "Check permissions",
    "Exit"
  };
  int numberOfMenuOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
  int numberOfPermissions = sizeof(permissionsNames) / sizeof(permissionsNames[0]);


  do
  {
    // *** MAIN MENU
    printf("\n*** BITWISE PERMISSIONS MANAGER ***\n");
    // printf("\nflagPermissions is currently : %d\n", flagPermissions);
    for (int i = 1; i <= numberOfMenuOptions; i++)
    {
      printf("%d. %s\n", i, menuOptions[i - 1]);
    }
    printf("Enter your choice: ");
    scanf(" %d", &userChoice);

    if (userChoice == 1) {
      printf("\n** GRANTING PERMISSION **\n");
      int userGrantChoice = 0;

      checkAndPrintPermissions(&flagPermissions, numberOfPermissions);

      printf("Enter your choice: ");
      scanf(" %d", &userGrantChoice);

      printf("\nYour choice was: %d\n", userGrantChoice);

      flagPermissions = addSubtractPermissions(ADD_BITS, userGrantChoice, &flagPermissions);

      printf("\nSuccessfully granted a permission!\n");
    }
    if (userChoice == 2) {
      printf("\n** REVOKING PERMISSION **\n");
      int userRevokeChoice = 0;

      checkAndPrintPermissions(&flagPermissions, numberOfPermissions);
      printf("Enter your choice: ");
      scanf(" %d", &userRevokeChoice);

      printf("\nYour choice was: %d\n", userRevokeChoice);

      flagPermissions = addSubtractPermissions(SUBTRACT_BITS, userRevokeChoice, &flagPermissions);

      printf("\nSuccessfully revoked a permission!\n");
    }
    if (userChoice == 3) {
      printf("\n** VIEWING USER PERMISSIONS **\n");
      checkAndPrintPermissions(&flagPermissions, numberOfPermissions);
    }
  } while (userChoice != 4);


  return 0;
}

int addSubtractPermissions(int flagAddSubtract, int userGrantRevokeChoice, int *flagPermissions) {
  switch (userGrantRevokeChoice)
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

void checkAndPrintPermissions(int *flagPermissions, int numberOfPermissions) {
  int startingBit = 0b00000001;
  for (int i = 1; i <= numberOfPermissions; i++)
  {
    printf("%s : %d. %s\n", (*flagPermissions & startingBit) ? ("ON ") : ("OFF"), i, permissionsNames[i - 1]);
    startingBit = startingBit << 1;
  }
}