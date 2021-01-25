
#include "elements.h"
#include<iostream>
using namespace std;


//Personaje de agua
//-----------------------------------------------------------------------------------------
WaterC::WaterC(){
	feedCount = 3;
}

string WaterC::getElement(){
	return "agua";
}

int WaterC::feed(){
	int previousE = energy;
	if(feedCount > 0){
		energy += 10;
		if(energy > 20) energy = 20;
		feedCount--;
	}
	return energy - previousE;
}

void WaterC::showFeedChange(int change){
	if(feedCount > 0){
		cout << "El personaje se alimento de plancton y recupero " << change << " puntos de energia" <<endl;
		cout << "Su energia actual es de " << energy << " puntos" <<endl;
		cout << "Este personaje puede alimentarse " << feedCount << " veces mas" <<endl;
	} else {
		cout << "El personaje no puede volver a alimentarse";
	}
}

//Personaje de tierra
//-----------------------------------------------------------------------------------------

int EarthC::feed(){
	int previousE = energy;
	energy += 8;
	if(energy > 20) energy = 20;
	return energy - previousE;
}

void EarthC::showFeedChange(int change){
	cout << "El personaje se alimento de hierbas y recupero " << change << " puntos de energia" <<endl;
	cout << "Su energia actual es de " << energy << " puntos" <<endl;
}

string EarthC::getElement(){
	return "tierra";
}


//Personaje de fuego
//-----------------------------------------------------------------------------------------

int FireC::feed(){
	int previousL = life;
	life += 15;
	if(life > 100) life = 100;
	return life - previousL;
}

void FireC::showFeedChange(int change){
	cout << "El personaje se alimento de madera y recupero " << change << " puntos de vida" <<endl;
	cout << "Su vida actual es de " << life << " puntos" <<endl;
}

string FireC::getElement(){
	return "fuego";
}

//Personaje de aire
//-----------------------------------------------------------------------------------------

int AirC::feed(){
	return 0;
}

void AirC::showFeedChange(int change){
	cout << "Los personajes de aire no pueden alimentarse" << endl;
	cout << "ya que no lo necesitan" << endl;
}

string AirC::getElement(){
	return "aire";
}



