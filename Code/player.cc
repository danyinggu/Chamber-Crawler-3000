//
//  2.m
//  cell
//
//  Created by YU Zhuoran on 2015-07-20.
//  Copyright (c)

#include <iostream>
#include <string>
#include <cmath>
#include "player.h"
#include "enemy.h"
#include "dwarf.h"
#include "item.h"
#include "potion.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Player::Player(){comp = NULL;}

int Player::getmaxHP(){}

int Player::getAtk(){
}
string Player::getName() {

}

int Player::getDef() {
}

Player* Player::getComp(){
	return NULL;
}

int Player::getHP() {
}


int Player::getGold() {
}

int Player::getX(){
}

int Player::getY(){
}

void Player::move(int newx, int newy){
}

void Player::setCoords(int newx, int newy){
}

void Player::useItem(Item* item){
}


void Player::attack(Enemy* e){
}


void Player::beAttacked(Enemy* e){
}


void Player::changeGold(int val) {
}

void Player::setRoom(int r) {
}

int Player::getRoom() {
}

