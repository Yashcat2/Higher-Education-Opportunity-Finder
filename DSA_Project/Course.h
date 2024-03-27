#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>  // for setw

//#ifndef HASH_H
//#define HASH_H
#define ANSI_GREEN "\033[32m"
#define ANSI_RESET "\033[0m"
using namespace std;

class listnode {
public:
    string university;
    string description;
    string price;
    string duration;
    listnode* next;
    listnode* prev;

    listnode() {
        university = "NULL";
        description = "NULL";
        price = "NULL";
        duration = "NULL";
        next = NULL;
        prev = NULL;
    }

    listnode(string uni, string dec, string pr, string dr) {
        university = uni;
        description = dec;
        price = pr;
        duration = dr;
    }
};

class Doubly_Linked_List {
private:
    listnode* head;
    listnode* tail;

public:
    int size;

    Doubly_Linked_List() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertLast(string uni, string dec, string pr, string dr) {
        listnode* newnode = new listnode(uni, dec, pr, dr);

        if (tail == NULL) {
            head = newnode;
            tail = newnode;
            size++;
        }
        else {

            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            tail->university = uni;
            tail->price = pr;
            tail->duration = dr;
            tail->description = dec;
            size++;
         
        }


    }

    void printAll() {
        listnode* current = head;

        if (size == 0) {
            cout << "Empty List" << endl;
        }
        else {
            for (int i = 0; i <= size; ++i) {
                cout << "| Course - " << i + 1 << "\t|" << endl;
                cout << current->university << endl;
                cout << current->description << endl;
                cout << "Price: " << current->price << " RUPEES" << endl;
                cout << current->duration << endl;

                cout << "-----------------------------" << endl;
                current = current->next;
            }
        }
    }

    void sortByPrice() {
        if (size <= 1) {
            // Already sorted or empty list
            return;
        }

        bool swapped;
        listnode* ptr1;
        listnode* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->price > ptr1->next->price) {
                    // Swap the nodes
                    swapNodes(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void swapNodes(listnode* a, listnode* b) {
        // Swap university
        string tempUniversity = a->university;
        a->university = b->university;
        b->university = tempUniversity;

        // Swap description
        string tempDescription = a->description;
        a->description = b->description;
        b->description = tempDescription;

        // Swap price
        string tempPrice = a->price;
        a->price = b->price;
        b->price = tempPrice;
    }

    void printCoursesInPriceRange(string range) {
        listnode* current = head;
        int count = 1;
        vector<listnode*> selectedCourses;  // Vector to store selected courses

        cout << setw(60) << "Courses in the selected price range:" << endl;

        while (current != nullptr) {
            // Check if the current node's price falls within the selected range
            if ((range == "1" && stoi(current->price) >= 1000000 && stoi(current->price) <= 1500000) ||
                (range == "2" && stoi(current->price) >= 1500000 && stoi(current->price) <= 2000000) ||
                (range == "3" && stoi(current->price) >= 2000000 && stoi(current->price) <= 2500000) ||
                (range == "4" && stoi(current->price) >= 2500000 && stoi(current->price) <= 2500000)) {
                cout << setw(60) << "| Course - " << count <<"|" << endl;
                cout << endl;
                cout << setw(60) <<"University Name :"<< current->university << endl;
                cout << setw(60) <<"Description :"<< current->description << endl;
                cout << setw(60) << "Price: " << current->price << " RUPEES" << endl;
                cout << setw(60) << "Duration :" << current->duration << " Months" << endl;
                cout << setw(35) << ANSI_GREEN << "=================================================" << ANSI_RESET << endl;

                // Store the current node in the vector
                selectedCourses.push_back(current);
                count++;
            }

            // Move to the next node
            current = current->next;
        }

        // Ask the user to select a course


        if (!selectedCourses.empty()) {

            int selectedNumber;
            cout << setw(70) << "Provide the course number you'd like to choose: ";
            cin >> selectedNumber;
            

            // Validate the user input
            if (selectedNumber >= 1 && selectedNumber <= selectedCourses.size()) {
                // User selected a valid course, you can use selectedCourses[selectedNumber - 1]
               /* Hash hashInstance(1/* specify the size );*/

                // Insert the selected course index into the hash table
                /*hashInstance.insertItem(selectedNumber); */
                cout << "---------------------------------"<<endl;
                cout <<setw(70) << "You selected the following course:" << endl;
                cout << setw(70) << selectedCourses[selectedNumber - 1]->university << endl;
                cout << setw(70) << selectedCourses[selectedNumber - 1]->description << endl;
                cout << setw(70) << "Price: " << selectedCourses[selectedNumber - 1]->price << " RUPEES" << endl;
            }

            else {
                cout << "Invalid selection." << endl;
            }
        }
        else {
            cout << "No courses in the selected price range." << endl;
        }
    }
   

    void printCoursesInPriceRange_1(string range) {
        sortByPrice();
        printCoursesInPriceRange(range);

    }

 


};

struct Students {
    string Name = "NULL";
    string NIC = "NULL";
    string Address = "NULL";
    string PhoneNumber = "NULL";

};

class Course {
private:
    listnode* head;
    Doubly_Linked_List CourseList;
    vector<Students> data; //To save students Details
    Students temp; //Tempory object to input student data
    int NumberOfStudents = 0;
    // Other member variables and functions...

public:
    /*Course() {

        // Initialize other variables or functionalities if needed...
    }
    ~Course() { //Defaul Destructor
    }*/

    void Menu();
    void students();
    string selectField();
    string priceRange();
    void fileRead();

    // Other member functions...
};

/*
class Hash
{
    int BUCKET;    // No. of buckets

    // Pointer to an array containing buckets
    list<int>* table;
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void displayHash();
};
#endif // HASH_H
*/