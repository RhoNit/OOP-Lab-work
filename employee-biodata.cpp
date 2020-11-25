#include <iostream>
using namespace std;

class Person {
	int age;
	char name[20];
public:
	void getData() {
		cin.ignore();
		cout << "\nEnter the name of person:\n";
		cin.getline(name,20);
		cout << "\nEnter his/her age:\n";
		cin >> age;
	}
	void printData() {
		cout << "\nName of the employee --> " << name << endl;
		cout << "Age --> " << age << endl;
	}
};

class ProfessionalRecords {
	char company[30], role[30];
	float exp;
public:
	void getPR() {
		cin.ignore();
		cout << "Enter in which company the person works:\n";
		cin.getline(company,30);
		
		cout << "Enter his/her role in company:\n";
		cin.getline(role,30);

		cout << "Enter his/her work-experience in years:\n";
		cin >> exp;
	}

	void printPR() {
		cout << "Company in which the employee works --> " << company << endl;
		cout << "Role --> " << role << endl;
		cout << "Years of experience --> " << exp << endl;
	}
};

class AcademicRecords {
	float ssc_per, hsc_per, grad_cgpa;
	char clg[20], degree[50];
public:
	void getAR() {
		cin.ignore();
		cout << "Enter 10th percentage:\n";
		cin >> ssc_per;
		cout << "Enter 12th percentage:\n";
		cin >> hsc_per;
		cin.ignore();
		cout << "Enter from which college the person graduated:\n";
		cin.getline(clg,20);
		cout << "Enter field of study:\n";
		cin.getline(degree,50);
		cout << "Enter graduation CGPA:\n";
		cin >> grad_cgpa;
	}
	void printAR() {
		cout << "10th percentage --> " << ssc_per << endl;
		cout << "12th percentage --> " << hsc_per << endl;
		cout << "Graduated from --> " << clg << endl;
		cout << "Degree --> " << degree << endl;
		cout << "Graduation CGPA --> " << grad_cgpa << endl;
	}
};

class Employee : public Person, public ProfessionalRecords, public AcademicRecords {
public:
	void read() {
		getData();
		getPR();
		getAR();
	}
	void display() {
		cout << "\n\n------------Displaying employee-info------------\n";
		printData();
		printPR();
		printAR();
	}
};


int main() {
	Employee emp[100];
	int num;
	cout << "How many employee bio-data you want to store?\n";
	cin >> num;

	for(int i = 0; i < num; ++i) {
		emp[i].read();
		emp[i].display();
	}
	return 0;
}
