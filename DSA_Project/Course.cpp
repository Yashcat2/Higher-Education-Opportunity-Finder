#include "Course.h"

using namespace std;
#include <string>
#include <fstream>
#include <vector>
//Bellow includes are recently added
#include <iostream>
#ifdef _WIN32
#include <windows.h> // For Windows console functions
#endif
#include <iomanip>  // for setw
// ANSI escape codes for text colors
// Reset Color:
#define ANSI_RESET "\033[0m"


//Foreground Colors:
//#define ANSI_BLACK "\033[30m"
//#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
//#define ANSI_YELLOW "\033[33m"
//#define ANSI_MAGENTA   "\033[34m"
//#define ANSI_MAGENTA "\033[35m"
//#define ANSI_CYAN "\033[36m"
//#define ANSI_WHITE "\033[37m"


void setTextColor(int color) {
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}


void Course::Menu() {
	// Your menu implementation
	string Choose;
	cout << ANSI_GREEN << setw(80) << "====================================" << ANSI_RESET << endl;
	cout << setw(60)			   << "\t  |A|->Students" << endl;
	cout << setw(60)			   << "|B|->Field" << endl;
	cout << setw(70)			   << "|C|->Selected Course" << endl;
	cout << setw(60)			   << "\t  |E|->Add data" << endl;
	cout << ANSI_GREEN << setw(80) << "     ====================================" << ANSI_RESET << endl;
	cout << setw(70)			   << "     Insert A, B, C, D or E" << endl;
	cout << ANSI_GREEN << setw(80) << "     ====================================" << ANSI_RESET << endl;
	cin >> Choose;


	if (Choose == "A" || Choose == "a")
	{
		//student selection
		system("cls"); //clear the screen and cursor go to the left top cornor

		//student function
		students();

	}
	else if (Choose == "B" || Choose == "b") {
		system("cls");


		//select field
		selectField();
	}
	else if (Choose == "C" || Choose == "c") {
		system("cls");

		//cout << hashtble << endl;;
		//selected caurses
	}
	else if (Choose == "E" || Choose == "e") {
		system("cls");

		//add testing data
		fileRead();
		system("cls");
		Menu();

	}
	else {
		system("cls");
		cout << setw(80)  <<"\t  OOPs.....!!!! Wrong selection....Try again" <<   endl;
		Menu();
	}
}


string Course::selectField() {
	// Logic to select a field
	string category;
	cout << setw(40) << ANSI_GREEN << " ===============================================" << ANSI_RESET << endl;
	cout << setw(60)			   << "			Select Your Field               "  << endl;
	cout << setw(40) << ANSI_GREEN <<  " ===============================================" << ANSI_RESET << endl;
	cout << setw(75)			   << "\t   01. Chemical Engineering          "  << endl;
	cout << setw(65)			   << "\t   02. Civil Engineering			   "  << endl;
	cout << setw(80)			   << "\t   03. Electrical and Electronic Engineering   "  << endl;
	cout << setw(70)			   << "\t   04. Mechanical Engineering		   "  << endl;
	cout << setw(40) << ANSI_GREEN << " ===============================================" << ANSI_RESET << endl;

	cin >> category;
	if (category == "1" || category == "2" || category == "3" || category == "4" || category == "5") {
		system("cls");
		priceRange();
	}
	else {
		system("cls");
		cout << setw(70) << "\t    Invalied Field.....!Try again" << endl;
		category = selectField();
	}
	return(category);
}


