#include "iostream"
#include "myLinkedList.h"

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
char yt;
int pilihanSorting;

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
    delete[] nilai;
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
            if (mhs[j].nilaiIpk > mhs[min].nilaiIpk)
            {
                min = j;
            }
        }
        if (mhs[i].nilaiIpk != mhs[min].nilaiIpk)
        {
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
            if (mhs[j].nilaiIpk < mhs[j+1].nilaiIpk)
            {
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
        mhsKey = mhs[i];
        j = i - 1;
        while (j >= 0 && mhs[j].nilaiIpk < mhsKey.nilaiIpk)
        {
            mhs[j + 1] = mhs[j];
            j = j - 1;
        }
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
    mhs = new Mahasiswa[n];
    atas = n;
    printf("Program Data Mahasiswa\n");
    for (int i = 0; i < n; i++){
        printf("Silahkan Masukkan Data Mahasiswa %d\n", i + 1);
        printf("Nama: ");
        std::cin.ignore();
        std::string namasem;
        std::getline(std::cin, namasem);
        (mhs + i)->name = namasem;
        printf("NIM: ");
        std::string nimsem;
        std::getline(std::cin, nimsem);
        (mhs + i)->mhsId = nimsem;
        printf("Silahkan Masukkan Nilai Mata Kuliah\n");
        printf("[jangkauan nilai adalah 0 - 100, nilai diluar jangkauan akan dijepit]\n");
        for (int j = 0; j < JUMLAH_MATKUL; j++){
            float *a = new float();
            std::cout << "Nilai Mata Kuliah " << makul[j] << ": ";
            std::cin >> *a;
            float b = clamp<float>(*a, 0, 100);
            nilai[i][j] = b;
            delete a;
        }
        (mhs + i)->nilaiIpk = average(nilai[i], JUMLAH_MATKUL);
    }
}