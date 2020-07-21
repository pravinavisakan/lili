#include "../include/main.h"

int main(int argc, char *argv[]){
        

        int xSize = 1366;
        int ySize = 768;

        SDL_Window* window;
        SDL_GLContext mainContext;
        //SDL_Renderer* renderer;

        //Initialize Library
        if(SDL_Init(SDL_INIT_EVERYTHING) !=0){
                std::cout << "SDL Initialization failure: " << SDL_GetError() << std::endl;
                return -1;
        } 

        //Set up window
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, xSize, ySize, SDL_WINDOW_OPENGL);

        if(window == nullptr){
                std::cout << "SDL Window Initialization failure: " << SDL_GetError() << std::endl;
                return -1;
        }
               
        //Set Up open gl context
        mainContext = SDL_GL_CreateContext(window);

        //Set GL Attributes
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetSwapInterval(1);

        #ifndef __APPLE__
	glewExperimental = GL_TRUE;
	glewInit();
	#endif 

        //renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
 
        //if(renderer == nullptr){
        //        std::cout << "SDL Renderer Initialization failure: " << SDL_GetError() << std::endl;
        //        return -1;
        //}

        //Begin Rendering
        // Set size of renderer to the same as window
        //SDL_RenderSetLogicalSize( renderer, xSize, yPos);
        // Set color of renderer to red
        //SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
        // Clear the window and make it all red
        //SDL_RenderClear( renderer );

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);

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
                //SDL_RenderPresent( renderer);

                SDL_Delay( 16 );
        }


        SDL_GL_DeleteContext(mainContext);
        SDL_DestroyWindow(window);
        SDL_Quit();

        std::cout << "Game Exit!" << std::endl;
        return 0;
}
