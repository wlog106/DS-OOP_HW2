#pragma once
#include "node.hpp"

using namespace std;

class BST{
public:
    BST(){}
    void insert(Node* newNode);
    void searchByBoth(string title, int year, vector<Node*>& result);
    void searchByTitle(string title, vector<Node*>& result);
    void searchByPublicYear(int year, vector<Node*>& result);
    void searchByAuthor(string author, vector<Node*>& result);
    void listall();
    void load();
    void save();
    

private:
    void insert(Node* newNode, Node* cur);
    void searchByBoth(string title, int year, Node* cur, vector<Node*>& result);
    void searchByTitle(string title, Node* cur, vector<Node*>& result);
    void searchByPublicYear(int year, Node* cur, vector<Node*>& result);
    void searchByAuthor(string author, Node* cur, vector<Node*>& result);
    void listall(Node* cur);
    Node* root;
};
