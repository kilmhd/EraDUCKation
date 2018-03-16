#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


#define largeur 640
#define hauteur 480

/*typedef struct text_s{
	SDL_Texture text;
	int imgDestRect.x;
	int imgDestRect.y;
}text_t;*/

int main(int argc, char** argv)
{
    	//Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	//Le pointeur vers la surface incluse dans la fenetre
   	SDL_Surface *texte=NULL, *image=NULL, *bouton=NULL, *boutonP=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect txtDestRect,imgDestRect;

	// Le pointeur vers notre police
	TTF_Font *police = NULL;
	// Une variable de couleur noire
	SDL_Color couleurNoire = {0, 0, 0};

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    } 

	/* Initialisation TTF */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}


	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow("EraDUCKation",SDL_WINDOWPOS_UNDEFINED,
												  SDL_WINDOWPOS_UNDEFINED,
												  largeur,
												  hauteur,
												  SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	if(!pWindow){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}


	if( (police = TTF_OpenFont("ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}
	texte = TTF_RenderUTF8_Blended(police, "EraDUCKation!!", couleurNoire);
	if(!texte){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte); 
	if(!texte_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(texte); /* on a la texture, plus besoin du texte */
	/* Position ou sera mis le texte dans la fenêtre */
    	txtDestRect.x = txtDestRect.y = 10;
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

	//////////Chargement image de fond////////////////////////////
	
	SDL_RWops *rwop=SDL_RWFromFile("12651.png", "rb");
	image=IMG_LoadPNG_RW(rwop);
	if(!image) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *image_tex = SDL_CreateTextureFromSurface(renderer, image); 
	if(!image_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */
	
	////////////// Chargement Image Bouton Option/////////////////////
	rwop=SDL_RWFromFile("option.png", "rb");
	bouton=IMG_LoadPNG_RW(rwop);
	if(!bouton) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *bouton_tex = SDL_CreateTextureFromSurface(renderer, bouton); 
	if(!bouton_tex){
		fprintf(stderr, "Erreur à la création du rendu du bouton : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(bouton); /* on a la texture, plus besoin de l'image */
	
	////////////// Chargement Image Bouton Play/////////////////////
	rwop=SDL_RWFromFile("Play.png", "rb");
	boutonP=IMG_LoadPNG_RW(rwop);
	if(!boutonP) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *boutonP_tex = SDL_CreateTextureFromSurface(renderer, boutonP); 
	if(!boutonP_tex){
		fprintf(stderr, "Erreur à la création du rendu du boutonP : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(bouton); /* on a la texture, plus besoin de l'image */
	
	////////////// Chargement Image Bouton Credit/////////////////////
	/*rwop=SDL_RWFromFile("option.png", "rb");
	bouton=IMG_LoadPNG_RW(rwop);
	if(!bouton) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *bouton_tex = SDL_CreateTextureFromSurface(renderer, bouton); 
	if(!bouton_tex){
		fprintf(stderr, "Erreur à la création du rendu du bouton : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(bouton); /* on a la texture, plus besoin de l'image */
	
	////////////// Chargement Image Bouton Quit/////////////////////
	/*rwop=SDL_RWFromFile("option.png", "rb");
	bouton=IMG_LoadPNG_RW(rwop);
	if(!bouton) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *bouton_tex = SDL_CreateTextureFromSurface(renderer, bouton); 
	if(!bouton_tex){
		fprintf(stderr, "Erreur à la création du rendu du bouton : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(bouton); /* on a la texture, plus besoin de l'image */
	
	////////////////////////////////////////////////////////////


	if( pWindow )
	{
		int running = 1; 
		while(running) { 
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; 
					break; 
					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:
				/* Le fond de la fenêtre sera blanc */
                                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderClear(renderer);
                                
                                							
                                /* Ajout de la premiere image à une certaine position */
                                imgDestRect.x = 0;
				imgDestRect.y = 0;
				SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                                /* Ajout Bouton Option */
				imgDestRect.x = 484;
				imgDestRect.y = 324;
				SDL_QueryTexture(bouton_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, bouton_tex, NULL, &imgDestRect);
				
				/* Ajout Bouton Play */
				imgDestRect.x = 480;
				imgDestRect.y = 72;
				SDL_QueryTexture(boutonP_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, boutonP_tex, NULL, &imgDestRect);
								
                                /* On fait le rendu ! */
                                SDL_RenderPresent(renderer);
								
							break;
						}
					break;
					///////////Gestion evenement clique souris////////////////////////
					////Recuperer largeur hauteur de chaque image/////
					case SDL_MOUSEBUTTONUP:
						if (e.button.y > 324 && e.button.y <= 324+156 && e.button.x > 484 && e.button.x <= 484+156 ){// si clic sur boutton
                 					txtDestRect.x = 10;
							txtDestRect.y = 50;
                 					/* Ajout du texte en noir */
                                			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                			SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
                                			SDL_RenderPresent(renderer);
                 				}
                 				if (e.button.y > 480 && e.button.y <= 480+166 && e.button.x > 72 && e.button.x <= 72+72 ){// si clic sur boutton
                 					txtDestRect.x = 50;
							txtDestRect.y = 50;
                 					/* Ajout du texte en noir */
                                			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                			SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
                                			SDL_RenderPresent(renderer);
                 				} 	
                 			break;
				
				} 
			} 
		}
	} else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	//Destruction de la fenetre
	SDL_DestroyWindow(pWindow);

	TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
	TTF_Quit();
    SDL_Quit();

    return 0;
}
