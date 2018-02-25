#include "struct.h"
#include <stdio.h>


void init_matrice(case_t ** matrice, int taille_mat){
	int i;
	int j;
	int k;	
	for(i=0;i<taille_mat;i++){
		for(j=0;j<taille_mat;j++){
			//Initialisation des murs a 0 (inexistant)//
			matrice[i][j].mur.murN=0;
			matrice[i][j].mur.murS=0;
			matrice[i][j].mur.murE=0;
			matrice[i][j].mur.murO=0;
			
			//Initialisation des Canards a 0 //
			for(k=0;k<nb_max;k++){
				matrice[i][j].tab_canard[k].nourriture=0;
				matrice[i][j].tab_canard[k].etat=-1;
			}
			
			//Initilisation nombre de canard//
			matrice[i][j].nb_occupant=0;
			//Initialisation de nourriture//
			matrice[i][j].pres_nourriture=0;
			matrice[i][j].pres_piege=0;
		}
	}
}
