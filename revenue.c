/* 
Melody Lam
09/10/23
calculate the revenue from a sale based on the unit price and quantity of a product input by the user
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void goodbye(){
    printf("\nThank You for using \"Temple\" store\n");
}

int main(int argc, char** argv){

double itemPrice;
double quantity;
double decimal;
double cost;
double discount;
double discAmt;
double total;


printf("Welcome to \"Temple\" store\n\n");
printf("\tEnter item price: ");
scanf("%lf", &itemPrice);
if(itemPrice < 0){
    printf("\n\tThis is not a valid item price.\n\tPlease run the program again\n");
    goodbye();
    return 0;
}

printf("\tEnter quantity: ");
scanf("%lf", &quantity);
if(quantity < 0 || modf(quantity, &decimal) > 0 ){
    printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n");
    goodbye();
    return 0;
}

cost = quantity*itemPrice;
if(quantity >= 1 && quantity <= 49){
    discount = 0;
    discAmt = 0;
}
else if(quantity >= 50 && quantity <= 99){
    discount = 10;
    discAmt = quantity*itemPrice*discount/100;
}
else if(quantity >= 100 && quantity <= 149){
    discount = 15;
    discAmt = quantity*itemPrice*discount/100;
}
else if(quantity >= 150){
    discount = 25;
    discAmt = quantity*itemPrice*discount/100;
}
total = cost - discAmt;

printf("\n\tThe item price is: $%.1lf\n", itemPrice);
printf("\tThe order is: %.0lf item(s)\n", quantity);
printf("\tThe cost is: $%.1lf\n", cost);
printf("\tThe discount is: $%.1lf%%\n ", discount);
printf("\tThe discount amount is: $%.1lf\n", discAmt);
printf("\tThe total is: $%.1lf\n\n", total);
goodbye();

return 0;

}