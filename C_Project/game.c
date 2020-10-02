/* game.c : all the functions to run the game

CREATION DATE : 30/11/2019
MODIFICATION DATE: 06/12/2019
AUTHORS : TABOU Metagang and TRICOT Clara*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "constant.h"
#include "game.h"

int generer_boundary(int min, int max){//return a random number between min and max

  return rand()%(max-min+1) + 1;

}

void InitializeColorSpot(ColorBand colorSpot[], int number_spot){//Initialiaze the color of the spot to indicate if it's free or not

  for (int i=0; i<number_spot; i++){//For all spots in the parking
    colorSpot[i].colorSurface = SDL_CreateRGBSurface(SDL_HWSURFACE,SIZE_BLOCK, 5, 32, 0, 0, 0,0);//Create red color
    SDL_FillRect(colorSpot[i].colorSurface, NULL, SDL_MapRGB(colorSpot[i].colorSurface->format,255,0,0)); //Initialize with red color
    colorSpot[i].color = 'R';//R--> Red
  }

  /*Indicate position of each band in the parking (in pixel)*/
  colorSpot[0].colorPosition.x= 4*SIZE_BLOCK;
  colorSpot[0].colorPosition.y= 1*SIZE_BLOCK;

  colorSpot[1].colorPosition.x= 6*SIZE_BLOCK;
  colorSpot[1].colorPosition.y= 1*SIZE_BLOCK;

  colorSpot[2].colorPosition.x= 8*SIZE_BLOCK;
  colorSpot[2].colorPosition.y= 1*SIZE_BLOCK;

  colorSpot[3].colorPosition.x= 10*SIZE_BLOCK;
  colorSpot[3].colorPosition.y= 1*SIZE_BLOCK;

  colorSpot[4].colorPosition.x= 4*SIZE_BLOCK;
  colorSpot[4].colorPosition.y= 8*SIZE_BLOCK;

  colorSpot[5].colorPosition.x= 6*SIZE_BLOCK;
  colorSpot[5].colorPosition.y= 8*SIZE_BLOCK;

  colorSpot[6].colorPosition.x= 8*SIZE_BLOCK;
  colorSpot[6].colorPosition.y= 8*SIZE_BLOCK;

  colorSpot[7].colorPosition.x= 10*SIZE_BLOCK;
  colorSpot[7].colorPosition.y= 8*SIZE_BLOCK;

  colorSpot[8].colorPosition.x= 4*SIZE_BLOCK;
  colorSpot[8].colorPosition.y= 10*SIZE_BLOCK;

  colorSpot[9].colorPosition.x= 6*SIZE_BLOCK;
  colorSpot[9].colorPosition.y= 10*SIZE_BLOCK;

  colorSpot[10].colorPosition.x= 8*SIZE_BLOCK;
  colorSpot[10].colorPosition.y= 10*SIZE_BLOCK;

  colorSpot[11].colorPosition.x= 10*SIZE_BLOCK;
  colorSpot[11].colorPosition.y= 10*SIZE_BLOCK;

  colorSpot[12].colorPosition.x= 2*SIZE_BLOCK;
  colorSpot[12].colorPosition.y= 17*SIZE_BLOCK;

  colorSpot[13].colorPosition.x= 4*SIZE_BLOCK;
  colorSpot[13].colorPosition.y= 17*SIZE_BLOCK;

  colorSpot[14].colorPosition.x= 6*SIZE_BLOCK;
  colorSpot[14].colorPosition.y= 17*SIZE_BLOCK;

  colorSpot[15].colorPosition.x= 8*SIZE_BLOCK;
  colorSpot[15].colorPosition.y= 17*SIZE_BLOCK;

  colorSpot[16].colorPosition.x= 10*SIZE_BLOCK;
  colorSpot[16].colorPosition.y= 17*SIZE_BLOCK;

  colorSpot[17].colorPosition.x= 12*SIZE_BLOCK;
  colorSpot[17].colorPosition.y= 17*SIZE_BLOCK;

}

