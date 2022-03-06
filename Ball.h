#ifndef BALL_H
#define BALL_H

#include "paddle.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

#define PI 3.14159

class Ball 
{
    public:
        Ball(int size_x, int size_y, int speed, int radius, double speed_update)
        {
            m_size_x = size_x;
            m_size_y = size_y;

            m_speed_init = speed;
            m_speed_update = speed_update;

            m_radius = radius;

            srand(time(NULL));

            reset();
        }

        void reset()
        {
            m_x = double(m_size_x) / 2;
            m_y = double(m_size_y) / 2;

            m_direction = double(rand()) / RAND_MAX * 2 * PI;

            m_speed = m_speed_init;
        }

        bool touchedPaddle(Paddle & p)
        {
            return (m_x + m_radius >= p.x() || m_x - m_radius >= p.x()) && (m_x + m_radius <= p.x() + p.width() || m_x - m_radius <= p.x() + p.width()) && (m_y + m_radius >= p.y()) && (m_y - m_radius <= p.y() + p.height());
        }

        void update(Paddle & p1, Paddle & p2, bool & haswon1, bool & haswon2)
        {
            m_x += std::sin(m_direction) * m_speed;
            m_y -= std::cos(m_direction) * m_speed;

            // If the bal touched the wall
            if(m_y - m_radius <= 0 || m_y + m_radius >= m_size_y)
            {
                m_direction = PI - m_direction;
            }

            // If the ball touched player 1's paddle
            if(touchedPaddle(p1) || touchedPaddle(p2))
            {
                m_direction = PI + m_direction + (2*double(rand())-RAND_MAX) / RAND_MAX * 0.5;
            }

            if(m_x - m_radius <= 0)
                haswon2 = true;
            if(m_x + m_radius >= m_size_x)
                haswon1 = true;

            m_speed *= m_speed_update;
        }

        double x() const
        {
            return m_x;
        }
        double y() const
        {
            return m_y;
        }
        int radius() const
        {
            return m_radius;
        }

    private:    
        int m_size_x;
        int m_size_y;

        double m_x;
        double m_y;
        double m_direction;

        double m_speed;
        double m_speed_init;
        double m_speed_update;

        int m_radius;

};

#endif