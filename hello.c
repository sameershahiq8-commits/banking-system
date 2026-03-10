#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float balance = 0.0;
char name[50];

void showMenu() {
    printf("\n=============================");
    printf("\n    SJH BANKING SYSTEMS      ");
    printf("\n=============================");
    printf("\n1. Check Balance");
    printf("\n2. Deposit Money");
    printf("\n3. Withdraw Money");
    printf("\n4. Exit");
    printf("\n=============================");
    printf("\nChoice (1-4): ");
}
int main() {
    int choice;
    float amount;

    printf("Welcome to SJH Banking Systems!\n");
    printf("Nee purthi peru (Full Name) enter cheyi: ");
    
    // Space unna names theeskodaniki fgets vadutunnam
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove extra newline character

    while(1) {
        showMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("\nThappu! Numbers (1-4) mathrame enter cheyi.");
            while(getchar() != '\n'); // Clear the buffer
            continue;
        }

        switch(choice) {
            case 1:
                printf("\n[BALANCE] %s, nee account lo %.2f/- unnayi.", name, balance);
                break;

            case 2:
                printf("\nEntha deposit chesthav?: ");
                scanf("%f", &amount);
                if(amount > 0) {
                    balance += amount;
                    printf("Deposit Successful!");
                } else {
                    printf("Amount correct ga enter cheyi.");
                }
                break;

            case 3:
                printf("\nEntha withdraw chesthav?: ");
                scanf("%f", &amount);
                if(amount > balance) {
                    printf("\nError: Inefficient funds!");
                } else {
                    balance -= amount;
                    printf("Withdraw Successful!");
                }
                break;

            case 4:
                printf("\nSJH Banking Systems ni vadinanduku thanks, %s!", name);
                return 0;

            default:
                printf("\nInvalid choice! Malli try cheyi.");
        }
    }
    return 0;
}