#include "iostream"
float average(int *arr, unsigned int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)  total += arr[i];
    return (float)total/(float)size;
}
char getScore(int* nilai)
{
    if (*nilai >= 90) return 'A';
    else if (*nilai >= 80) return 'B';
    else if (*nilai >= 70) return 'C';
    else if (*nilai >= 60) return 'D';
    else if (*nilai >= 50) return 'E';
    else return 'F';
}

int main()
{
    std::string nama, nim;
    std::string makul[7] = 
    {
        "Struktur Data", "Komunikasi Data", "Pemrograman", 
        "Sistem Operasi", "Hardware/Software", "Komputer Grafis", "Bahasa Inggris"
    };
    int *nilai;
    printf("Program Data Mahasiswa\n");
    printf("Silahkan Masukkan Data Anda\n");
    printf("Nama: ");
    std::getline(std::cin, nama);
    printf("NIM: ");
    std::getline(std::cin, nim);
    printf("Silahkan Masukkan Nilai Mata Kuliah\n");
    for (int i = 0; i < 7; i++)
    {
        std::cout << "Nilai Mata Kuliah " << makul[i] << ": ";
        std::cin >> nilai[i];
    }
    system("cls");
    std::cout << "Nama: " << nama << std::endl;
    std::cout << "NIM: " << nim << std::endl;
    printf("\n");
    std::cout << "===== Nilai Nilai =====" <<std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout << makul[i] << ": " << nilai[i];
        printf(" (%c)", getScore(&(nilai[i])));
        if (getScore(&(nilai[i])) == 'F') printf(" Tidak Lulus");
        std::cout << std::endl;
    }
    float ipk = average(nilai, 7);
    std::cout << "IPK: " << ipk << std::endl;
}