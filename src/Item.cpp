#include "..\include\MainHeader.h"
using namespace std;
int ItemManager::menu(std::vector<string> menu)
{
    int choice;
    while (true)
    {
        for (int i = 0; i < menu.size(); i++)
        {
            cout << i + 1 << ". " << menu[i] << endl;
        }
        cout << "------------------------" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        if (choice > 0 && choice <= menu.size())
        {
            return choice;
        }
        else
        {
            cout << "------------------------" << endl;
            cout << "Pilihan tidak ada" << endl;
            cout << "------------------------" << endl;
        }
    }
}
void ItemManager::addItem()
{

    int choice;
    std::vector<string> listMenu;
    listMenu.push_back("Tambah Item");
    listMenu.push_back("Tambah jumlah Item");
    choice = menu(listMenu);
    switch (choice)
    {
    case 1:
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
        cout << "------------------------" << endl;
        cout << "Item berhasil ditambahkan" << endl;
        cout << "------------------------" << endl;
        break;
    }
    case 2:
    {
        int id, jumlah;
        cout << "Masukkan id item: ";
        cin >> id;
        for (int i = 0; i < this->itemVector.size(); i++)
        {
            if (this->itemVector[i].id == id)
            {
                cout << "Jumlah item: ";
                cin >> jumlah;
                this->itemVector[i].quantity += jumlah;
                cout << "------------------------" << endl;
                cout << "Jumlah Item berhasil ditambahkan" << endl;
                cout << "------------------------" << endl;
                break;
            }
        }
        break;
    }
    }
}

void ItemManager::removeItem()
{
    int choice, id;
    std::vector<string> listMenu;
    listMenu.push_back("Hapus Item");
    listMenu.push_back("Hapus jumlah Item");
    choice = menu(listMenu);
    cout << "------------------------" << endl;
    cout << "Masukkan id item: ";
    cin >> id;
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        if (this->itemVector[i].id == id)
        {
            if (choice == 1)
            {
                this->itemVector.erase(this->itemVector.begin() + i);
                cout << "------------------------" << endl;
                cout << "Item berhasil dihapus" << endl;
                cout << "------------------------" << endl;
                return;
            }
            else if (choice == 2)
            {
                int jumlah;
                cout << "Jumlah item: ";
                cin >> jumlah;
                this->itemVector[i].quantity -= jumlah;
                if (this->itemVector[i].quantity < 0)
                {
                    this->itemVector[i].quantity = 0;
                }
                cout << "------------------------" << endl;
                cout << "Item berhasil dikurangi" << endl;
                cout << "------------------------" << endl;
                return;
            }
        }
    }
    cout << "------------------------" << endl;
    cout << "Item tidak ditemukan" << endl;
    cout << "------------------------" << endl;
}
void ItemManager::updateItem()
{
    int id;
    cout << "------------------------" << endl;
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
            cout << "------------------------" << endl;
            cout << "Item berhasil diupdate" << endl;
            cout << "------------------------" << endl;
            return;
        }
    }
    cout << "------------------------" << endl;
    cout << "Item tidak ditemukan" << endl;
    cout << "------------------------" << endl;
}
void ItemManager::printItems()
{
    this->sortItems();
    for (int i = 0; i < this->itemVector.size(); i++)
    {
        cout << "Id    : " << this->itemVector[i].id << endl;
        cout << "Nama  : " << this->itemVector[i].name << endl;
        cout << "Jumlah: " << this->itemVector[i].quantity << endl;
        cout << "===============================" << endl;
    }
}
void ItemManager::sortItems()
{
    int choice, tipe;
    std::vector<string> listMenu, listTipe;
    listMenu.push_back("Urutkan berdasarkan id");
    listMenu.push_back("Urutkan berdasarkan nama");
    listMenu.push_back("Urutkan berdasarkan jumlah");
    choice = menu(listMenu);
    listTipe.push_back("Ascending");
    listTipe.push_back("Descending");
    tipe = menu(listTipe);
    cout << "choice: " << choice << endl;
    cout << "tipe: " << tipe << endl;
    shellSort(choice, tipe);
}
void ItemManager::shellSort(int jenis, int tipe)
{
    int n = itemVector.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            Item temp = itemVector[i];
            int j;
            if (jenis == 1)
            {
                for (j = i; j >= gap && ((tipe == 1) ? (itemVector[j - gap].id > temp.id) : (itemVector[j - gap].id < temp.id)); j -= gap)
                    itemVector[j] = itemVector[j - gap];
            }
            else if (jenis == 2)
            {
                for (j = i; j >= gap && ((tipe == 1) ? (itemVector[j - gap].name.compare(temp.name) > 0) : (itemVector[j - gap].name.compare(temp.name)) < 0); j -= gap)
                    itemVector[j] = itemVector[j - gap];
            }
            else if (jenis == 3)
            {
                for (j = i; j >= gap && ((tipe == 1) ? (itemVector[j - gap].quantity > temp.quantity) : (itemVector[j - gap].quantity < temp.quantity)); j -= gap)
                    itemVector[j] = itemVector[j - gap];
            }
            itemVector[j] = temp;
        }
    }
}
// Manajemen File Ekternal
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
