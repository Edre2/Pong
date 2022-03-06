#ifndef PONG_H
#define PONG_H

#include "paddle.h"
#include "Ball.h"

class Pong
{
    public:
        Pong(int size_x, int size_y, int paddle_height, int paddle_width, int m_x_paddles, double speed_ball, int speed_paddle, int ball_radius, double speed_update);

        void updateBall();
        void reset();

        void ai_2();

        void up_1();
        void down_1();
        void up_2();
        void down_2();

        int y_paddle_1() const;
        int y_paddle_2() const;
        int x_ball() const;
        int y_ball() const;
        int score1() const;
        int score2() const;

    private:
        int m_size_x;
        int m_size_y;

        Paddle m_left;
        Paddle m_right;

        Ball m_ball;

        bool m_haswon1;
        bool m_haswon2;
        int m_score1;
        int m_score2;
};

#endif