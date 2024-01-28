#include <stdio.h>
#include <stdlib.h>

int v[50];
int N[50];
int P[50];

int afisareASM(int n,int v[]);

int main() {
    FILE* f=fopen("numere.txt","r");

    int x;
    int ln=0;
    while(fscanf(f,"%d",&x)!=EOF){
        v[++ln]=x;
    }
    int n=0,p=0, okn =0, okp = 0;
    for(int i=1; i<=ln; ++i){
        if(v[i]<0){
            N[++n]=v[i];
            okn = 1;;
        } else {
            P[++p]=v[i];
            okp = 1;
        }
    }
    if(okp > 0){
        printf("Numere negative: ");
        afisareASM(n,N);
        printf("\n");
    }
    else 
        printf("Nu exista numere negative!\n");
    if(okn > 0){
    printf("Numere pozitive: ");
    afisareASM(p,P);
    }
    else 
        printf("Nu exista numere pozitive!\n");

    return 0;
}