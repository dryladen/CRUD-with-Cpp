#ifndef _Item
#define _Item
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
    int lastIndex = 0;
    int lastId = 0;
    void addItem();
    void removeItem();
    void updateItem();
    void printItems();
    void readDatabase();
    void writeDatabase();
};
#endif
