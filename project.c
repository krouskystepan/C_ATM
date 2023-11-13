#include <stdio.h>

// Function prototypes
void displayMenu();
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);
int changePIN(int oldPIN);

int main() {
    // Hardcoded initial balance and PIN
    float balance = 1000.0;
    int pin = 1234;

    printf("Welcome to the ATM!\n");

    int enteredPin;
    printf("Please enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin == pin) {
        int choice;

        do {
            // Display menu
            displayMenu();

            // Prompt for user choice
            printf("Enter your choice: ");
            scanf("%d", &choice);

            // Perform the selected operation
            switch (choice) {
                case 1:
                    checkBalance(balance);
                    break;
                case 2:
                    balance = deposit(balance);
                    break;
                case 3:
                    balance = withdraw(balance);
                    break;
                case 4:
                    pin = changePIN(pin);
                    break;
                case 5:
                    printf("Thank you for using the ATM. Goodbye!\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 5);
    } else {
        printf("Invalid PIN. Exiting...\n");
    }

    return 0;
}

void displayMenu() {
    printf("\nATM Menu:\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
}

void checkBalance(float balance) {
    printf("Your balance is: $%.2f\n", balance);
}

float deposit(float balance) {
    float amount;
    printf("Enter the deposit amount: $");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Deposit successful. New balance: $%.2f\n", balance);
    } else {
        printf("Invalid amount. Deposit failed.\n");
    }

    return balance;
}

float withdraw(float balance) {
    float amount;
    printf("Enter the withdrawal amount: $");
    scanf("%f", &amount);

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Withdrawal successful. New balance: $%.2f\n", balance);
    } else {
        printf("Invalid amount or insufficient funds. Withdrawal failed.\n");
    }

    return balance;
}

int changePIN(int oldPIN) {
    int newPIN;
    printf("Enter your new PIN: ");
    scanf("%d", &newPIN);
    printf("Your new PIN is: %d\n", newPIN);
    printf("PIN changed successfully!\n");
    return newPIN;
}
