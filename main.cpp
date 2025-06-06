#include <iostream>
#include <vector>
#include <string>
#include "object/BST.hpp"
#include "controllers.hpp"
#include "utils.hpp"

using namespace std;

#define addNewBook 1
#define searchBook 2
#define checkoutBook 3
#define returnBook 4
#define listBooks 5
#define exitMgr 6

int main(int argc, char *argv[]){
    BST db;
    db.load();
    Entry(db);
}