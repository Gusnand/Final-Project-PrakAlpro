#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct barang{
    char kodebarang[10];
    char nama[100];
    char kategori[20];
    long int harga;
    int jumlah;
}barang[100];

FILE *fptr;
int pilihan;
char ch;

void tambahdata()
{
    
        fptr = fopen ("inventory.txt", "a");
        masukbarang:
        
        
        printf("Masukkan kode barang : ");
        fflush(stdin);
        gets(barang->kodebarang);
        
        printf("Masukkan nama barang : ");
        fflush(stdin);
        gets(barang->nama);

        printf("Masukkan kategori barang : ");
        fflush(stdin);
        gets(barang->kategori);

        printf("Masukkan harga barang : ");
    
        scanf("%ld", &barang->harga);

        printf("Masukkan jumlah barang : ");
        
        scanf("%d", &barang->jumlah);
        
        fprintf(fptr, "Kode Barang\t: %s\nNama Barang\t: %s\nKategori Barang\t: %s\nHarga Barang\t: %ld\nJumlah Barang\t: %d\n-----------\n", barang->kodebarang, barang->nama, barang->kategori, barang->harga, barang->jumlah);
        printf("\nData telah ditambahkan\n");
        
    
    
    fclose(fptr);
}

void lihatdata()
{
    system("CLS");
    if((fptr = fopen("inventory.txt", "r")) == NULL){
    printf("\nBelum ada file, silakan buat file terlebih dahulu\n");
    fclose(fptr);


    } 
    else if((fptr = fopen("inventory.txt", "r")) != NULL){
        
        while((ch = fgetc(fptr)) != EOF){
      printf("%c", ch);
        }
    }
    fclose(fptr);
    
    system("PAUSE");
    system("CLS");
}

int main ()
{
    
    menu:
    system("cls");
    printf("Final Project Praktikum Algoritma Pemrograman\nProgram Inventaris dan Jual Beli\n===========================\n");
    printf("Menu : \n");
    printf("1. Tambah Barang\n");
    printf("2. Lihat Barang\n");
    printf("3. Keluar \n");
    printf("Pilihan : ");
    fflush(stdin);
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        system("CLS");
        tambahdata();
        system("PAUSE");
        goto menu;
    case 2:
        system("CLS");
        lihatdata();
        goto menu;
    case 3:
        fclose(fptr);
        exit(1);
    default:
        printf("Pilihan salah, silakan coba lagi\n");
        system("PAUSE");
        goto menu;
    }
    
    return 0;
}