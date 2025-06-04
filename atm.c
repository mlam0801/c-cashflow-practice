/*
Melody Lam
09/17/2023
ATM Machine
Write a C Program for an ATM machine by implementing functions for 4 options(Balance, Withdrawals, Deposits, Quit)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int PIN = 3014;

int validation(){
    int attemptAmt = 0;
    int pinInput;

    printf("Welcome user, your card has been inserted. Please input your PIN to continue.(For use purposes pin in 3014)\n");
    scanf("%d", &pinInput);
    while(pinInput != PIN){
        attemptAmt++;
        if(attemptAmt == 3){
        printf("You have reached your maximum number of PIN attempts. We will now eject your card.\n");
        return 0;
        }
        printf("Invalid PIN has been entered, please try again. You have %d tries remaining.\n", 3-attemptAmt);
        scanf("%d", &pinInput);
    }
        return 1;
}

void menu(){
    puts("Welcome user, please pick an option from below to perform in your account.");
    puts("1. Balance");
    puts("2. Cash withdrawal");
    puts("3. Cash deposition");
    puts("4. Quit");
}

void bal(double balance){
    printf("Balance: $%.2lf\n", balance);
}

double withdrawal(double bal, double withdrawn){
    double withdrawalAmt;
    double test;
    
    printf("%s", "Please enter the amount you would like to withdraw.\nThis ATM will only allow you to withdraw in increments of 20.\n");
    scanf("%lf", &withdrawalAmt);
    
    while(withdrawn + withdrawalAmt > 1000 || withdrawalAmt <= 0 || remainder(withdrawalAmt, 20.0) != 0){
        if(withdrawn + withdrawalAmt > 1000){
            printf("The amount you have entered exceeds the withdrawal limit. You have $%.2lf in available withdrawals remaining. Try again with a valid amount.\n", 1000 - withdrawn);
            return bal;
        }
        else if(remainder(withdrawalAmt, 20.0) != 0){
            puts("This machine does not take that arrangement of bills/coins, try again with a valid amount.");
        }
        else{
            puts("You have entered an invalid amount, we will try again.");
        }
        printf("%s", "Please enter the amount you would like to withdraw.\nThis ATM will only allow you to withdraw in increments of 20.\n");
        scanf("%lf", &withdrawalAmt);
    }

    bal -= withdrawalAmt;

    return bal;
}

double deposition(double bal, double deposited){
    double depositAmt;
    
    printf("Please enter the amount you would like to deposit.\nThis ATM will only allow you to deposit bills, NO coins.\n");
    scanf("%lf", &depositAmt);
    
    while(deposited + depositAmt > 10000 || depositAmt <= 0 || remainder(depositAmt, 1.0) != 0){
        if(deposited + depositAmt > 10000){
            printf("The amount you have entered exceeds the deposit limit. You have $%.2lf in available deposits remaining. Try again with a valid amount.\n", 10000 - deposited);
            return bal;
        }
        else{
            (remainder(depositAmt, 1.0) != 0? puts("This machine does not take any coins, try again with only bills."):puts("You have entered an invalid amount, we will try again."));
        }
        printf("Please enter the amount you would like to deposit.\nThis ATM will only allow you to deposit bills, NO coins.\n");
        scanf("%lf", &depositAmt);
    }
    bal += depositAmt;

    return bal;
}

void quit(int transAmt){
    int receiptOption;

    printf("Thank you for using our ATM today, Nana. You have made %d transactions.\n", transAmt);
    puts("Would you like a receipt? Enter 1 for yes or 2 for no");
    scanf("%d", &receiptOption);
    while(receiptOption != 1 && receiptOption != 2){
    puts("That is an invalid selection, please enter 1 for a receipt or 2 for no receipt");
    scanf("%d", &receiptOption);
    }
    (receiptOption == 1? puts("Printing your receipt. Goodbye"):puts("Goodbye."));
}


int main(int argc, char** argv){

    int transactionAmt = 0;
    double withdrawnAmt = 0;
    double depositedAmt = 0;
    double balance = 5000;
    int userInput;
    double tempBal;
    int security;
    
    //takes in PIN and if 3 attempts are reached without correct pin, program terminates
    security = validation();
    if(security == 0){
        return 0;
    }

    menu();
    
    scanf("%d", &userInput);
while(userInput!= 4){

    if(userInput == 1){
        bal(balance);
    }
    else if(userInput ==2){
        tempBal = balance;
        balance = withdrawal(balance, withdrawnAmt);
        withdrawnAmt += tempBal - balance;
        transactionAmt++;
    }
    else if(userInput == 3){
        tempBal = balance;
        balance = deposition(balance, depositedAmt);
        depositedAmt = balance - tempBal;
        transactionAmt++;
    }

    menu();
    scanf("%d", &userInput);
}

quit(transactionAmt);
return 0;
}