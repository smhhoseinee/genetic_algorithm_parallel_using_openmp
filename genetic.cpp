#include<stdio.h>	            //to use the printf function
#include<conio.h>         		//to use the getche function
#include<stdlib.h>         		//to use the rand function

#define GENE_COUNT 10
#define POPULATION 100
#define ITER 100
#define STATIC_POP_FILE "population.txt"

typedef struct Chrom{             		// creating the chrom structure
    short int bit[GENE_COUNT];
    int fit;
}chrom;

void init_pop(chrom popcurrent[POPULATION]);    	//defining the functions that we will use
int fitness(chrom chrom);
void select(chrom popcurrent[POPULATION]);
void crossover(chrom popnext[POPULATION]);
void mutation(chrom popnext[POPULATION]);

int main(){

}

chrom convert_str_2_chrom(char* chrom_str){         //Accepts a string of 1s & 0s to the length of GENE_COUNT.
    chrom chromo;                                   //Will return the corresponding chromosome.
    for(int i=0;chrom_str[i];i++){
        if(i>=GENE_COUNT || (chrom_str[i]!='0' && chrom_str[i]!='1')){
            printf("Error!\nInvalid string as a chromosome.\n");
            exit(EXIT_FAILURE);
        }
        chromo.bit[i] = chrom_str[i] - '0';
    }
    return chromo;
}

void init_pop(chrom popcurrent[POPULATION]){        //Read Initial population from a static file. STATIC_POP_FILE
    FILE *population;

    population = fopen(STATIC_POP_FILE,"rt");

    if(population == NULL){
        printf("Error!\nCouldn't open population file.\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<POPULATION;i++){
        char chrom_str[GENE_COUNT + 2];
        fscanf(population,"%s",chrom_str);
        chrom_str[GENE_COUNT] = 0;
        popcurrent[i] = convert_str_2_chrom(chrom_str);
    }
    for(int i=0;i<POPULATION;i++){
        popcurrent[i].fit = fitness(popcurrent[i]);
    }
}

int fitness(chrom chrom){
  int bit_number = 0;
  int sum = 0;
  while(bit_number < GENE_COUNT){
    sum += (chrom.bit[bit_number]*(2^bit_number));
    bit_number++;
  }
  sum = sum%101;
  return(sum);                	//return the value of sum
}