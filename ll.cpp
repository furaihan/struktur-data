#include "iostream"
#include "myLinkedList.h"
#include "windows.h"
int main()
{    
    int pilihanMenu;
    int data; 
    MyLinkedList<int> ll;
    Sleep(3000);
    do 
    {
        std::cout << ">>> PILIHAN MENU SINGLY LINKED LIST <<<" << std::endl << std::endl;
        std::cout << "1. Menambahkan Node" << std::endl;
        std::cout << "2. Menghapus Node dari Depan" << std::endl;
        std::cout << "3. Menghapus Node dari Belakang" << std::endl;
        std::cout << "4. Mengosongkan Node" << std::endl;
        std::cout << "5. Menampilkan Node" << std::endl;
        std::cout << "6. Tambahkan Node Ditengah" << std::endl;
        std::cout << "99. Selesai" << std::endl << std::endl;
        
        std::cout << "Masukkan pilihan Anda : "; std::cin >> pilihanMenu;
        std::cout << std::endl;
        
        switch (pilihanMenu)
        {
            case 1: // menambah node
                std::cout << "Masukkan data : "; std::cin >> data;
                ll.AddLast(data);
                break;
                
            case 2: // menghapus node dari depan
                if (ll.Empty())
                {
                    std::cout << "List masih kosong !!!" << std::endl << std::endl;
                }
                else
                {
                    ll.RemoveFirst();
                }
                break;
                
            case 3: // menghapus node dari belakang
                if (ll.Empty())
                {
                    std::cout << "List masih kosong !!!" << std::endl << std::endl;
                }
                else
                {
                    ll.RemoveLast();
                }
                break;
                
            case 4: // mengosongkan node
                if (ll.Empty())
                {
                    std::cout << "List masih kosong !!!" << std::endl << std::endl;
                }
                else
                {
                    ll.Clear();
                }
                break;
                
            case 5: // menampilkan node
                if (ll.Empty())
                {
                    std::cout << "List masih kosong !!!" << std::endl << std::endl;
                }
                else
                {
                    ll.PrintList();
                }
                break;
                
            case 6:
                 break;
            
            default:
                std::cout << "Menu yang Anda pilih tidak terdaftar" << std::endl << std::endl;
                break;
        }
        
    } while (pilihanMenu != 6);
        
    std::cout << std::endl;    
                           
    system("pause");
    return 0;
}
