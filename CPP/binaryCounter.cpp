#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int number,next,prev;
	number = 1;
	while( number < 100 ){
        next = number + number;
        number = next;
        cout << " " << next << endl;
	}
	return 0;
}