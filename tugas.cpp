#include "iostream"
const int JUMLAH_MATKUL = 8;
int n;
float (*nilai)[JUMLAH_MATKUL];
std::string *nama;
std::string *nim;
float *ipk;
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
template<typename T>
void tukar(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
void DisplayRank()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << i + 1 << ". " << nama[i];
        std::cout <<" (" << nim[i] << ")";
        std::cout <<  " ==> IPK: " << ipk[i];
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
    printf("Insertion Sorting: \n");
    for (i = 1; i < n; i++)
    {
        key = ipk[i];
        nimkey = nim[i];
        namakey = nama[i];
        j = i - 1;
        while (j >= 0 && ipk[j] < key)
        {
            ipk[j + 1] = ipk[j];
            nama[j + 1] = nama[j];
            nim[j + 1] = nim[j];
            j = j - 1;
        }
        ipk[j + 1] = key;
        nim[j + 1] = nimkey;
        nama[j + 1] = namakey;
    }
    DisplayRank();
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
    printf("Program Data Mahasiswa\n");
    for (int i = 0; i < n; i++){
        printf("Silahkan Masukkan Data Mahasiswa %d\n", i + 1);
        printf("Nama: ");
        std::cin.ignore();
        std::getline(std::cin, nama[i]);
        printf("NIM: ");
        std::getline(std::cin, nim[i]);
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
        ipk[i] = average(nilai[i], JUMLAH_MATKUL);
    }
}
char yt;
int pilihanSorting;
int main(){
    inputData();
    system("cls");
    for (int i = 0; i < n; i++){
        printf("=== MAHASISWA %d ===\n", i + 1);
        std::cout << "Nama: " << nama[i] << std::endl;
        std::cout << "Nim: " << nim[i] << std::endl;
        std::cout << "IPK: " << ipk[i] << std::endl;
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
    delete[] nilai;
    delete[] nama;
    delete[] nim;
    delete[] ipk;
}