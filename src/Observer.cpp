/*
 * Copyright (C) 2014 Luca Sciullo
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include<string>
#include<cstring>
#include<sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Observer.h"
#include "Shot.h"

using namespace std;

#define X_FIRING ((shot->pos.x + shot->width) > ast->pos.x - ast->width/2) && (shot->pos.x < ast->pos.x + ast->width/2)
#define Y_FIRING ((shot->pos.y + shot->height) > ast->pos.y - ast->height/2) && (shot->pos.y < ast->pos.y + ast->height/2)
#define SHOT_DEAD shot->died

#define X_COLLISION (ast->pos.x - ast->width/2) < (ship->pos.x + ship->width/2) && (ast->pos.x + ast->width/2) > (ship->pos.x - ship->width/2)
#define Y_COLLISION (ast->pos.y - ast->height/2) < (ship->pos.y + ship->height/2) && (ast->pos.y + ast->height/2) > (ship->pos.y - ship->height/2)
#define SHIP_DEAD ship->died

void
Observer::manage_deaths(){

	int i, y;
	std::vector<Shot *> *shots;
	Spaceship *ship;	
	Shot *shot;	
	Asteroid *ast;	
	for(i = 0; i < (int)ships->size(); i++) {
		shots = &((*ships)[i]->shots);
		for(y = 0; y < (int)shots->size(); y++) {
			//if the shot has to be deleted..
			if((*shots)[y]->died) {
				//delete shot
				shot = (*shots)[y];
				delete shot;
				(*shots).erase((*shots).begin() + y);
				shot = NULL;
				y--;
			}
		}
		if((*ships)[i]->died) {
			(*Blines)[(*ships)[i]->pos.nLine]->ships_in_cells[(*ships)[i]->pos.ncell] = false;
			ship = (*ships)[i];
			delete ship;
			(*ships).erase((*ships).begin()+i);
			ship = NULL;
			i--;
		}
	}
	if(game->wave != NULL)
	for(i = 0; i < (int)game->wave->Asteroids.size(); i++) {
		//if the asteoroid has to be deleted..
		if(game->wave->Asteroids[i]->died) {
			if(game->wave->Asteroids[i]->win)
				game->update_score(SCORE_ASTEROIDS);
			//delete asteroid
			ast = game->wave->Asteroids[i];
			delete ast;
			game->wave->Asteroids.erase(game->wave->Asteroids.begin() + i);
			ast = NULL;
			i--;
		}
	}


}

void
Observer::check_firing(int line, std::vector<Shot *> *shots) {
	int i = 0;
	Asteroid *ast;
	Shot *shot;
	if(game->wave != NULL)
	for(i = 0; i < (int)game->wave->Asteroids.size(); i++) {
		ast = game->wave->Asteroids[i];

		if(ast->pos.nLine == line) {
			for(int y = 0; y < (int)shots->size(); y++) {
				shot = (*shots)[y];
			//need to check the firing and if the shot is still alive
				if(X_FIRING && Y_FIRING && !SHOT_DEAD) {
					shot->died = true;
					ast->died = true;
					game->update_score(SCORE_HIT);
				}
			}
		}
	}
}

void
Observer::detect_problems() {
	int i;
	Spaceship *ship;
	std::vector<Shot *> *shots;
	check_level_finished();
	for(i = 0; i < (int)ships->size(); i++) {
		shots = &((*ships)[i]->shots);
		ship = (*ships)[i];
		check_collision(ship);
		check_firing((*ships)[i]->pos.nLine, shots);
	}

}

void
Observer::check_collision(Spaceship *ship) {
	int i = 0;	
	int counter = 0;
	Asteroid *ast;
	if(game->wave != NULL)
		for(i = 0; i < (int)game->wave->Asteroids.size(); i++) {
			ast = game->wave->Asteroids[i];
			if(ast->pos.nLine == ship->pos.nLine) {
				//need to check the collision and if the ship is still alive
				if(X_COLLISION && Y_COLLISION && !SHIP_DEAD) {
					//each shot has to die together with its spaceship

					if(ship->type - 1 == -1) {
						ship->died = true;
					} else {
						ship->type--;
						ship->properties_assign();
					}
					ast->died = true;
					game->update_score(SCORE_COLLISION);
				} else if(ast->pos.x < ship->pos.x) {
					counter++;
					ship->change_shot_direction(counter);
				} else {
					ship->change_shot_direction(-1);
				}
			}
		}
}

void
Observer::check_level_finished() {
	if(game->wave != NULL) {
		if(game->wave->Asteroids.empty() && game->wave->number_asteroids == 0 && !game->game_over) {
			game->level_completed();

		}
	}
	else {
		if(game->score < SNOW_SHIP_COST  && ships->empty()) {
			game->game_over = true;
		}
	}
}
