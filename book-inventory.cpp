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
#include <cstring>
#include <stdlib.h>
using namespace std;

#define SIZE 100

class Book {
	char *author, *title, *publisher;
	float price;
	int stock;
public:
	void getBookData();
	void printBookData();
	char *getTitle();
	char *getAuthor();
	int getPrice();
	int stockPosition();
};

void Book :: getBookData() {
	title = new char[50];
	author = new char[20];
	publisher = new char[40];

	cout << "Enter the TITLE of the book:\n";
	cin.ignore();
	cin.getline(title,50);

	cout << "Enter the name of AUTHOR:\n";
	cin.ignore();
	cin.getline(author,20);

	cout << "Enter the PUBLISHER of the book:\n";
	cin.ignore();
	cin.getline(publisher,40);

	cout << "Enter the PRICE of the book:\n";
	cin >> price;

	cout << "Enter the QUANTITY of book:\n";
	cin >> stock;
}

void Book :: printBookData() {
	cout << "TITLE--> " << title << endl;
	cout << "AUTHOR--> " << author << endl;
	cout << "PUBLISHER--> " << publisher << endl;
	cout << "PRICE--> " << price << endl;
	cout << "STOCK POSITION--> " << stock << endl;
}
char* Book :: getTitle() { return title; }
char* Book :: getAuthor() { return author; }
int Book :: getPrice() { return price; }
int Book :: stockPosition() { return stock; }


class Inventory {
	int num_of_books = 0, n;
	Book b[SIZE];
public:
	void getNumOfBooks();
	void getInventory();
	void displayInventory();
	int searchInventory(char t[], char a[]);
};

void Inventory :: getNumOfBooks() {
	cout << "Enter the total number of books:\n";
	cin >> n;
}

void Inventory :: getInventory() {
	for(int i = num_of_books; i < n+num_of_books; ++i)
		b[i].getBookData();
	num_of_books += n;
}

void Inventory :: displayInventory() {
	cout << "\n----------Book Inventory----------\n";
	for(int i = 0; i < num_of_books; ++i)
		b[i].printBookData();
	cout << endl;
}

int Inventory :: searchInventory(char t[], char a[]) {
	int cost, ch, i;
	int reqStock;
	for(i = 0; i < num_of_books; i++) {
		if(strcmp(t,b[i].getTitle()) == 0) {
			if(strcmp(a,b[i].getAuthor()) == 0) {
				cout << "<" << t << ">" << "is available\n";
				while(1) {
					cout << "\nEnter:\n1.Price of one copy\n2.Total copies of books you require\n3.Get a glimpse on stock details\n4.Your bill\n5.Exit\n";
					cin >> ch;

					switch(ch) {
						case 1:
							cout << "Price of the book --> ";
							cout << b[i].getPrice();
							break;
						case 2:
							cout << "How many copies do you require?\n";
							cin >> reqStock;
							break;
						case 3:
							if(reqStock <= b[i].stockPosition()) {
								cout << "\n--> STOCK IS AVAILABLE";
								break;
							}
							else {
								cout << "\n--> Oops... seems like book is currently out of stock\n";
								break;
							}
						case 4:
							if(reqStock <= b[i].stockPosition()) {
								cout << "\nTotal Price --> \n";
								cost = reqStock*b[i].getPrice();
								cout << cost;
								break;
							}
							else {
								cout << "\n--> Sorry!!! Book is currently out of stock\n";
								break;
							}
						case 5:
							exit(0);
					}
				}
			}
		}
	}
	if(i == num_of_books) {
		cout << "\nBook isn't available\n";
		return i;
	}
	//return i;
}

int main() {
	int i, ch;
	char searchTitle[50], searchAuthor[20];
	Inventory obj;
	while(1) {
		cout << "\nEnter:\n1.Enter the books in inventory\n2.Display the inventory\n3.Search a book in the inventory\n4.Exit\n";
		cin >> ch;

		switch(ch) {
			case 1:
				obj.getNumOfBooks();
				obj.getInventory();
				break;
			case 2:
				obj.displayInventory();
				break;
			case 3:
				cout << "\nEnter the TITLE of the book you're looking for:\n";
				cin.ignore();
				cin.getline(searchTitle,50);
				
				cout << "\nEnter the AUTHOR of the book you're looking for:\n";
				cin.ignore();
				cin.getline(searchAuthor,20);

				obj.searchInventory(searchTitle,searchAuthor);
				break;
			case 4:
				exit(0);
		}
	}
	return i;
}


