#include <stdio.h>

struct barang{
    char kodebarang[10];
    char nama[100];
    char kategori[20];
    long int harga;
    int jumlah;
}barang[100];

FILE *fptr;
int pilihan;
int currentItems = 0;

void tambahdata()
{
    if(fptr = fopen("inventory.txt", "r") == NULL){
        fptr = fopen ("inventory.txt", "a");
        masukbarang:
        currentItems++;
        
        printf("Masukkan kode barang : ");
        fflush(stdin);
        gets(barang[currentItems].kodebarang);
        
        printf("Masukkan nama barang : ");
        fflush(stdin);
        gets(barang[currentItems].nama);

        printf("Masukkan kategori barang : ");
        fflush(stdin);
        gets(barang[currentItems].kategori);

        printf("Masukkan harga barang : ");
    
        scanf("%ld", &barang[currentItems].harga);

        printf("Masukkan jumlah barang : ");
        
        scanf("%d", &barang[currentItems].jumlah);
        
        fprintf(fptr, "%s\n%s\n%s\n%ld\n%d\n-----------", barang[currentItems].kodebarang, barang[currentItems].nama, barang[currentItems].kategori, barang[currentItems].harga, barang[currentItems].jumlah);
    }
    tanya: 
    printf("Apakah Anda ingin menambahkan data lagi ? [1/0]\n");
    scanf("%d", &pilihan);
    if(pilihan==1){
        goto masukbarang;
        system("CLS");
    }
}

void lihatdata()
{
    if((fptr = fopen("inventory.txt", "r")) == NULL){
    printf("File belum ada. Buat baru dulu.\n");
    fclose(fptr);

    } else if((fptr = fopen("inventory.txt", "r")) != NULL){
        printf("KODE BARANG\tNAMA BARANG\tKATEGORI BARANG\tHARGA BARANG\tJUMLAH BARANG\n");
        while (fgets(barang, sizeof(struct barang), fptr)){
            printf("%s\t%s\t%s\t%ld\t%d\n", barang->kodebarang, barang->nama, barang->kategori, barang->harga, barang->jumlah);
        }
    }
    
    system("PAUSE");
    system("CLS");
}

int main ()
{
    menu:
    printf("Final Project Praktikum Algoritma Pemrograman\nProgram Inventaris dan Jual Beli\n===========================\n");
    printf("Menu : \n");
    printf("1. Tambah Barang\n");
    printf("2. Lihat Barang\n");
    printf("3. Keluar \n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        system("cls");
        tambahdata();
        goto menu;
    case 2:
        system("CLS");
        lihatdata();
        goto menu;
    case 3:
        fclose(fptr);
        return 0;
    default:
        printf("Pilihan Tidak Ada, Ulangi Lagi.\n");
        system("PAUSE");
        goto menu;
    }
    
    return 0;
}