#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void signup(void);
void login(void);
void adventureGame(void);

struct {
    char password[20];
    char username[20];
} s;

FILE *fp;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int ch;

    while (1) {
        printf("\n");
        printf("******************************************\n");
        printf("*        Welcome to BNMIT                *\n");
        printf("******************************************\n");
        printf("\n");
        printf("1. Sign Up\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n");
                printf("******************************************\n");
                printf("*             Sign Up                    *\n");
                printf("******************************************\n");
                signup();
                break;

            case 2:
                printf("\n");
                printf("******************************************\n");
                printf("*             Login                      *\n");
                printf("******************************************\n");
                login();
                break;

            case 3:
                printf("\nThank you for using our platform!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        clearInputBuffer();
    }

    return 0;
}

void login() {
    char username[20];
    char pass[20];
    int validUser = 0;

    printf("Enter UserName: ");
    scanf("%19s", username);

    // Clear the input buffer
    clearInputBuffer();

    printf("Enter Password: ");

    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < 20 - 1) {
        pass[i++] = c;
    }
    pass[i] = '\0';

    fp = fopen("record.bin", "rb");
    if (fp == NULL) {
        printf("\nFile not found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        int chku = strcmp(username, s.username);
        int chkp = strcmp(pass, s.password);

        if (chku == 0 && chkp == 0) {
            printf("\nWelcome, %s! You've successfully logged in.\n", s.username);
            validUser = 1;
            break;
        }
    }

    fclose(fp);

    if (!validUser) {
        printf("\nInvalid Username or Password!\n");
    }

    printf("\nPress Enter to continue...");
    clearInputBuffer();

    if (validUser) {
        adventureGame(); // Call the adventure game function
    }
}

void signup() {
    char c;

    fp = fopen("record.bin", "ab");
    if (fp == NULL) {
        printf("\nFile not found.\n");
        return;
    }

    printf("Set UserName: ");
    scanf("%19s", s.username);

    // Clear the input buffer
    clearInputBuffer();

    printf("Set Password: ");
    int i = 0;
    while ((c = getchar()) != '\n' && i < 20 - 1) {
        s.password[i++] = c;
    }
    s.password[i] = '\0';

    fwrite(&s, sizeof(s), 1, fp);
    printf("\nAccount created successfully!\n");

    fclose(fp);
    printf("\nPress Enter to continue...");
    clearInputBuffer();
}

