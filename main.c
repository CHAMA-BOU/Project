#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "menu.h"
#include "functions.h"

int main(){

	char order, confirm, OK, confirm2, autreChoix;
	int nbCategorie, nbSubCateg, nbElement,nbChoix=0;
	char *choices[10];
	double prices[10];
	do
    {
        start:
        printf("\t================ Welcome to Nom de Restau! ================\n");
        printf("\t==== make sure you do not quit before validating your choices!====\n");
        printf("\t\t====you have up to 10 choices to make!====\n");
        printf("================ S to Show Menu 		Q to Quit ================\n");//presente deux options afficher le menu ou quitter
        scanf(" %c", &order);
        /* si le client a choisi de quitter on lui demande de confirmer son choix
        si oui il veut quitter, sinon la console est vidée et le program saute au menu*/
        if (order == 'Q'){
            printf("Are you sure you want to quit?\nY.yes 		N.No\n");
            scanf(" %c", &confirm); // " %c" to avoid buffer broblems
            if (confirm == 'Y'){
                printf("Thanks for visit us! Have a good day!\n");
                exit(0);
            }
            else {
                system("cls");// "clear" sous Linux et "cls" sous Windows
                goto menu; // the program jumb to label menu
            }
        }

        else if (order == 'S'){ //si le client a choisi de voir le menu
            menu: //label
            nbChoix+=1;
            printf("================== Select your choices ==================\n");
            showCategories(categories_);
            printf("Enter nomber of categorie\n");
            scanf("%d", &nbCategorie);
            switch(nbCategorie){
                case 1:
                    showCoeffes(coeffe);
                    scanf("%d", &nbElement);
                    addElements(choices, coeffe, nbElement,nbChoix);
                    addPrices(prices,coeffeP, nbElement,nbChoix);
                    break;
                case 2:
                    showTeas(tea);
                    scanf("%d", &nbElement);
                    addElements(choices, tea, nbElement,nbChoix);
                    addPrices(prices,teaP, nbElement,nbChoix);
                    break;
                case 3:
                    showSubCategories(drinks_);
                    scanf(" %d", &nbSubCateg);
                    switch(nbSubCateg){
                        case 1:
                            showJuices(juice);
                            scanf("%d", &nbElement);
                            addElements(choices, juice, nbElement,nbChoix);
                            addPrices(prices,juiceP, nbElement,nbChoix);
                            break;
                        case 2:
                            showOthers(other);
                            scanf("%d", &nbElement);
                            addElements(choices, other, nbElement,nbChoix);
                            addPrices(prices,otherP, nbElement,nbChoix);
                            break;
                        default:
                            printf("Enter a valid option");//si le client a saisi un nombre qui n'est pas dans le menu principal retourner ce message
                            nbChoix-=1;
                            goto menu;
                    }
                    break;
                case 4:
                    showDesserts(dessert);
                    scanf("%d", &nbElement);
                    addElements(choices, other, nbElement,nbChoix);
                    addPrices(prices,dessertP, nbElement,nbChoix);
                    break;
                case 5:
                    showBurgers(burger);
                    scanf("%d", &nbElement);
                    addElements(choices, burger, nbElement,nbChoix);
                    addPrices(prices,burgerP, nbElement,nbChoix);
                    break;
                case 6:
                    showTraditionalDishes(traditional);
                    scanf("%d", &nbElement);
                    addElements(choices, traditional, nbElement,nbChoix);
                    addPrices(prices,traditionalP, nbElement,nbChoix);
                    break;
                default:
                    printf("Enter a valid option"); //si le client a saisi un nombre qui n'est pas dans le menu principal retourner ce message
                    nbChoix-=1;
                    goto menu;
            }
            printf("======================= You asked for:\n");
            yourChoices(choices,nbChoix);
            printf("======================= Is this OK! ===========================\n");
            printf("O.OK\t\tB.Back\t\tC.Cancel\n");
            scanf(" %c", &OK);
            switch(OK){
                case 'O':
                    printf("========================= Enjoy! =======================\n");
                    break;
                case 'B':
                    system("cls");
                    nbChoix=0;
                    goto menu;
                    break;
                case 'C':
                    printf("Are you sure you want to quit?\nY.yes 		N.No\n");
                    scanf(" %c", &confirm2); // " %c" to avoid buffer broblems
                    if (confirm2 == 'Y'){
                        printf("Thanks for visit us! Have a good day!\n");
                        exit(0);
                    }
                    else {
                        system("cls");
                        nbChoix=0;
                        goto menu;
                    }
                    break;
            }
        }
    /*si le client a saisi un nombre qui n'est pas dans le menu principal retourner un message d'erreur
    et le programme recommence au niveau de start label*/
        else {
            system("cls");
            printf("Enter a valid option!\n");
            goto start;
        }
        printf("voulez vous effectuer un autre choix? tapez Y si oui ");
        scanf(" %c",&autreChoix);
        if (autreChoix!='Y')
        {
            facture(choices, prices, nbChoix);
            printf("*************** Thanks for visiting us! *************** \n\t\t*******************");
        }
        else
        {
            system("cls");
        }
    } while (autreChoix=='Y');
    return 0;
}
