#include <iostream>
#include <vector>
#include <string>
#include "object/BST.hpp"
#include "controllers/entry/entry.hpp"
#include "utils.hpp"

using namespace std;

#define addNewBook 1
#define searchBook 2
#define checkoutBook 3
#define returnBook 4
#define listBooks 5
#define exitMgr 6

int main(int argc, char *argv[]){
    load_data();
    BST db;
    Entry(db);
}