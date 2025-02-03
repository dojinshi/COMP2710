// Dojin Kim
// Project1_Kim_edk0012.cpp
// When Life Gives You Credit Debt
// I looked at the Project1.pdf for inspiration.
// I looked at stackoverflow post that had a similar project for inspiration.
// I looked at Youtube on how to do a left-lining style.
// I asked ChatGPT for revisions on my code, how to add a comma after a thousand, and asked what I could do better.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>
using namespace std;

int main() {    
    int month = 0;
    double balance, yearlyRate, interest, principal, monthlyRate, monthlyPayment, totalInterest;
//inputs
    cout << "Loan Amount: ";
    cin >> balance;

    cout << "Interest Rate (% per year): ";
    cin >> yearlyRate;
    
    cout << "Monthly Payments: ";
    cin >> monthlyPayment;
//add commas to numbers above a thousand
    cout.imbue(locale("en_US.UTF-8"));
//formulas
    monthlyRate = (yearlyRate / 12);
    interest = (balance * ((yearlyRate / 100) / 12));
    principal = (interest / monthlyRate);

//text
    cout << "**********************************************************" << endl;
    cout << "                    Amortization Table                    " << endl;
    cout << "**********************************************************" << endl;
    cout << left << setw(6) << "Month"
    << setw(12) << "Balance"
    << setw(12) << "Payment"
    << setw(8) << "Rate"
    << setw(11) << "Interest"
    << setw(13) << "Principal" << endl;
//0th month calculations
    cout << left << setw(6) << "0"
    << "$" << setw(11) << fixed << setprecision(2) << balance
    << setw(12) << "N/A"
    << setw(8) << "N/A"
    << setw(11) << "N/A"
    << setw(13) << "N/A" << endl;

//while loop to initialize balance until it hits 0
    while (balance > 0) {
        month++;
        interest = balance * ((yearlyRate / 100) / 12);
        principal = monthlyPayment - interest;

        if (balance - principal < 0) {
            principal = balance;
            monthlyPayment = principal + interest;
        }

//input of values from while loop
    totalInterest += interest;
    balance -= principal;

    cout << left << setw(6) << month
        << "$" << setw(11) << fixed << setprecision(2) << balance
        << "$" << setw(11) << fixed << setprecision(2) << monthlyPayment
        << setw(8) << fixed << setprecision(2) << monthlyRate
        << "$" << setw(10) << fixed << setprecision(2) << interest
        << "$" << setw(15) << fixed << setprecision(2) << principal << endl;
    
    }

    cout << "**********************************************************" << endl;
    cout << "It takes " << month << " months to pay off the loan." << endl;
    cout << "Total interest paid is: $" << totalInterest << endl;

}
