#include <iostream>
#include <vector>
#include <limits>
#include "utils.hpp"
#include "object/BST.hpp"
#include "object/node.hpp"

using namespace std;


void Add(BST& db){
    showMessage(Add_);
    string title, author;
    int copy, year;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    cout << "> Title: ";
    do{
        getline(cin, title);
    }while(title.length() > 20 && cout << "length > 20, invaild. Try again: ");
    cout << "> Author: ";
    do{
        getline(cin, author);
    }while(author.length() > 20 && cout << "length > 20, invaild. Try again: ");
    cout << "> Available copies: ";
    while (!(cin >> copy) || copy < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Try again: ";
    }
    cout << "> Public Year: ";
    while (!(cin >> year) || year < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Try again: ";
    }

    Node* newNode = new Node(title, author, year, copy);
    if(!db.isIn(newNode)){
        db.insert(newNode);
        cout << "Success!\n";
    }
    else{
        cout << "The book has already existed\n";
    }
    cout << "Navigate back to main page...\n\n";
    navigator(Entry_, db);
}

void Checkout(BST& db){
    showMessage(Checkout_);
    vector<Node*> v;
    string title, author;
    int year;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "> Title: ";
    do{
        getline(cin, title);
    }while(title.length() > 20 && cout << "length > 20, invaild. Try again: ");
    cout << "> Author: ";
    do{
        getline(cin, author);
    }while(author.length() > 20 && cout << "length > 20, invaild. Try again: ");
    cout << "> Public Year: ";
    while (!(cin >> year) || year < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Try again: ";
    }
    db.searchByAll(title, year, author, v);
    if(v.size() == 0){
        cout << "No such book in this library\n";
    }
    else if(v[0]->getAvaliable_copies() == 0){
        cout << "No more avaliable copy\n";
    }
    else{
        v[0]->borrowOne();
        cout << "Success!\n";
    }
    cout << "Navigate back to main page...\n\n";
    navigator(Entry_, db);
}

void Return(BST& db){
    showMessage(Return_);
    vector<Node*> v;
    string title, author;
    int year;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "> Title: ";
    do{
        getline(cin, title);
    }while(title.length() > 20 && cout << "length > 20, invaild. Try again: ");
    cout << "> Author: ";
    do{
        getline(cin, author);
    }while(author.length() > 20 && cout << "length > 20, invaild. Try again: ");
    cout << "> Public Year: ";
    while (!(cin >> year) || year < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Try again: ";
    }
    db.searchByAll(title, year, author, v);
    if(v.size() == 0){
        cout << "No such book in this library\n";
    }
    else{
        v[0]->returnOne();
        cout << "Success!\n";
    }
    cout << "Navigate back to main page...\n\n";
    navigator(Entry_, db);
}

void Listall(BST& db){
    showMessage(Listall_);
    db.listall();
    cout << "===================================\n"
         << "Navigate back to main page...\n\n";
    navigator(Entry_, db);
}

void SearchByTitle(BST& db){
    vector<Node*> v;
    string title;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "> Title: ";
    do{
        getline(cin, title);
    }while(title.length() > 20 && cout << "length > 20, invaild. Try again: ");
    db.searchByTitle(title, v);
    if(v.size() != 0){
        showBooks(v);
    }
    else{
        cout << "No such book in the library\n";
    }
    cout << "Navigate back to main page...\n\n";
    navigator(Entry_, db);
}

void SearchByAuthor(BST& db){
    vector<Node*> v;
    string author;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "> Author: ";
    do{
        getline(cin, author);
    }while(author.length() > 20 && cout << "length > 20, invaild. Try again: ");
    db.searchByAuthor(author, v);
    if(v.size() != 0){
        showBooks(v);
    }
    else{
        cout << "No such book in the library\n";
    }
    cout << "Navigate back to main page...\n\n";
    navigator(Entry_, db);
}

void SearchByPublicYear(BST& db){
    vector<Node*> v;
    int year;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "> Public Year: ";
    while (!(cin >> year) || year < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Try again: ";
    }
    db.searchByPublicYear(year, v);
    if(v.size() != 0){
        showBooks(v);
    }
    else{
        cout << "No such book in the library\n";
    }
    cout << "Navigate back to main page...\n\n";
    navigator(Entry_, db);
}

void Search(BST& db){
    showMessage(Search_);
    int choice;
    cout << "> Enter your choice: ";
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Try again: ";
    }
    navigator(choice+7, db);
}

void Exit(BST& db){
    db.save();
    db.rmalloc();
    cout << "Good Bye\n";
    exit(0);
}

void Entry(BST& db){
    showMessage(Entry_);
    int choice;
    cout << "> Enter your choice: ";
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Try again: ";
    }
    navigator(choice, db);
}