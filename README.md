# Parking_Simulator

## Introduction
This project is an Parking Simulator in C using the SDL librairy. It was developped in 2019 for a Linux environnement (here Ubuntu). There is two modes (choose randomly) which are the Fuild and the Full mode. Depending on the mode, the number of cars is in the parking evolves (more cars in the full mode than the Ffuid mode).

## Getting Started
1. Download the [master branch](https://github.com/SilverDove/Parking_Simulator.git
2. Install the different librairies by executing the following commands:
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install libsdl1.2-dev
sudo apt-get install libsdl-ttf2.0-dev
sudo apt-get install libsdl-image1.2-dev
3. Execute the command "makefile all" to do the compilation process and then write the command "./main" to start the programm.


## Features

### Must Have
* Different cars
* Implements the two modes : Full and Fluid modes
* Parking spots changing colors (red if the spot is already taken, red if it's free) 
* Implement one main entrance and one exit
* Each cars must pay when leaving the parking

### What I implemented
* Two screens: 
    * Home page: Page giving information about the project (team members, etc...). Must press 'S' to start the simulation
    * Parking: cars are chosing randomly a sport in the parking. They leave it when they want.
* Copyright


 ## Overview

## Home Page
To start the simulation, the user should press the button S.

![](https://github.com/SilverDove/Parking_Simulator/blob/main/Screen/%C3%A9cran-d'accueil.png)

Radomly, two modes will be chosen: Full mode and Fuild mode


### Displacement of cars
Fluid Mode

![](https://github.com/SilverDove/Parking_Simulator/blob/main/Screen/%5BFUILD%20MODE%5D%20Nouvelle%20voiture.png)

Full Mode

![](https://github.com/SilverDove/Parking_Simulator/blob/main/Screen/%5BFULL%20MODE%5D%20D%C3%A9placements.png)

### New cars
Fluid Mode

![](https://github.com/SilverDove/Parking_Simulator/blob/main/Screen/%5BFUILD%20MODE%5D%20Nouvelle%20voiture.png)

Full Mode

![](https://github.com/SilverDove/Parking_Simulator/blob/main/Screen/%5BFULL%20MODE%5D%20Nouvelle%20voiture.png)

### Payement
Fluid Mode

![](https://github.com/SilverDove/Parking_Simulator/blob/main/Screen/%5BFUILD%20MODE%5D%20Payements.png)

Full Mode

![](https://github.com/SilverDove/Parking_Simulator/blob/main/Screen/%5BFULL%20MODE%5D%20Payement.png)

## Authors
  * **Clara Tricot** - *Parking_Simulator* - [SilverDove](https://github.com/SilverDove)
  * **Metagang Tabou** - *Parking_Simulator* - [TMetagang](https://github.com/TMetagang)
 
 ## License
 This project is licensed under the MIT license.

 Copyright (c) 2019 Clara Tricot
