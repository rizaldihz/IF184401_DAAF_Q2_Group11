#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define debugc(p) for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%c ",p[i][j]);}printf("\n");}
#define debugi(p) for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%d ",p[i][j]);}printf("\n");}
using namespace std;

char papan[3][3] = 
{ 
    { 'x', '_', '_' }, 
    { '_', 'o', 'o' }, 
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

int main()
{
    printf("score %d\n",score_eval());
    return 0; 
}