#include<stdio.h>	            //to use the printf function
#include<conio.h>         		//to use the getche function
#include<stdlib.h>         		//to use the rand function

#define GENE_COUNT 10

typedef struct Chrom{             		// creating the chrom structure
    short int bit[GENE_COUNT];
      int fit;
}chrom;

void evpop(chrom popcurrent[4]);    	//defining the functions that we will use
int x(chrom popcurrent);
int y(int x);
void pickchroms(chrom popcurrent[4]);
void crossover(chrom popnext[4]);
void mutation(chrom popnext[4]);

int main(){
    
}