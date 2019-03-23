#include <iostream>
#include <string>

using namespace std;

class Number{
private:
	int number;
     string position;
public:
	Number(){
		number = 0;
		position = "";
	}
	int getNumber(void){
		return number;
	}
	string getPosition(void){
		return position;
	}
	void setPosition(string pos){
		position = pos;
	}
};

  Number numbers[4];

void read(int array,int len){
		for(int i = 0; i < len; i++){
			for(int j = 2; j < 5; j++){
				if(numbers[j].getNumber() < numbers[i].getNumber()){
					 numbers[j].setPosition(i);
					 numbers[i].setPosition(j);
				}
			}
		}
	}
 int main( ){
 	

 	return 0;
 }