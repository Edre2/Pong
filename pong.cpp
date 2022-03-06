#include "pong.h"
#include "Ball.h"
#include <cstdlib>
#include <iostream>

Pong::Pong(int size_x, int size_y, int paddle_height, int paddle_width, int x_paddles, double speed_ball, int speed_paddle, int ball_radius, double speed_update) : m_left(speed_paddle, paddle_height, paddle_width, x_paddles, size_y), m_right(speed_paddle, paddle_height, paddle_width, size_x - x_paddles, size_y), m_ball(size_x, size_y, speed_ball, ball_radius, speed_update)
{
    m_size_x = size_x;
    m_size_y = size_y;

    m_haswon1 = false;
    m_haswon2 = false;

    m_score1 = 0;
    m_score2 = 0;
}

void Pong::updateBall()
{
    m_ball.update(m_left, m_right, m_haswon1, m_haswon2);
    if(m_haswon1)
    {
        m_score1++;
        reset();
        m_haswon1 = false;
    }
    if(m_haswon2)
    {
        m_score2++;
        reset();
        m_haswon2 = false;
    }

}

void Pong::reset()
{
    m_ball.reset();
    m_left.reset();
    m_right.reset();
}

void Pong::ai_2()
{
    if(m_ball.y() + m_ball.radius() < m_right.y() + m_right.height() / 2)
        m_right.up();
    else if(m_ball.y() + m_ball.radius() > m_right.y() + m_right.height()/2)
        m_right.down();
}

void Pong::up_1()
{
    m_left.up();
}
void Pong::down_1()
{
    m_left.down();
}

void Pong::up_2()
{
    m_right.up();
}
void Pong::down_2()
{
    m_right.down();
}

int Pong::y_paddle_1() const
{
    return m_left.y();
}
int Pong::y_paddle_2() const
{
    return m_right.y();
}
int Pong::x_ball() const
{
    return m_ball.x();
}
int Pong::y_ball() const
{
    return m_ball.y();
}
int Pong::score1() const
{
    return m_score1;
}
int Pong::score2() const
{
    return m_score2;
}