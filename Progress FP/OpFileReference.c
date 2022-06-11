#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct barang {
    char kodebarang[10];
    char nama[100];
    char kategori[20];
    char harga[100];
    char jumlah[100];
}barang[100];

struct sc {
    char kodebarang[10];
    char nama[100];
    char kategori[20];
    int harga;
    int jumlah;
} shoppingCart[100];

int pilihan;
int currentItems = -1;
int i = -1;
char buffer[255]; 

void lihatdata() {
	
    FILE *fptr = fopen("inventory.txt","r");
	currentItems = -1;

    if(fptr == NULL){
    	printf("File belum ada. Buat baru dulu.\n");
		system("PAUSE");
		system("CLS");
    } else if(fptr != NULL){
        
		currentItems++;
		i = -1;
		
        while(fgets(buffer, 100, fptr)) { 
			
			i++;
			
			buffer[strlen(buffer) -1] = '\0'; 
											  
			if(i == 0) {
				strcpy(barang[currentItems].kodebarang, buffer);
																
			}	 
			if(i == 1) {
				strcpy(barang[currentItems].nama, buffer);
			}
			
			if(i == 2) {
				strcpy(barang[currentItems].kategori, buffer); 
			}
			
			if(i == 3) {
				strcpy(barang[currentItems].harga, buffer);
			}
			
			if(i == 4) {
				strcpy(barang[currentItems].jumlah, buffer);
			}
			
			if(i == 5) {
				i = -1;
				currentItems++;
			}
			
        }
		
		fclose(fptr);
		
		printf("KODE BARANG\tNAMA BARANG\tKATEGORI BARANG\tHARGA BARANG\tJUMLAH BARANG\n");
		
		for(i = 0; i < currentItems; i++) {
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", barang[i].kodebarang, barang[i].nama, barang[i].kategori, barang[i].harga, barang[i].jumlah);
		}
		
		system("PAUSE");
    }
}

void rewriteFile() {
	int i = 0;
	FILE *fptr = fopen("inventory.txt","a");

	for(i = 0; i <= currentItems; i++) {
		fputs(barang[i].kodebarang, fptr);
		fputs("\n", fptr);
		fputs(barang[i].nama, fptr);
		fputs("\n", fptr);
		fputs(barang[i].kategori, fptr);
		fputs("\n", fptr);
		fputs(barang[i].harga, fptr);
		fputs("\n", fptr);
		fputs(barang[i].jumlah, fptr);
		fputs("\n", fptr);
		fputs("=======================", fptr);
		fputs("\n", fptr);
	}
	
	fclose(fptr);
}

void tambahdata() {

	char a[100];
	char kodeBarang[10];
	int flag;
	
	currentItems--;

	printf("DATABASE BARANG\n");
	printf("---------------------------------\n");
	
	
	currentItems++;
	do {

		system("CLS");

		flag = 0;

		printf("Masukkan Kode Barang : ");
		gets(kodeBarang);

		for(int i = 0; i <= currentItems; i++) {
			if(strcmp(barang[i].kodebarang, kodeBarang) == 0) {
				flag = 1; 
				break;
			}
		}

		if(flag == 0) {
			strcpy(barang[currentItems].kodebarang, kodeBarang);
			
			printf("Masukkan Nama Barang : ");
			gets(barang[currentItems].nama);

			printf("Masukkan Kategori Barang : ");
			gets(barang[currentItems].kategori);

			printf("Masukkan Harga Barang : ");
			gets(barang[currentItems].harga);
			
			printf("Masukkan Jumlah Barang : ");   
			gets(barang[currentItems].jumlah);

			remove("inventory.txt");

			rewriteFile();

			printf("Data Berhasil Ditambahkan !\n");

		}else {
			printf("kode barang sudah ada di database\n");
			getch();
		}
	}while(flag == 1);
    
	
	getch();
	system("CLS");
}



