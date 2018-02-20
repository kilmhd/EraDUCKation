#include <stdlib.h>
#include <stdio.h>

#include "joueur.h"
#include "canard.h"
#include "struct.h"
#include "labyrinthe.h"


joueur_t joueur;
joueur_t joueur2;


int choix_difficultee(int choix){
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
int choix_nbr_joueur(int choix){
	int nbr_joueur;
	switch(choix){
		case 1 :
			caract_joueur(joueur);
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
			taille_mat=choix_difficultee(choix);
			
			/* Nombre de Joueur */
			printf("1 : 1 joueur\n");
			printf("2 : 2 joueurs\n");
			scanf("%i",&choix);
			nbr_joueur=choix_nbr_joueur(choix);
			
			/*Mise en place de la matrice adaptée*/
			init_matrice(taille_mat);

			/*Creation du Labyrinthe*/
			creer_labyrinthe();
			
			//Apparition de canard
			init_canard(); 

			if(nbr_joueur==1){
				jeu_solo();
			}else{
				jeu_multi();
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