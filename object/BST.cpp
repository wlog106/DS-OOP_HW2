#include <iostream>
#include <vector>
#include "BST.hpp"
#include "node.hpp"

using namespace std;

BST::BST(){
    root = nullptr;
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
            cur->left == newNode;
            return;
        }
        insert(newNode, cur->left);
    }
}

void BST::searchByBoth(string title, int year, vector<Node*>& result){
    searchByBoth(title, year, root, result);
}

void BST::searchByBoth(string title, int year, Node* cur, vector<Node*>& result){
    if(cur == nullptr){
        return;
    }
    if(title == cur->getTitle()){
        while(title == cur->getTitle() && cur != nullptr){
            if(year = cur->getPublish_year()){
                result.push_back(cur);
            }
            cur = cur->right;
            return;
        }
    }
    else if(title > cur->getTitle()){
        searchByBoth(title, year, cur->right, result);
    }
    else{
        searchByBoth(title, year, cur->left, result);
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
        while(title == cur->getTitle() && cur != nullptr){
            result.push_back(cur);
            cur = cur->right;
        }
        return;
    }
    if(title > cur->getTitle()){
        searchByTitle(title, cur->right, result);
    }
    else{
        searchByTitle(title, cur->left, result);
    }
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
    if(cur->left != nullptr){
        listall(cur->left);
    }
    cout << cur;
    if(cur->right != nullptr){
        listall(cur->right);
    }
}
