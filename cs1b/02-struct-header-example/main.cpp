// main.cpp - Using a struct from a header file
#include "Student.h"
#include <iostream>
using namespace std;

int main()
{
    // Method 1: Declare then assign members individually
    Student student1;
    
    // Method 2: Initialize with initializer list (order matters!)
    Student student2 = { 1234, "Med Mogasemi", 3.3 };
    
    // Get input for student1
    cout << "ID: ";
    cin >> student1.id;
    
    cout << "Name: ";
    cin.ignore();  // Clear newline from buffer
    getline(cin, student1.name);
    
    cout << "GPA: ";
    cin >> student1.gpa;
    
    // Display both students
    cout << "\n--- Student 1 ---\n";
    cout << "ID: " << student1.id << endl;
    cout << "Name: " << student1.name << endl;
    cout << "GPA: " << student1.gpa << endl;
    
    cout << "\n--- Student 2 ---\n";
    cout << "ID: " << student2.id << endl;
    cout << "Name: " << student2.name << endl;
    cout << "GPA: " << student2.gpa << endl;
    
    return 0;
}
