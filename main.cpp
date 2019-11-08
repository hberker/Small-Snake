/*
    Small Snake
*/
#include <SDL2/SDL.h>
#include <vector>
#define P while
#define X return
#define F for
#define O if
typedef int i;struct s{s(i a):W(a){}i W;SDL_Rect r={W,W,W,W};std::vector<std::vector<i>>b={{W,W}};i m(i d[2], i h, i w, i a){O(a)b.push_back({0,0});F(i e=b.size()-1;e>0;e--)b.at(e)=b.at(e-1);O(b.at(0).at(0)+d[0]>5&&b.at(0).at(0)+d[0]<h-W)b.at(0).at(0)+=d[0];O(b.at(0).at(1)+d[1]>5&&b.at(0).at(1)+d[1]<w-W)b.at(0).at(1)+=d[1];}i d(){F(i e=0;e<b.size();e++)F(i a=0;a<b.size();a++)O(a!=e&&b.at(e).at(0)==b.at(a).at(0)&&b.at(e).at(1)==b.at(a).at(1))X 0;X 1;}i e(i x,i y){F(i e=0;e<b.size();e++)O(b.at(e).at(0)==x&&b.at(e).at(1)==y)X 1;X 0;}i R(SDL_Renderer*R){SDL_SetRenderDrawColor(R,255,0,255,255);F(i e=0;e<b.size();e++)r.x=b.at(e).at(0),r.y=b.at(e).at(1),SDL_SetRenderDrawColor(R,255,0,255,255),SDL_RenderFillRect(R,&r);}};i main(i c,char*v[]){i l=10,E=-1,w=480,h=640,D[2]={0,0};SDL_Window *W;SDL_Renderer *R;SDL_Event e;SDL_Rect f={0,0,10,10};s S=s(++l);W=SDL_CreateWindow("S",536805376,536805376,h,w,2);R=SDL_CreateRenderer(W,-1,2);P(S.d()&&!(e.type==256)){O(E)f.x=25+(11*(rand()%(54+1))),f.y=25+(11*(rand()%(40+1))),E=-1;P(SDL_PollEvent(&e)){O(e.type==768){i J=(e.key.keysym.sym);O(J==1073741906)D[0]=0,D[1]=-l;O(J==1073741905)D[0]=0,D[1]=l;O(J==1073741904)D[0]=-l,D[1]=0;O(J==1073741903)D[0]=l,D[1]=0;}}SDL_SetRenderDrawColor(R,0,0,0,0);SDL_RenderClear(R);E=S.e(f.x,f.y);S.m(D,h,w,E);S.R(R);SDL_RenderFillRect(R,&f);SDL_RenderPresent(R);SDL_Delay(50);}SDL_Quit();}



