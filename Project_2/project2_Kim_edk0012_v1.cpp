//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Dojin Kim
// Truel of the Fates
// Project2_Kim_edk0012_v1.cpp
//
// ** References **
// I looked at the Project2.pdf for hints, instructions, and guidance.
// Asked ChatGPT on revisions of code, to improve quality, and implemented advice
// Used CPPReference.com for references on C++
// 
// ** Compile **
// Compiled using G++ and the Auburn Server.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 
#include <iostream> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctime> 
using namespace std; 

//prototypes
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void press_enter();

//vars
const int totalRuns = 10000;
const bool ALIVE = true;
const bool DEAD = false;

int main() {
    bool aaronAlive = true, bobAlive = true, charlieAlive = true;
    int aaronVicRoy1 = 0, aaronVicRoy2 = 0, bobVicRoy = 0, charlieVicRoy = 0;

    //initializes and calls test functions
    cout << "*** Welcome to Dojin's Truel Simulator ***\n"; 
    srand(time(0)); 

    // strat 1 start
    cout << "\nReady to test strategy 1 (run 10000 times):\n"; 
    press_enter(); 
    for (int i = 0; i < totalRuns; i++) { 
        aaronAlive = ALIVE;
        bobAlive = ALIVE;
        charlieAlive = ALIVE; 
    while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) { 
        if (aaronAlive) {
            Aaron_shoots1(bobAlive, charlieAlive);
        }
        if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
        }

        if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
        }
    } 
   
    if (aaronAlive) { 
        aaronVicRoy1++;
    }
    if (bobAlive) { 
        bobVicRoy++; 
    } 
    if (charlieAlive) {
        charlieVicRoy++;
    }
 }
  
    cout << "\nAaron won " << aaronVicRoy1 << "/10000 duels or " << static_cast<double>(aaronVicRoy1) / totalRuns * 100 << "%\n" 
        << "Bob won " << bobVicRoy << "/10000 duels or " << static_cast<double>(bobVicRoy) / totalRuns * 100 << "%\n" 
        << "Charlie won " << charlieVicRoy << "/10000 duels or " << static_cast<double>(charlieVicRoy) / totalRuns * 100 << "%" << endl;
    cout << " " << endl;
  
    // reinitialize so code can run strat 2
    bobVicRoy = 0;
    charlieVicRoy = 0; 

    cout << "Ready to test strategy 2 (run 10000 times):" << endl; 
    press_enter(); 
    for (int i = 0; i < totalRuns; i++) { 
        aaronAlive = ALIVE;
        bobAlive = ALIVE;
        charlieAlive = ALIVE;
    while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive))  { 
        if (aaronAlive) {
            Aaron_shoots2(bobAlive, charlieAlive);
        }

        if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
        }

        if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
        }
    } 
    if (aaronAlive) { 
        aaronVicRoy2++;
    }
    if (bobAlive) { 
        bobVicRoy++; 
    } 
    if (charlieAlive) {
        charlieVicRoy++;
        }
    } 
    cout << "\nAaron won " << aaronVicRoy2 << "/10000 duels or " << static_cast<double>(aaronVicRoy2) / totalRuns * 100 << "%\n"
    << "Bob won " << bobVicRoy << "/10000 duels or " << static_cast<double>(bobVicRoy) / totalRuns * 100 << "%\n"
    << "Charlie won " << charlieVicRoy << "/10000 duels or " << static_cast<double>(charlieVicRoy) / totalRuns * 100 << "%" << endl;
    cout << " " << endl;
  
    if (aaronVicRoy1 > aaronVicRoy2) { 
        cout << "Strategy 1 is better than strategy 2.\n"; 
    } 
    if (aaronVicRoy1 < aaronVicRoy2) {
        cout << "Strategy 2 is better than strategy 1.\n"; 
    }  
    return 0; 
} 



bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) { 
    if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive)) {
        return true;
    }
    else {
        return false;
    }
} 

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    int shootChance = rand() % 100;
    if (shootChance < 33) { // 33% hit rate
        if (C_alive) {
            C_alive = false; // Shoot Charlie first
        } else if (B_alive) {
            B_alive = false;
        }
    }
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    static bool firstShotMissed = false;
    
    if (!firstShotMissed) {
        firstShotMissed = true;
        return;
    }

    int shootChance = rand() % 100;
    if (shootChance < 33) {
        if (C_alive) {
            C_alive = false;
        } else if (B_alive) {
            B_alive = false;
        }
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
    int shootChance = rand() % 100;
    if (shootChance < 50) { // 50% hit rate
        if (C_alive) {
            C_alive = false; // Shoot Charlie first
        } else if (A_alive) {
            A_alive = false;
        }
    }
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
    if (B_alive) {
        B_alive = false;
    } else if (A_alive) {
        A_alive = false;
    }
}

void press_enter() { 
    cout << "Press Enter to continue..."; 
    cin.ignore().get();  
}
