/* Source code by :                 	
   _______                            _     _
  |   __  \                          |_|   | |                        
  |  |  |  |     ______    _______    _   _| |____                           
  |  |__|  |    |____  \  |  ___  \  | | |_   ____|                       
  |   _   /     _____| |  | |   | |  | |   | |                          
  |  | \  \    /  ___  |  | |   | |  | |   | |   _                      
  |  |  \  \  |  |___| |  | |   | |  | |   | |__/ /                        
  |__|   \__\  \_______|  |_|   |_|  |_|   |_____/   

*/

#include <iostream>
using namespace std;

class Calculator {
	float a, b;
	char d;
	float addition() { cout << a+b; }
	float subtraction() { cout << a-b; }
	float multiplication() { cout << a*b; }
	float division() { cout << a/b; }
public:
	Calculator() {
		a = b = 0;
		d = NULL;
	}
	void read() {
		cout << "\nEnter the operation you wanna perform:\n";
		cin >> d;
		cout << "Enter the value:\n";
		cin >> a >> b;
	}
	void calculate() {
		cout << "Result is --> ";
		switch(d) {
			case '+':
				addition();
				break;
			case '-':
				subtraction();
				break;
			case '*':
				multiplication();
				break;
			case '/':
				division();
				break;
			default:
				cout << "Enter valid choice...";
				break;
		}
	}
};

int main() {
	int ans;
	Calculator obj;
	do {
		obj.read();
		obj.calculate();
		cout << "\nDo you want to perform any other operation(y/n)?\n";
		cin >> ans;
	} while(ans == 'y');
	return 0;
}