void Course::students() {
	// Your student handling logic
	string student_1;
	cout << setw(40) << ANSI_GREEN << "================================================" << ANSI_RESET <<  endl;
	cout << setw(80) << "\t  |E| Studant is an exsisting student    " <<  endl;
	cout << setw(80) << "\t  |N| Student is a new Student             " << endl;
	cout << setw(80) << "\t  |B| Go Back                              "  << endl;
	cout << setw(40) << ANSI_GREEN << "================================================" << ANSI_RESET << endl;

	cin >> student_1;


	if (student_1 == "N" || student_1 == "n") {
		//creating a new Student
		system("cls");
		cout << setw(50) << "Name = "; cin.ignore();
		getline(cin, temp.Name); //get input in seperate lines
		cout << setw(50) << "NIC = "; cin >> temp.NIC;
		cout << setw(50) << "Address = "; cin.ignore();
		getline(cin, temp.Address);
		cout << setw(50) << "Mobile Number = "; cin >> temp.PhoneNumber;


		NumberOfStudents++;

		data.push_back(temp);

		string anotherNewStudent;
		cout << setw(40) << ANSI_GREEN <<  "=====================================" << ANSI_RESET << endl;
		cout << setw(65) << "|A|->Add onther Student" << endl;
		cout << setw(50) << "\t  |B|->Go back" << endl;
		cout << setw(50) << "\t  |C|->Menu" << endl;
		cout << setw(30) << ANSI_GREEN << "\t   =====================================" << ANSI_RESET << endl;
		cin >> anotherNewStudent;

		if (anotherNewStudent == "A" || anotherNewStudent == "a") {
			//addNewStudent();

			//add a newStudent using students's linkedList

			system("cls");
			students();

		}
		else if (anotherNewStudent == "B" || anotherNewStudent == "b") {
			//Go back
			system("cls");
			students(); //redirecting the student


		}
		else if (anotherNewStudent == "C" || anotherNewStudent == "c") {
			system("cls");
			Menu(); //redirecting the main menu

		}
		else if (anotherNewStudent == "K") {
			//operating for an existing customer

		}

	}
	else if (student_1 == "B" || student_1 == "b") {
		system("cls");
		Menu();
	}
	else {
		// Operation for existing customer
		system("cls");
		int j = 0;
		bool found = false;
		cout << setw(50) << "Enter NIC for existing customer: ";
		string inputNIC;
		cin >> inputNIC;
		cout << setw(50) << data.size();

		while (j < data.size()) {
			if (data[j].NIC == inputNIC) {
				found = true;
				break;
			}
			j++;
		}
		int loopfactor = 0;
		while (loopfactor == 0) {
			system("cls");
			if (found) {
				// Print information for the existing customer
				cout << setw(50) << "Name: " << data[j].Name << endl;
				cout << setw(50) << "NIC: " << data[j].NIC << endl;
				cout << setw(50) << "Address: " << data[j].Address << endl;
				cout << setw(50) << "Phone Number: " << data[j].PhoneNumber << endl;

				string option_1;
				cout << "Need to change student details(y/n)";
				cin >> option_1;
				if (option_1 == "y" || option_1 == "Y") {
					string Opinion;
					cout << "| A | Edit Customer's Name\t\t|\n| B | Edit Customer's NIC\t\t|\n| C | Edit Customer's Address\t\t|" << endl;
					cout << "| D | Edit Customer's Phone Number\t|\n| G | Main menu \t\t\t| \n----------------------------------------" << endl;
					cin >> Opinion;


					//Editing customer's data section
					if (Opinion == "A" || Opinion == "a") //Edit custormer's name
					{
						cout << setw(50) << "New Name =";
						cin >> data[j].Name;
					}
					else if (Opinion == "B" || Opinion == "b") //Edit custormer's NIC
					{
						cout << setw(50) << "New NIC =";
						cin >> data[j].NIC;
					}
					else if (Opinion == "C" || Opinion == "c") //Edit custormer's Address
					{
						cout << setw(50) << "New Address =";
						cin >> data[j].Address;
					}
					else if (Opinion == "D" || Opinion == "d") //Edit custormer's Phone no.
					{
						cout << setw(50) << "New Phone Number =";
						cin >> data[j].PhoneNumber;
					}
					else //Direct to the main menu
					{
						loopfactor = 1;
						system("cls");
						Menu();
					}

				}
				else {
					Menu();
				}
			}
			else {
				cout << setw(50) << "Customer with NIC " << inputNIC << " not found." << endl;
			}

		}


	}
	system("cls");
	students();
	//Edit student details


}