void ChangeColorSpot(ColorBand colorSpot[], int number_spot,int length, int height, int pos_map[height][length]){//Modify the color of a Band

for(int i=0; i<number_spot; i++){//For each bands
    switch(i){//Depending or the band selected
	case 0://1st band
		if (pos_map[2][4] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[2][4] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 1://2nd band
		if (pos_map[2][6] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[2][6] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 2://3rd band

		if (pos_map[2][8] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[2][8] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 3://4th band

		if (pos_map[2][10] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[2][10] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}

	break;

	case 4://5th band

		if (pos_map[6][4] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[6][4] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}

	break;

	case 5://6th band
		if (pos_map[6][6] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[6][6] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}

	break;

	case 6://7th band

		if (pos_map[6][8] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[6][8] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 7://8th band

		if (pos_map[6][10] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[6][10] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 8://9th band

		if (pos_map[11][4] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[11][4] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 9://10th band

		if (pos_map[11][6] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[11][6] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 10://11th band

		if (pos_map[11][8] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[11][8] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 11://12th band

		if (pos_map[11][10] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[11][10] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 12://13th band

		if (pos_map[15][2] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[15][2] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 13://14th band

		if (pos_map[15][4] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[15][4] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 14://15th band

		if (pos_map[15][6] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[15][6] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 15://15th band

		if (pos_map[15][8] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[15][8] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

	case 16://17th band
		if (pos_map[15][10] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[15][10] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}

	break;

	case 17://18th band

		if (pos_map[15][12] == 3){//If the spot is already taken
		    colorSpot[i].color = 'R';//Set the color of the band to red
		}

		if (pos_map[15][12] == 2){//If the spot is free
		    colorSpot[i].color = 'G';//Set the color of the band to green
		}
	break;

    }
}

}


Llist* addVehicule(Llist* v, Vehicule* vehicule){//add a new vehicule into the list

    Llist* new= NULL;//Create a empty list
    new = malloc(sizeof(Llist));//allocate a single block of memory using malloc

    if (v==NULL){//If we have nothing into the list
      new->vehicule=vehicule;//put the data
      new->NXT=NULL;//the new node points to nothing (i.e. NULL)
      v=new;//Move the head to point to the new node
     }else{//Otherwise
       new->vehicule=vehicule;//put the data
       new->NXT=v;//New node point to the 1st element from the list
       v=new;//Move the head to point to the new node
     }
   return v;//return the update list

}

Llist* emptyList(Llist* v)//delete the Linked List
{
   Llist *tmp;//Create a temporary list

   while (v != NULL)//While we are not at the end of the list
    {
       tmp = v;
       v = v->NXT;
       free(tmp);//Free element of the list
    }
    return NULL;//The list is empty
}


Llist* removeVehicule(Llist* v, Vehicule* vehicule){//remove a specific vehicule from Llist

     if (v == NULL){//If the list is empty
      return NULL;
     }

     if (v->vehicule == vehicule){//If the vehicule to remove corresponds to the head
        v = v->NXT;//move the head to the second node
        return v;
     }else{//Otherwise
       Llist* current = v;//Current node
       Llist* previous= v;//previous node

        do{
          previous = current;
          current=current->NXT;//Move our current node
          if (current->vehicule == vehicule){//If we found the vehicule to remove
            current = current->NXT;//current node goes to the next node
            previous->NXT = current;//Previous node points to current node
            break;
          }
        } while(current != NULL);//Until we are not at the end of the list
      }

  return v;
}


void Initialization_Map(int height, int length, int map[height][length], char *file_name){//Fill the contents of the array regarding the file
  FILE* file = NULL;
  file = fopen(file_name, "r");//Open the file in the "read" mode
  int number;

  if (file == NULL){//If file is not open
    printf("The file doesn't exist!\n");
    fclose(file);//close the file
    exit(-1);//error
  }

  /*Put values into the multi-dimensional array*/
  for (int i=0; i<height; i++){
    for (int j=0; j<(length-1) ; j++){
        fscanf(file, "%d ", &number);//read an integer from the file
        map[i][j] = number;//add it into the array
    }
    fscanf(file, "%d\n", &number);//read the last element of the file
    map[i][length-1]=number;//add the last element into the array
  }

  fclose(file);//Close the file

}

void load_Map(SDL_Surface* screen){//Create the parking

  /*Creation of all the surfaces needed to build our parking*/
  SDL_Surface *Black = NULL, *Concrete_Vertical = NULL, *ConcreteCorner_LeftDown = NULL, *ConcreteCorner_LeftUp = NULL, *ConcreteCorner_RightDown = NULL, *ConcreteCorner_RightUp = NULL, *Concrete_Horizontal = NULL, *ConcreteStop_Down = NULL, *ConcreteStop_Up = NULL, *Corner_LeftDown = NULL, *Corner_LeftUp = NULL, *Corner_RightDown = NULL, *Corner_RightUp=NULL, *Junction_Down = NULL, *Junction_Up = NULL, *Stripe_Horizontal = NULL, *Stripe_Vertical = NULL;
  SDL_Rect Position;


  /*Load the image for the parking*/
  ConcreteCorner_LeftDown = IMG_Load("Concrete/ConcreteCorner_LeftDown.png");
  ConcreteCorner_LeftUp = IMG_Load("Concrete/ConcreteCorner_LeftUp.png");
  ConcreteCorner_RightDown=IMG_Load("Concrete/ConcreteCorner_RightDown.png");
  ConcreteCorner_RightUp = IMG_Load("Concrete/ConcreteCorner_RightUp.png");
  Concrete_Horizontal = IMG_Load("Concrete/ConcreteHorizontal.png");
  ConcreteStop_Down = IMG_Load ("Concrete/ConcreteStop_Down.png");
  ConcreteStop_Up = IMG_Load ("Concrete/ConcreteStop_Up.png");
  Concrete_Vertical = IMG_Load("Concrete/ConcreteVertical.png");
  Corner_LeftDown = IMG_Load ("Corner/Corner_LeftDown.png");
  Corner_LeftUp = IMG_Load("Corner/Corner_LeftUp.png");
  Corner_RightDown = IMG_Load("Corner/Corner_RightDown.png");
  Corner_RightUp = IMG_Load("Corner/Corner_RightUp.png");
  Junction_Down = IMG_Load ("Junction/JunctionDown.png");
  Junction_Up = IMG_Load ("Junction/JunctionUp.png");
  Stripe_Horizontal = IMG_Load("Stripe/Stripe_Horizontal.png");
  Stripe_Vertical = IMG_Load ("Stripe/Stripe_Vertical.png");
  Black = IMG_Load ("Black.png");


  int map[NB_BLOCKS_HEIGHT][NB_BLOCKS_LENGTH];//Create an array with all the information to know how the parking is structured

  Initialization_Map(NB_BLOCKS_HEIGHT,NB_BLOCKS_LENGTH, map, "create_map.txt" );//Initialise the values of the table by looking into the file

  /*Go through the array*/
  for (int i = 0; i< NB_BLOCKS_HEIGHT ; i++){
    for (int j = 0; j< NB_BLOCKS_LENGTH; j++){
        /*Initialiaze the position in pixel for specific indexes*/
        Position.x = j* SIZE_BLOCK;
        Position.y = i* SIZE_BLOCK;

        /*Depending the value from the file add into the array*/
        switch (map[i][j]){
          case CONCRETE_CORNER_LEFTDOWN:
            SDL_BlitSurface(ConcreteCorner_LeftDown, NULL, screen, &Position);//Create a CONCRETE_CORNER_LEFTDOWN Surface at this position
            break;

          case CONCRETE_CORNER_LEFTUP:
            SDL_BlitSurface(ConcreteCorner_LeftUp, NULL, screen, &Position);//Create a CONCRETE_CORNER_LEFTUP Surface at this position
            break;

          case CONCRETE_CORNER_RIGHTDOWN:
           SDL_BlitSurface(ConcreteCorner_RightDown, NULL, screen, &Position);//Create a CONCRETE_CORNER_RIGHTDOWN Surface at this position
          break;

          case CONCRETE_CORNER_RIGHTUP:
         SDL_BlitSurface(ConcreteCorner_RightUp, NULL, screen, &Position);//Create a CONCRETE_CORNER_LEFTUP Surface at this position
          break;

          case CONCRETE_HORIZONTAL:
          SDL_BlitSurface(Concrete_Horizontal, NULL, screen, &Position);//Create a CONCRETE_HORIZONTAL Surface at this position
            break;

          case CONCRETE_STOP_DOWN:
          SDL_BlitSurface(ConcreteStop_Down, NULL, screen, &Position);//Create a CONCRETE_STOP_DOWN Surface at this position
            break;

          case CONCRETE_STOP_UP:
          SDL_BlitSurface(ConcreteStop_Up, NULL, screen, &Position);//Create a CONCRETE_STOP_UP Surface at this position
            break;

          case CONCRETE_VERTICAL:
            SDL_BlitSurface(Concrete_Vertical, NULL, screen, &Position);//Create a CONCRETE_VERTICAL Surface at this position
            break;

          case CORNER_LEFTDOWN:
          SDL_BlitSurface(Corner_LeftDown, NULL, screen, &Position);//Create a CORNER_LEFTDOWN Surface at this position
            break;

          case CORNER_LEFTUP:
          SDL_BlitSurface(Corner_LeftUp, NULL, screen, &Position);//Create a CORNER_LEFTUP Surface at this position
            break;

          case CORNER_RIGHTDOWN:
          SDL_BlitSurface(Corner_RightDown, NULL, screen, &Position);//Create a CORNER_RIGHTDOWN Surface at this position
            break;

          case CORNER_RIGHTUP:
          SDL_BlitSurface(Corner_RightUp, NULL, screen, &Position);//Create a CORNER_RIGHTUP Surface at this position
            break;

          case JUNCTION_DOWN:
          SDL_BlitSurface(Junction_Down, NULL, screen, &Position);//Create a JUNCTION_DOWN Surface at this position
            break;

          case JUNCTION_UP:
          SDL_BlitSurface(Junction_Up, NULL, screen, &Position);//Create a JUNCTION_UP Surface at this position
            break;

          case STRIPE_HORIZONTAL:
          SDL_BlitSurface(Stripe_Horizontal, NULL, screen, &Position);//Create a STRIPE_HORIZONTAL Surface at this position
            break;

          case STRIPE_VERTICAL:
          SDL_BlitSurface(Stripe_Vertical, NULL, screen, &Position);//Create a STRIPE_VERTICAL Surface at this position
            break;

          case BLACK:
            SDL_BlitSurface(Black, NULL, screen, &Position);//Create a BLACK Surface at this position
            break;
         }
    }
  }

  SDL_Flip(screen);//Display the screen

  /*Free all the surfaces from the memory*/
  SDL_FreeSurface(ConcreteCorner_LeftDown);
  SDL_FreeSurface(ConcreteCorner_LeftUp);
  SDL_FreeSurface(ConcreteCorner_RightDown);
  SDL_FreeSurface(ConcreteCorner_RightUp);
  SDL_FreeSurface(Concrete_Horizontal);
  SDL_FreeSurface(ConcreteStop_Down);
  SDL_FreeSurface(ConcreteStop_Up);
  SDL_FreeSurface(Concrete_Vertical);
  SDL_FreeSurface(Corner_LeftDown);
  SDL_FreeSurface(Corner_LeftUp);
  SDL_FreeSurface(Corner_RightDown);
  SDL_FreeSurface(Corner_RightUp);
  SDL_FreeSurface(Junction_Down);
  SDL_FreeSurface(Junction_Up);
  SDL_FreeSurface(Stripe_Horizontal);
  SDL_FreeSurface(Stripe_Vertical);
  SDL_FreeSurface(Black);

}

void display_Cars(SDL_Surface* screen, Vehicule* vehicule){//Display a specific vehicule on the screen
  vehicule->positionPixel.x = (vehicule->positionTable.x)*SIZE_BLOCK;//Position x-axis (in pixel)
  vehicule->positionPixel.y = (vehicule->positionTable.y)*SIZE_BLOCK;//Position y-axis (in pixel)
  /*Display the vehicule*/
  SDL_BlitSurface(vehicule->currentVehicule, NULL, screen, &(vehicule->positionPixel));

}

void NORTH_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]){//Vehicule goes to the North
  int previous_x =0, previous_y=0;

  /*Vehicule displacement*/
  if ((vehicule->positionTable.y)>4 && (vehicule->positionTable.x) == 13){//If we have the conditions to go to the North
    vehicule->currentVehicule = vehicule->vehicule[UP];//Select the vehicule's image going to the North
    previous_x = vehicule->positionTable.x;//Previous x-axis direction (with index)
    previous_y = vehicule->positionTable.y;//Previous y-axis direction (with index)
    if (pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] != 1 && pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] != 1){//If there is no cars in front of the current vehicule
        vehicule->positionTable.y = (vehicule->positionTable.y)-1;//Current car goes to the North
        pos_map[previous_y][previous_x] = 0;//There is no vehicule where we were anymore
        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;//Now, there is a vehicule where we are
    }
  }

}

void SOUTH_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]){//Vehicule goes to the South
  int previous_x =0, previous_y=0;

  /*Vehicule displacement*/
  if ((vehicule->positionTable.y)<13 && (vehicule->positionTable.x) == 2){//If we have the conditions to go to the South
    vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the vehicule's image going to the SOUTH
    previous_x = vehicule->positionTable.x;//Previous x-axis direction (with index)
    previous_y = vehicule->positionTable.y;//Previous y-axis direction (with index)

    if (pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] != 1 && pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] != 1){//If there is no cars in front of the current vehicule
        vehicule->positionTable.y = (vehicule->positionTable.y)+1;//Current car goes to the South
        pos_map[previous_y][previous_x] = 0;//There is no vehicule where we were anymore
        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;//Now, there is a vehicule where we are
    }
  }

}

void EAST_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]){//Vehicule goes to the EAST
  int previous_x =0, previous_y=0;

  /*Vehicule displacement*/
  if ((vehicule->positionTable.x) <13 && (vehicule->positionTable.y)==13 && vehicule->state == 1 ){//If we have the conditions to go to the EAST
    vehicule->currentVehicule = vehicule->vehicule[RIGHT];//Select the vehicule's image going to the EAST
    previous_x = vehicule->positionTable.x;//Previous x-axis direction (with index)
    previous_y = vehicule->positionTable.y;//Previous y-axis direction (with index)

    if (pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+2] != 1 && pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+1] != 1){//If there is no cars in front of the current vehicule
        vehicule->positionTable.x = (vehicule->positionTable.x)+1;//Current car goes to the EAST
        pos_map[previous_y][previous_x] = 0;//There is no vehicule where we were anymore
        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;//Now, there is a vehicule where we are
    }
   }
}

void WEST_Direction (SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]){//Vehicule goes to the WEST
  int previous_x =0, previous_y=0;
  int previous_x =0, previous_y=0;

  /*vehicule displacement*/
  if ((vehicule->positionTable.x)>2 && (vehicule->positionTable.y)==4 && vehicule->state == 1){//If we have the conditions to go to the WEST
    vehicule->currentVehicule = vehicule->vehicule[LEFT];//Select the vehicule's image going to the WEST
    previous_x = vehicule->positionTable.x;//Previous x-axis direction (with index)
    previous_y = vehicule->positionTable.y;//Previous y-axis direction (with index)

    if (pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)-2] != 1 && pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)-1] != 1){//If there is no cars in front of the current vehicule
        vehicule->positionTable.x = (vehicule->positionTable.x)-1;//Current car goes to the WEST
        pos_map[previous_y][previous_x] = 0;//There is no vehicule where we were anymore
        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;//Now, there is a vehicule where we are
    }
  }

}

