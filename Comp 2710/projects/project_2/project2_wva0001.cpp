//William Abbot
//Auburn User ID: wva0001
//project2_wva0001.cpp
//use the command g++ to compile this code
//I recived help about calling by reference from tutorialspoint.com

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>

using namespace std;


int rand_result;
bool A_alive_main = true, B_alive_main = true, C_alive_main = true;
bool Aaron_first_shot = true;
bool testing = true;
bool strat2;
int strat1_percent;
int A_win_count = 0, B_win_count = 0, C_win_count = 0;
//constants
const double NUMBER_OF_TEST_RUNS = 10000.0;
const double AARON_WIN_PERCENT = 33.33;
const double BOB_WIN_PERCENT = 50.0;
const int RAND_START_TIME = 0;


bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool&, bool&);
void Bob_shoots(bool&, bool&);
void Charlie_shoots(bool&, bool&);
void Aaron_shoots2(bool&, bool&);

void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

void test_strat_x(int&);


int main()
{
	int best_strategy;
	srand(time(RAND_START_TIME));//seeds the RNG so that the random number 
	                             //changes every time the program is run

	cout << "\n*** Welcome to William's Duel Simulator ***\n";
	test_at_least_two_alive();
	test_Aaron_shoots1();
	test_Bob_shoots();
	test_Charlie_shoots();
	test_Aaron_shoots2();
        cout.setf(ios::fixed);//this sets numbers that are output to be in fixed-point notation
        cout.setf(ios::showpoint);//will show decimal point
        cout.precision(2);//sets the number of digits that come after the decimal point
	testing = false;
	strat2 = false;
	cout << "\nReady to test strategy 1 (run 10000 times): \n" << "Press enter to continue...\n";

	test_strat_x(A_win_count);
	strat1_percent = (A_win_count/NUMBER_OF_TEST_RUNS)*100;

	strat2 = true;
	cout << "\nReady to test strategy 2 (run 10000 times): \n" << "Press enter to continue...\n";

	test_strat_x(A_win_count);
	
	if (strat1_percent > ((A_win_count/NUMBER_OF_TEST_RUNS)*100))
	{
		best_strategy = 1;
		cout << "\nStrategy " << best_strategy << " is better than strategy " << 2 << "\n\n";
	}
	else
	{
		best_strategy = 2;
		cout << "\nStrategy " << best_strategy << " is better than strategy " << 1 << "\n\n";
	}
	
	return 0;
}


bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
	return (((A_alive + B_alive + C_alive) > 1) ? true : false);//you can add booleans together
	                                                            // 0 = false, 1 = true
}

void Aaron_shoots1(bool& B_alive, bool& C_alive)
{
	rand_result = rand()%100;//divides rand() by 100 and returns the remainder, it will be from 0 to 100
	if (rand_result <= AARON_WIN_PERCENT)
	{
		if (C_alive)
		{
			C_alive = false;
			if (testing) {cout << "\t\tCharlie is dead" << "\n";}
		}
		else
		{
			B_alive = false;
			if (testing) {cout << "\t\tBob is dead" << "\n";}
		}
	}
	else
	{
		if (testing) {cout << "\t\tAaron missed" << "\n";}
	}
}

void Bob_shoots(bool& A_alive, bool& C_alive)
{
	rand_result = rand()%100;
	if (rand_result <= BOB_WIN_PERCENT)
	{
		if (C_alive)
		{
			C_alive = false;
			if (testing) {cout << "\t\tCharlie is dead\n";}
		}
		else 
		{
			A_alive = false;
			if (testing) {cout << "\t\tAaron is dead\n";}
		}
	}
	else
	{
		if (testing) {cout << "\t\tBob missed\n";}
	}
}
void Charlie_shoots(bool& A_alive, bool& B_alive)
{
	if (B_alive)
	{
		B_alive = false;
		if (testing) {cout << "\t\tBob is dead\n";}
	}
	else
	{
		A_alive = false;
		if (testing) {cout << "\t\tAaron is dead\n";}
	}
}
void Aaron_shoots2(bool& B_alive, bool& C_alive)
{
	if (Aaron_first_shot)
	{
		if (testing) {cout << "\t\tAaron intentionally misses his first shot\n";}
	}
	else
	{
		rand_result = rand()%100;
		if (rand_result <= AARON_WIN_PERCENT)
		{
			if (C_alive)
			{
				C_alive = false;
				if (testing) {cout << "\t\tCharlie is dead\n";}
			}
			else
			{
				B_alive = false;
				if (testing) {cout << "\t\tBob is dead\n";}
			}
		}
		else
		{
			if (testing) {cout << "\t\tAaron missed" << "\n";}
		}
	}
}
void test_strat_x(int& A_win_count)
{
        cin.ignore();
	cout << "...\n...\n...\n\n";

        A_win_count = 0;
        B_win_count = 0;
	C_win_count = 0;
	int strat1_counter = 0;

	do 
	{
	        A_alive_main = true;
       		B_alive_main = true;
        	C_alive_main = true;
		int while_loop_counter = 0;
		while(at_least_two_alive(A_alive_main, B_alive_main, C_alive_main) == true)
		{
			if (A_alive_main)
			{
				switch (strat2)
				{
					case false://strategy one
						Aaron_shoots1(B_alive_main, C_alive_main);
						break;
					case true://strategy two
						Aaron_first_shot = false;
                        	      		if (while_loop_counter == 0)//if first iteration of while loop 
                                		{
                                        		Aaron_first_shot = true;
                                		}
                                		Aaron_shoots2(B_alive_main, C_alive_main);
						break;
				}
			}
			if (B_alive_main)
			{
				Bob_shoots(A_alive_main, C_alive_main);
			}
			if (C_alive_main)
			{
				Charlie_shoots(A_alive_main, B_alive_main);
			}
			while_loop_counter++;
		}

                if (!A_alive_main && !C_alive_main)
                {
                	B_win_count++;//if both are ded bob has to be alive because of the while loop condition
                }
                if (!A_alive_main && !B_alive_main)
                {
                	C_win_count++;
                }
                if (!B_alive_main && !C_alive_main)
                {
                	A_win_count++;
                }

		strat1_counter++;

	} while (strat1_counter < NUMBER_OF_TEST_RUNS);

        cout << "Aaron won " << noshowpoint << A_win_count << "/10000 duels or ";
        cout << showpoint << ((A_win_count/NUMBER_OF_TEST_RUNS)*100) << "%\n";
        cout << "Bob won " << noshowpoint << B_win_count << "/10000 duels or ";
        cout << showpoint << ((B_win_count/NUMBER_OF_TEST_RUNS)*100) << "%\n";
        cout << "Charlie won " << noshowpoint << C_win_count << "/10000 duels or ";
        cout << showpoint << ((C_win_count/NUMBER_OF_TEST_RUNS)*100) << "%\n";
	cout <<"\n";
}