string Course::priceRange() {
	system("cls");
	string range;
	
	cout << setw(50) << ANSI_GREEN << "=========================================" << ANSI_RESET << endl;
	cout << setw(80) <<"\t   Select a preference price range    " << ANSI_RESET <<endl;
	cout << setw(50) << ANSI_GREEN << "=========================================" << ANSI_RESET<< endl;
	cout << endl;
	cout << setw(80) <<"|1|.RS. 1 000 000 - 1 500 000"    << ANSI_RESET << endl;
	cout << setw(80) <<"|2|.RS. 1 500 000 - 2 000 000"    << ANSI_RESET<<endl;
	cout << setw(80) <<"|3|.RS. 2 000 000 - 2 500 000"    << ANSI_RESET<< endl;
	cout << setw(80) <<"|4|.RS. 2 500 000 - 3 000 000"    << ANSI_RESET <<endl;
	cout << endl;
	cout << setw(50) << ANSI_GREEN << "=========================================" << ANSI_RESET<< endl;

	cin >> range;

	system("cls");

	
	// Traverse the linked list
	CourseList.printCoursesInPriceRange_1(range);

	return range;
}


void Course::fileRead() {
	
	fstream task;
	task.open("Tasklist.txt", ios::in);

	cout << setw(45) << ANSI_GREEN << "=================================================" << ANSI_RESET << endl;
	cout << setw(85) << "What department details you want to store";
	cout << endl;
	cout << setw(45) << ANSI_GREEN << "=================================================" << ANSI_RESET << endl;


	string category_1;

	cout << setw(70) << "\t1.Chemical Engineering "<< endl;
	cout << setw(65) << "\t2.Civil Engineering" << endl;
	cout << setw(80) << "\t3.Electrical and Electronic Engineering" << endl;
	cout << setw(70) <<"\t4.Mechanical Engineering" << endl;
	cout << setw(45) << ANSI_GREEN << "=================================================" << ANSI_RESET << endl;

	cin >> category_1;
	if (category_1 == "1") {
		system("cls");

	}
	else {
		system("cls");
		cout << setw(70) << "Invalied Field" << endl;
	}


	if (true) {
		if (task.peek() == ifstream::traits_type::eof()) {
			
		}
		else {
			cout << setw(70) << "File is not empty" << endl;
		}

		int lenth = 0;
		cout << setw(70) << "Enter the number of courses you want to store: ";
		cin >> lenth;
		cin.ignore();

		for (int i = 0; i < lenth; ++i) {
			string uni, dec, pr,dr;
			cout << setw(35) << ANSI_GREEN << "=================================================" << ANSI_RESET << endl;
			cout << setw(50) << "University " << i + 1 << endl;
			cout << setw(35) << ANSI_GREEN << "=================================================" << ANSI_RESET << endl;
			cout << setw(45) << endl;
			cout << setw(50) << "University Name " << ": ";
			getline(cin, uni);

			cout << setw(50) << "Description "  << ": ";
			getline(cin, dec);

			cout << setw(50) << "Price "  << ": "<<"RS. ";
			getline(cin, pr);

			cout << setw(50) << "Duration" << ": ";
			getline(cin, dr);
			

			task << uni << " " << dec << " " << pr << endl;
			CourseList.insertLast(uni, dec, pr ,dr);
		}

		task.close();

	}
}

/*

int getConsoleWidth() {
#ifdef _WIN32
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return columns;
#else
	// For other platforms, you may need to find a different way to get the console width
	return 80; // Default width
#endif
}*/
/*
void centerText(const std::string& text) {
	int consoleWidth = getConsoleWidth();
	int padding = (consoleWidth - text.length()) / 2;

	for (int i = 0; i < padding; ++i) {
		std::cout << " ";
	}

	std::cout << text << std::endl;
} */
/*
Hash::Hash(int V) : BUCKET(V), table(new std::list<int>[BUCKET]) {}

void Hash::insertItem(int x) {
	int index = hashFunction(x);
	table[index].push_back(x);
}

void Hash::deleteItem(int key) {
	int index = hashFunction(key);

	for (auto it = table[index].begin(); it != table[index].end(); ++it) {
		if (*it == key) {
			table[index].erase(it);
			break;
		}
	}
}
int Hash::hashFunction(int x) {
	return x % BUCKET;
}

void Hash::displayHash() {
	for (int i = 0; i < BUCKET; ++i) {
		std::cout << "[" << i << "]";
		for (auto it = table[i].begin(); it != table[i].end(); ++it)
			std::cout << " -> " << *it;
		std::cout << std::endl;
	}
}*/