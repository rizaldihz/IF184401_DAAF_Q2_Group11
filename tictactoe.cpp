#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define MAX 1000
#define MIN -1000
#define debugc(p) for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%c ",p[i][j]);}printf("\n");}
#define debugi(p) for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%d ",p[i][j]);}printf("\n");}
using namespace std;

char papan[3][3] = 
{ 
    { '_', '_', '_' }, 
    { '_', '_', '_' }, 
    { '_', '_', '_' } 
}; 

char pemain='o',ai='x',kosong='_';

int score_eval()
{
    for(int i=0;i<3;i++){
        if(papan[i][0]==papan[i][1]&&papan[i][1]==papan[i][2]&&papan[i][0]==pemain) return -10;
        else if(papan[0][i]==papan[1][i]&&papan[1][i]==papan[2][i]&&papan[0][i]==pemain) return -10;
        else if(papan[i][0]==papan[i][1]&&papan[i][1]==papan[i][2]&&papan[i][0]==ai) return 10;
        else if(papan[0][i]==papan[1][i]&&papan[1][i]==papan[2][i]&&papan[0][i]==ai) return 10;
    }
    if(papan[0][0]==papan[1][1]&&papan[1][1]==papan[2][2]&&papan[0][0]==pemain) return -10;
    else if(papan[0][2]==papan[1][1]&&papan[1][1]==papan[2][0]&&papan[0][2]==pemain) return -10;
    else if(papan[0][0]==papan[1][1]&&papan[1][1]==papan[2][2]&&papan[0][0]==ai) return 10;
    else if(papan[0][2]==papan[1][1]&&papan[1][1]==papan[2][0]&&papan[0][2]==ai) return 10;
    return 0;
}

char other(char pion)
{
    if(pion == pemain) return ai;
    else return pemain;
}

bool masihbermain()
{
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++){
            if(papan[i][j]==kosong) return true;
        }
    }
    return false;
}

int max(int a,int b)
{
    return a>b ? a:b;
}

int min(int a,int b)
{
    return a<b ? a:b;
}

int minimax(char pion)
{
    int skor = score_eval();
    if(skor!=0){
        return skor;
    }
    if(!masihbermain()){
        return 0;
    }
    int hasil;
    if(pion==ai){
        hasil = MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(papan[i][j]==kosong){
                    papan[i][j] = pion;
                    hasil = max(hasil,minimax(other(pion)));
                    papan[i][j]=kosong;
                }
            }
        }
    }
    else{
        hasil = MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(papan[i][j]==kosong){
                    papan[i][j] = pion;
                    hasil = min(hasil,minimax(other(pion)));
                    papan[i][j]=kosong;
                }
            }
        }
    }
    return hasil;
}

void ambil_path()
{
    int hasil,sementara;
    int x=-1,y=-1;
    hasil = MIN;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(papan[i][j]==kosong){
                papan[i][j] = ai;
                sementara = minimax(pemain);
                if(sementara>hasil)
                {
                    hasil = sementara;
                    x = i;
                    y = j;
                }
                papan[i][j] = kosong;
            }
        }
    }
    papan[x][y] = ai;
    return;
}

void play()
{
    system("cls");
    printf("Mari bermain tic tac toe:\nAnda: O, Computer: X\n");
    printf("Tekan sembarang tombol untuk lanjut");
    getch();
    int score;
    for(int i=0;i<9;i++){
        system("cls");
        score = score_eval();
        if(score!=0) break;
        if(!(i%2)){
            printf("Giliran anda:\n");
            debugc(papan);
            int x,y;
            printf("Baris Kolom: ");
            scanf("%d %d",&x,&y);
            x--;y--;
            while(x>2 || y>2 || papan[x][y]!=kosong){
                system("cls");
                printf("Giliran anda:\n");
                debugc(papan);
                printf("Input tidak valid atau tempat telah diisi\n");
                printf("Baris Kolom: ");
                scanf("%d %d",&x,&y);
                x--;y--;
            }
            papan[x][y]=pemain;
            system("cls");
            printf("Giliran anda:\n");
            debugc(papan);
            Sleep(500);
            printf("Tekan sembarang tombol untuk lanjut");
            getch();
        }
        else{
            for(int k=3;k>=1;k--){
                system("cls");
                printf("Giliran komputer:\n");
                debugc(papan);
                printf("Komputer sedang berfikir %d\n",k);
                Sleep(1000);
            }
            ambil_path();
            system("cls");
            printf("Giliran komputer:\n");
            debugc(papan);
            Sleep(500);
            printf("Tekan sembarang tombol untuk lanjut");
            getch();
        }
    }
    system("cls");
    printf("Hasilnya adalah:\n");
    debugc(papan);
    if(score == 10) printf("Komputer menang!\n");
    if(score == -10) printf("Anda menang!\n");
    if(score == 0) printf("SERI!\n");
}

int main()
{
    play();  
    return 0; 
}