void EXIT_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]){//Vehicule goes to the EXIT
  int previous_x =0, previous_y=0;

  /*vehicule displacement*/
  if ((vehicule->positionTable.y)>1 && (vehicule->positionTable.x) == 13 && vehicule->state == 1){//If we have the conditions to go to the EXIT
    vehicule->currentVehicule = vehicule->vehicule[UP];//Select the vehicule's image going to the EXIT
    previous_x = vehicule->positionTable.x;//Previous x-axis direction (with index)
    previous_y = vehicule->positionTable.y;//Previous y-axis direction (with index)

    if (pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] != 1 && pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] != 1){//If there is no cars in front of the current vehicule
        vehicule->positionTable.y = (vehicule->positionTable.y)-1;//Current car goes to the EXIT
        pos_map[previous_y][previous_x] = 0;//There is no vehicule where we were anymore
        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;//Now, there is a vehicule where we are
    }
  }

}

void ENTRY_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]){//Vehicule goes to the EXIT
  int previous_x =0, previous_y=0;

  /*vehicule displacement*/
  if ((vehicule->positionTable.y)<3 && (vehicule->positionTable.x) == 2 && vehicule->state != 1){//If we have the conditions to go into the parking
    vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the vehicule's image going into the parking
    previous_x = vehicule->positionTable.x;//Previous x-axis direction (with index)
    previous_y = vehicule->positionTable.y;//Previous y-axis direction (with index)

    if (pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] != 1 && pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] != 1){//If there is no cars in front of the current vehicule
        vehicule->positionTable.y = (vehicule->positionTable.y)+1;//Current car goes into the parking
        pos_map[previous_y][previous_x] = 0;//There is no vehicule where we were anymore
        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;//Now, there is a vehicule where we are
    }
   }
}