void transaksibarang(){
	int total, bayar, jmlBeli, sisa;
	
	int totalShoppingCart = 0;

	int indexBarang = 0;
	int indexShoppingCart = 0;

	char pilih = 'y';
	char kodeBarang[10];
	int flag = 0;
	int flagger = 0;
	int foo;
	char a[100];
	int i, j;

	do {

		printf("masukkan kode barang: "); gets(kodeBarang);

		flagger = 0;

		for(i = 0; i <= currentItems; i++) {
			if(strcmp(kodeBarang, barang[i].kodebarang) == 0) {
				flag = 0;
				indexBarang = i;

				printf("barang ditemukan\n");
				printf("kode : %s\n", barang[i].kodebarang);
				printf("nama : %s\n", barang[i].nama);
				printf("ktgri: %s\n", barang[i].kategori);
				printf("harga: %s\n", barang[i].harga);
				printf("jmlh : %s\n", barang[i].jumlah);

				do {
					printf("input jumlah yang ingin dibeli: "); scanf("%d", &jmlBeli); fflush(stdin);
					if(jmlBeli > atoi(barang[i].jumlah)) {
						printf("barang yang ingin dibeli melebihi jumlah stok\n");
					}
				}while(jmlBeli > atoi(barang[i].jumlah) && atoi(barang[i].jumlah) > 0);
				
				
				foo = atoi(barang[i].jumlah) - jmlBeli;
				snprintf(a, sizeof(a), "%d", foo);
				
				strcpy(barang[i].jumlah, a);

				for(j = 0; j < totalShoppingCart; j++) {
					if(strcmp(kodeBarang, shoppingCart[j].kodebarang) == 0) {
						flag = 1;
						indexShoppingCart = j;
						shoppingCart[j].jumlah += jmlBeli;
						printf("keranjang belanja berhasil diperbarui\n");
						break;
					}
				}

				if(flag == 0) {
					strcpy(shoppingCart[totalShoppingCart].kodebarang, barang[indexBarang].kodebarang);
					strcpy(shoppingCart[totalShoppingCart].nama, barang[indexBarang].nama);
					strcpy(shoppingCart[totalShoppingCart].kategori, barang[indexBarang].kategori);
					shoppingCart[totalShoppingCart].harga = atoi(barang[indexBarang].harga);
					shoppingCart[totalShoppingCart].jumlah = jmlBeli;
					printf("barang berhasil ditambahkan ke keranjang belanja\n");

					totalShoppingCart++;
				}

				flagger = 1;

				break;

			}
		}

		if(flagger == 0) {
			printf("kode barang %s tidak ditemukan\n", kodeBarang);
		}

		printf("input data barang lagi? [y/t]: "); scanf("%c", &pilih); fflush(stdin);


	}while(pilih == 'y');

	total = 0;
	
	system("CLS");
	
	printf("=====================================================================================\n");
	printf("KODE\t\tNAMA\t\tHARGA\t\tQTY\t\tSUBTOTAL\n");
	printf("=====================================================================================\n");
	for(i = 0; i < totalShoppingCart; i++) {
		printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", shoppingCart[i].kodebarang, shoppingCart[i].nama, shoppingCart[i].harga, shoppingCart[i].jumlah, shoppingCart[i].harga * shoppingCart[i].jumlah);	  
		total += shoppingCart[i].harga * shoppingCart[i].jumlah;
		printf("=====================================================================================\n");
	}
	

	printf("total belanja anda\t\t\t\t\t\t%d\n", total);
	do {
		printf("uang anda : "); scanf("%d", &bayar); fflush(stdin);
		if(bayar < total) {
			printf("uang yang anda bayarkan kurang, coba lagi \n");
		}
	}while(bayar < total);
	
	printf("kembalian : %d\n", bayar - total);
	
	getch();
	
	remove("inventory.txt");
	
	rewriteFile();
	
}

int main() {
	
	char pilih = '9';
	
	while(pilih != '4') {
		
		system("CLS");
	
		printf("Final Project Praktikum Algoritma dan Pemrograman\n");
		printf("Data Inventaris dan Kasir\n");
		printf("=================================================\n");
		printf("1. Lihat Barang \n");
		printf("2. Tambah Barang \n");
		printf("3. Transaksi Barang\n");
		printf("4. Keluar");

		printf("\nMasukkan Pilihan Anda :  "); 
		scanf("%c",&pilih); 
		fflush(stdin);
		
		switch (pilih) {
			case '1': {
				system("CLS");
				lihatdata();
				break;
			}
			case '2': {
				system("CLS");
				tambahdata(); 
				break;
			}
			case '3' : {
				system("CLS");
				transaksibarang();
				break;
			}
			case '4' : {
				break;
			}
			default : {
				printf("Pilihan Tidak Ada. Ulangi Lagi.");
				system("PAUSE");
				system("CLS");
			}
				
		};

	}	 
	
	return 0;
}

