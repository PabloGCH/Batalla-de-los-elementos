#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class RenderWindow{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        RenderWindow();
        // PRE:
        // POS: Devuelve la ventana
        SDL_Window* getWindow();
        // PRE: Recibe un array de caracteres que indica el path de la imagen
        // POS: Carga la imagen en una variable SDL_Texture* y la devuelve
        SDL_Texture* LoadTexture(const char* filePath);
        void clear();
        void render(SDL_Texture* texture, int fila, int columna);
        void display();
        ~RenderWindow();
};


#endif