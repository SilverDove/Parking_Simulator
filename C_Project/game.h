/* game.h : all function's prototypes use in game.c

CREATION DATE : 30/11/2019
MODIFICATION DATE: 06/12/2019
AUTHORS : TABOU Metagang and TRICOT Clara*/

#ifndef DEF_GAME
#define DEF_GAME

#include "constant.h"

int generer_boundary(int min, int max);//return a random number between min and max

void InitializeColorSpot(ColorBand colorSpot[], int number_spot);//return a random number between min and max

void ChangeColorSpot(ColorBand colorSpot[], int number_spot,int length, int height, int pos_map[height][length]);//Modify the color of a Band

Llist* addVehicule(Llist* v, Vehicule* vehicule);//add a new vehicule into the list

Llist* emptyList(Llist* v);//delete the Linked List

Llist* removeVehicule(Llist* v, Vehicule* vehicule);//remove a specific vehicule from Llist

void Initialization_Map(int height, int length, int map[height][length], char *file_name);//Fill the contents of the array regarding the file

void load_Map(SDL_Surface* screen);//Create the parking

void display_Cars(SDL_Surface* screen, Vehicule* vehicule);//Display a specific vehicule on the screen

void NORTH_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]);//Vehicule goes to the North

void SOUTH_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]);//Vehicule goes to the South

void EAST_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]);//Vehicule goes to the EAST

void WEST_Direction (SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]);//Vehicule goes to the WEST

void EXIT_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]);//Vehicule goes to the EXIT

void ENTRY_Direction(SDL_Surface* screen, Vehicule* vehicule, int length, int height, int pos_map[height][length]);//Vehicule goes to the EXIT

void go_Out_Parking(SDL_Surface* screen,Vehicule* vehicule, int length, int height, int pos_map[height][length]);//Instructions to go out of the parking when the car parked

void Park_NORTH (SDL_Surface* screen, Vehicule* vehicule,int length, int height, int pos_map[height][length], unsigned long int tps/*, SDL_Surface* ColorSpot[], int number_spot*/);

void Park_SOUTH (SDL_Surface* screen, Vehicule* vehicule,int length, int height, int pos_map[height][length], unsigned long int tps/*, SDL_Surface* ColorSpot[], int number_spot*/);

void SearchParkingSpace(SDL_Surface* screen, Vehicule* vehicule,int length, int height, int pos_map[height][length], unsigned long int tps);//Insctructions for the vehicule to find a spot

Vehicule*  CreateVehicule ();//Create and initialize a vehicule

#endif
