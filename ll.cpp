#include "iostream"
#include "myLinkedList.h"

int main()
{
    MyLinkedList<int> coba;
    coba.Add(32);
    coba.Add(33);
    printf("Int LinkedList: \n");
    coba.PrintList();
    MyLinkedList<float> coba2;
    coba2.Add(3.14f);
    coba2.Add(6.62607015f);
    printf("Float LinkedList: \n");
    coba2.PrintList();
}