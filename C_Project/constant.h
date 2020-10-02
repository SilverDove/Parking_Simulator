/*constant.h : defines all constants that the program wil use

CREATION DATE : 30/10/2019
MODIFICATION DATE : 06/12/2019
AUTHORS : TABOU Metagang and TRICOT Clara
 */

#ifndef DEF_CONSTANT
#define DEF_CONSTANT

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

enum {UP,DOWN,LEFT,RIGHT};
enum {EMPTY, VEHICULE, FREE, FULL, BAN};
enum {CONCRETE_CORNER_LEFTDOWN, CONCRETE_CORNER_LEFTUP, CONCRETE_CORNER_RIGHTDOWN, CONCRETE_CORNER_RIGHTUP, CONCRETE_HORIZONTAL, CONCRETE_STOP_DOWN, CONCRETE_STOP_UP, CONCRETE_VERTICAL,CORNER_LEFTDOWN, CORNER_LEFTUP, CORNER_RIGHTDOWN, CORNER_RIGHTUP, JUNCTION_DOWN, JUNCTION_UP, STRIPE_HORIZONTAL, STRIPE_VERTICAL,BLACK};


  #define SIZE_BLOCK              55
  #define NB_BLOCKS_LENGTH        15
  #define NB_BLOCKS_HEIGHT        18
  #define WINDOW_LENGTH           (SIZE_BLOCK*NB_BLOCKS_LENGTH)+5
  #define WINDOW_HEIGHT           (SIZE_BLOCK*NB_BLOCKS_HEIGHT)+5
  #define NUMBER_SPOT             18

struct Vehicule_ {//Structure of a vehicule
  SDL_Rect positionPixel;//Position of the vehicule on the screen (with pixel)
  SDL_Rect positionTable;//Position of the vehicule into the table (with index)
  SDL_Surface *vehicule[4];//Images of the car in different directions (North, South, East and West)
  SDL_Surface *currentVehicule;//Current image of the vehicule which will be display on the screen
  char state;//Indicate whatever the vehicule parked or nor :'1' already park, '0' looking for a spot
  unsigned long int tps;//time to stay in the parking
  unsigned long int current_tps;//current time spend in the parking
  int find_place;//Indicate if the vehicule finds the place: '1'-> find and '0' -> don't find yet
};

typedef struct Vehicule_ Vehicule;

struct ColorBand_{//Band to indicate if a spot is free or not using colors
   SDL_Surface *colorSurface;//Surface
   char color;//'R'--> Red (not free)  or 'G'-->Green (free)
   SDL_Rect colorPosition;//Position of the surface
};

typedef struct ColorBand_ ColorBand;

struct Llist_{//Linked List
  Vehicule *vehicule;
  struct Llist_* NXT;//Next node
};

typedef struct Llist_ Llist;

#endif
