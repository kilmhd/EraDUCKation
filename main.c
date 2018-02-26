#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "matrice.h"
#include "event.h"
#include "joueur.h"
#include "canard.h"
#include "labyrinthe.h"
#include "deplacer_multi.h"
#include "jeu_solo.h"



int choix_difficultee(int choix){
	int taille_mat;
	switch(choix){
		case 1 :
			return taille_mat=15;
		break;	
		case 2:
			return taille_mat=25;
		break;
		case 3:
			return taille_mat=50;
		break;		
	}
}
int choix_nbr_joueur(int choix,joueur_t joueur,joueur_t joueur2){
	int nbr_joueur;
	switch(choix){
		case 1 :
			caract_joueur(joueur);
			joueur2.score=0;
			return nbr_joueur=1;
		break;	
		case 2:
			caract_joueur(joueur);
			caract_joueur(joueur2);
			return nbr_joueur=2;
		break;	
	}
}


int main(){

	//definition matrice
	caract_mat_t * cmat;

	//definition joueur
	joueur_t joueur;
	joueur_t joueur2;
	joueur2.nom_joueur[0]='n';
	joueur2.nom_joueur[1]='u';
	joueur2.nom_joueur[2]='l';
	joueur2.nom_joueur[3]='l';

	//definition nourriture
	int nourriture_accouplement;//Nourriture qu'on a besoin pour se reproduire
	int nourriture_genere;//Nourriture qui apparait
	
	int choix; // Choix du joueur
	int nbr_joueur;
	
	
	printf("EraDUCKation\n\n");

	printf("1 : Jouer à EraDUCKation\n");
	printf("2 : Option (non opérationel)\n");
	printf("3 : Quitter\n");
	
		
	switch(choix){
		case 1 :
			/* Difficulté*/
			printf("1 : Facile\n");
			printf("2 : Intermédiaire\n");
			printf("3 : Difficile\n");
			scanf("%i",&choix);
			cmat->taille_mat_x=choix_difficultee(choix);
			cmat->taille_mat_y=cmat->taille_mat_x;

			/* Nombre de Joueur */
			printf("1 : 1 joueur\n");
			printf("2 : 2 joueurs\n");
			scanf("%i",&choix);
			nbr_joueur=choix_nbr_joueur(choix,joueur,joueur2);
			
			/*Mise en place de la matrice adaptée*/
			creation_matrice(cmat);
			init_matrice(cmat);

			/*Creation du Labyrinthe*/
			creer_labyrinthe();
			
			//Apparition de canard
			init_canard(cmat); 

			if(nbr_joueur==1){
				jeu_solo(cmat,nourriture_genere,nourriture_accouplement,joueur,joueur2);
			}else{
				//jeu_multi();
			}
			
		break;

		case 2 : 
			printf("2 : Option (non opérationel)");
		break;

		case 3 :
			return 0;
		break;
	
	}
	printf("Le score total du joueur 1 est : %i",joueur.score);
	if(joueur2.nom_joueur!=NULL){
		printf("Le score total du joueur 1 est : %i",joueur2.score);
	}
}