#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#pragma comment(lib, "SDL3")

//C++ console entry -> iOS, Window, Linux
//int main(int argc, char* argv[])
//{
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	SDL_Window* MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);
	
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);
	
	SDL_Event MyEvent;
	
	bool bIsRunning = true;
	while(bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			if (MyEvent.type == SDL_EVENT_QUIT)
			{
				bIsRunning = false;
			}
		}
		else
		{
			//command queue
			SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
			SDL_RenderClear(MyRenderer);

			//int Radius = 100;
			//for(int j = 0;j<100;j++)
			{
				SDL_SetRenderDrawColor(MyRenderer, SDL_rand(256), SDL_rand(256), SDL_rand(256), 0);

				//int Radius = SDL_rand(110) + 10;
				//int CenterX = SDL_rand(160) + 160;
				//int CenterY = SDL_rand(120) + 120;
				//for (int Degree = 0; Degree <= 360; Degree++)
				//{
				//	int CircleX = SDL_cos((float)Degree * SDL_PI_F / 180.0f) * Radius + CenterX;
				//	int CircleY = SDL_sin((float)Degree * SDL_PI_F / 180.0f) * Radius + CenterY;
				//	SDL_RenderPoint(MyRenderer, CircleX, CircleY);
				//}

				float Radius = 200.0f;
				float CenterX = 320.0f;
				float CenterY = 240.0f;
				for (int Degree = 20; Degree <= 360; Degree += 20)
				{
					float OldCircleX = (float)SDL_cos((float)(Degree - 20) * SDL_PI_F / 180.0f) * Radius + CenterX;
					float OldCircleY = (float)SDL_sin((float)(Degree - 20) * SDL_PI_F / 180.0f) * Radius + CenterY;

					float CircleX = (float)SDL_cos((float)Degree * SDL_PI_F / 180.0f) * Radius + CenterX;
					float CircleY = (float)SDL_sin((float)Degree * SDL_PI_F / 180.0f) * Radius + CenterY;
					//언리얼 Sphere 표현 방식
					SDL_RenderLine(MyRenderer, OldCircleX, OldCircleY, CircleX, CircleY);
				}

				//for (float i = 0; i < 360; i += 0.1f)
				//{
				//	float CircleX = (SDL_cos(i) * Radius) + CenterX;
				//	float CircleY = (SDL_sin(i) * Radius) + CenterY;
				//	SDL_RenderPoint(MyRenderer, CircleX, CircleY);
				//}

			}
			
			SDL_RenderPresent(MyRenderer);
		}
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);
	
	SDL_Quit();
	return 0;
}