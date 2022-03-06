#include <iostream>
#include <string>
#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"
#include "pong.h"

// Wnidow size
const int SIZE_X = 500;
const int SIZE_Y = 300;
const int PIX_SIZE = 2;

// Ball prameters
const double BALL_SPEED = 5;
const double SPEED_UPDATE = 1.001;
const int BALL_RADIUS = 10;

// Paddle parametres
const int PADDLE_SPEED = 5;
const int PADDLE_HEIGHT = 50;
const int PADDLE_WIDTH = 10;
const int PADDLE_X = 20;

// AI or not
const bool AI = true;


class Example : public olc::PixelGameEngine
{
	public:
		Example() : game(SIZE_X, SIZE_Y, PADDLE_HEIGHT, PADDLE_WIDTH, PADDLE_X, BALL_SPEED, PADDLE_SPEED, BALL_RADIUS, SPEED_UPDATE)
		{
			sAppName = "Pong";
            ai = AI;
            playing = true;
			
		};

	public:
		bool OnUserCreate() override
		{

			// Called once at the start, so create things here
			return true;
		};

		bool OnUserUpdate(float fElapsedTime) override
		{
            // period += fElapsedTime;
            // if(period * 100 < 60 / float(10))
			// 	return true;
            // period = 0;

            if(GetKey(olc::SPACE).bPressed)
                playing = !playing;
            
            if(playing)
            {
                Clear(olc::BLACK);

                showBall();
                showpaddles();
                showScores();

                if(!ai)
                {
                    if(GetKey(olc::UP).bHeld)
                        game.up_2();
                    if(GetKey(olc::DOWN).bHeld)
                        game.down_2();
                }
                else {
                    game.ai_2();
                }

                if(GetKey(olc::A).bHeld)
                    game.up_1();
                if(GetKey(olc::Q).bHeld)
                    game.down_1();

                game.updateBall();
            }

			return true;
		};

        void showBall()
        {
            FillCircle(game.x_ball(), game.y_ball(), 10);
        };
        void showpaddles()
        {
            FillRect(PADDLE_X, game.y_paddle_1(), PADDLE_WIDTH, PADDLE_HEIGHT);
            FillRect(SIZE_X - PADDLE_X, game.y_paddle_2(), PADDLE_WIDTH, PADDLE_HEIGHT);
        };
        void showScores()
        {
            DrawString(35, 20, "Score : " + std::to_string(game.score1()), olc::WHITE, 1);
            DrawString(SIZE_X - 100, 20, "Score : " + std::to_string(game.score2()), olc::WHITE, 1);
        };

	private:
        Pong game;
        bool ai;
        bool playing;
        // float period;
};


int main()
{
	bool fullscreen = false;
	Example demo;
	if (demo.Construct(SIZE_X, SIZE_Y, PIX_SIZE, PIX_SIZE, fullscreen, true))
		demo.Start();

	return 0;
}