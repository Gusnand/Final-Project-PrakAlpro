#include <stdio.h>
#include <stdlib.h>

struct data{
    char nama[100], harga[100];
    int qty;
}data[50];

int curr = 0;
int ulg = 1;
void input(){
    FILE *baca = fopen("dagang.txt", "r");
    if(baca != NULL){
        printf("File ada!");
        while(!feof(baca)){
            if(ulg == 1){
                fscanf(baca, "%s", &data[curr].nama); ulg++;
            }
            if(ulg == 2){
                fscanf(baca, "%s", &data[curr].harga); ulg++;
            }
            if(ulg == 3){ 
                fscanf(baca, "%d", &data[curr].qty); ulg++;
            }
            if(ulg == 4){
                ulg = 1;
                curr++;
            }
        }
    }
    else{
        printf("File kosong!");
    }
    fclose(baca);
}
void tulis(){
    FILE *tulis = fopen("dagang.txt", "w");
    for(int i = 0; i < curr; i++){
        fprintf(tulis, "%s\n", data[i].nama);
        fprintf(tulis, "%s\n", data[i].harga);
        fprintf(tulis, "%d\n", data[i].qty);
    }
    fclose(tulis);
}
void tambah(int n){
    int t = curr;
    printf("Data yang ditambahkan : %d\n", n);
    for(int i = t; i < t+n; i++){
        printf("Masukkan nama barang : ");
        scanf("%s", &data[i].nama);
        printf("Masukkan harga barang : ");
        scanf("%s", &data[i].harga);
        printf("Masukkan kuantitas : ");
        scanf("%d", &data[i].qty);
        curr++;
    }
    tulis();
}
void cetak(){
    printf("Mencetak data : \n");
    for(int i = 0; i < curr; i++){
        printf("%s\n", data[i].nama);
        printf("%s\n", data[i].harga);
        printf("%d\n", data[i].qty);
    }
}
void transaksi(){
	int a, b;
	printf("Masukkan urutan data : "); scanf("%d", &a);
	printf("Masukkan kuantitas : "); scanf("%d", &b);
    if(data[a-1].qty == 0){
        printf("Maaf, barang sudah habis....");
    }
    else if(a <= curr+1){
        printf("%s sebanyak %d berhasil dibeli!", data[a-1].nama, b);
        data[a-1].qty -= b;
    }
    else if(a > curr+1){
        printf("Data tidak ada!");
    }
}
int main(){
    input();
    cetak();
    return 0;
}