void test_at_least_two_alive(void)
{
	cout << "\nUnit Testing 1: Function - at_least_two_alive()\n";
      
	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(at_least_two_alive(true, true, true) == true);
	cout << "\tCase passed ...\n";
      
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(at_least_two_alive(false, true, true) == true);
	cout << "\tCase passed ...\n";
      
	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(at_least_two_alive(true, false, true) == true);
	cout << "\tCase passed ...\n";
      
	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(at_least_two_alive(true, true, false) == true);
	cout << "\tCase passed ... \n";

	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(at_least_two_alive(false, false, true) == false);
	cout << "\tCase passed ... \n";

	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(at_least_two_alive(false, true, false) == false);
	cout << "\tCase passed ... \n";

        cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
        assert(at_least_two_alive(true, false, false) == false);
        cout << "\tCase passed ... \n";

        cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
        assert(at_least_two_alive(false, false, false) == false);
        cout << "\tCase passed ... \n";

	//Pause Command for Linux Terminal
	cout << "Press enter to continue...";
	cin.ignore();
}
void test_Aaron_shoots1(void)
{
	B_alive_main = true;
	C_alive_main = true;

	cout << "\n" << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
	cout << "\tCase 1: Bob alive, Charlie alive\n";
	cout << "\t\tAaron is shooting at Charlie\n";
	Aaron_shoots1(B_alive_main, C_alive_main);

	cout << "\tCase 2: Bob dead, Charlie alive\n" << "\t\tAaron is shooting at Charlie\n";
	B_alive_main = false;
	C_alive_main = true;
	Aaron_shoots1(B_alive_main, C_alive_main);

	cout << "\tCase 3: Bob alive, Charlie dead\n" << "\t\tAaron is shooting at Bob\n";
	B_alive_main = true;
	C_alive_main = false;
	Aaron_shoots1(B_alive_main, C_alive_main);

	cout << "Press enter to continue...";
	cin.ignore(); 
}
void test_Bob_shoots(void)
{
	A_alive_main = true;
	C_alive_main = true;

	cout << "\n" << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
	cout << "\tCase 1: Aaron alive, Charlie alive\n" << "\t\tBob is shooting at Charlie\n";
	Bob_shoots(A_alive_main, C_alive_main);

	A_alive_main = false;
	C_alive_main = true;

	cout << "\tCase 2: Aaron dead, Charlie alive\n" << "\t\tBob is shooting at Charlie\n";
	Bob_shoots(A_alive_main, C_alive_main);
	
        A_alive_main = true;
        C_alive_main = false;
	
	cout << "\tCase 3: Aaron alive, Charlie dead\n" << "\t\tBob is shooting at Aaron\n";
	Bob_shoots(A_alive_main, C_alive_main);

        cout << "Press enter to continue...";
        cin.ignore();
}
void test_Charlie_shoots(void)
{
	A_alive_main = true;
	B_alive_main = true;
 
	cout << "\n" << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
	cout << "\tCase 1: Aaron alive, Bob alive\n" << "\t\tCharlie is shooting at Bob\n";
	Charlie_shoots(A_alive_main, B_alive_main);

	A_alive_main = false;
	B_alive_main = true;

	cout << "\tCase 2: Aaron dead, Bob alive\n" << "\t\tCharlie is shooting at Bob\n";
	Charlie_shoots(A_alive_main, B_alive_main);

	A_alive_main = true;
	B_alive_main = false;

	cout << "\tCase 3: Aaron alive, Bob dead\n" << "\t\tCharlie is shooting at Aaron\n";
	Charlie_shoots(A_alive_main, B_alive_main);

        cout << "Press enter to continue...";
        cin.ignore();
}
void test_Aaron_shoots2(void)
{
	B_alive_main = true;
	C_alive_main = true;

        cout << "\n" << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
        cout << "\tCase 1: Bob alive, Charlie alive\n";
	Aaron_shoots2(B_alive_main, C_alive_main);
	assert(B_alive_main && C_alive_main == true);
	cout << "\t\tBoth Bob and Charlie are alive.\n";

	Aaron_first_shot = false;
        B_alive_main = false;
        C_alive_main = true;

	cout << "\tCase 2: Bob dead, Charlie alive\n" << "\t\tAaron is shooting at Charlie\n";
	Aaron_shoots2(B_alive_main, C_alive_main);

        B_alive_main = true;
        C_alive_main = false;

	cout << "\tCase 3: Bob alive, Charlie dead\n" << "\t\tAaron is shooting at Bob\n";
	Aaron_shoots2(B_alive_main, C_alive_main);

        cout << "Press enter to continue...";
        cin.ignore();
}
