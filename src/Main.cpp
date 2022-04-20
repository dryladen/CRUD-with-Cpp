#include "..\include\MainHeader.h"
using namespace std;
int main()
{
    ItemManager itemManager;
    cout << "Program Manajemen Item" << endl;
    cout << "1. Tambah Item" << endl;
    cout << "2. Hapus Item" << endl;
    cout << "3. Update Item" << endl;
    cout << "4. Print Item" << endl;
    cout << "5. Exit" << endl;
    int choice;
    cin >> choice;
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
        return 0;
    default:
        cout << "Pilihan tidak ada" << endl;
        break;
    }
}
