#include "../headers/sdlInit.h"

SdlInit::SdlInit(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "Inicializacion de video fallo: \n\n" << SDL_GetError() << endl;
    }
}

SdlInit::~SdlInit(){
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
    SDL_Quit();
}

