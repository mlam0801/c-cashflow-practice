/* 
Melody Lam
09/10/23
calculate paycheck for Temple employee based on the hourlySalary, weeklyTime, and overtime
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void goodbye(){
    printf("\nThank You for using \"TEMPLE HUMAN RESOURCES\"\n");
}

int main(int argc, char** argv){

    double hourlySalary;
    double weeklyTime;
    double empNum;
    double netPay;
    double overtimePay;
    double regularPay;
    double decimal;

    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");
    printf("\tEnter Employee Number: ");
    scanf("%lf", &empNum);
    if(empNum < 0 || modf(empNum, &decimal) > 0 ){ //make sure the number is an integer
        printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n");
        goodbye();
        return 0;
    }
    
    printf("\tEnter Hourly Salary: ");
    scanf("%lf", &hourlySalary);
    if(hourlySalary < 0){
        printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n");
        goodbye();
        return 0;
    }
    printf("\tEnter Weekly Time: ");
    scanf("%lf", &weeklyTime);
    if(weeklyTime < 0){
        printf("\n\tThis is not a valid weekly time.\n\tPlease run the program again\n");
        goodbye();
        return 0;
    }
    
    if(weeklyTime <= 40){
        overtimePay = 0;
        regularPay = weeklyTime*hourlySalary;
        netPay = regularPay;
    }
    else{
        overtimePay = (weeklyTime-40)*1.5*hourlySalary;
        regularPay = 40*hourlySalary;
        netPay = regularPay + overtimePay;
    }
    
    printf("\t==============================\n");
    printf("\tEmployee #: %.0lf\n", empNum);
    printf("\tHourly Salary: $%.1lf\n", hourlySalary);
    printf("\tWeekly Time: %.1lf\n", weeklyTime);
    printf("\tRegular Pay: $%.1lf\n", regularPay);
    printf("\tOvertime Pay: $%.1lf\n", overtimePay);
    printf("\tNet Pay: $%.1lf\n", netPay);
    printf("\t==============================\n");
    goodbye();
    return 0;
}