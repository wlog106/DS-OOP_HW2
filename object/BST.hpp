#pragma once
#include <vector>
#include "node.hpp"

using namespace std;

class BST{
public:
    BST();
    void insert(Node* newNode);
    void searchByAll(string title, int year, string author, vector<Node*>& result);
    void searchByTitle(string title, vector<Node*>& result);
    void searchByPublicYear(int year, vector<Node*>& result);
    void searchByAuthor(string author, vector<Node*>& result);
    void rmalloc();
    void listall();
    bool isIn(Node* node);
    void load();
    void save();
    

private:
    void insert(Node* newNode, Node* cur);
    void searchByAll(string title, int year, string author, Node* cur, vector<Node*>& result);
    void searchByTitle(string title, Node* cur, vector<Node*>& result);
    void searchByTitle_(string title, Node* cur, vector<Node*>& result);
    void searchByPublicYear(int year, Node* cur, vector<Node*>& result);
    void searchByAuthor(string author, Node* cur, vector<Node*>& result);
    void listall(Node* cur);
    void rmalloc(Node* cur);
    void balanceLoad(vector<Node*> lv, int start, int end);
    void save(Node* cur, ofstream& out);
    Node* root;
};
