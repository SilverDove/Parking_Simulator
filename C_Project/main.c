/* main.c : menu of the game where mode of the parking simulator is chosen randomly

CREATION DATE : 30/10/2019
MODIFICATION DATE: 06/12/2019
AUTHORS : TABOU Metagang and TRICOT Clara*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "game.h"
#include "constant.h"


void game(SDL_Surface *screen, ColorBand ColorSpot[], int number_spot, int mode){//Run the game
  /*Creation of variables*/
  char string[50] = "";
  double price = 0.75;
  SDL_Event event;
  SDL_Surface *text, *payement;//text to display
  SDL_Rect position_text;//Position of the text
  SDL_Rect position_payement;//Position of the text
  TTF_Font *police = NULL;//Type of police
  SDL_Color whiteColor = {255,255,255};//Color of the text
  int timesRespawn = 0;//When we can add a car
  int delay=0;
  Llist* List_Vehicule = NULL; //Linked List of vehicules
  Llist *Cursor = NULL;//Linked List to be able to go through the list
  int welcome_counter = 0;
  int exit_counter = 5;
  int position_Map[NB_BLOCKS_HEIGHT][NB_BLOCKS_LENGTH];//Creation array to store structure of the parking
  int Continue = 1;

  if(mode == 6){//If it's the full mode
    SDL_WM_SetCaption("Parking Simulator [FULL MODE]", NULL);
  }else{//Othrwise, it's the fluid mode
    SDL_WM_SetCaption("Parking Simulator [FUILD MODE]", NULL);
  }

  if(TTF_Init() == -1){//If we have a problem when using TFF library
        fprintf(stderr, "Erreur d'initialisation de TFF_Init : %s\n", TTF_GetError());
  }

  police = TTF_OpenFont("Sunflower.ttf", 20);//Sunflower police is used with a size of 20 pixel

  text = TTF_RenderText_Solid(police, "Welcome ;)", whiteColor);//Write a text on the screen
  /*Position x and y of the text*/
  position_text.x = SIZE_BLOCK *1.15;
  position_text.y = SIZE_BLOCK *0.5;

  /*Position of the second text to display*/
  position_payement.x = SIZE_BLOCK *11;
  position_payement.y = SIZE_BLOCK *0.25;

  /*Add a vehicule*/
  List_Vehicule = addVehicule(List_Vehicule, CreateVehicule());
  Cursor = List_Vehicule;

  Initialization_Map(NB_BLOCKS_HEIGHT, NB_BLOCKS_LENGTH, position_Map, "update_pos.txt");//Initialize array depending structure of the parking (written into a file)
  load_Map(screen);//show the parking

  position_Map[1][2] == 1;//Now there is a car at these indexes

  while(Continue == 1){//Until the user didn't close the window
    Cursor = List_Vehicule;//At the begining of the list

    if(timesRespawn == mode){//if it's the moment to add a vehicule
       List_Vehicule = addVehicule(List_Vehicule, CreateVehicule());//Add a vehicule into the list
       timesRespawn ++;
       Cursor = List_Vehicule;//At the beginning of the list
	   welcome_counter = 3;
    }

    if(welcome_counter != 0){//If the counter is not equal to 0, display "Welcome" on the screen
        SDL_BlitSurface(text, NULL, screen, &position_text);//Display the text
        SDL_Flip(screen);//Display the screen
        welcome_counter --;
    }

    if(timesRespawn != mode){//If it's not the moment to add a vehicule
	    timesRespawn ++;
	    timesRespawn%=(mode+1);
    }

    delay = 0;

    while(Cursor != NULL){//Until we are not at the end of the list

    if (SDL_PollEvent(&event) !=0){//If a event occurs
	    if (event.type == SDL_QUIT){//If the user wants to close the window
		    Continue = 0;//End of the program
		    break;
	    }
    }

    if (delay == 70000){//If enough time passed

      SearchParkingSpace(screen, Cursor->vehicule, NB_BLOCKS_LENGTH, NB_BLOCKS_HEIGHT, position_Map, Cursor->vehicule->tps);//Current vehicule is going to search a spot

      if (Cursor->vehicule->state == 1 && Cursor->vehicule->positionTable.x == 13 && Cursor->vehicule->positionTable.y == 1){//If the current vehicule already parked and is at the exit
            if( exit_counter != 0){//If the counter is not equal to 0
                sprintf(string, "Payement: %.2f", (Cursor->vehicule->tps)*price );//Indicate how many the conductor should pay
                payement = TTF_RenderText_Solid(police,string, whiteColor);//Display how much the conductor should pay
                exit_counter --;
            }else{//If the vehicule paid
                position_Map[Cursor->vehicule->positionTable.y][Cursor->vehicule->positionTable.x] = 0;
                removeVehicule(List_Vehicule, Cursor->vehicule);//remove the vehicule from the parking
                exit_counter = 5;
            }
      }
      Cursor = Cursor->NXT;//Select the next vehicule of the list

    }else{//If it's to soon
      delay++;
      delay = delay%70001;
    }
  }

  Cursor = List_Vehicule;//At the beginning of the list

  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255,255,255));//Restore the screen
  load_Map(screen);//Display the parking
  while(Cursor != NULL){//Display all the vehicules
     display_Cars(screen, Cursor->vehicule) ;
     Cursor = Cursor->NXT;
  }

  ChangeColorSpot(ColorSpot,number_spot,NB_BLOCKS_LENGTH, NB_BLOCKS_HEIGHT, position_Map);//Return the color that the band should have (Red if not free and Green and free

  for (int i=0; i< number_spot ; i++){//For all spots
	if(ColorSpot[i].color == 'R'){//If the spot is not free
	 	SDL_FillRect(ColorSpot[i].colorSurface, NULL, SDL_MapRGB(ColorSpot[i].colorSurface->format,255,0,0)); //Display band with red color
        SDL_BlitSurface(ColorSpot[i].colorSurface, NULL, screen,&(ColorSpot[i].colorPosition));
	}
	if(ColorSpot[i].color == 'G'){//If the spot is free
		SDL_FillRect(ColorSpot[i].colorSurface, NULL, SDL_MapRGB(ColorSpot[i].colorSurface->format,0,255,0)); //Display band with green color
		SDL_BlitSurface(ColorSpot[i].colorSurface, NULL, screen,&(ColorSpot[i].colorPosition));
	}
  }
    if(exit_counter != 5){//Display price if the car is still trying to pay
	  SDL_BlitSurface(payement, NULL, screen, &position_payement);
	}
    SDL_Flip(screen);//Display the screen

}
  /*Free or Quit*/
  SDL_FreeSurface(text);
  SDL_FreeSurface(payement);
  TTF_CloseFont(police);
  TTF_Quit();
  emptyList(List_Vehicule);
  emptyList(Cursor);

}