void go_Out_Parking(SDL_Surface* screen,Vehicule* vehicule, int length, int height, int pos_map[height][length]){//Instructions to go out of the parking when the car parked

  if (vehicule->positionTable.x != 13 && vehicule->positionTable.y != 4  && vehicule->state == 1){//If the vehicule is not near the exit and already parked

    if ((vehicule->positionTable.x <13 && vehicule->positionTable.x > 2) && vehicule->positionTable.y == 4){//The vehicule need to go in the West direction
      WEST_Direction(screen, vehicule, length, height, pos_map);
    }

    if (vehicule->positionTable.x == 2 && (vehicule->positionTable.y <14 && vehicule->positionTable.y > 3)){//The vehicule need to go in the SOUTH direction
      SOUTH_Direction(screen, vehicule, length, height, pos_map);
    }

    if ((vehicule->positionTable.x <14 && vehicule->positionTable.x > 1)&& vehicule->positionTable.y == 13){//The vehicule need to go in the EAST direction
      EAST_Direction(screen, vehicule, length, height, pos_map);
    }


    if (vehicule->positionTable.x == 13 && (vehicule->positionTable.y >3 && vehicule->positionTable.y < 14)){//The vehicule need to go in the North direction
      NORTH_Direction(screen, vehicule, length, height, pos_map);
    }

  }else{//Otherwise
   if ((vehicule->positionTable.x <13 && vehicule->positionTable.x > 2) && vehicule->positionTable.y == 4){//The vehicule need to go in the West direction
      WEST_Direction(screen, vehicule, length, height, pos_map);
    }

    if (vehicule->positionTable.x == 2 && (vehicule->positionTable.y <14 && vehicule->positionTable.y > 3)){//The vehicule need to go in the South direction
      SOUTH_Direction(screen, vehicule, length, height, pos_map);
    }

    if (vehicule->positionTable.x == 13 && (vehicule->positionTable.y >4 && vehicule->positionTable.y < 14)){//The vehicule need to go in the North direction
      NORTH_Direction(screen, vehicule, length, height, pos_map);
    }

    if(vehicule->state == 1 && vehicule->positionTable.x == 13 && vehicule->positionTable.y <= 4){//The vehicule can take the exit
      EXIT_Direction(screen, vehicule, length, height, pos_map);
    }
  }
}

