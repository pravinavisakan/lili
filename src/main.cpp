//#include <SDL2/SDL.h>
//#include <iostream>
#include "../include/main.h"

int main(int argc, char *argv[]){
        

        int xPos = 512;
        int yPos = 256;
        int xSize = 1366;
        int ySize = 768;

        SDL_Window* window;
        SDL_Renderer* renderer;

        //Initialize Library
        if(SDL_Init(SDL_INIT_EVERYTHING) !=0){
                std::cout << "SDL Initialization failure: " << SDL_GetError() << std::endl;
                return -1;
        } 

        window = SDL_CreateWindow("Platformer", xPos, yPos, xSize, ySize, 0);

        if(window == nullptr){
                std::cout << "SDL Window Initialization failure: " << SDL_GetError() << std::endl;
                return -1;
        }
               
        renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

 
        if(renderer == nullptr){
                std::cout << "SDL Renderer Initialization failure: " << SDL_GetError() << std::endl;
                return -1;
        }

        //Begin Rendering
        // Set size of renderer to the same as window
        SDL_RenderSetLogicalSize( renderer, xSize, yPos);
        // Set color of renderer to red
        SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
        // Clear the window and make it all red
        SDL_RenderClear( renderer );

        bool loop = true;

        while(loop){

                //Process input
                SDL_Event event;

                while(SDL_PollEvent(&event)){

                        //exit
                        if(event.type == SDL_QUIT)
                                loop = false;

                }

                // Render the changes above ( which up until now had just happened behind the scenes )
                SDL_RenderPresent( renderer);

                SDL_Delay( 16 );
        }

        std::cout << "Game Exit!" << std::endl;
        return 0;
}
