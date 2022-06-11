#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char nama[100], ktg[100];
    int kode, harga, jumlah;
}data[50];

int jml;
int ulg = 1;
int saldo = 100000000;

void baca(){
    char *ch;
    FILE *input = fopen("Inv.txt", "r");
    if(input != NULL){
        printf("File ada !\n");
        while(!feof(input)){
            ch = fgetc(input);
            printf("%c", ch);
        }
    }
    else {
        printf("file tidak ada!");
    }
}
void input(){
    FILE *baca = fopen("Inv.txt", "r");
    if(baca != NULL){
        printf("File ada!\n");
        while(!feof(baca)){
            if(ulg == 1){
                fscanf(baca, "%s", &data[jml].nama); ulg++;
            }
            if(ulg == 2){
                fscanf(baca, "%s", &data[jml].ktg); ulg++;
            }
            if(ulg == 3){ 
                fscanf(baca, "%d", &data[jml].kode); ulg++;
            }
            if(ulg == 4){ 
                fscanf(baca, "%d", &data[jml].harga); ulg++;
            }
            if(ulg == 5){ 
                fscanf(baca, "%d", &data[jml].jumlah); ulg++;
            }
            if(ulg == 6){
                ulg = 1;
                jml++;
            }
        }
    }
    else{
        printf("File kosong!");
    }
    fclose(baca);
}
void tulis(){
    FILE *tulis = fopen("Inv.txt", "w");
    for(int i = 0; i < jml; i++){
        fflush(stdin);
        fprintf(tulis, "%s\n", data[i].nama);
        fflush(stdin);
        fprintf(tulis, "%s\n", data[i].ktg);
        fprintf(tulis, "%d\n", data[i].kode);
        fprintf(tulis, "%d\n", data[i].harga);
        fprintf(tulis, "%d\n", data[i].jumlah);
    }
    fclose(tulis);
}
void tambah(int n){
    int t = jml-1;
    printf("Data yang ditambahkan : %d\n", n);
    for(int i = t; i < t+n; i++){
        printf("Masukkan nama barang : ");
        fflush(stdin);
        scanf("%s", &data[i].nama);
        printf("Masukkan kategori barang : ");
        fflush(stdin);
        scanf("%s", &data[i].ktg);
        printf("Masukkan kode barang : ");
        scanf("%d", &data[i].kode);
        printf("Masukkan harga barang : ");
        scanf("%d", &data[i].harga);
        printf("Masukkan jumlah barang : ");
        scanf("%d", &data[i].jumlah);
        jml++;
    }
    tulis();
}
void cetak(){
    printf("Mencetak data : \n");
    for(int i = 0; i < jml; i++){
        printf("%s\n", data[i].nama);
        printf("%s\n", data[i].ktg);
        printf("%d\n", data[i].kode);
        printf("%d\n", data[i].harga);
        printf("%d\n", data[i].jumlah);
    }
}
void transaksi(){
    int kode, jumlah;
    if(saldo == 0){
        printf("Uang anda habis !\n");
    }
    else {
        printf("Masukkan kode barang : "); scanf("%d", &kode);
        printf("Masukkan jumlah barang : "); scanf("%d", &jumlah);
        for(int i = 0; i < jml; i++){
            if(data[i].kode == kode){
                data[i].jumlah -= jumlah; saldo -= data[i].harga;
            }
            else {
                printf("Data barang tidak ada !\n");
            }
        }
    }
    
}
void supply(){
    int kode, jumlah;
    printf("Masukkan kode barang : "); scanf("%d", &kode);
    printf("Masukkan jumlah barang : "); scanf("%d", &jumlah);
    for(int i = 0; i < jml; i++){
        if(data[i].kode == kode){
            data[i].jumlah += jumlah;
        }
        else {
            printf("Data barang tidak ada !\n");
        }
    }
}
int main(){
    baca();
    input();
    cetak();
    int pilihan, p2;
    printf("Selamat datang di toko SURYA ABADI TEKNO !\n==========\n");
    mulai:
    printf("Silahkan melakukan transaksi [1/0] [ya/tidak]\n"); scanf("%d", &pilihan);
    if(pilihan == 1){
        printf("1. Transaksi\n2. Cetak saldo\n Masukkan input anda : "); scanf("%d", &p2);
        if(p2 == 1){
            transaksi();
            cetak();
        }
        if(p2 == 2){
            printf("Saldo anda : %d", saldo);
        }
        goto mulai;
    }
    if(pilihan == 0){
        tulis();
        goto lese;
    }
    lese:
    return 0;
}