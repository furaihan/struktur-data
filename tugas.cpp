#include "iostream"
#include "conio.h"

const int JUMLAH_MATKUL = 2;
struct Mahasiswa
{
    std::string name;
    std::string mhsId;
    float nilaiIpk;
};

Mahasiswa *mhs;
int n, atas;
float (*nilai)[JUMLAH_MATKUL];
std::string *nama;
std::string *nim;
float *ipk;
char yt;
int pilihanSorting;

#pragma region linked-list
struct Node
{
    Mahasiswa data;
    Node *next;
};
Node *headNode = NULL;
Node *currentNode = NULL;
void insertDataToList(Mahasiswa data);
void insertListMiddle(Mahasiswa data, int elementAt);
bool isListEmpty();
void deleteListFront();
void deleteListEnd();
void deleteListIndex();
void clearList();
void printAllNode();
int listSize();
#pragma endregion

#pragma region methodDeclaration
float average(float *arr, unsigned int size);
template<typename T>
T clamp(T val, T min, T max);
template<typename T>
void tukar(T *a, T *b);
std::string MakeLowercase(std::string str);
void DisplayRank();
void selectionSort();
void bubbleSort();
void insertionSort();
void sequentiualSearch(std::string key);
void inputData();
void stackMenu();
#pragma endregion

