//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Dojin Kim
// Truel of the Fates
// Project2_Kim_edk0012_v2.cpp
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

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive); 
/* Input: A_alive indicates whether Aaron is alive
* B_alive indicates whether Bob is alive
* C_alive indicates whether Charlie is alive
* Return: true if at least two are alive
* otherwise return false
*/

void Aaron_shoots1(bool& B_alive, bool& C_alive); 
/* Strategy 1: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/

void Bob_shoots(bool& A_alive, bool& C_alive); 
/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change C_alive into false if Charlie is killed.
*/

void Charlie_shoots(bool& A_alive, bool& B_alive); 
/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* B_alive indicates whether Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change B_alive into false if Bob is killed.
*/

void Aaron_shoots2(bool& B_alive, bool& C_alive); 
/* Strategy 2: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/

//prototypes
void test_at_least_two_alive(void); 
void test_Aaron_shoots1(void); 
void test_Bob_shoots(void); 
void test_Charlie_shoots(void); 
void test_Aaron_shoots2(void); 
void press_enter(void); 

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
    test_at_least_two_alive(); 
    press_enter(); 
    test_Aaron_shoots1(); 
    press_enter(); 
    test_Bob_shoots(); 
    press_enter(); 
    test_Charlie_shoots(); 
    press_enter(); 
    test_Aaron_shoots2(); 
    press_enter(); 
  
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
 
// test drivers
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) { 
    if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive)) {
        return true;
    }
    else {
        return false;
    }
} 
 
void test_at_least_two_alive(void) { 
    cout << "Unit Testing 1: Function - at_least_two_alive()\n"; 
  
    cout << "\t Case 1: Aaron alive, Bob alive, Charlie alive\n"; 
    assert(true == at_least_two_alive(ALIVE, ALIVE, ALIVE)); 
    cout << "\t Case passed ...\n"; 
  
    cout << "\t Case 2: Aaron dead, Bob alive, Charlie alive\n"; 
    assert(true == at_least_two_alive(DEAD, ALIVE, ALIVE)); 
    cout << "\t Case passed ...\n";
 
    cout << "\t Case 3: Aaron alive, Bob dead, Charlie alive\n"; 
    assert(true == at_least_two_alive(ALIVE, DEAD, ALIVE));
    cout << "\t Case passed ...\n";

    cout << "\t Case 4: Aaron alive, Bob alive, Charlie dead\n"; 
    assert(true == at_least_two_alive(ALIVE, ALIVE, DEAD));
    cout << "\t Case passed ...\n";

    cout << "\t Case 5: Aaron dead, Bob dead, Charlie alive\n"; 
    assert(false == at_least_two_alive(DEAD, DEAD, ALIVE));
    cout << "\t Case passed ...\n";

    cout << "\t Case 6: Aaron dead, Bob alive, Charlie dead\n"; 
    assert(false == at_least_two_alive(DEAD, ALIVE, DEAD));
    cout << "\t Case passed ...\n";

    cout << "\t Case 7: Aaron alive, Bob dead, Charlie dead\n"; 
    assert(false == at_least_two_alive(ALIVE, DEAD, DEAD));
    cout << "\t Case passed ...\n";

    cout << "\t Case 8: Aaron dead, Bob dead, Charlie dead\n"; 
    assert(false == at_least_two_alive(DEAD, DEAD, DEAD));
    cout << "\t Case passed ...\n";
} 
 
void Aaron_shoots1(bool& B_alive, bool& C_alive) { 

    int shot_percentage = rand() % 100; 
    if (C_alive && shot_percentage < 33) { 
        C_alive = false; 
        return;
    } 
    else if (B_alive && shot_percentage < 33) { 
        B_alive = false;
    } 
} 
 
void test_Aaron_shoots1(void) { 
    cout << "\nUnit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n"; 
  
    bool Bob_a = ALIVE, Charlie_a = ALIVE;
    cout << "\t Case 1: Bob alive, Charlie alive\n" << "\t\tAaron is shooting at Charlie\n"; 
    Aaron_shoots1(Bob_a, Charlie_a); 
    assert(Bob_a == ALIVE);
  
    Bob_a = DEAD; 
    Charlie_a = ALIVE; 
    cout << "\t Case 2: Bob dead, Charlie alive\n" << "\t\tAaron is shooting at Charlie\n"; 
    Aaron_shoots1(Bob_a, Charlie_a); 
    assert(Bob_a == DEAD);
 
    Bob_a = ALIVE; 
    Charlie_a = DEAD; 
    cout << "\t Case 3: Bob alive, Charlie dead\n" << "\t\tAaron is shooting at Bob\n"; 
    Aaron_shoots1(Bob_a, Charlie_a); 
    assert(Charlie_a == DEAD);
} 
 
void Bob_shoots(bool& A_alive, bool& C_alive) { 
    int shot_percentage = rand()%100;
    if (C_alive && shot_percentage < 50)
    {
        C_alive = false;
        return;
    }
    else if (A_alive && shot_percentage < 50)
    {
        A_alive = false;
    }
} 
 
void test_Bob_shoots(void) { 
    cout << "\nUnit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n"; 
  
    bool Aaron_a = ALIVE, Charlie_a = ALIVE;
    cout << "\t Case 1: Aaron alive, Charlie alive\n" << "\t\tBob is shooting at Charlie\n"; 
    Bob_shoots(Aaron_a, Charlie_a); 
    assert(Aaron_a == ALIVE);
  
    Aaron_a = DEAD; 
    Charlie_a = ALIVE; 
    cout << "\t Case 2: Aaron dead, Charlie alive\n" << "\t\tBob is shooting at Charlie\n"; 
    Bob_shoots(Aaron_a, Charlie_a); 
    assert(Aaron_a == DEAD);
 
    Aaron_a = ALIVE; 
    Charlie_a = DEAD; 
    cout << "\t Case 3: Aaron alive, Charlie dead\n" << "\t\tBob is shooting at Aaron\n"; 
    Bob_shoots(Aaron_a, Charlie_a); 
    assert(Charlie_a == DEAD); 
  
} 
  
void Charlie_shoots(bool& A_alive, bool& B_alive) { 
    if (B_alive) {
        B_alive = false;
        return;
    }
    else if (A_alive) {
        A_alive = false;
    }
} 
 
void test_Charlie_shoots(void) { 
    cout << "\nUnit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n"; 
  
    bool Aaron_a = ALIVE, Bob_a = ALIVE;
    cout << "\t Case 1: Aaron alive, Bob alive\n" << "\t\tCharlie is shooting at Bob\n"; 
    Charlie_shoots(Aaron_a, Bob_a); 
    assert(Aaron_a == ALIVE && Bob_a == DEAD);

    Aaron_a = DEAD; 
    Bob_a = ALIVE; 
    cout << "\t Case 2: Aaron dead, Bob alive\n" << "\t\tCharlie is shooting at Bob\n"; 
    Charlie_shoots(Aaron_a, Bob_a); 
    assert(Aaron_a == DEAD && Bob_a == DEAD);
 
    Aaron_a = ALIVE; 
    Bob_a = DEAD; 
    cout << "\t Case 3: Aaron alive, Charlie dead\n" << "\t\tCharlie is shooting at Aaron\n"; 
    Charlie_shoots(Aaron_a, Bob_a); 
    assert(Aaron_a == DEAD && Bob_a == DEAD); 
} 
 
void Aaron_shoots2(bool& B_alive, bool& C_alive) { 
    if(B_alive && C_alive) {
        return;
    }

    int shot_percentage = rand() % 100; 
    if (C_alive && shot_percentage < 33) { 
        C_alive = false; 
        return;
    } 
    else if (B_alive  && shot_percentage < 33) { 
        B_alive = false;
    }
} 
 
void test_Aaron_shoots2(void) { 
    cout << "\nUnit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n"; 
  
    bool Bob_a = ALIVE, Charlie_a = ALIVE;
    cout << "\t Case 1: Bob alive, Charlie alive\n" << "\t\tAaron intentionally misses his first shot\n" << "\t\tBoth Bob and Charlie are alive.\n"; 
    Aaron_shoots2(Bob_a, Charlie_a); 
    assert(Bob_a == ALIVE && Charlie_a == ALIVE);
  
    Bob_a = DEAD; 
    Charlie_a = ALIVE; 
    cout << "\t Case 2: Bob dead, Charlie alive\n" << "\t\tAaron is shooting at Charlie\n"; 
    Aaron_shoots1(Bob_a, Charlie_a); 
    assert(Bob_a == DEAD);
 
    Bob_a = ALIVE; 
    Charlie_a = DEAD; 
    cout << "\t Case 3: Bob alive, Charlie dead\n" << "\t\tAaron is shooting at Bob\n"; 
    Aaron_shoots1(Bob_a, Charlie_a); 
    assert(Charlie_a == DEAD); 
} 
 
void press_enter() { 
    cout << "Press Enter to continue..."; 
    cin.ignore().get();  
}
