#include "struct.h"
#include "joueur.h"
#include <stdio.h>
#define taille_mat 20 //taille de la matrice//

case_t matrice[taille_mat][taille_mat];

void reproduction(caract_mat_t * matrice, int nourriture_accouplement,joueur_t joueur,joueur_t joueur2){
	int i;
	int j;
	int k;
	int l;
	int compteur;
	for(i=0;i<taille_mat;i++){
		for(j=0;j<taille_mat;j++){
			//Parcours du nombre de canard//
			compteur=0;//compteur du nombre de canard favorable a la reproduction//
			for(k=0;k<nb_max;k++){
				if(matrice[i][j].tab_canard[k].nourriture>=nourriture_accouplement){
					compteur++;
				}
			}
			for(l=0;l<compteur/2;l++){
				matrice[i][j]nb_occupant++; //Ajout des nouveaux canards//
				matrice[i][j].tab_canard[l].etat=0;
				matrice[i][j].tab_canard[k].nourriture=100;
				ajout_score(25,joueur,joueur2);
			}
		}
	}
}
