#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct barang {
    char kodebarang[10];
    char nama[100];
    char kategori[20];
    int harga;
    int jumlah;
}barang[100];

int pilihan;
int currentItems = -1;
int i = -1;
char buffer[255];

void lihatdata() {
		
    FILE *fptr = fopen("masukkinInteger.txt","r");
	currentItems = -1;

    if(fptr == NULL){
    	printf("File belum ada. Buat baru dulu.\n");
		system("PAUSE");
		system("CLS");
    } else if(fptr != NULL){
        
		currentItems++;
		i = -1;
		
        while(fgets(buffer, 80, fptr)) {
			
			i++;
			
			buffer[strlen(buffer) -1] = '\0';
			if(i == 0) {
				strcpy(barang[currentItems].kodebarang, buffer);
			}
			
			if(i == 1) {
				strcpy(barang[currentItems].nama, buffer);
			}
			
			if(i == 2) {
				strcpy(barang[currentItems].kategori, buffer); fflush(stdin);
			}
			
			if(i == 3) {
				strcpy(barang[currentItems].harga, buffer); fflush(stdin);
			}
			
			if(i == 4) {
				strcpy(barang[currentItems].jumlah, buffer); fflush(stdin);
			}
			
			if(i == 5) {
				i = -1;
				currentItems++;
			}
			
        }
		
		fclose(fptr);
	    system("cls");
		
		printf("KODE BARANG\tNAMA BARANG\tKATEGORI BARANG\tHARGA BARANG\tJUMLAH BARANG\n");
		
		for(i = 0; i < currentItems; i++) {
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", barang[i].kodebarang, barang[i].nama, barang[i].kategori, barang[i].harga, barang[i].jumlah);
		}
		printf("\n\nTekan Enter untuk Kembali ke Menu Awal.\n");
		system("PAUSE");
		system("CLS");
    }
}

void tambahdata() {

    FILE *fptr = fopen("masukkinInteger.txt","a");
	
	currentItems--;
	
    if(fptr != NULL) {
	
        currentItems++;
       
        printf("Masukkan Kode Barang : ");
        fflush(stdin);
        gets(barang[currentItems].kodebarang);
		fputs(barang[currentItems].kodebarang, fptr);
		fputs("\n", fptr);
		
        printf("Masukkan Nama Barang : ");
        fflush(stdin);
        gets(barang[currentItems].nama);
		fputs(barang[currentItems].nama, fptr);
		fputs("\n", fptr);

        printf("Masukkan Kategori Barang : ");
        fflush(stdin);
        gets(barang[currentItems].kategori);
		fputs(barang[currentItems].kategori, fptr);
		fputs("\n", fptr);

        printf("Masukkan Harga Barang : ");
        scanf("%d", barang[currentItems].harga); //ternyata gabisa masukkin angka ke operasi file.
		fputs(barang[currentItems].harga, fptr);
		fputs("\n", fptr);

        printf("Masukkan Jumlah Barang : ");     
        scanf("%d", barang[currentItems].jumlah);
		fputs(barang[currentItems].jumlah, fptr);
		fputs("\n", fptr);
		
		fputs("=======================", fptr);
		fputs("\n", fptr);
	}
    
    fclose(fptr);
	printf("Data Berhasil Ditambahkan !\n");
	system("PAUSE");
	system("CLS");
}

void transaksibarang(){
	
}

int main() {
	char pilih = '0';
	menu :
	printf("Final Project Praktikum Algoritma dan Pemrograman\n");
	printf("Data Inventaris dan Kasir\n");
	printf("=================================================\n");
	printf("1. Lihat Barang \n");
	printf("2. Tambah Barang \n");
	printf("3. Transaksi Barang\n");
	printf("4. Keluar");
	//printf("\nGudang Anda saat ini berisi :\n");
	//lihatdata();

	printf("\nMasukkan Pilihan Anda :  "); 
	scanf("%c",&pilih); 
	fflush(stdin);
	
	switch (pilih) {
		case '1': {
			system("cls");
			lihatdata(); 
			goto menu;
			break;
		}
		case '2': {
			system("cls");
			tambahdata(); 
			goto menu;
			break;
		}
		case '3' : {
			system("cls");
			//transaksidata();
			break;
		}
		case '4' : {
			return 0;
			break;
		}
		default :
			printf("Pilihan Tidak Ada. Ulangi Lagi.");
			system("PAUSE");
			system("CLS");
			goto menu;
	}
	return 0;
}

