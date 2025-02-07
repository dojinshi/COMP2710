// Dojin Kim
// Project1_Kim_edk0012.cpp
// When Life Gives You Credit Debt
// I looked at the Project1.pdf for inspiration.
// I looked at stackoverflow post that had a similar project for inspiration.
// I looked at Youtube on how to do a left-lining style.
// I asked ChatGPT for revisions on my code, how to add a comma after a thousand, and asked what I could do better.
// I asked ChatGPT for inspiration on how to set the inputs to fail if the inputs would lead to an error.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

int main() {    
    int month = 0;
    double balance, yearlyRate, interest, principal, monthlyRate, monthlyPayment, totalInterest = 0; // Initialized totalInterest

    // Inputs with validation
    do {
        cout << "Loan Amount: ";
        cin >> balance;
        if (balance <= 0) {
            cout << "Error occurred: Loan amount should be a positive amount." << endl; 
        }
    } while (balance <= 0);

    do {
        cout << "Interest Rate (% per year): ";
        cin >> yearlyRate;
        if (yearlyRate < 0) {
            cout << "Error occurred: Interest rate should not be negative." << endl;
        }
    } while (yearlyRate < 0);

    // Calculate monthly interest rate
    monthlyRate = yearlyRate / 12;

    // Validate Monthly Payment
    do {
        interest = (balance * ((yearlyRate / 100) / 12)); // Correct placement of interest calculation

        cout << "Monthly Payments: ";
        cin >> monthlyPayment;

        if (monthlyPayment <= interest) {
            cout << "Error occurred: Monthly payment must be greater than the first month's interest ($" 
                 << fixed << setprecision(2) << interest << ")." << endl;
        }
    } while (monthlyPayment <= interest);

    // Add commas to numbers above a thousand
    cout.imbue(locale("en_US.UTF-8"));

    // Text for amortization table
    cout << "**********************************************************" << endl;
    cout << "                    Amortization Table                    " << endl;
    cout << "**********************************************************" << endl;
    cout << left << setw(6) << "Month"
         << setw(12) << "Balance"
         << setw(12) << "Payment"
         << setw(8) << "Rate"
         << setw(11) << "Interest"
         << setw(13) << "Principal" << endl;

    // 0th month calculations
    cout << left << setw(6) << "0"
         << "$" << setw(11) << fixed << setprecision(2) << balance
         << setw(12) << "N/A"
         << setw(8) << "N/A"
         << setw(11) << "N/A"
         << setw(13) << "N/A" << endl;

    // Loan payment loop
    while (balance > 0) {
        month++;
        interest = balance * ((yearlyRate / 100) / 12);
        principal = monthlyPayment - interest;

        // Adjust final payment if needed
        if (balance - principal < 0) {
            principal = balance;
            monthlyPayment = principal + interest;
        }

        // Accumulate total interest
        totalInterest += interest;
        balance -= principal;

        // Print table row
        cout << left << setw(6) << month
             << "$" << setw(11) << fixed << setprecision(2) << balance
             << "$" << setw(11) << fixed << setprecision(2) << monthlyPayment
             << setw(8) << fixed << setprecision(2) << monthlyRate
             << "$" << setw(10) << fixed << setprecision(2) << interest
             << "$" << setw(15) << fixed << setprecision(2) << principal << endl;
    }

    cout << "**********************************************************" << endl;
    cout << " " << endl;
    cout << "It takes " << month << " months to pay off the loan." << endl;
    cout << "Total interest paid is: $" << fixed << setprecision(2) << totalInterest << endl;

    return 0;
}
