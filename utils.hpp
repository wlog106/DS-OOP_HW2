#pragma once

#include "object/BST.hpp"

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

void showMessage(int i);

void navigator(int i, BST& db);