void Park_NORTH (SDL_Surface* screen, Vehicule* vehicule,int length, int height, int pos_map[height][length], unsigned long int tps){//Instructions to find a spot and park at this spot
  int previous_x =0, previous_y=0;
  int currentTime=0, previousTime=0;

  /*Move the car to have the good position*/
  previous_x = vehicule->positionTable.x;
  previous_y = vehicule->positionTable.y;
  pos_map[previous_y][previous_x] = 0;//Where the vehicule was
  pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;//Where the vehicule is

  if (vehicule->positionTable.x >2 && vehicule->positionTable.y ==4 && vehicule->state !=1 && vehicule->find_place != 1){//If we are not at the end of the road and the car didn't park yet
    previous_x = vehicule->positionTable.x;
    previous_y = vehicule->positionTable.y;

    vehicule->currentVehicule = vehicule->vehicule[LEFT];//Select the image of the vehicule going to the WEST

    if (pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] == 2 || pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] == 2){//if the car can park up or down
        previous_y = vehicule->positionTable.y;
        previous_x = vehicule->positionTable.x;
        int random = generer_boundary(0,4);//Generate a random variable to decide if the vehicule should park or not (if the spot is free)

        if(random == 2 || random == 1){//If the vehicule wants to park
            if (pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] == 2 && random == 1){//Can park up
                if(vehicule->positionTable.y != 3 && vehicule->positionTable.y == 4){//Moving to park
                    vehicule->currentVehicule = vehicule->vehicule[UP];//Select the image of the vehicule going to the NORTH
                    vehicule->positionTable.y = (vehicule->positionTable.y)-1;//Go to the North
                    pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                    pos_map[previous_y][previous_x]=0;
                    previous_y = vehicule->positionTable.y;
                    vehicule->find_place = 1;//find where to park
                }
            }else{///can park down
                if (pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] == 2 && random == 2){//Can park down
                    if(vehicule->positionTable.y != 5 && vehicule->positionTable.y == 4){//Moving to park
                        vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the image of the vehicule going to the SOUTH
                        vehicule->positionTable.y = (vehicule->positionTable.y)+1;//Go to the SOUTH
                        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                        pos_map[previous_y][previous_x]=0;
                        previous_y = vehicule->positionTable.y;
                        vehicule->find_place = 1;//find where to park
                    }
                }
            }
        }else{//If the vehicule doesn't want to park
                if ( pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+2] != 1 &&  pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+1] != 1){//If there is no car in front of the current one
                    vehicule->currentVehicule = vehicule->vehicule[LEFT];//Select the image of the vehicule going to the WEST
                    vehicule->positionTable.x = (vehicule->positionTable.x)-1;//Go to the WEST
                    pos_map[previous_y][previous_x]= 0;
                    pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                }

        }
    }else{//If the car can't park because the place is already taken
        if ( pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+2] != 1 && pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+1] != 1){//If there is no car in front of the current one
            vehicule->currentVehicule = vehicule->vehicule[LEFT];//Select the image of the vehicule going to the WEST
            vehicule->positionTable.x = (vehicule->positionTable.x)-1;//Go to the WEST
            pos_map[previous_y][previous_x]= 0;
            pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
    	  }
    }
  }else{//If we are at the end of the road the car already park or y!=4
       if(vehicule->find_place == 1 && vehicule->state != 1 && vehicule->positionTable.x>2 && vehicule->positionTable.y != 4){//If we find the place, we are in position to park but didn't park yet
          	/*The car is going to park*/
            if(vehicule->positionTable.x >2 && vehicule->positionTable.y <4 && vehicule->state !=1){//park up
                    if (pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] == 2 || pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] == 2 || (pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] == 4 && pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] == 3)){//If the car is not park yet or is park
                            if ((vehicule->positionTable.y) > 1 && (vehicule->positionTable.y) != 4 && vehicule->current_tps < vehicule->tps ){//Going to park up
                                    vehicule->currentVehicule = vehicule->vehicule[UP];//Select the image of the vehicule going to the NORTH
                                    pos_map[previous_y][previous_x]= 3;//The spot is taken
                                    vehicule->positionTable.y = (vehicule->positionTable.y)-1;
                                    pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=3;
                                    previous_y = vehicule->positionTable.y;
                            }

                            if (vehicule->current_tps >= vehicule->tps){//If the car stayed enough time
                                    previous_y = vehicule->positionTable.y;
                                    if(vehicule->positionTable.y < 4 && vehicule->positionTable.y != 3 && pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] != 1 ){//Going to leave if there is no car behind
                                        vehicule->currentVehicule = vehicule->vehicule[UP];//Select the image of the vehicule to go back
                                        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=2;//The spot is free
                                        vehicule->positionTable.y = (vehicule->positionTable.y)+1;
              		  	             }

                                    if (vehicule->positionTable.y != 4 && vehicule->positionTable.y==3 && vehicule->state !=1 ){//Trying to go out parking spot
                                            vehicule->currentVehicule = vehicule->vehicule[UP];//Select the image of the vehicule going to go back
                                            previous_x= vehicule->positionTable.x;
                                            previous_y=vehicule->positionTable.y;
                                            pos_map[previous_y][previous_x]=1;

                                            if (pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] != 1){//If the car can leave without having an accident with another car
                                                vehicule->positionTable.y = (vehicule->positionTable.y)+1;//Go to the SOUTH to leave the spot
                                                pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;//The spot is free
                                                pos_map[previous_y][previous_x]=0;
                                                previous_y = vehicule->positionTable.y;
                    		                 }
                	                }else{
                                            if(vehicule->positionTable.y == 4 && vehicule->state != 1){//If leave the spot
                                                vehicule->state = 1;//We can indicate that the car was parked and now it has to leave the parking
                                            }
                                    }
                            }else{//Not yet the time to go out of the parking spot
                                    vehicule->current_tps = vehicule->current_tps + 1;//Incremment current time spend in the parking spot
                            }

                            if(vehicule->find_place == 1 && vehicule->state != 1 && vehicule->positionTable.x>2 && vehicule->positionTable.y == 4 ){
                                    vehicule->state = 1;
                            }
              }
        }else{//park down
                if(vehicule->positionTable.x >2 && vehicule->positionTable.y >4 && vehicule->state !=1){//park down
                        if (pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] == 2 || pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] == 2 || (pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] == 4 && pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] == 3)){//If the car is not park yet or is park
                            if ((vehicule->positionTable.y) < 6 && (vehicule->positionTable.y) != 4 && vehicule->current_tps < vehicule->tps ){//Going to park(down)
                                    vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the image of the vehicule going to the NORTH
                                    pos_map[previous_y][previous_x]= 3;
                                    vehicule->positionTable.y = (vehicule->positionTable.y)+1;//Go to the North
                                    pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=3;//The spot is taken
                                    previous_y = vehicule->positionTable.y;
                            }

                            if (vehicule->current_tps == vehicule->tps){//If the car stayed enough time
                                    previous_y = vehicule->positionTable.y;
                                    if(vehicule->positionTable.y > 5 && vehicule->positionTable.y != 5 && pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] != 1){//Going to leave
                                        vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the image of the vehicule going to back
                                        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=2;//The spot is free
                                        vehicule->positionTable.y = (vehicule->positionTable.y)-1;
                                    }

                                    if (vehicule->positionTable.y != 4 && vehicule->positionTable.y==5 && vehicule->state !=1 ){//Trying to go out parking spot
                                            previous_x= vehicule->positionTable.x;
                                            previous_y=vehicule->positionTable.y;
                                            pos_map[previous_y][previous_x]=1;
                                            vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the image of the vehicule going back

                                            if (pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] != 1){//If the car can leave without having an accident with another car
                                                vehicule->positionTable.y = (vehicule->positionTable.y)-1;//Leave the spot
                                                pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                                                pos_map[previous_y][previous_x]=0;
                                                previous_y = vehicule->positionTable.y;
                                            }
                                    }else{
                                            if(vehicule->positionTable.y == 4 && vehicule->state != 1){//If leave the spot
                                                vehicule->state = 1;//We can indicate that the car was parked and now it has to leave the parking
                                            }
                                    }
                            }else{//Not yet the time to go out of the parking spot
                                    vehicule->current_tps = vehicule->current_tps + 1;//Incremment current time spend in the parking spot
                            }

                            if(vehicule->find_place == 1 && vehicule->state != 1 && vehicule->positionTable.x>2 && vehicule->positionTable.y == 4 ){
                                    vehicule->state = 1;
                            }


                        }
                    }

	   }
	}
  }
}

