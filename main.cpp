#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <stdio.h>
#include <vector>
#include <iostream>

typedef int i;
typedef double d;

using namespace std;
struct snake
{
    snake(i a) : W(a){}
    i W;
    SDL_Rect rc = {25,25,10,10};
    vector<vector<i>> b = {{25,25}};
       
    void move(i dir[2], i SH, i SW, bool a)
    {
        if (a) b.push_back({0,0});
        //if (((dir[0] + b.at(0).at(0)) % 5 == 0) || ((dir[1] + b.at(0).at(1)) % 11 == 0) || true)
       // {
        for (i e = b.size() - 1; e > 0; e--)b.at(e) = b.at(e - 1);
        if (b.at(0).at(0) + dir[0] > 5 && b.at(0).at(0) + dir[0] < SH - W) b.at(0).at(0) += dir[0];
        if (b.at(0).at(1) + dir[1] > 5 && b.at(0).at(1) + dir[1] < SW - W) b.at(0).at(1) += dir[1];
        //}
    }
    void render(SDL_Renderer *rend)
    {
        SDL_SetRenderDrawColor(rend, 0xFF, 0x00, 0xFF, 0xFF );
        for(i e = 0; e < b.size(); e++)
        {
            rc.x = b.at(e).at(0), rc.y = b.at(e).at(1) ;
            SDL_RenderFillRect(rend,&rc);
        }
    }

}; 
int main(int argc, char* argv[])
{
    i s = 10;
    bool a = true;
    bool eat = true;
    i SW = 480, SH = 640;
    i Dir[2] = {0,0};

    SDL_Window *wind;
    SDL_Renderer *rend;

    snake sn = snake(++s);

    wind = SDL_CreateWindow("An SDL2 window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SH,SW,SDL_WINDOW_OPENGL);
    rend = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED );
    while(a)
    {
        SDL_Event e;
        
        //Handle events on queue 
        while( SDL_PollEvent( &e ) != 0 ) 
        { 
            if( e.type == SDL_QUIT ) a = false;  
            if( e.type == SDL_KEYDOWN ) 
            { 
                switch( e.key.keysym.sym ) 
                { 
                    case SDLK_UP: Dir[0] = 0, Dir[1] = -s; break; 
                    case SDLK_DOWN:  Dir[0] = 0, Dir[1] = s; break; 
                    case SDLK_LEFT:  Dir[0] = -s, Dir[1] = 0; break; 
                    case SDLK_RIGHT:  Dir[0] = s, Dir[1] = 0; break; 
                    default:  Dir[0] = 0, Dir[1] = 0; break; 
                } 
            } 
        }

        SDL_SetRenderDrawColor(rend, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderClear(rend);
        sn.move(Dir, SH, SW, eat);
        sn.render(rend);
        SDL_RenderPresent(rend);
        SDL_Delay(40);
    }
    SDL_Quit();
    return 0;

}