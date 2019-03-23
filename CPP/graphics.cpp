#include <iostream>
//#include <graphics.h>

using namespace std;

int main(int argc, char const *argv[])
{
	do{
		int Number;
		cout << "Enter a Number: ";
		cin >> Number;
		if (!cin){
			cin.ignore('\n');
			cin.clear();
		}
	}while(!cin);
	cout << "Number is " << endl;
	return 0;
}