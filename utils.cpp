#include <iostream>
#include "utils.hpp"
#include "controllers.hpp"
#include "object/BST.hpp"

using namespace std;

void showMessage(int i){
    if(i == Add_){
        cout << "Please enter the info of the book\n"; 
    }
    else if(i == Checkout_){
        cout << "Please enter the book's information to checkout\n";
    }
    else if(i == Return_){
        cout << "Please enter the book's information to return\n";
    }
    else if(i == Listall_){
        cout << "======== Books information ========\n";
        cout << "-----------------------------------\n";
    }
    else if(i == Search_){
        cout << "Choose your search criteria\n"
             << "1. Search by title\n"
             << "2. Search by author\n"
             << "3. Search by public year\n";
    }
    else if(i == Entry_){
        cout << "==== Library Management System ====\n"
             << "1. Add a new book\n"
             << "2. Search a book\n"
             << "3. Checkout a book\n"
             << "4. Return a book\n"
             << "5. List all books' info\n"
             << "6. Exit this system\n"
             << "===================================\n";
    }
}

void showBooks(vector<Node*> books){
    cout << "======== Books information ========\n";
    for(auto book : books){
        cout << book;
        cout << "-----------------------------------\n";
    }
    cout << "===================================\n";
}

void navigator(int target, BST& db){
    if(target == Add_){
        Add(db);
    }
    else if(target == Search_){
        Search(db);
    }
    else if(target == Checkout_){
        Checkout(db);
    }
    else if(target == Return_){
        Return(db);
    }
    else if(target == Listall_){
        Listall(db);
    }
    else if(target == Exit_){
        Exit(db);
    }
    else if(target == Entry_){
        Entry(db);
    }
    else if(target == title_){
        SearchByTitle(db);
    }
    else if(target == author_){
        SearchByAuthor(db);
    }
    else if(target == public_year){
        SearchByPublicYear(db);
    }
    else{
        cout << "Not a valid operation...\n";
        Entry(db);
    }
}