#include <stdio.h>
#include <stdlib.h>

struct barang{
    char kodebarang[10];
    char nama[100];
    char kategori[20];
    long int harga;
    int jumlah;
}barang[100];

FILE *fptr, *fptr2;
int pilihan;
int currentItems = 0;

int ulg = 1;
void input(){
	int i=0;
    FILE *baca = fopen("dagang.txt", "r");
    if(baca != NULL){
        printf("File ada!");
        while(!feof(baca)){
            if(ulg == 1){
                fscanf(baca, "%s", &barang[i].kodebarang); ulg++;
            }
            if(ulg == 2){
                fscanf(baca, "%s", &barang[i].nama); ulg++;
            }
            if(ulg == 3){ 
                fscanf(baca, "%s", &barang[i].kategori); ulg++;
            }
            if(ulg == 4){ 
                fscanf(baca, "%ld", &barang[i].harga); ulg++;
            }
            if(ulg == 5){ 
                fscanf(baca, "%d", &barang[i].jumlah); ulg++;
            }
            if(ulg == 6){
            	ulg++;
			}
            if(ulg == 7){
                ulg = 1;
                i++;
                currentItems++;
            }
        }
    }
    else{
        printf("File kosong!");
    }
    fclose(baca);
}
void tambahdata()
{
	fptr = fopen("inventory.txt", "r");
    if(fptr == NULL){
        fptr2 = fopen ("inventory.txt", "w");
        fclose(fptr);
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
        
    }
    int j;
    for(j=0; j<currentItems; j++){
    	fprintf(fptr, "%s\n%s\n%s\n%ld\n%d\n-----------", barang[j].kodebarang, barang[j].nama, barang[j].kategori, barang[j].harga, barang[j].jumlah);
	}
    tanya: 
    printf("Apakah Anda ingin menambahkan data lagi ? [1/0]\n");
    scanf("%d", &pilihan);
    if(pilihan==1){
        goto masukbarang;
        system("CLS");
    }
    else fclose(fptr2);
}

void lihatdata()
{
	int i;
	for(i=0; i<currentItems; i++){
		printf("%s\t", barang[i].kodebarang);
		printf("%s\t", barang[i].nama);
		printf("%s\t", barang[i].kategori);
		printf("%ld\t", barang[i].harga);
		printf("%d\t", barang[i].jumlah);
	}
}

int main ()
{
	input();
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
