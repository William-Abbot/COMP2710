//William Abbot
//wva0001
//project3_wva0001.cpp
//compile code using g++
//learned how to pass an array by address to "readFile" function from from www.learncpp.com

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstdlib>

using namespace std;

bool testing = true;
bool isValid(string);
int getFileSize(string);
void readFile(int *, string);
string sortToOutput(int *, int *, int, int);


void readFile_test(void);
void sortToOutput_test(void);
void getFileSize_test(void);
void isValid_test(void);


/*
* First, main() tests the user made functions. Then, it reads 2 files to
* combine their contets into a sorted array which is outputted.
*
* Returns int value of 1 if failed to open file, and 0 otherwise
*/
int main()
{
        string fileName1;
        string fileName2;
        int fileSize1;
        int fileSize2;
        int next1;
        int next2;

        //testing
        cout << "\n*** Unit Test Cases  ***\n" << "Ensure you have permissions to write a txt to the current directory\n";
        readFile_test();
        sortToOutput_test();
        getFileSize_test();
        isValid_test();
        
	testing = false;        
        cout << "\n*** Welcome to William's sorting program***\n";
        cout << "Enter the first input file name: ";
        cin >> fileName1;

        if (cin.fail() || !isValid(fileName1)) //if problem with cin or opening file, exit.
        {
                cout << "file could not be opened, terminating...\n";
                exit(1);
        }
        
        fileSize1 = getFileSize(fileName1); 
        cout << "The list of " << fileSize1 << " numbers in file " << fileName1 << " is: \n";
        int inputArray1[fileSize1];
        
        readFile(inputArray1, fileName1);
        
        cout << "Enter the second input file name: ";
        cin >> fileName2;

        if (cin.fail() || !isValid(fileName2)) //if problem with cin or opening file, exit.
        {
                cout << "file could not be opened, terminating...\n";
                exit(1);
        }
        
        fileSize2 = getFileSize(fileName2);
        cout << "The list of " << fileSize2 << " numbers in file " << fileName2 << " is: \n";
        int inputArray2[fileSize2];
        
        readFile(inputArray2, fileName2);
        
        cout << "The sorted list of " << (fileSize1 + fileSize2) << " number is: ";
        string ofName = sortToOutput(inputArray1, inputArray2, fileSize1, fileSize2);
	cout << "*** Please check the new file - " << ofName << " ***\n";

	cout << "*** Goodbye. ***\n\n";

        return 0;
}



/*
* Checks to see if file of name "filename"  was succesfully opened.
*
* Returns true if oppened correctly
* Returns false otherwise
*/
bool isValid(string fileName)
{
        ifstream input;
        input.open(fileName.c_str());
        
        if (!input.fail())
        {
                input.close();
                return true;
        }
        input.close();
        return false;
}

/*
* Gets number of integers inside a file named "filename".
*
* Returns and int that is the number of items is the file
*/
int getFileSize(string fileName)
{
        ifstream input;
        input.open(fileName.c_str());
        int next;
        int fileSize = 0;
        
	while (input >> next)//while not end of file or bad stream, increment fileSize
	{
                fileSize++;
        }
        
        input.close();
        return fileSize;
}

/*
* prints elements from filName.txt and adds them to the parameter, 
* inputArray, which is a pointer to an array.
*
* Returns void
*/
void readFile(int *inputArray, string fileName)
{
	int next;
        int readCounter = 0;
        
        ifstream input;
        input.open(fileName.c_str());
        while (input >> next)
        {
                inputArray[readCounter] = next;
                if(!testing){cout << next <<"\n";}
                readCounter++;
        }
        input.close();
}

/*
 * Sorts the elements from inputArray 1 & 2, adds them to the 
 * outputArray in sorted order. than sends the array to the
 * output file.
 *
 * Returns file name
 */
string sortToOutput(int *inputArray1, int *inputArray2, int arraySize1, int arraySize2)
{
	int outCounter = 0;
	int index1 = 0;
	int index2 = 0;
	int outputArraySize = arraySize1 + arraySize2;
	int outputArray[outputArraySize];
	string outFileName;
	ofstream output;

	while(index1 < arraySize1 && index2 < arraySize2)
	{
		if(inputArray1[index1] < inputArray2[index2])
		{
			outputArray[outCounter] = inputArray1[index1];
			if(!testing){cout << inputArray1[index1] << " ";}
			index1++;
		}
		else
		{
			outputArray[outCounter] = inputArray2[index2];
			if(!testing){cout << inputArray2[index2] << " ";}
			index2++;
		}
		outCounter++;
	}
	if(index1 < arraySize1)
	{
		while((arraySize1 - (index1+1)) >= 0)
		{
			outputArray[outCounter] = inputArray1[index1];
			if(!testing){cout << inputArray1[index1] << " ";}
			index1++;
			outCounter++;
		}
	}
	if (index2 < arraySize2)
	{
		while((arraySize2 - (index2+1)) >= 0)
		{
			outputArray[outCounter] = inputArray2[index2];
			if(!testing){cout << inputArray2[index2] << " ";}
			index2++;
			outCounter++;
		}
	}
	if(!testing)
	{
		cout << "\nEnter the output file name: ";
		cin >> outFileName;
	}
	else
	{
		outFileName = "output_testing.txt";
	}
        output.open(outFileName.c_str());
        if(cin.fail() || output.fail())
        {
                cout << "failed to open outputFile, terminating...\n";
		output.close();
                exit(EXIT_FAILURE);
        }

	outCounter = 0;
	while ((outCounter+1) < outputArraySize)
	{
		output << outputArray[outCounter] <<"\n";
		outCounter++;
	}
	output.close();
	return outFileName;
}


