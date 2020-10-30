# Parking_Simulator
Parking Simulator in C

Install SDL
Il faut installer la librairie sdl au préalable. Pour cela il faut retrouver le bon paquet que tu peux chercher avec apt-cache. Par convention les paquets de développement sont suffixés "-dev" et préfixés lib :

apt-cache search libsdl | grep dev


Tu vas voir parmi les lignes qui apparaissent un truc du genre :

...
libsdl1.2-dev - Simple DirectMedia Layer development files
...


Donc le paquet qui nous intéresse est ici : libsdl1.2-dev. Installons le avec apt-get :

sudo apt-get update
sudo apt-get upgrade
sudo apt-get install libsdl1.2-dev

Ensuite on installe les librairies supplémentaires faisant référence à image et tff
- sudo apt-get install libsdl-ttf2.0-dev
- sudo apt-get install libsdl-image1.2-dev


Ensuite on compile avec la commande make all
puis on lacnce le programme avec la commande ./main
