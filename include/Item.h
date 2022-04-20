#ifndef _Item
#define _Item
#include "MainHeader.h"
using namespace std;
struct Item
{
    int id;
    string name;
    int quantity;
};

class ItemManager
{
public:
    std::vector<Item> itemVector;
    int lastId;
    fstream file;
    void addItem();
    void removeItem();
    void updateItem();
    void printItems();
    void openDatabase();
    void readDatabase();
    void writeDatabase();
};
#endif
