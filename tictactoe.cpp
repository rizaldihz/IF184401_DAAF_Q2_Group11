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
    { 'x', 'x', 'o' }, 
    { 'x', 'o', 'o' }, 
    { '_', 'o', '_' } 
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
    printf("hasil %d baris %d kolom %d\n",hasil,x,y);
}

int main()
{
    debugc(papan);
    printf("minimax sekarang %d\n",minimax(ai));
    ambil_path();
    debugc(papan);
    printf("playing %d score %d\n",masihbermain(),score_eval());
    return 0; 
}