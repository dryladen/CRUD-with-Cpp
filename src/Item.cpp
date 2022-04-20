#include "..\include\MainHeader.h"
using namespace std;

ItemManager::addItem()
{
    Item item;
    item.id = this->lastId;
    fflush(stdin);
    getline(cin, item.name);
    cin >> item.quantity;
    this->itemVector.push_back(item);
}
ItemManager::removeItem()
{
    int id;
    cout << "Masukkan id item yang akan dihapus: ";
    cin >> id;
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        if (this->itemVector[i].id == id)
        {
            this->itemVector.erase(this->itemVector.begin() + i);
            cout << "Item berhasil dihapus" << endl;
            return;
        }
    }
}
ItemManager::updateItem()
{
    int id;
    cout << "Masukkan id item yang akan diupdate: ";
    cin >> id;
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        if (this->itemVector[i].id == id)
        {
            fflush(stdin);
            getline(cin, this->itemVector[i].name);
            cin >> this->itemVector[i].quantity;
            cout << "Item berhasil diupdate" << endl;
            return;
        }
    }
}
ItemManager::printItems()
{
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        cout << "Id: " << this->itemVector[i].id << endl;
        cout << "Nama: " << this->itemVector[i].name << endl;
        cout << "Jumlah: " << this->itemVector[i].quantity << endl;
        cout << "-----------------------------------------------------" << endl;
    }
}
ItemManager::readDatabase()
{
    ifstream file;
    file.open("item.csv");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string id, name, quantity;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, quantity, ',');
        Item item;
        item.id = stoi(id);
        item.name = name;
        item.quantity = stoi(quantity);
        this->itemVector.push_back(item);
        this->lastId = item.id;
    }
    file.close();
}
ItemManager::writeDatabase()
{
    ofstream file;
    file.open("item.csv");
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        file << this->itemVector[i].id << ",";
        file << this->itemVector[i].name << ",";
        file << this->itemVector[i].quantity << endl;
    }
    file.close();
}
