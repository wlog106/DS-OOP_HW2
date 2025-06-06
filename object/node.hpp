#pragma once
#include <string>
#include <iostream>

class Node{
private:
    std::string title;
    std::string author;
    int publish_year;
    int avaliable_copies;

public:
    Node(){
        left = nullptr;
        right = nullptr;
    }
    Node(std::string title, std::string author, int year, int copy){
        left = nullptr;
        right = nullptr;
        this->title = title;
        this->author = author;
        this->publish_year = year;
        this->avaliable_copies = copy;
    }

    std::string getTitle();
    std::string getAuthor();
    int getPublish_year();
    int getAvaliable_copies();
    void borrowOne();
    void returnOne();

    Node* left;
    Node* right;
};


std::ostream& operator << (std::ostream& out, Node* node);