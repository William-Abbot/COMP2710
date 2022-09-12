

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/*
* Check whether a file exists.
*
* Param: file Name of file to read. (string)
* Return: true File exists. (boolean)
*/
bool check_file(string);

/*
* Return a vector containing the numbers in a specified file.
*
* Param: file Name of file to read. (string)
* Return: v Vector containing numbers from file. (vector<int>)
*/
vector<int> read_file(string);

/*
* Write the values of a specified vector to a specified file.
*
* Param: file Name of file to write. (string)
* Param: v Vector containing values to write to file. (vector<int>)
*/
void write_file(string, vector<int>);

/*
* Combine the values from two vectors into one vector, sorted
* in ascending order.
*
* Param: v1 First vector to combine. (vector<int>)
* Param: v2 Second vector to combine. (vector<int>)
* Return: v3 Combined and sorted vector. (vector<int>)
*/
vector<int> merge(vector<int>, vector<int>);

/*
* Display the values of a given vector.
*
* Param: file Name of file to display. (string)
* Param: v Vector containing values to display. (vector<int>)
*/
void to_string(string, vector<int>);

/*
* Merge the numbers in two specified files and write all the numbers
* to a specified third file sorted in ascending order.
*
* Return: 1 Program completed successfully. (int)
*/
int main() {
	/* Name of input file one. (string) */
	string file1;

	/* Name of input file two. (string) */
	string file2;

	/* Name of output file. (string) */
	string file3;

	/* Vector containing values from file one. (vector<int>) */
	vector<int> numbers1;

	/* Vector containing values from file two. (vector<int>) */
	vector<int> numbers2;

	/* Vector containing values to write to output file. (vector<int>) */
	vector<int> numbers3;

	cout << "*** Welcome to \033[1mClay Miller\033[0m's sorting program ***\n";

	/* Get name of file one. */
	do {
		cout << "Enter the first input file name: \033[1m";
		cin >> file1;
		cout << "\033[0m";
	} while (cin.fail() || !check_file(file1));

	/* Get and display numbers from file one. */
	numbers1 = read_file(file1);
	to_string(file1, numbers1);

	/* Get name of file two. */
	do {
		cout << "Enter the second input file name: \033[1m";
		cin >> file2;
		cout << "\033[0m";
	} while (cin.fail() || !check_file(file2));

	/* Get and display numbers from file two. */
	numbers2 = read_file(file2);
	to_string(file2, numbers2);

	/* Combine vectors and display the sorted result. */
	numbers3 = merge(numbers1, numbers2);
	cout << "The sorted list of \033[1m" << numbers3.size() << "\033[0m "
		 << "numbers is: ";

	for (int i = 0; i < numbers3.size() - 1; i++) {
		cout << numbers3.at(i) << " ";
	}
	cout << numbers3.at(numbers3.size() - 1) << "\n";

	/* Get name of output file. */
	do {
		cout << "Enter the output file name: \033[1m";
		cin >> file3;
		cout << "\033[0m";
	} while (cin.fail());

	/* Write combined vector to output file. */
	write_file(file3, numbers3);
	cout << "*** Please check the new file - " << file3 << " ***\n";
	cout << "*** Goodbye. ***\n";

	return 1;
}

bool check_file(string file) {
	/* Input file stream. (ifstream) */
	ifstream stream;

	/* Check whether file exists. */
	stream.open(file.c_str());
	if (stream.fail()) {
		cerr << "File not found.\n\n";
		return false;
	}
	stream.close();

	return true;
}

vector<int> read_file(string file) {
	/* Input file stream. (ifstream) */
	ifstream stream;

	/* Vector containing numbers from file. (vector<int>) */
	vector<int> v;

	/* Integer read from file. (int) */
	int i;

	/* Add each number in the file to a vector. */
	stream.open(file.c_str());
	while (stream.good()) {
		stream >> i;
		v.push_back(i);
	}
	v.pop_back();
	stream.close();

	return v;
}

void write_file(string file, vector<int> v) {
	/* Output file stream. (ofstream) */
	ofstream stream;

	/* Vector iterator number. (unsigned short) */
	unsigned short i;

	/* Write each number in the vector to the file. */
	stream.open(file.c_str());
	for (i = 0; i < v.size() - 1; i++) {
		stream << v.at(i) << "\n";
	}
	stream << v.at(v.size() - 1);
	stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
	/* Combined and sorted vector. (vector<int>) */
	vector<int> v3;

	/* Vector interator number. (unsigned short) */
	unsigned short i;

	/* Vector iterator size. (unsigned short) */
	unsigned short s;

	/* Compare both vectors. */
	while (v1.size() > 0 && v2.size() > 0) {
		if (v1.at(0) < v2.at(0)) {
			v3.push_back(v1.at(0));
			v1.erase(v1.begin());
		} else {
			v3.push_back(v2.at(0));
			v2.erase(v2.begin());
		}
	}

	/* Add any remaining numbers from vector one. */
	if (v1.size() > 0) {
		s = v1.size();
		for (i = 0; i < s; i++) {
			v3.push_back(v1.at(0));
			v1.erase(v1.begin());
		}
	}

	/* Add any remaining numbers from vector two. */
	if (v2.size() > 0) {
		s = v2.size();
		for (i = 0; i < s; i++) {
			v3.push_back(v2.at(0));
			v2.erase(v2.begin());
		}
	}
			
	return v3;
}

void to_string(string file, vector<int> v) {
	/* Vector interator number. (unsigned short) */
	unsigned short i;

	/* Display the numbers contained in a vector. */
	cout << "The list of \033[1m" << v.size() << "\033[0m numbers "
		 << "in file \033[1m" << file << "\033[0m is:\n";

	for (i = 0; i < v.size(); i++) {
		cout << v.at(i) << "\n";
	}

	cout << "\n";
}
