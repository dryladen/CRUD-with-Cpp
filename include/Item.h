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
    void sortItems();
    void shellSort(int jenis, int tipe);
    void searchItems();
    int binarySearch(std::vector<Item> menu, int l, int r, int x);
    void openDatabase();
    void readDatabase();
    void writeDatabase();
    int menu(std::vector<string> menu);
    int inputHandling(string input);
};
#endif
