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
        fptr = fopen ("inventory.txt", "w");
        masukbarang:
        currentItems++;
        /*
        printf("Masukkan kode barang : ");
        fflush(stdin);
        scanf("%c", &barang[currentItems].kodebarang);
        //gets(barang[currentItems].kodebarang);
        
        printf("Masukkan nama barang : ");
        fflush(stdin);
        scanf("%c", &barang[currentItems].nama);
        //gets(barang[currentItems].nama);

        printf("Masukkan kategori barang : ");
        fflush(stdin);
        scanf("%c", &barang[currentItems].kategori);
        //gets(barang[currentItems].kategori);

        printf("Masukkan harga barang : ");
        fflush(stdin);
        scanf("%ld", &barang[currentItems].harga);

        printf("Masukkan jumlah barang : ");
        fflush(stdin);
        scanf("%d", &barang[currentItems].jumlah);

        //fwrite(barang, sizeof(struct barang), 1, fptr);
        for(int i = 1; i <= currentItems; i++){
            fprintf(fptr, "%s\n", barang[i].kodebarang);
            fprintf(fptr, "%s\n", barang[i].nama);
            fprintf(fptr, "%s\n", barang[i].kategori);
            fprintf(fptr, "%ld\n", barang[i].harga);
            fprintf(fptr, "%d\n", barang[i].jumlah);
        }
        */
        //fprintf(fptr, "%s\n%s\n%s\n%ld\n%d\n-----------", barang[currentItems].kodebarang, barang[currentItems].nama, barang[currentItems].kategori, barang[currentItems].harga, barang[currentItems].jumlah);
        
        printf("Masukkan Kode Barang : ");
        fflush(stdin);
        fgets(barang->kodebarang, sizeof(struct barang), stdin);
        //scanf("%s", &barang[i].kodebarang);
        fputs(barang->kodebarang, fptr);

        printf("Masukkan Nama Barang : ");
        fgets(barang->nama, sizeof(struct barang), stdin);
        //scanf("%s", &barang[i].nama);
        fputs(barang->nama, fptr);

        printf("Masukkan Kategori Barang : ");
        fgets(barang->kategori, sizeof(struct barang), stdin);
        //scanf("%s", &barang[i].kategori);
        fputs(barang->kategori, fptr);

        printf("Masukkan Harga Barang : ");
        scanf("%ld", &barang->harga);
        //scanf("%s", &barang[i].harga);
        fputs(barang->harga, fptr);

        printf("Masukkan Jumlah Barang : ");
        scanf("%d", &barang->jumlah);
        //scanf("%s", &barang[i].jumlah);
        fputs(barang->jumlah, fptr);
        fputs("------\n", fptr);
        //fputs(tulisan, fptr);
        
        printf("Semua data sudah berhasil ditulis ke file.\n");
        fclose(fptr);
        system("PAUSE");
        system("CLS");
    }
    tanya: 
    printf("Apakah Anda ingin menambahkan data lagi ? [1/0]\n");
    scanf("%d", &pilihan);
    if(pilihan==1){
        goto masukbarang;
        system("CLS");
    }
    /*else if(pilihan==0){
        goto menu;
    }else{
        printf("Pilihan Tidak Ada. Ulangi Lagi.\n");
        system("PAUSE");
        goto tanya;
    }*/
}

int ulg = 1;
void lihatdata()
{
    if((fptr = fopen("inventory.txt", "r")) == NULL){
    printf("File belum ada. Buat baru dulu.\n");
    fclose(fptr);

    } else if((fptr = fopen("inventory.txt", "r")) != NULL){
        printf("KODE BARANG\tNAMA BARANG\tKATEGORI BARANG\tHARGA BARANG\tJUMLAH BARANG\n");
        
        printf("Jumlah Barang Sekarang : %d\n\n", currentItems);
        /*for(int i = 0; i < currentItems; i++){
            fgets(&barang, sizeof(struct barang), fptr);
            printf("%s\t%s\t%s\t%ld\t%d\n", barang[currentItems].kodebarang, barang[currentItems].nama, barang[currentItems].kategori, barang[currentItems].harga, barang[currentItems].jumlah);
        }*/
        
       /*
       while(!feof(fptr)){
           if (ulg == 1){
               fscanf(fptr, "%s\t", barang[currentItems].kodebarang);
               ulg++;
           }if(ulg == 2){
               fscanf(fptr, "%s\t", barang[currentItems].nama);
               ulg++;
           }if(ulg == 3){
               fscanf(fptr, "%s\t", barang[currentItems].kategori);
               ulg++;
           }if(ulg == 4){
               fscanf(fptr, "%ld\t", barang[currentItems].harga);
               ulg++;
           }if(ulg == 5){
               fscanf(fptr, "%d\t", barang[currentItems].jumlah);
               ulg++;
               currentItems++;
           }
           fclose(fptr);
       }
       */
       while (fgets(barang, sizeof(struct barang), fptr)){
           printf("%s\t%s\t%s\t%ld\t%d\n", barang->kodebarang, barang->nama, barang->kategori, barang->harga, barang->jumlah);
       }
    }
    
    /*while(fgets(barang, sizeof(struct barang), fptr)){
        printf("%s\n", barang->kodebarang);
        printf("%s\n", barang->nama);
        printf("%s\n", barang->kategori);
        printf("%ld\n", barang->harga);
        printf("%d\n", barang->jumlah);
    }*/
    
    /*for(int i = 0; i < 5; i++){
        printf("%s\n", barang[i].kodebarang);
        printf("%s\n", barang[i].nama);
        printf("%s\n", barang[i].kategori);
        printf("%ld\n", barang[i].harga);
        printf("%d\n", barang[i].jumlah);
    }*/
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