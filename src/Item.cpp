#include "..\include\MainHeader.h"
using namespace std;

void ItemManager::addItem()
{
    Item item;
    item.id = this->lastId;
    cout << "Nama item   : ";
    fflush(stdin);
    getline(cin, item.name);
    cout << "Jumlah item : ";
    cin >> item.quantity;
    this->itemVector.push_back(item);
    this->lastId++;
    cout << "Item berhasil ditambahkan" << endl;
}
void ItemManager::removeItem()
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
            lastId--;
        }
    }
    cout << "Item tidak ditemukan" << endl;
}
void ItemManager::updateItem()
{
    int id;
    cout << "Masukkan id item yang akan diupdate: ";
    cin >> id;
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        if (this->itemVector[i].id == id)
        {
            cout << "Nama item   : ";
            fflush(stdin);
            getline(cin, this->itemVector[i].name);
            cout << "Jumlah item : ";
            cin >> this->itemVector[i].quantity;
            cout << "Item berhasil diupdate" << endl;
            return;
        }
    }
}
void ItemManager::printItems()
{
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        cout << "Id    : " << this->itemVector[i].id << endl;
        cout << "Nama  : " << this->itemVector[i].name << endl;
        cout << "Jumlah: " << this->itemVector[i].quantity << endl;
        cout << "===============================" << endl;
    }
}
void ItemManager::openDatabase()
{
    file.open("databases\\item.csv", std::ios::out | std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        return;
    }
    file.close();
    // jika file tidak ada maka akan dibuatkan file baru
    file.open("databases\\item.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
}
void ItemManager::readDatabase()
{
    openDatabase();
    string id, name, quantity;
    while (!file.eof())
    {
        Item item;
        // mengambil data dari file csv
        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, quantity, '\n');
        // stringstream untuk convert string ke int
        stringstream stringId(id);
        stringstream stringQuantity(quantity);
        stringId >> item.id;
        stringQuantity >> item.quantity;
        item.name = name;
        this->lastId = item.id;
        this->lastId++;
        // mengecek apakah data di akhir file csv
        if (file.eof())
        {
            break;
        }
        this->itemVector.push_back(item);
    }
    file.close();
}
void ItemManager::writeDatabase()
{
    file.open("databases\\item.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        // menulis data ke csv
        file << this->itemVector[i].id << "," << this->itemVector[i].name << "," << this->itemVector[i].quantity;
        // untuk enter di file csv
        file << "\n";
    }
    file.close();
}
