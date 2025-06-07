#include "object/BST.hpp"
#include "controllers.hpp"
#include "utils.hpp"

using namespace std;

int main(int argc, char *argv[]){
    BST db;
    db.load();
    Entry(db);
}