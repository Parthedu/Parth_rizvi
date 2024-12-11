#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234;  // The preset PIN for the user
    int enteredPin, choice;
    double balance;
    double amount;
    FILE *file;

    // PIN Authentication
    printf("\t\t\t***** ATM INTERFACE******\t\t\t\n");
    printf("Enter PIN to access your account: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Incorrect PIN. Access denied.\n");
        return 0;
    }

    // Open the file containing the balance
    file = fopen("account_balance.txt", "r");

    // If the file doesn't exist, create it with a starting balance
    if (file == NULL) {
        printf("Account balance file not found. Creating a new file with balance $1000.00\n");
        balance = 1000.0;  // Default starting balance
        file = fopen("account_balance.txt", "w");
        if (file == NULL) {
            printf("Error creating balance file.\n");
            return 1;
        }
        fprintf(file, "%.2f\n", balance);  // Write starting balance to file
        fclose(file);
    } else {
        // Read the balance from the file
        fscanf(file, "%lf", &balance);
        fclose(file);
    }

    // ATM Menu
    while (1) {
        printf("\nATM Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Check balance
                printf("Your current balance is: $%.2f\n", balance);
                break;

            case 2:  // Deposit money
                printf("Enter amount to deposit: $");
                scanf("%lf", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("You have successfully deposited $%.2f.\n", amount);
                    // Update balance in file
                    file = fopen("account_balance.txt", "w");
                    if (file == NULL) {
                        printf("Error opening balance file for writing.\n");
                        return 1;
                    }
                    fprintf(file, "%.2f\n", balance);
                    fclose(file);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:  // Withdraw money
                printf("Enter amount to withdraw: $");
                scanf("%lf", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("You have successfully withdrawn $%.2f.\n", amount);
                    // Update balance in file
                    file = fopen("account_balance.txt", "w");
                    if (file == NULL) {
                        printf("Error opening balance file for writing.\n");
                        return 1;
                    }
                    fprintf(file, "%.2f\n", balance);
                    fclose(file);
                } else if (amount > balance) {
                    printf("Insufficient funds. Your current balance is $%.2f.\n", balance);
                } else {
                    printf("Invalid withdrawal amount.\n");
                }
                break;

            case 4:  // Exit
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        } }return 0;
}
