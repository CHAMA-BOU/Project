#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "functions.h"


void showCategories(char **categ){

	for (int k = 1, i=0; i<6; ++i, ++k){
		printf("%d.%s\t\t", i+1, categ[i]);
		if (k%3==0) printf("\n\n\n");
	}
}

// *********************************************************************
void showSubCategories(char **sub_categ){

    printf("Juices or something else?\n");
    for (int l = 1, k=0; k<2; ++l, k++){
        printf("%d.%s\t\t", k+1, sub_categ[k]);
        if (l%3==0) printf("\n\n\n");
    }
    printf("\n ============================================= \n");
}

// *********************************************************************
void showDesserts(char **d){

	for(int k = 1, j=0; j<12; ++j, ++k){
		printf("%d.%s\t\t", j+1, d[j]);
		if (k%3==0) printf("\n\n\n");
	}
	printf("\n ========================================================= \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
void showJuices(char **j){
	for(int k = 1, i=0; i<12; ++i, ++k){
		printf("%d.%s\t\t", i+1, j[i]);
		if (k%3==0) printf("\n\n\n");
	}
	printf("\n ========================================================= \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
void showCoeffes(char **c){
	for(int k = 1,  j=0; j<12; ++j, ++k){
        printf("%d.%s\t\t", j+1, c[j]);
		if (k%3==0) printf("\n\n\n");
	}
	printf("\n ================================================ \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
void showTeas(char **t){
	for(int k = 1, j=0; j<8; ++j, ++k){
		printf("%d.%s\t\t", j+1, t[j]);
		if (k%3==0) printf("\n\n\n");
	}
	printf("\n ================================================ \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
void showTraditionalDishes(char **td){

	for(int k = 1, j=0; j<9; ++j, ++k){
		printf("%d.%s\t", j+1, td[j]);
		if (k%3==0) printf("\n\n\n");
	}
	printf("\n =============================================== \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
void showBurgers(char **bu){

	for(int k = 1, j=0; j<9; ++j, ++k){
		printf("%d.%s\t\t", j+1, bu[j]);
		if (k%3==0) printf("\n\n\n");
	}
	printf("\n ================================================ \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
void showOthers(char **o){
	for(int k = 1, j=0; j<5; ++j, ++k){
		printf("%d.%s\t\t", j+1, o[j]);
		if (k%3==0) printf("\n\n\n");
	}
	printf("\n ======================================= \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
void yourChoices(char **choices, int nbChoix){
    for(int i = 0; i<nbChoix; ++i){
        printf("%s\t\t", choices[i]);
    }
    printf("\n");
}

// *********************************************************************
void addElements(char **choices, char **categ,int nb ,int nbChoix){
    choices[nbChoix-1] = categ[nb-1];
}

// *********************************************************************

void facture(char **choices, double prices[], int nbChoix){
    system("cls");
    printf("\t\t\tNom de Restaurant\n\t\t\t*******************\n");
    char curr_time[10], curr_date[12];
    strcpy(curr_date, __DATE__);
    strcpy(curr_time, __TIME__);
    printf("======== %s\t\t\t%s ========\n", curr_date, curr_time);
    printf("Facture N°:552 \t\t Client N°:54\n");
    printf("---------------------------------------------------------\n");
    for(int i = 0; i<nbChoix; ++i){
        printf("%d. %s\t\t %g  DH\n", i+1, choices[i], prices[i]);
    }

    double TTC=0;
    for(int i=0; i<nbChoix; ++i){
        TTC += prices[i];
    }
    printf("---------------------------------------------------------\n");
    printf("TOTAL TTC %g DH\n\n\n\n", TTC);
}


void addPrices(double prices[], double categP[],int nb,int nbChoix){

    prices[nbChoix-1] = categP[nb-1];
}
