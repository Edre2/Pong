#ifndef PADDLE_H
#define PADDLE_H

class Paddle 
{
    public:
        Paddle(int speed, int height, int width, int x, int size_y)
        {
            m_speed = speed;
            m_height = height;
            m_width= width;
            m_x = x;
            m_size_y = size_y;
            m_y = m_size_y/2 - m_height/2;
        }

        void reset()
        {
            m_y = m_size_y/2 - m_height/2;
        }

        void up()
        {
            if(m_y > m_speed)
                m_y -= m_speed;
            else
                m_y = 0;
        }
        void down()
        {
            if(m_y < m_size_y - m_speed - m_height)
                m_y += m_speed;
            else
                m_y = m_size_y - m_speed - m_height;
        }

        int x() const
        {
            return m_x;
        }
        int y() const
        {
            return m_y;
        }
        int width() const
        {
            return m_width;
        }
        int height() const
        {
            return m_height;
        }


    private:
        int m_speed;

        int m_height;
        int m_width;

        int m_x;

        int m_y;

        int m_size_y;
};


#endif