# Pong

This is an implementation in `c++` of the Pong game, using `OOP`, and a graphic interface made with the `olcPixelGameEngine` from @OneLoneCoder. It is provided with a little bot to play against and you can change various settings in `main.cpp`.

# Ho to use it

On GNU/Linux, you can just run `pong`.
To compile the whole roject with `g++`, you can run :
``` bash
g++ -o pong pong.cpp main.cpp -std=c++17 -lX11 -lGL -lpthread -lpng -lstdc++fs -O3 && ./pong
```

# How to play 

For the player on the right, pressing `a` and `q` will make the paddle move. \
If there is no bot, for the second player, the up and down arrow keys will make the paddle move. \
This is a regular game of pong, except that when the ball hits a paddle, its direction changes with a little bit of randomness, and the ball's speed increases while no one has scored. \
You can change basic settings, like the paddle's size, the ball's radius... in `main.cpp`, by changing the cnostant variables declared at the top of the file.

# License

The `olcPixelGameEngine` is published under the `OLC-3` license (see in the file itself).
The rest of the code is published under the `GPL v3`.