void Park_SOUTH (SDL_Surface* screen, Vehicule* vehicule,int length, int height, int pos_map[height][length], unsigned long int tps){//Instructions to find a spot and park at this spot
    int previous_x =0, previous_y=0;
    int currentTime=0, previousTime=0;

  /*Move the car to have the good position*/
  previous_x = vehicule->positionTable.x;
  previous_y = vehicule->positionTable.y;
  pos_map[previous_y][previous_x] = 0;
  pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;

  if (vehicule->positionTable.x <13 && vehicule->positionTable.y ==13 && vehicule->state !=1 && vehicule->find_place != 1){//If we are not at the end of the road and the car didn't park yet
    previous_x = vehicule->positionTable.x;
    previous_y = vehicule->positionTable.y;

    vehicule->currentVehicule = vehicule->vehicule[RIGHT];//Select the image of the vehicule going to the EAST

    if (pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] == 2 || pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] == 2){//if the car can park up or down
        previous_y = vehicule->positionTable.y;
        previous_x = vehicule->positionTable.x;
        int random = generer_boundary(0,4);//Generate a random variable to decide if the vehicule should park or not (if the spot is free)


        if(random == 2 || random ==1){//If the car wants to park
                if (pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] == 2 && random == 1){//Can park up
                    if(vehicule->positionTable.y != 12 && vehicule->positionTable.y == 13){//Moving to park
                        vehicule->currentVehicule = vehicule->vehicule[UP];//Select the image going to the NORTH
                        vehicule->positionTable.y = (vehicule->positionTable.y)-1;//Go up
                        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                        pos_map[previous_y][previous_x]=0;
                        previous_y = vehicule->positionTable.y;
                        vehicule->find_place = 1;//find where to park
	                 }
                }else{///can park down
                    if (pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] == 2 && random == 2){//Can park down
                            if(vehicule->positionTable.y != 14 && vehicule->positionTable.y == 13){//Moving to park
                                    vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the image going to the SOUTH
                                    vehicule->positionTable.y = (vehicule->positionTable.y)+1;//Go down
                                    pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                                    pos_map[previous_y][previous_x]=0;
                                    previous_y = vehicule->positionTable.y;
                                    vehicule->find_place = 1;//find where to park
                            }
                    }
                }
        }else{
                if (pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+1] != 1 && pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+2] != 1){//If there is no car in front of the current one
                        //We move the car
                        vehicule->currentVehicule = vehicule->vehicule[RIGHT];//Select the image to going to the EAST
                        vehicule->positionTable.x = (vehicule->positionTable.x)+1;//Moving to the RIGHT
                        pos_map[previous_y][previous_x]= 0;
                        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                }
        }
    }else{//If the car can't park because the place is already taken
        if (pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+1] != 1 && pos_map[vehicule->positionTable.y][(vehicule->positionTable.x)+2] != 1){//If there is no car in front of the current one
            //We move the car
            vehicule->currentVehicule = vehicule->vehicule[RIGHT];//Select the image to going to the EAST
            vehicule->positionTable.x = (vehicule->positionTable.x)+1;//Moving to the RIGHT
            pos_map[previous_y][previous_x]= 0;
            pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
        }
    }
  }else{//If we are at the end of the road the car already park or y!=4
       if(vehicule->find_place == 1 && vehicule->state != 1 && vehicule->positionTable.x<13 && vehicule->positionTable.y != 13 ){//If we find the place but didn't park yet
          	/*The car is going to park*/
            if(vehicule->positionTable.x <13 && vehicule->positionTable.y <13 && vehicule->state !=1){//park up
                if (pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] == 2 || pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] == 2 || (pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] == 4 && pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] == 3)){//If the car is not park yet or is park
                    if ((vehicule->positionTable.y) > 10 && (vehicule->positionTable.y) != 13 && vehicule->current_tps < vehicule->tps ){//Going to park(up)
                        vehicule->currentVehicule = vehicule->vehicule[UP];//Select the image to go to the NORTH
                        pos_map[previous_y][previous_x]= 3;
                        vehicule->positionTable.y = (vehicule->positionTable.y)-1;//Go up to park
                        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=3;//the place is taken
                        previous_y = vehicule->positionTable.y;

                    }

                   if (vehicule->current_tps >= vehicule->tps){//If the car stayed enough time
                        previous_y = vehicule->positionTable.y;
                        if(vehicule->positionTable.y < 13 && vehicule->positionTable.y != 12 && pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] != 1){//Going to leave
                                vehicule->currentVehicule = vehicule->vehicule[UP];//Select the image to go back
                                pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=2;//The spot is free
                                vehicule->positionTable.y = (vehicule->positionTable.y)+1;
              		    }

                        if (vehicule->positionTable.y != 13 && vehicule->positionTable.y==12 && vehicule->state !=1 ){//Trying to go out parking spot
                    		previous_x= vehicule->positionTable.x;
                    		previous_y=vehicule->positionTable.y;
                    		pos_map[previous_y][previous_x]=1;
                            vehicule->currentVehicule = vehicule->vehicule[UP];//Select the image to go back

                    		if (pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] != 1){//If the car can leave without having an accident with another car
                        		vehicule->positionTable.y = (vehicule->positionTable.y)+1;//The car go out parking spot
                        		pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                        		pos_map[previous_y][previous_x]=0;
                        		previous_y = vehicule->positionTable.y;
                    		}
                	   }else{
                            if(vehicule->positionTable.y == 13 && vehicule->state != 1){//If the vehicule just go out of the spot
                                vehicule->state = 1;//Indicate that the vehicule parked and now need to go to the exit
                            }
                        }
         	      }else{//Not yet the time to go out of the parking spot
                        vehicule->current_tps = vehicule->current_tps + 1;//Increment the current time spend in the parking spot
                  }

                  if(vehicule->find_place == 1 && vehicule->state != 1 && vehicule->positionTable.x<13 && vehicule->positionTable.y == 13 ){
                        vehicule->state = 1;
                  }
                }
            }else{//park down
                    if(vehicule->positionTable.x <13 && vehicule->positionTable.y >13 && vehicule->state !=1){//park down
                            if (pos_map[(vehicule->positionTable.y)+2][vehicule->positionTable.x] == 2 || pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] == 2 || (pos_map[(vehicule->positionTable.y)+1][vehicule->positionTable.x] == 4 && pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] == 3)){//If the car is not park yet or is park
                                if ((vehicule->positionTable.y) < 16 && (vehicule->positionTable.y) != 13 && vehicule->current_tps < vehicule->tps ){//Going to park(down)
                                        vehicule->currentVehicule = vehicule->vehicule[DOWN];
                                        pos_map[previous_y][previous_x]= 3;
                                        vehicule->positionTable.y = (vehicule->positionTable.y)+1;
                                        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=3;
                                        previous_y = vehicule->positionTable.y;
                                }

                                if (vehicule->current_tps == vehicule->tps){//If the car stayed enough time
                                        previous_y = vehicule->positionTable.y;

                                        if(vehicule->positionTable.y > 13 && vehicule->positionTable.y != 14 && pos_map[(vehicule->positionTable.y)-2][vehicule->positionTable.x] != 1){//Going to leave
                                                vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the image of the car to go out spot
                                                pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=2;//the spot is free
                                                vehicule->positionTable.y = (vehicule->positionTable.y)-1;
                                        }

                                        if (vehicule->positionTable.y != 13 && vehicule->positionTable.y==14 && vehicule->state !=1 ){//Trying to go out parking spot
                                                previous_x= vehicule->positionTable.x;
                                                previous_y=vehicule->positionTable.y;
                                                pos_map[previous_y][previous_x]=1;
                                                vehicule->currentVehicule = vehicule->vehicule[DOWN];//Select the image of the car to go out spot

                                                if (pos_map[(vehicule->positionTable.y)-1][vehicule->positionTable.x] != 1){//If the car can leave without having an accident with another car
                                                        vehicule->positionTable.y = (vehicule->positionTable.y)-1;//Go out spot
                                                        pos_map[vehicule->positionTable.y][vehicule->positionTable.x]=1;
                                                        pos_map[previous_y][previous_x]=0;
                                                        previous_y = vehicule->positionTable.y;
                                                }
                                        }else{
                                                if(vehicule->positionTable.y == 13 && vehicule->state != 1){//If the vehicule just go out parking spot
                                                    vehicule->state = 1;//Need to indicate that the vehicule already parked and now need to go to the exit
                                                }
                                        }
                                }else{//Not yet the time to go out of the parking spot
                                    vehicule->current_tps = vehicule->current_tps + 1;//Incremment current time spend in the parking spot
                                }

                                if(vehicule->find_place == 1 && vehicule->state != 1 && vehicule->positionTable.x<13 && vehicule->positionTable.y == 13 ){
                                    vehicule->state = 1;
                                }
                            }
                        }
                    }
        }
  }
}

