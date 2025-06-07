#include <iostream>
#include <fstream>
#include <vector>
#include "BST.hpp"
#include "node.hpp"

using namespace std;

BST::BST(){
    root = nullptr;
}

void BST::load(){
    ifstream in;
    char buffer[25];
    vector<Node*> v;
    vector<string> vs;
    in.open("data.txt");
    while(in.getline(buffer, 25)){
        string str(buffer);
        if(str == "--------"){
            Node* newNode = new Node(vs[0], vs[1], stoi(vs[2]), stoi(vs[3]));
            v.push_back(newNode);
            vs.clear();
            continue;
        }
        vs.push_back(buffer);
    }
    in.close();
    balanceLoad(v, 0, v.size()-1);
}

void BST::balanceLoad(vector<Node*> v, int start, int end){
    if(start > end) return;

    int mid = (start+end)/2;
    insert(v[mid]);

    balanceLoad(v, start, mid-1);
    balanceLoad(v, mid+1, end);
}

void BST::save(){
    ofstream out;
    out.open("data.txt");
    save(root, out);
    out.close();
}

void BST::save(Node* cur, ofstream& out){
    if(cur == nullptr) return;

    save(cur->left, out);
    out << cur->getTitle() << "\n"
        << cur->getAuthor() << "\n"
        << cur->getPublish_year() << "\n"
        << cur->getAvaliable_copies() << "\n"
        << "--------\n";
    save(cur->right, out);
}

void BST::insert(Node* newNode){
    insert(newNode, root);
}

void BST::insert(Node* newNode, Node* cur){
    if(cur == nullptr){
        root = newNode;
        return;
    }
    if(newNode->getTitle() >= cur->getTitle()){
        if(cur->right == nullptr){
            cur->right = newNode;
            return;
        }
        insert(newNode, cur->right);
    }
    else{
        if(cur->left == nullptr){
            cur->left = newNode;
            return;
        }
        insert(newNode, cur->left);
    }
}

void BST::searchByAll(string title, int year, string author, vector<Node*>& result){
    searchByAll(title, year, author, root, result);
}

void BST::searchByAll(string title, int year, string author, Node* cur, vector<Node*>& result){
    if(cur == nullptr){
        return;
    }
    if(title == cur->getTitle()){
        while(cur != nullptr && title == cur->getTitle()){
            if(year = cur->getPublish_year() && author == cur->getAuthor()){
                result.push_back(cur);
            }
            cur = cur->right;
            return;
        }
    }
    else if(title > cur->getTitle()){
        searchByAll(title, year, author, cur->right, result);
    }
    else{
        searchByAll(title, year, author, cur->left, result);
    }
}

void BST::searchByTitle(string title, vector<Node*>& result){
    searchByTitle(title, root, result);
}

void BST::searchByTitle(string title, Node* cur, vector<Node*>& result){
    if(cur == nullptr){
        return;
    }
    if(title == cur->getTitle()){
        searchByTitle_(title, cur, result);
        return;
    }
    if(title > cur->getTitle()){
        searchByTitle(title, cur->right, result);
    }
    else{
        searchByTitle(title, cur->left, result);
    }
}

void BST::searchByTitle_(string title, Node* cur, vector<Node*>& result){
    if(cur == nullptr) return;
    if(title == cur->getTitle()){
        result.push_back(cur);
    }
    searchByTitle_(title, cur->left, result);
    searchByTitle_(title, cur->right, result);
}

void BST::searchByPublicYear(int year, vector<Node*>& result){
    searchByPublicYear(year, root, result);
}

void BST::searchByPublicYear(int year, Node* cur, vector<Node*>& result){
    if(cur->left != nullptr){
        searchByPublicYear(year, cur->left, result);
    }
    if(year == cur->getPublish_year()){
        result.push_back(cur);
    }
    if(cur->right != nullptr){
        searchByPublicYear(year, cur->right, result);
    }
}

void BST::searchByAuthor(string author, vector<Node*>& result){
    searchByAuthor(author, root, result);
}

void BST::searchByAuthor(string author, Node* cur, vector<Node*>& result){
        if(cur->left != nullptr){
        searchByAuthor(author, cur->left, result);
    }
    if(author == cur->getAuthor()){
        result.push_back(cur);
    }
    if(cur->right != nullptr){
        searchByAuthor(author, cur->right, result);
    }
}

void BST::listall(){
    listall(root);
}

void BST::listall(Node* cur){
    if(cur == nullptr){
        return;
    }
    listall(cur->left);
    cout << cur;
    cout << "-----------------------------------\n";
    listall(cur->right);
}

void BST::rmalloc(){
    rmalloc(root);
}

void BST::rmalloc(Node* cur){
    if(cur == nullptr){
        return;
    }
    if(cur->left != nullptr){
        rmalloc(cur->left);
    }
    if(cur->right != nullptr){
        rmalloc(cur->right);
    }
    delete cur;
}

bool BST::isIn(Node* node){
    vector<Node*> v;
    searchByAll(node->getTitle(), node->getPublish_year(), node->getAuthor(), root, v);
    return v.size() != 0;
}