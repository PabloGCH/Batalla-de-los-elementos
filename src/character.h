
#ifndef CHARACTER_H_
#define CHARACTER_H_
#include<string>
using namespace std;

class Character{
	protected:
		string name;
		int shield;
		int life;
		int energy;
	public:
		//POS: alimenta al personaje y devuelve el cambio
		// producido
		virtual int feed() = 0;
		//POS: asigna newName a name
		void setName(string newName);
		//POS: asigna newShield a shield
		void setShield(int newShield);
		//POS: asigna newLife a life
		void setLife(int newLife);
		//POS: asigna newEnergy a Energy
		void setEnergy(int newEnergy);
		//POS: devuelve el nombre
		string getName();
		//POS: devuelve el escudo
		int getShield();
		//POS: devuelve la vida
		int getLife();
		//POS: devuelve la energia
		int getEnergy();
		//POS: devuelve el elemento
		virtual string getElement() = 0;
		Character();
		//destructor
		virtual ~Character();
		//PRE: change es el cambio que hubo despues de alimentarse
		//POS: muestra el cambio despues de alimentarse
		virtual void showFeedChange(int change) = 0;
};



#endif /* CHARACTER_H_ */
