#include <iostream>

using namespace std;

typedef int angle;

angle a = 30;
angle b = 60;

int main() {
	int choice = 2;
	switch(choice)
	{
		case 1:
			cout << 1;
			break;
		case 2:
			cout << 2 << "\n";
			break;
	}
	bool x = true;
	if(x);
		cout << "yo\n";
        if(x);
                cout << "nah\n";
	return 0;
}