int main(){
    inputData();
    system("cls");
    for (int i = 0; i < n; i++){
        printf("=== MAHASISWA %d ===\n", i + 1);
        std::cout << "Nama: " << (mhs + i)->name << std::endl;
        std::cout << "Nim: " << (mhs + i)->mhsId << std::endl;
        std::cout << "IPK: " << (mhs + i)->nilaiIpk << std::endl;
    }
    printf("Apakah anda ingin melihat rank mahasiswa? [Y/N]: ");
    std::cin >> yt;
    if (yt == 'y' || yt == 'Y')
    {
        SORT:
        printf("Silahkan pilih metode sorting:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("Jawab: ");
        std::cin >> pilihanSorting;
        system("cls");
        if (pilihanSorting == 1) bubbleSort();
        else if (pilihanSorting == 2) selectionSort();
        else if (pilihanSorting == 3) insertionSort();       
        else
            printf("Pilihan tidak valid\n");
        printf("\n");
        printf("Apakah anda ingin mengganti metode sorting?\n");
        printf("Jawab: ");
        std::cin >> yt;
        if (yt == 'y' || yt == 'Y')
        {
            goto SORT;
        }
    }
    printf("Apakah anda ingin mencari Mahasiswa? [Y/N]: ");
    std::cin >> yt;
    if (yt == 'y' || yt == 'Y')
    {
        printf("Silahkan masukkan nama mahasiswa yang ingin dicari: ");
        std::string kataPencarian = "";
        std::cin.ignore();
        std::getline(std::cin, kataPencarian);
        sequentiualSearch(kataPencarian);
    }
    printf("Apakah ingin membuka menu stack? [Y/N]");
    std::cin >> yt;
    if (yt == 'y' || yt == 'Y')
    {
        stackMenu();
    }
    delete[] nilai;
    delete[] nama;
    delete[] nim;
    delete[] ipk;
    delete[] mhs;
}

float average(float *arr, unsigned int size){
    float total = 0;
    for (int i = 0; i < size; i++)  total += arr[i];
    return (total / (size * 100)) * 4;
}
template<typename T>
T clamp(T val, T min, T max){
    if (val > max) return max;
    else if (val < min) return min;
    return val;
}
//swap memory refrence value from a to b and vice versa
template<typename T>
void tukar(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
std::string MakeLowercase(std::string str)
{
    std::string result = str;
    for (int i = 0; i < str.size(); i++)
    {
        if (result[i] > 64 && result[i] < 91)
            result[i] = result[i] + 32;
    }
    return result;
}

void DisplayRank()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << i + 1 << ". " << (mhs + i)->name;
        std::cout <<" (" << (mhs + i)->mhsId << ")";
        std::cout <<  " ==> IPK: " << (mhs + i)->nilaiIpk;
        std::cout << std::endl;
    }
}
//selection sort
void selectionSort()
{
    printf("Selection Sorting: \n");
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (ipk[j] > ipk[min])
            {
                min = j;
            }
        }
        if (ipk[i] != ipk[min])
        {
            tukar(&nama[i], &nama[min]);
            tukar(&nim[i], &nim[min]);
            tukar(&ipk[i], &ipk[min]);
            tukar(&mhs[i], &mhs[min]);
        }
    } 
    DisplayRank();
}
void bubbleSort()
{
    int i, j;
    printf("Bubble Sorting: \n");
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (ipk[j] < ipk[j+1])
            {
                tukar(&ipk[j], &ipk[j+1]);
                tukar(&nama[j], &nama[j+1]);
                tukar(&nim[j], &nim[j+1]);
                tukar(&mhs[i], &mhs[j+1]);
            }
        }
    }
    DisplayRank();
}
void insertionSort()
{
    int i, j;
    float key;
    std::string nimkey, namakey;
    Mahasiswa mhsKey;
    printf("Insertion Sorting: \n");
    for (i = 1; i < n; i++)
    {
        key = ipk[i];
        nimkey = nim[i];
        namakey = nama[i];
        mhsKey = mhs[i];
        j = i - 1;
        while (j >= 0 && ipk[j] < key)
        {
            ipk[j + 1] = ipk[j];
            nama[j + 1] = nama[j];
            nim[j + 1] = nim[j];
            mhs[j + 1] = mhs[j];
            j = j - 1;
        }
        ipk[j + 1] = key;
        nim[j + 1] = nimkey;
        nama[j + 1] = namakey;
        mhs[j + 1] = mhsKey;
    }
    DisplayRank();
}
void sequentiualSearch(std::string key)
{
    int posisi = - 1;
    bool ketemu = false;
    for (int i = 0; i < n; i++)
    {
        if (MakeLowercase((mhs + i)->name) == MakeLowercase(key))
        {
            posisi = i;
            ketemu = true;
            break;
        }
    }
    if (ketemu)
    {
        printf("Mahasiswa dengan nama %s menempati rangking %d", (mhs + posisi)->name, posisi + 1);
    }
    else
    {
        printf("Maaf, mahasiswa dengan nama %s tidak ditemukan", key);
    }
}
std::string makul[8] = {
        "Struktur Data", "Komunikasi Data", "Pemrograman", 
        "Sistem Operasi", "Hardware/Software", "Komputer Grafis", "Bahasa Inggris II",
        "Lingkungan Bisnis",
};
void inputData(){
    printf("Masukkan jumlah mahasiswa: ");
    std::cin >> n;
    nilai = new float[n][JUMLAH_MATKUL];
    nama = new std::string[n];
    nim = new std::string [n];
    ipk = new float(n);
    mhs = new Mahasiswa[n];
    atas = n;
    printf("Program Data Mahasiswa\n");
    for (int i = 0; i < n; i++){
        printf("Silahkan Masukkan Data Mahasiswa %d\n", i + 1);
        printf("Nama: ");
        std::cin.ignore();
        std::string namasem;
        std::getline(std::cin, namasem);
        nama[i] = namasem;
        (mhs + i)->name = namasem;
        printf("NIM: ");
        std::string nimsem;
        std::getline(std::cin, nimsem);
        nim[i] = nimsem;
        (mhs + i)->mhsId = nimsem;
        printf("Silahkan Masukkan Nilai Mata Kuliah\n");
        printf("[jangkauan nilai adalah 0 - 100, nilai diluar jangkauan akan dijepit]\n");
        for (int j = 0; j < JUMLAH_MATKUL; j++){
            float *a = new float();
            std::cout << "Nilai Mata Kuliah " << makul[j] << ": ";
            std::cin >> *a;
            float b = clamp<float>(*a, 0, 100);
            nilai[i][j] = b;
            (mhs + i)->nilaiIpk = b;
            delete a;
        }
        ipk[i] = average(nilai[i], JUMLAH_MATKUL);
    }
}
bool done = false;
void stackMenu()
{
    int sp = 0;
    while (true)
    {
        switch (sp)
        {
            case 0:
                system("cls");
                printf("Menu Stack\n1.Tampil\n2.Hapus\n3.Clear\n99.Keluar");
                printf("\nInput: ");
                std::cin >> sp;
                break;
            case 1:
                if (atas == -1)
                {
                    printf("Data Kosong!!!!!!\n");
                    system("pause");
                    sp = 0;
                    break;
                }
                printf("%d atas\n", atas);
                for (int i = 0; i < atas; i++)
                {
                    std::cout << (mhs + i)->name << std::endl;
                }
                system("pause");
                sp = 0;
                break;
            case 2:
                if (atas != -1) 
                {
                    atas--;
                    std::cout << (mhs + atas)->name << " dihapus\n";
                }
                system("pause");
                sp = 0;
                break;
            case 3:
                if (atas != -1) 
                {
                    atas = -1;
                    printf("Tumpukan dibersihkan\n");
                }
                system("pause");
                sp = 0;
                break;
            case 99:
                done = true;
                break;
        }
        if (done) break;
    }
}
#pragma region linkedListEncapsulation
bool isListEmpty()
{
    return headNode = NULL;
}
void insertDataToList(Mahasiswa data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (isListEmpty())
    {
        headNode = newNode;
    }
    else 
    {
        currentNode->next = newNode;
    }
    currentNode = newNode;
    currentNode.next = NULL;
    printf("Data berhasil ditambahkan");
}
void deleteListFront()
{
    if (!isListEmpty())
    {
        
    }
}
#pragma endregion