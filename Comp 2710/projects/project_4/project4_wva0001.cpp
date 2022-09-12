//William Abbot
//wva0001
//project4_wva0001.cpp
//compile this code with the command: g++ <filename>. and to enter the debug version, enter command: g++ <file name> -DUNIT_testing.
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

struct triviaNode
{
	string question;
	string answer;
	int points;
        triviaNode* next;
};

typedef triviaNode* triviaNode_ptr;


int current_size = 0;
bool testing = false;
int test_points = 0;


//Creates a linked list with 3 hard-coded 
//questions inserted automatically.
//Param head: points to a trivia node (call by reference)
//Returns void
void createList(triviaNode_ptr& head);
//Adds a node after the node pointed to by afterMe.
//Param afterMe: points to a trivia node (call by reference)
//Param trivia_size: used to keep track of the number of questions
//Returns void
void addNode(triviaNode_ptr& afterMe, int& trivia_size);
//Starts the game and asks the questions the user typed in.
//Param trivia_size: holds the number of questions
//Returns void
void startTrivia(triviaNode_ptr list, int trivia_size);
//Gets the number of elements ahead of the current node 
//Param curr_node: pointer to the current node
//Returns the current size of teh linked list
int getNumOfItemsLeft(triviaNode_ptr curr_node);
//tests startTrivia function.
//Returns void
void unitTest();


//#define UNIT_TESTING
#ifndef UNIT_TESTING//if unit testing is not defined, go into product version
#define trivia_quiz
#endif
void createList(triviaNode_ptr& head)
{
        head = new triviaNode;
        
        triviaNode_ptr node1;
        node1 = new triviaNode;
        node1->question = "How long was the shortest war on record? (Hint: how many minutes)";
        node1->answer = "38";
        node1->points = 100;
        
        triviaNode_ptr node2;
        node2 = new triviaNode;
        node2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
        node2->answer = "Bank of Italy";
        node2->points = 50;
        
        triviaNode_ptr node3;
        node3 = new triviaNode;
        node3->question = "What is the best-selling video game of all time?(Hint: Call of Duty or Wii Sports)";
        node3->answer = "Wii Sports";
        node3->points = 20;
        
        head = node1;
        node1->next = node2;
        node2->next = node3;
        node3->next = NULL;
	
}

void addNode(triviaNode_ptr& afterMe, int& trivia_size)
{
        //create new node
        triviaNode_ptr node;
        node = new triviaNode;
        
        string question;
        string answer;
        int points;
        
        cout << "\nEnter a question: ";
        getline(cin, question);
        node->question = question;
        cout << "\nEnter the answer: ";
        getline(cin, answer);
        node->answer = answer;
        cout << "\nEnter award points: ";
        cin >> points;
        node->points = points;
        
        //add new node after the node "afterMe"
        node->next = afterMe->next;
        afterMe->next = node;
        
        trivia_size++;
}

void startTrivia(triviaNode_ptr list, int trivia_size)
{
	string trivia_answer;
	int trivia_points = 0;

	if(list == NULL)
	{
		return;
	}
	if(trivia_size < 1)
	{
		cout << "Warning - the number of trivia to be asked must be equal to or be larger than 1\n";
	}
	else if(current_size < trivia_size)
	{
		cout << "Warning - there is only " << current_size << " trivia in the list\n";
	}
	else 
	{
        //asks player a question
        	for (int i = 0; i < trivia_size; i++)
			{
			cout << "Question: " << list->question;
			cout << "\nAnswer: ";
			//input the players answer
			getline(cin, trivia_answer);
			if(trivia_answer.compare(list->answer) == 0)
			{
				if(!testing){cout << "Your answer is correct. you recieved " << list->points << " points\n";}
				//change their score approprietely based on their answer
				trivia_points += list->points;
				test_points += list->points;
			}
			else
			{
				//display correct answer if incorrect one is entered
				if(!testing){cout <<"Your answer is wrong. The correct answer is: " << list->answer << "\n";}
			}
			list = list->next;
			if(!testing){cout << "your total points: "<< trivia_points << "\n";}
		}
	}
	
	return;
}

int getCurrentSize(triviaNode_ptr node)
{
	current_size = 0;

	while(node != NULL)
	{
		current_size++;
		node = node->next;
	}
	return current_size;
}


int main()
{	
	triviaNode_ptr main_list;
	string yes = "Yes";
	int question_amount = 3; 
#ifdef trivia_quiz
	cout << "*** Welcome to William's trivia quiz game ***\n";
	createList(main_list);
	while(yes == "Yes" || yes == "yes" || yes == "YES")
	{
		addNode(main_list->next->next, question_amount);
		cout << "\nContinue? (Yes/No): ";
		cin >> yes;
		cin.ignore();//ignores \n that cin >> str has left (if user pressed enter key)
	}
	cout << "\n\n";
	current_size = getCurrentSize(main_list);
	startTrivia(main_list, question_amount);

	cout << "\n*** Thank you for playing the trivia quizgame. Goodbye!***\n\n";
#endif
#ifdef UNIT_TESTING
	unitTest();
#endif
	return 0;
}


void unitTest()
{
	testing = true;
	triviaNode_ptr test_list;

	createList(test_list);

	current_size = getCurrentSize(test_list);
	test_points = 0;

	
	cout << "*** This is a debugging version ***\n";
	cout << "Unit Test Case 1: Ask no question. The program should give a warning message.\n";
	startTrivia(test_list, 0);
	cout << "Case 1 Passed...\n\n";

	
	cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";
	startTrivia(test_list, 1);
	assert(test_points == 0);
	cout << "Case 2.1 passed...\n\n";

	
	cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.\n";
	test_list = test_list->next;
	current_size = getCurrentSize(test_list);
	test_points = 0;
	startTrivia(test_list, 1);
	assert(test_points == 50);
	cout << "Case 2.2 passed...\n\n";

	
	cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list.\n";
	//test_list->next = NULL;
	//test_list = NULL;
	test_list = test_list->next;

	current_size = getCurrentSize(test_list);
	startTrivia(test_list, 1);
	test_list = test_list->next;
        createList(test_list);
        current_size = getCurrentSize(test_list);
        startTrivia(test_list, 2);
	assert(test_list->next->next->next == NULL);
	cout << "Case 3 passed...\n\n";

	
	cout << "Unit Test Case 4: Ask five questionsin thelinked list.\n";
	test_list->next = NULL;
	test_list = NULL;
	createList(test_list);
	current_size = getCurrentSize(test_list);
	startTrivia(test_list, 5);
	cout << "Case 4 passed...\n\n";

	cout << "\n*** End of Debugging Version ***\n\n";
	
	return;
}
