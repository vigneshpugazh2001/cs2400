/*
 *        File: invoice.cc
 *      Author: Vignesh Pugazhenthi
<<<<<<< HEAD
 *        Date: 9/14/2020
=======
 *        Date: 9/214/2020
>>>>>>> bf80237f1775447e8ccc909835d62a821a9cdc30
 * Description: This program allows the user to get an invoice depending on the users choices between 2 different hardrive providers
 *              
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

///function prototypes

int main(int argc, char const *argv[]) {
    const double NUMWEST = 90.00;
    const double NUMSEA = 95.00;
    const double DISCOUNT = 0.05;
    const double TAX = 0.07;
for (int i =0; i < 10; i++){
    cout << "hello world" << endl;
}
    double quantity, costw, costs,discountw, discounts, subtotalw, subtotals, totalw, totals;
    string hardrive, choice;
// set decimal points to 2
    cout << fixed << setprecision(2) << endl;
// allows the user to decide which hardrive they want 
    cout << "Enter a hard drive type (w, s) followed by the quantity:"; 
    cin >> hardrive >> quantity;
    cout << "Do you live in Ohio (yes/no)? ";
    cin >> choice;
    cout << "Hard Drives Invoice" << endl;
    cout << "------------------------" << endl;
// uses users input
    if (hardrive == "w")
    {   cout << "Drive brand: Western Digital" << endl;

    } else {
        cout << "Drive brand: Seagate" << endl;
    }

    cout << "Quantity: " << quantity << endl;

    if (hardrive == "w"){
        cout << "Price: " << NUMWEST << endl;
    } else {
        cout << "Price: " << NUMSEA << endl;
    }
    
    cout << "Ohio Resident: " << choice << endl;

    if (hardrive == "w"){
        costw = NUMWEST * quantity;
        cout << "Total price: " << costw << endl;
    } else {
        costs = NUMSEA * quantity;
        cout << "Total price:" << costs << endl;
    }
    
    cout << "-------------------------" << endl;
    if ((quantity >= 5) && (hardrive == "w" || hardrive == "s")){
        discountw = DISCOUNT * costw;
        discounts = DISCOUNT * costs;
        cout << "Discount: " << discountw || discounts; 
        cout << "\n";
        
    } else {
        cout << "Discount: "<< endl;
    }
    
    if (hardrive == "w"|| hardrive == "s"){
        subtotalw = costw + discountw;
        subtotals = costs + discounts;
        cout << "Subtotal: "<< subtotalw || subtotals;
        cout << "\n"; 
    } else {
        cout << "Subtotal: "<< endl;
    }

    if (choice == "yes" ){
        cout << "Taxes: " << TAX << endl;
    } else {
        cout << "Taxes: "<< endl;
    }
    cout << "=========================" << endl;
    totalw = subtotalw + TAX;
    totals = subtotals + TAX;
    cout << "Total:  " << totalw || totals;
    cout << "\n";
    cout << "-------------------------" << endl;
    
    return 0;
} /// main
