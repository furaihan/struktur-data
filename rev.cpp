#include "iostream"

struct Mahasiswa
{
    float nilai;
    std::string nama;
    std::string nim;
};
void reverse(std::string str)
{
    int len = str.length();
     for (int i = len - 1; i >= 0; i--)
        std::cout << str[i];
}
float average(Mahasiswa arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i].nilai;
    }
    return (sum / (float)size);
}
int numOfGraduate(Mahasiswa *arr, int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if ((arr + i)->nilai > 60)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    printf("Silahkan Masukkan Sembarang Kata:\n");
    printf("Input: ");
    std::string kata;
    std::getline(std::cin, kata);
    printf("\n");
    printf("Output: ");
    reverse(kata);
    Mahasiswa mhs1;
    mhs1.nama = "A";
    mhs1.nim = "1";
    mhs1.nilai = 95;
    Mahasiswa mhs2;
    mhs2.nama = "B";
    mhs2.nim = "2";
    mhs2.nilai = 55;
    Mahasiswa mhsarr[2] = {mhs1, mhs2};
    printf("\n%f", average(mhsarr, 2));
    printf("\n%d", numOfGraduate(mhsarr, 2));
}