void SearchParkingSpace(SDL_Surface* screen, Vehicule* vehicule,int length, int height, int pos_map[height][length], unsigned long int tps){//Insctructions for the vehicule to find a spot

  SDL_Event event;

  ENTRY_Direction(screen, vehicule, length, height, pos_map);//The vehicule is going into the parking

  if(vehicule->state !=1){//If the vehicule didn't park yet (i.e. still looking for a spot)
      SOUTH_Direction(screen, vehicule, length, height, pos_map);//Go to the South Direction

      Park_SOUTH(screen, vehicule, length, height, pos_map,tps);//Try to park in the south area of the parking

      NORTH_Direction(screen, vehicule, length, height, pos_map);//Go to the North didn't find a spot

      Park_NORTH(screen, vehicule, length, height, pos_map,tps);//Try to park in the north area of the parking

  }else{//If the vehicule already parked
        go_Out_Parking(screen, vehicule, length, height, pos_map);//The vehicule is going out of the parking
  }
}

Vehicule*  CreateVehicule (){//Create and initialize a vehicule
  Vehicule* vehicule_tmp = malloc(sizeof(Vehicule));//Create a vehicule
  int type_car=0;

  /*Initialization*/
  vehicule_tmp->positionTable.x =2;//x-axis where the car need to start (with index)
  vehicule_tmp->positionTable.y= 1;//y-axis where the car need to start (with index)
  vehicule_tmp->positionPixel.x=(vehicule_tmp->positionTable.x)*SIZE_BLOCK;//x-axis where the car need to start (with pixel)
  vehicule_tmp->positionPixel.y=(vehicule_tmp->positionTable.y)*SIZE_BLOCK;//y-axis where the car need to start (with pixel)

  vehicule_tmp->state = 0;//The car didn't park yet
  type_car=generer_boundary(1,5);//Choose the type of car randomly

  switch (type_car){//Depending of the car of the car, Initialize images in different direction
    case 1:
        vehicule_tmp->vehicule[DOWN] =IMG_Load("car_1/South.png");
        vehicule_tmp->vehicule[UP] =IMG_Load("car_1/North.png");
        vehicule_tmp->vehicule[LEFT] =IMG_Load("car_1/West.png");
        vehicule_tmp->vehicule[RIGHT] =IMG_Load("car_1/East.png");
      break;

    case 2:
        vehicule_tmp->vehicule[DOWN] =IMG_Load("car_2/South.png");
        vehicule_tmp->vehicule[UP] =IMG_Load("car_2/North.png");
        vehicule_tmp->vehicule[LEFT] =IMG_Load("car_2/West.png");
        vehicule_tmp->vehicule[RIGHT] =IMG_Load("car_2/East.png");
      break;

    case 3:
        vehicule_tmp->vehicule[DOWN] =IMG_Load("car_3/South.png");
        vehicule_tmp->vehicule[UP] =IMG_Load("car_3/North.png");
        vehicule_tmp->vehicule[LEFT] =IMG_Load("car_3/West.png");
        vehicule_tmp->vehicule[RIGHT] =IMG_Load("car_3/East.png");
      break;

    case 4:
        vehicule_tmp->vehicule[DOWN] =IMG_Load("car_4/South.png");
        vehicule_tmp->vehicule[UP] =IMG_Load("car_4/North.png");
        vehicule_tmp->vehicule[LEFT] =IMG_Load("car_4/West.png");
        vehicule_tmp->vehicule[RIGHT] =IMG_Load("car_4/East.png");
      break;

    case 5:
        vehicule_tmp->vehicule[DOWN] =IMG_Load("car_5/South.png");
        vehicule_tmp->vehicule[UP] =IMG_Load("car_5/North.png");
        vehicule_tmp->vehicule[LEFT] =IMG_Load("car_5/West.png");
        vehicule_tmp->vehicule[RIGHT] =IMG_Load("car_5/East.png");
      break;

    default:
      printf("ERROR: we need to obtain a number between 1 and 4\n");
      break;
  }

  vehicule_tmp->currentVehicule = vehicule_tmp->vehicule[DOWN];//The car is going to the North
  vehicule_tmp->tps = generer_boundary(30, 80);//Choose randomly between two values how long the vehicule is going to park
  vehicule_tmp->current_tps = 0;//current time spend in the parking
  vehicule_tmp->find_place=0;//Didn't find a spot where to park

  return vehicule_tmp;

}
