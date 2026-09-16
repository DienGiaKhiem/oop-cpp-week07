#include <iostream>
#include <string>
using namespace std;

struct ComputerInfo{
    int id;
    string Computername;
    string system;
    string username;
    string model;   
    int year;
};

void computerInfo(ComputerInfo info){
    cout << "Computer ID: " << info.id << endl;
    cout << "Computer Name: " << info.Computername << endl;
    cout << "System: " << info.system << endl;
    cout << "Username: " << info.username << endl;
    cout << "Model: " << info.model << endl;
    cout << "Year: " << info.year << endl;
}