int main (){

    /*Creation of variables*/
    SDL_Surface *screen = NULL;
    SDL_Surface *BG = NULL;
    SDL_Rect positionBG;
    SDL_Event event;
    int cont = 1;
    positionBG.x =0;
    positionBG.y = 0;
    srand(time(NULL));

  if (SDL_Init(SDL_INIT_VIDEO) == -1) // If errors when begin SDL
    {
        fprintf(stderr, "ERROR with SDL initialization : %s\n", SDL_GetError()); // Error message is written
        exit(EXIT_FAILURE); //Leave the program
    }

    screen = SDL_SetVideoMode(WINDOW_LENGTH,WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);//Initialize the screen
    SDL_WM_SetCaption("Parking Simulator by TRICOT Clara and TABOU Metagang 3A-35", NULL);//Title of the window

    if (screen == NULL){//If the screen is not initialized
      fprintf(stderr, "Impossible to be in Video Mode : %s\n", SDL_GetError());//Error message is written
      exit(EXIT_FAILURE);//Leave the program
    }

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    BG = IMG_Load("MENU.png");//Load image of the Menu
    SDL_BlitSurface(BG, NULL, screen, &positionBG);//Display the Menu
    SDL_Flip(screen);//Display the screen

   while (cont){
    SDL_WaitEvent(&event);//Wait a event from the user
    switch(event.type)
    {
        case SDL_QUIT://If the user close the window
            cont = 0;//Leave the program
            break;

        case SDL_KEYDOWN://If the user press a key
            switch (event.key.keysym.sym)
            {
                case SDLK_s: //If the user press 's', start the simulation
                    cont = 0;
                    ColorBand colorSpot[NUMBER_SPOT];//Create array with all the band
                    InitializeColorSpot(colorSpot,NUMBER_SPOT);//Initialize the bands
                    if(rand()%2 == 0){//Fluid Mode
                        game(screen, colorSpot, NUMBER_SPOT, 15);//run the parking simulator in Fluid Mode
                    }else{// Full mode
                        game(screen, colorSpot, NUMBER_SPOT, 6);//run the parking simulator in Full Mode
                    }
                break;
            }
        break;
   	 }
   }

    /*Free or quit*/
    SDL_FreeSurface(BG);
    SDL_Quit();

  return EXIT_SUCCESS;
}
