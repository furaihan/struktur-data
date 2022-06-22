#include "iostream"
#include "myLinkedList.h"
using namespace std;

int main()
{    
    int pilihanMenu;
    int data; 
    MyLinkedList<int> ll;
    do 
    {
        cout << ">>> PILIHAN MENU SINGLY LINKED LIST <<<" << endl << endl;
        cout << "1. Menambahkan Node" << endl;
        cout << "2. Menghapus Node dari Depan" << endl;
        cout << "3. Menghapus Node dari Belakang" << endl;
        cout << "4. Mengosongkan Node" << endl;
        cout << "5. Menampilkan Node" << endl;
        cout << "6. Selesai" << endl << endl;
        
        cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
        cout << endl;
        
        switch (pilihanMenu)
        {
            case 1: // menambah node
                cout << "Masukkan data : "; cin >> data;
                ll.AddLast(data);
                break;
                
            case 2: // menghapus node dari depan
                if (ll.Empty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    ll.RemoveFirst();
                }
                break;
                
            case 3: // menghapus node dari belakang
                if (ll.Empty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    ll.RemoveLast();
                }
                break;
                
            case 4: // mengosongkan node
                if (ll.Empty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    ll.Clear();
                }
                break;
                
            case 5: // menampilkan node
                if (ll.Empty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    ll.PrintList();
                }
                break;
                
            case 6:
                 break;
            
            default:
                cout << "Menu yang Anda pilih tidak terdaftar" << endl << endl;
                break;
        }
        
    } while (pilihanMenu != 6);
        
    cout << endl;    
                           
    system("pause");
    return 0;
}
