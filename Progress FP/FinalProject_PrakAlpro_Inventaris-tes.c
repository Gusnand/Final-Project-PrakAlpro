#include <stdio.h>
#include <stdlib.h> //itoa atoi
#include <string.h> //strcmp, strlen

FILE *fptr;

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
char buffer[255]; // var untuk menyimpan data pada txt nanti

void lihatdata() {
		
    fptr = fopen("inventory.txt","r");
	currentItems = -1;

    if(fptr == NULL){
    	printf("File belum ada. Buat baru dulu.\n");
		system("PAUSE");
		system("CLS");
    } else if(fptr != NULL){
        
		currentItems++;
		i = -1;
		
        while(fgets(buffer, 80, fptr)) { //fgets itu fungsi untuk membaca satu baris, 80 artinya panjang char yang akan dibaca
										 //isi file pada fptr akan dibaca dan disimpan di var buffer
			
			i++; // indeks akan dimulai dari 0
			
			buffer[strlen(buffer) -1] = '\0'; //line ini akan menghapus char <ENTER> atau \n ketika akan ditampilkan di program.
											  //mengapa ada \n ? karena di file txt susunan stringnya per baris dipisahkan oleh \n
			if(i == 0) {
				strcpy(barang[currentItems].kodebarang, buffer); //fungsi untuk menyalin data txt di var buffer,
																 //untuk kemudian disalin ke struct barang pada field/attribute kodebarang.
			}
			
			if(i == 1) {
				strcpy(barang[currentItems].nama, buffer);
			}
			
			if(i == 2) {
				strcpy(barang[currentItems].kategori, buffer); 
			}
			
			if(i == 3) {
				//strcpy(barang[currentItems].harga, buffer); pake ini jika atribut harga make char
				barang[currentItems].harga = atoi(buffer); // pake ini jika atribut harga make int/selain char
			}
			
			if(i == 4) {
				//strcpy(barang[currentItems].jumlah, buffer); 
				barang[currentItems].jumlah = atoi(buffer);
			}
			
			if(i == 5) {
				i = -1;
				currentItems++;
			}
		
        }
		
		fclose(fptr);
	    system("CLS");
		
		printf("KODE BARANG\tNAMA BARANG\tKATEGORI BARANG\tHARGA BARANG\tJUMLAH BARANG\n");
		
		for(i = 0; i < currentItems; i++) {
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", barang[i].kodebarang, barang[i].nama, barang[i].kategori, barang[i].harga, barang[i].jumlah);
		}
    }
}

void tambahdata() {

    fptr = fopen("inventory.txt","a");
	
	currentItems--;
	
    if(fptr != NULL) {
	
        currentItems++;
       
        printf("Masukkan Kode Barang : ");
        fflush(stdin);
        gets(barang[currentItems].kodebarang);
		fputs(barang[currentItems].kodebarang, fptr);
		fputs("\n", fptr);
		
        printf("Masukkan Nama Barang : ");
        //fflush(stdin);
        gets(barang[currentItems].nama);
		fputs(barang[currentItems].nama, fptr);
		fputs("\n", fptr);

        printf("Masukkan Kategori Barang : ");
        //fflush(stdin);
        gets(barang[currentItems].kategori);
		fputs(barang[currentItems].kategori, fptr);
		fputs("\n", fptr);

		printf("Masukkan Harga Barang : ");
        //fflush(stdin);
        //gets(barang[currentItems].harga);
		scanf("%d", &barang[currentItems].harga);
		fputs(itoa(barang[currentItems].harga, buffer, 10), fptr);
		fputs("\n", fptr);
		
        printf("Masukkan Jumlah Barang : ");     
        //fflush(stdin);
        //gets(barang[currentItems].jumlah);
		scanf("%d", &barang[currentItems].jumlah);
		fputs(itoa(barang[currentItems].jumlah, buffer, 10), fptr);
		fputs("\n", fptr);
		
		fputs("=======================", fptr);
		fputs("\n", fptr);
	}
    
    fclose(fptr);
	printf("Data Berhasil Ditambahkan !\n");
	system("PAUSE");
	system("CLS");
}

void updateFile(){
	remove ("inventory.txt");
	fptr = fopen("inventory.txt", "w");
	for(int i = 0; i < currentItems; i++){
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

int transaksibarang(){
	int bayar, jmlBeli, sisa;
	char sisaBuffer[100];
	ulang:
	lihatdata();
	printf("\nCurrent Items : %d\n", currentItems);
	fptr = fopen ("inventory.txt", "r");
	if(fptr == NULL){
		printf("Belum ada barang di inventory. Tidak bisa melakukan transaksi.\n");
		system("PAUSE");
		system("CLS");
	}else if(fptr != NULL){
		// untuk bisa melakukan transaksi barang, 
		// maka string yang ada pada file harus dikonversi ke angka.
		printf("\nMasukkan Kode dari Barang yang mau diambil : ");
		char kodebarangUser[10];
		gets(kodebarangUser);
		int bandingkan;
		for(int i = 0; i < currentItems; i++){
			bandingkan = strcmp(kodebarangUser, barang[i].kodebarang);
			if(bandingkan == 0){
				//int konversiHarga;
				//int konversiJumlah;
				//konversiHarga = atoi(barang[i].harga);
				//konversiJumlah = atoi(barang[i].jumlah);
				printf("Barang :\n");
				printf("%s (%s)\n", barang[i].nama, barang[i].kategori);
				printf("Harga : %d\n", barang[i].harga);
				printf("========================\n");
				printf("       PEMBAYARAN       \n");
				printf("========================\n");
				ulangbeli:
				printf("Beli Berapa : ");
				scanf("%d", &jmlBeli);
				sisa = barang[i].jumlah - jmlBeli;
				if(barang[i].jumlah < jmlBeli){
					printf("Barang yang mau dibeli melebihi stok yang tersedia. Coba lagi. \n");
					system("PAUSE");
					goto ulangbeli;
				}
				itoa(sisa, sisaBuffer, 10);
				//strcpy(barang[i].jumlah, sisaBuffer);
				itoa(barang[i].jumlah, sisaBuffer, 10);
				printf("Total Harga Barang : %d\n", barang[i].harga*jmlBeli);
				pembayaran :
				printf("Masukkan Nominal Pembayaran : ");
				scanf("%d", &bayar);
				if(bayar<barang[i].harga*jmlBeli){
					printf("Uang Tidak Cukup !\n");
					system("PAUSE");
					goto pembayaran;
				}else{
					int kembalian = bayar - (barang[i].harga*jmlBeli);
					printf("Pembayaran Berhasil.\n");
					printf("Kembalianmu : %d\n", kembalian);
					printf("Terima Kasih Sudah Berbelanja.\n");
					updateFile();
					system("PAUSE");
					system("CLS");
					return main();
				}
			}else{
				continue;
			}
			printf("Kode Barang tidak ada di inventaris. Coba Lagi ! \n");
			system("PAUSE");
			goto ulang;
		}
	}
}

int main() {
	char pilih;
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
	fflush(stdin);
	scanf("%c",&pilih); 
	fflush(stdin);
	
	switch (pilih) {
		case '1': {
			system("CLS");
			lihatdata();
			printf("\n\nTekan Enter untuk Kembali ke Menu Awal.\n");
			system("PAUSE");
			system("CLS");
			goto menu;
		}
		case '2': {
			system("CLS");
			tambahdata(); 
			goto menu;
		}
		case '3' : {
			system("CLS");
			transaksibarang();
			//updateFile();
			goto menu;
		}
		case '4' : {
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

