/******************************************************************************

Student List by Nabhan Abedin
This program creates an editable database of students, including their names, ID's, and GPA's.
3.14.2021


*******************************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
#include <ctype.h> //for uppercase conversion

using namespace std;

struct Student { //struct with all the info
    char firstName[100];
    char lastName[100];
    int id;
    float gpa;
};

//function prototypes
void addStudent(vector <Student*> &StudentList);
void printStudent(vector<Student*> &StudentList);
void deleteStudent(vector<Student*> &StudentList);

int main()
{
    bool running = true;
    vector<Student*> StudentList; //
    while (running) {
        char command[20];
        cout<<"Enter command (ADD, PRINT, DELETE, QUIT): ";
        cin >> command;
        for (int i = 0; i < sizeof(command); i++) { //convert command to uppercase
            command[i] = toupper(command[i]);
        }
        //call functions dependent on command
        if (strcmp(command, "ADD") == 0) {
            addStudent(StudentList);
        } else if (strcmp(command, "PRINT") == 0) {
            printStudent(StudentList);
        } else if (strcmp(command, "DELETE") == 0) {
            deleteStudent(StudentList);
        } else if (strcmp(command, "QUIT") == 0) {
            cout << "Program has ended.";
            running = false; //exit program
        }
       
    }
    return 0; 
}

//adds student pointer into the vector of student pointers (StudentList)
void addStudent(vector<Student*> &StudentList) {
    Student* Studentptr = new Student;
    cout << "Enter student's first name: ";
    cin >> (*Studentptr).firstName;
    cout << "Enter student's last name: ";
    cin >> (*Studentptr).lastName;
    cout << "Enter student's ID number: ";
    cin >> (*Studentptr).id;
    cout << "Enter student's GPA: ";
    cin >> (*Studentptr).gpa;
    StudentList.push_back(Studentptr);
}

//iterate through StudentList and print every component of each struct
void printStudent(vector<Student*> &StudentList) { 
    for (vector<Student*>::iterator Studentptr = StudentList.begin(); Studentptr != StudentList.end(); ++Studentptr) {
        cout << (*Studentptr) -> firstName << " " << (*Studentptr) -> lastName << ", " << (*Studentptr) -> id << ", " << (*Studentptr) -> gpa << "\n";
    }
}

//iterate through StudentList to find matching id number and remove Student from the vector of student pointers
void deleteStudent(vector<Student*> &StudentList) {
    int deleteID;
    cout << "Enter the id of the student you want to delete: ";
    cin >> deleteID;
    int i = 0;
    for (vector<Student*>::iterator Studentptr = StudentList.begin(); Studentptr != StudentList.end(); ++Studentptr) {
        if ((*Studentptr) -> id == deleteID) {
            StudentList.erase(StudentList.begin() + i);
            break;
        } else {
            i++;
        }
    }    

}