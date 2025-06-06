#include <iostream>
#include <vector>
#include "utils.hpp"
#include "object/BST.hpp"
#include "object/node.hpp"

#define Add_ 1
#define Search_ 2
#define Checkout_ 3
#define Return_ 4
#define Listall_ 5
#define Exit_ 6 
#define Entry_ 7
#define title_ 8
#define author_ 9
#define public_year 10

using namespace std;


void Add(BST& db){
    showMessage(Add_);
    string title, author;
    int copy, year;
    cout << "Title: ";
    cin >> title;
    cout << "\nAuthor: ";
    cin >> author;
    cout << "\nAvailable copies: ";
    cin >> copy;
    cout << "\nPublic Year: ";
    cin >> year;
    cout << "\n";
    Node* newNode = new Node(title, author, year, copy);
    db.insert(newNode);
    cout << "Success!\nNavigate back to main page...\n";
    navigator(Entry_, db);
}

void Checkout(BST& db){
    showMessage(Checkout_);
    vector<Node*> v;
    string title;
    int year;
    cout << "Title: ";
    cin >> title;
    cout << "\nPublic Year: ";
    cin >> year;
    cout << "\n";
    db.searchByBoth(title, year, v);
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
    cout << "Navigate back to main page...\n";
    navigator(Entry_, db);
}

void Return(BST& db){
    showMessage(Return_);
    vector<Node*> v;
    string title;
    int year;
    cout << "Title: ";
    cin >> title;
    cout << "\nPublic Year: ";
    cin >> year;
    cout << "\n";
    db.searchByBoth(title, year, v);
    if(v.size() == 0){
        cout << "No such book in this library\n";
    }
    else{
        v[0]->returnOne();
        cout << "Success!\n";
    }
    cout << "Navigate back to main page...\n";
    navigator(Entry_, db);
}

void Listall(BST& db){
    showMessage(Listall_);
    db.listall();
    cout << "=======================================\n"
         << "Navigate back to main page...\n";
    navigator(Entry_, db);
}

void SearchByTitle(BST& db){
    vector<Node*> v;
    string title;
    cout << "Title: ";
    cin >> title;
    cout << "\n";
    db.searchByTitle(title, v);
    for(auto book : v){
        cout << book;
    }
}

void SearchByAuthor(BST& db){
    vector<Node*> v;
    string author;
    cout << "Author: ";
    cin >> author;
    cout << "\n";
    db.searchByAuthor(author, v);
    for(auto book : v){
        cout << book;
    }
}

void SearchByPublicYear(BST& db){
    vector<Node*> v;
    int year;
    cout << "Public Year: ";
    cin >> year;
    cout << "\n";
    db.searchByPublicYear(year, v);
    for(auto book : v){
        cout << book;
    }
}

void Search(BST& db){
    showMessage(Search_);
    int choice;
    cin >> choice;
    navigator(choice+7, db);
}

void Exit(BST& db){
    db.save();
    cout << "Goodbye\n";
    exit;
}

void Entry(BST& db){
    showMessage(Entry_);
    int choice;
    cin >> choice;
    navigator(choice, db);
}