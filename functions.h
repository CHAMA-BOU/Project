#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED// include guard pour eviter les problemes des include
#include <stdio.h>
#include <stdio.h>


void yourChoices(char **choices, int nbChoix);// afficher les elements choisi
void showCategories(char **categ);
void showSubCategories(char **sub_categ);
void showDesserts(char **d);
void showJuices(char **j);
void showCoeffes(char **c);
void showTeas(char **t);
void showTraditionalDishes(char **td);
void showBurgers(char **b);
void showOthers(char **o);
void addElements(char **choices, char **categ,int nb ,int nbChoix);/*ajouter chaque element choisi par l'utilisateur
                                                        dans l'array choices afin de le conserver pour les utiliser
                                                        plus tard*/
void addPrices(double prices[], double categP[],int nb,int nbChoix);
void facture(char **choices, double prices[], int nbChoix);
#endif // FUNCTIONS_H_INCLUDED