void readFile_test(void)
{
	cout << "\nUnit Test Case 1: Function Name – void readFileName(int *inputArray, string fileName)\n";
	cout << "\tCase 1.1: inputArray is one element and file name valid.\n";
	ofstream output_test;
	int inputArray_test[1];
	string fileName_test = "input_test.txt";
	output_test.open(fileName_test.c_str());
	output_test << 5 << "\n";
	output_test.close();
	readFile(inputArray_test, fileName_test);
	assert(inputArray_test[0] = 5);
	cout << "\tCase 1.1 passed\n";

	cout << "\tCase 1.2: inputArray is 6 elements.\n";
	inputArray_test[6];
	output_test.open(fileName_test.c_str());
        output_test << 0 << "\n" << 1 << "\n" << 2 << "\n" << 11 << "\n" << 18 << "\n" << 100 << "\n";
        output_test.close();
	readFile(inputArray_test, fileName_test);
	int temp[6] = {0, 1, 2, 11, 18, 100};
	assert(*inputArray_test == *temp);
	cout << "\tCase 1.2 passed\n";

	cout << "\t...\n" << "Press enter to continue...";
	cin.ignore();
}
void sortToOutput_test(void)
{
        cout << "\nUnit Test Case 2: Function Name – sortToOutput(int *inputArray1, int *inputArray2, int arraySize1, int arraySize2)\n";
	
	cout << "\tCase 2.1: normal inputs, will check to see if file output_test.txt conatins right values\n";
	int inputArray1_test[] = {4, 6};
	int inputArray2_test[] = {0, 5, 7, 8, 8};
	int outputArray_test[] = {0, 4, 5, 6, 7, 8, 8};
 	int testArraySize1 = 2;
	int testArraySize2 = 5;
	string fileName = sortToOutput(inputArray1_test, inputArray2_test, testArraySize1, testArraySize2);
	int inputFile[7];
	readFile(inputFile, fileName);
	assert(*inputFile == *outputArray_test);
	cout << "\tCase 2.1 passed\n";

	cout << "\tCase 2.2: input array 1 only has one value\n";
	outputArray_test[0] = 0;
	outputArray_test[1] = 4;
	outputArray_test[2] = 5;
	outputArray_test[3] = 7;
	outputArray_test[4] = 8;
	outputArray_test[5] = 8;
	testArraySize1 = 1;
	testArraySize2 = 5;
	fileName = sortToOutput(inputArray1_test, inputArray2_test, testArraySize1, testArraySize2);
	inputFile[6];
	readFile(inputFile, fileName);
	assert(*inputFile == *outputArray_test);
	cout << "\tCase 2.2 passed\n";

	cout << "\tCase 2.3: the input arrays are exactly the same\n";
	inputArray2_test[0] = 6;
	inputArray2_test[1] = 100;
        inputArray1_test[0] = 6;
        inputArray1_test[1] = 100;
	testArraySize1 = 2;
	testArraySize2 = 2;
	outputArray_test[0] = 6;
	outputArray_test[1] = 6;
	outputArray_test[2] = 100;
	outputArray_test[3] = 100;
	fileName = sortToOutput(inputArray1_test, inputArray2_test, testArraySize1, testArraySize2);
	inputFile[4];
	readFile(inputFile, fileName);
	assert(*inputFile == *outputArray_test);
	cout << "\tCase 2.3 passed\n";

	cout << "\t...\n" << "Press enter to continue...";
	cin.ignore();
}
void getFileSize_test(void)
{
        cout << "\nUnit Test Case 3: Function Name – getFileSize(string FileName)\n";
	
	cout << "\tCase 3.1: input_test should have 6 numbers in it\n";
	string fileName_test3 = "input_test.txt";
	int fileSize = getFileSize(fileName_test3);
	assert(fileSize == 6);
	cout << "\tCase 3.1 passed\n";

	cout << "\tCase 3.2: input_test.txt will have one number\n";
	ofstream output_test3;
	output_test3.open(fileName_test3.c_str());
	output_test3 << 1 << "\n";
	output_test3.close();
	fileSize = getFileSize(fileName_test3);
	assert(fileSize == 1);
	cout << "\tCase 3.2 passed\n";

        cout << "\t...\n" << "Press enter to continue...";
        cin.ignore();
}
void isValid_test(void)
{
        cout << "\nUnit Test Case 4: Function Name - isValid(string fileName)\n";

	cout << "\tCase 4.1: file name is valid (input1.txt - make sure this is in the current directory), \n\tfunction will return true.\n";
	string fileName = "input1.txt";
	bool testFile = isValid(fileName);
	assert(testFile == true);
	cout << "\tCase 4.1 passed\n";

	cout << "\tCase 4.2: file name is invalid, will return false\n";
	fileName = "lkajkdfjh@";
	testFile = isValid(fileName);
	assert(testFile == false);
	cout << "\tCase 4.2 passed\n";

        cout << "\t...\n" << "Press enter to continue...";
        cin.ignore();
}
