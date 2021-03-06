#include "..\include\MainHeader.h"
using namespace std;
int main()
{
    ItemManager itemManager;
    bool loop = true;
    int choice;
    itemManager.lastId = 0;
    itemManager.readDatabase();
    while (loop)
    {
        cout << "===========================" << endl;
        cout << "Program Manajemen Item" << endl;
        cout << "1. Tambah Item" << endl;
        cout << "2. Hapus Item" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Print Item" << endl;
        cout << "5. Search Item" << endl;
        cout << "6. Exit" << endl;
        cout << "===========================" << endl;
        choice = itemManager.inputHandling("Masukan pilihan : ");
        switch (choice)
        {
        case 1:
            itemManager.addItem();
            break;
        case 2:
            itemManager.removeItem();
            break;
        case 3:
            itemManager.updateItem();
            break;
        case 4:
            itemManager.printItems();
            break;
        case 5:
            itemManager.searchItems();
            break;
        case 6:
            loop = false;
            break;
        default:
            cout << "===========================" << endl;
            cout << "Pilihan tidak ada" << endl;
            break;
        }
    }
    itemManager.writeDatabase();
}
