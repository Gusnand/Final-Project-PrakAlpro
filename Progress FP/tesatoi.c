#include <stdio.h>
#include <string.h>

int main ()
{
    char a[] = "abcde";
    char b[] = "aBcde";
    int angka, jumlah;
    angka = atoi(a);
    jumlah = angka * 2;
    printf("string %s menjadi integer %d, hasil kali jumlahnya = %d\n", a, angka, jumlah);
    return 0;
}