
#ifndef ELEMENTS_H_
#define ELEMENTS_H_
#include "character.h"


//Personaje de agua
//-----------------------------------------------------------------------------------------
class WaterC : public Character{
	private:
		int feedCount;
	public:
		//POS: alimenta al personaje haciendo que recupere energia
		// y devuelve la cantidad de energia que recupero
		int feed();
		//POS: devuelve el elemento
		string getElement();
		//PRE: change es el cambio que hubo despues de alimentarse
		//POS: muestra la energia despues de alimentarse
		void showFeedChange(int change);
		WaterC();
};

//Personaje de tierra
//-----------------------------------------------------------------------------------------
class EarthC : public Character{
	public:
		//POS: alimenta al personaje haciendo que recupere energia
		// y devuelve la cantidad de energia que recupero
		int feed();
		//POS: devuelve el elemento
		string getElement();
		//PRE: change es el cambio que hubo despues de alimentarse
		//POS: muestra la energia despues de alimentarse
		void showFeedChange(int change);
};

//Personaje de fuego
//-----------------------------------------------------------------------------------------
class FireC : public Character{
	public:
		//POS: alimenta al personaje haciendo que recupere vida
		// y devuelve la vida que recupero
		int feed();
		//POS: devuelve el elemento
		string getElement();
		//PRE: change es el cambio que hubo despues de alimentarse
		//POS: muestra la vida despues de alimentarse
		void showFeedChange(int change);
};

//Personaje de aire
//-----------------------------------------------------------------------------------------
class AirC : public Character{
	public:
		//returns 0
		int feed();
		//POS: devuelve el elemento
		string getElement();
		//PRE: change debe ser 0
		//POS: informa al usuario que no se puede alimentar a un personaje de aire
		void showFeedChange(int change);
};




#endif /* ELEMENTS_H_ */