void adventureGame() {
    char startingPoint, destination;

    printf("\n");
    printf("******************************************\n");
    printf("*            Navigation                  *\n");
    printf("******************************************\n");
    printf("\n");

    // Get starting point
    printf("Choose starting point:\n");
    printf("A. College Main Gate\n");
    printf("B. Main Building\n");
    printf("C. Canteen\n");
    printf("D. N block\n");
    printf("E. S block\n");
    startingPoint = getchar();
    clearInputBuffer();

    // Get destination
    printf("Choose destination:\n");
    printf("A. Auditorium\n");
    printf("B. S Block\n");
    printf("C. N Block\n");
    printf("D. IOT labs\n");
    printf("E. Main Building\n");
    printf("F. Physics Lab\n");
    printf("G. Chemistry Lab\n");
    printf("H. CPC Labs\n");
    printf("I. Seminar Hall\n");
    destination = getchar();
    clearInputBuffer();

    printf("\n");

    // Add the adventure game logic with comparisons
    if (startingPoint == 'A') {
        if (destination == 'A') {
            printf("Directions: Come a little bit straight, turn right, go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 4th floor.\n");
        } else if (destination == 'B') {
            printf("Directions: Come a little bit straight, turn left, take the stairs on the left side, go straight. You'll find the S Block on your right.\n");
        } else if (destination == 'C') {
            printf("Directions: Come a little bit straight, turn left, take the stairs on the left side, go right, go straight a little bit, take the left, and you'll find N Block on your right.\n");
        } else if (destination == 'D') {
            printf("Directions: Come a little bit straight, turn left, take the stairs on the left side, go right, go straight a little bit, take the left, and you'll find N Block on your right,then take stairs and go to 6th floor ,there you find the IOT labs\n");
        } else if (destination == 'E') {
            printf("Directions: Come a little bit straight, turn right and go little bit straight on your left main building\n");
        } else if (destination == 'F') {
            printf("Directions: Come a little bit straight, turn right, go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 3rd floor ,there you find the physics lab\n");
        } else if (destination == 'G') {
            printf("Directions: Come a little bit straight, turn right, go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 3rd floor ,there you find the chemistry lab\n");
        } else if (destination == 'H') {
            printf("Directions: Come a little bit straight, turn right and go little bit straight on your left main building,in ground floor M006 room and then in 2nd floor M201 \n");
        } else if (destination == 'I') {
            printf("Directions: Come a little bit straight, turn right, go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 2nd floor,there you find seminar hall\n");
        } else {
            printf("Invalid destination.\n");
        }
    } else if (startingPoint == 'B') {
        if (destination == 'A') {
            printf("go little bit straight,take left,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 4th floor.\n");
        } else if (destination == 'B') {
            printf("Directions: Come a little bit straight, turn right, go straight and take the stairs, go straight, You'll find the S Block on your right.\n");
        } else if (destination == 'C') {
            printf("Directions: Come a little bit straight, turn right, go straight and take stairs, go right, go straight a little bit, take the left, and you'll find N Block on your right.\n");
        } else if (destination == 'D') {
            printf("Directions: Come a little bit straight, turn right, go straight and take stairs, go right, go straight a little bit, take the left, and you'll find N Block on your right,then take stairs and go to 6th floor ,there you find the IOT labs\n");
        } else if (destination == 'E') {
            printf("you are in main block only");
        } else if (destination == 'F') {
            printf("Directions: Come a little bit straight, turn left, go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 3rd floor ,there you find the physics lab\n");
        } else if (destination == 'G') {
            printf("Directions: Come a little bit straight, turn left, go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 3rd floor ,there you find the chemistry lab\n");
        } else if (destination == 'H') {
            printf("you are in same building,in ground floor M006 room and then in 2nd floor M201");
        } else if (destination == 'I') {
            printf("Directions: Come a little bit straight, turn left, go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 2nd floor,there you find seminar hall\n");
        } else {
            printf("Invalid destination.\n");
        }
    } else if (startingPoint == 'C') {
        if (destination == 'A') {
            printf("Directions:in the same floor, take the nearby stairs go to 4rth floor there you find auditorium\n");
        } else if (destination == 'B') {
            printf("Directions:take right from canteen,go straigt pass the main building and take stairs,go straight, You'll find the S Block on your right. \n");
        } else if (destination == 'C') {
            printf("Directions:take right from canteen,go straigt pass the main building and take stairs,go right, go straight a little bit, take the left, and you'll find N Block on your right. \n");
        } else if (destination == 'D') {
            printf("Directions:take right from canteen,go straigt pass the main building and take stairs,go right, go straight a little bit, take the left, and you'll find N Block on your right,then take stairs and go to 6th floor ,there you find the IOT labs \n");
        } else if (destination == 'E') {
            printf("Directions: take right from canteen,go straigt on your right you will get main building\n");
        } else if (destination == 'F') {
            printf("Directions: take the nearby stairs ,go to 3rd floor ,there you find physics lab\n");
        } else if (destination == 'G') {
            printf("Directions: take the nearby stairs ,go to 3rd floor ,there you find chemistry lab\n");
        } else if (destination == 'H') {
            printf("Directions:take right from canteen,go straigt on your right you will get main building,in ground floor M006 room and then in 2nd floor M201\n");
        } else if (destination == 'I') {
            printf("Directions: take the nearby stairs ,go to 2nd floor ,there you find seminar hall\n");
        } else {
            printf("Invalid destination.\n");
        }
    } else if (startingPoint == 'D') {
        // ... (Similar logic for other starting points)
        if (destination == 'A') {
            printf("Directions: go left,go little bit straing then take right,go little bit straight take left by stairs,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 4th floor.\n");
        } else if (destination == 'B') {
            printf("Directions: in the front of you\n");
        } else if (destination == 'C') {
            printf("Directions: you are in  N block only\n");
        } else if (destination == 'D') {
            printf("Directions: in the same block, take stairs ,go to 6th floor,there you find IOT labs\n");
        } else if (destination == 'E') {
            printf("rections: go left,go little bit straing then take right,go little bit Distraight take left by stairs,go straight in your left you find main building\n");
        } else if (destination == 'F') {
            printf("Directions: go left,go little bit straing then take right,go little bit straight take left by stairs,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 3rd floor,there you find physics lab\n");
        } else if (destination == 'G') {
            printf("Directions: go left,go little bit straing then take right,go little bit straight take left by stairs,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 3rd floor,there you find physics lab\n");
        } else if (destination == 'H') {
            printf("Directions: go left,go little bit straing then take right,go little bit Distraight take left by stairs,go straight in your left you find main building,in ground floor M006 room and then in 2nd floor M201\n");
        } else if (destination == 'I') {
            printf("Directions: go left,go little bit straing then take right,go little bit straight take left by stairs,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 2nd  floor,there you find seminar hall.\n");
        } else {
            printf("Invalid destination.\n");
        }
    } else if (startingPoint == 'E') {
        // ... (Similar logic for other starting points)
        if (destination == 'A') {
            printf("Directions:take left,go little bit straight take stairs,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 4th floor.\n");
        } else if (destination == 'B') {
            printf("Directions: you are in S block only.\n");
        } else if (destination == 'C') {
            printf("Directions: in backside of s block.\n");
        } else if (destination == 'D') {
            printf("Directions: go to back side ,you get N block ,take stairs ,go to 6th floor,there you find IOT labs.\n");
        } else if (destination == 'E') {
            printf("Directions:left,go little bit straight take stairs,go straight in your left you find main building. \n");
        } else if (destination == 'F') {
            printf("Directions:take left,go little bit straight take stairs,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 3rd floor,there you find the physics lab\n");
        } else if (destination == 'G') {
            printf("Directions:take left,go little bit straight take stairs,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 3rd floor,there you find the chemistry lab\n");
        } else if (destination == 'H') {
            printf("Directions:left,go little bit straight take stairs,go straight in your left you find main building,in ground floor M006 room and then in 2nd floor M201\n");
        } else if (destination == 'I') {
            printf("Directions: take left,go little bit straight take stairs,go straight until the auditorium block. Then take the first left , and nearby there is stairs. Go to the 2nd floor,there you find the seminar lab\n");
        } else {
            printf("Invalid destination.\n");
        }
    } else {
        printf("Invalid starting point.\n");
    }

    printf("\nPress Enter to continue...");
    clearInputBuffer();
}