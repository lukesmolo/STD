#STD: Spaceship Tower Defense.

STD is a version in the space of the famous game Tower Defense.<br>
There is a grid in which you can put spaceships to defense your land. Waves of
asteroids come to attack you, so you need to install a big defense in order to
keep the game going.

##How it works
Each spaceship automatically shots from the left to right, but in case a
well-known number of asteroids are on the same line behind the spaceship, this
starts to shot from right to the left.

There are three types of spaceships:
* _SNOW_ : very cheap white spaceship, very fast moving and shooting, but very weak
* _GRASS_ : green spaceship with a cost, speed, and frequency of shooting in the average. Stronger than _SNOW_ spaceship
* _BLOOD_: very expensive red spaceship, very slow moving and shooting but very hard to destroy. Very useful near the border of grid to create a defensive "wall"

Each time a spaceship is hit by an asteroid, if it is not a _SNOW_ spaceship,
it is turned in a lower type of spaceship, otherwise it is destroyed. For example a _BLOOD_ spaceship can become a _GRASS_ spaceship.

You can add only one spaceship per cell, if you can pay a well-known value with
your score.

Asteroids can move only from right to left, and if they reach the left border
score is decreased according on a well-known value.<br>
Pay attention, because if you
reach a negative score and you have not any other spaceships, you lose the
match. Otherwise, until you have some spaceships alive, you can keep going with
the game.<br>
If you kill every asteroid in a wave, you can call a next wave.

Every wave has a bigger number of asteroids, so make sure you have a great
defense!


##Keys for playing
* _p_: Game in pause
* _h_: Show help page
* _a_: Launch a new wave of asteroids
* _q_: Select spaceship _SNOW_
* _w_: Select spaceship _GRASS_
* _e_: Select spaceship _BLOOD_
* _mouse left-key_: put a ship inside a cell

##Requirements
* Linux distribution
* GLUT is required for the GUI

##GUI
A very basic GUI is used for the game. Thanks to [Guillaume
Perez](http://www.i3s.unice.fr/~gperez/) for his GLUT based library.


##Usage
Clone the repository:
```
$ git clone --recursive git@github.com:lukesmolo/STD.git
```
You can have a look at the Configuration.h file in order to set your favorite values<br>
Compile the program:
```
$ make
```
If you modify Config.h file, please clean all and compile again:
```
$ make clean
$ make
```

##Credits
__libEngine.a__, the GLUT based library used in this project for GUI, was written
by [Guillaume Perez](http://www.i3s.unice.fr/~gperez/). Very soon his code will
be available.

##License
STD is released under the GPLv2 license.



##TODO
* improve asteroids











