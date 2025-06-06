#include "node.hpp"

std::string Node::getTitle(){
    return this->title;
}

std::string Node::getAuthor(){
    return this->author;
}

int Node::getPublish_year(){
    return this->publish_year;
}

int Node::getAvaliable_copies(){
    return this->avaliable_copies;
}

void Node::borrowOne(){
    this->avaliable_copies--;
}

void Node::returnOne(){
    this->avaliable_copies++;
}

std::ostream& operator << (std::ostream& out, Node* node){
    try{
        out << "Title: " << node->getTitle() << "\n"
        << "Author: " << node->getAuthor() << "\n"
        << "Public Year: " << node->getPublish_year() << "\n"
        << "avaliable copies: " << node->getAvaliable_copies() << "\n";
    }
    catch(std::exception& e){
        out << node->getAuthor().length();
    }
    return out;
}