#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "connect4.h"
#include "Engine.h"

int main() {
    Engine engine("Connect4", 800, 700, "arial.ttf", 24, "drop.wav");

    bool running = true;
    Connect4 game;
    int hoverCol = -1;

    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                running = false;

            else if (e.type == SDL_MOUSEMOTION) {
                int x = e.motion.x;
                hoverCol = (x - 50) / 100;
                if (hoverCol < 0 || hoverCol >= 7) hoverCol = -1;
            }

            else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && game.status() == Connect4::gameState::onGoing) {
                if (hoverCol >= 0 && hoverCol < 7)
                    game.play(hoverCol);
            }

            else if (e.type == SDL_KEYDOWN && game.status() != Connect4::gameState::onGoing) {
                if (e.key.keysym.sym == SDLK_r) {
                    game = Connect4(); // restart game
                }
                else if (e.key.keysym.sym == SDLK_q) {
                    running = false;
                }
            }
        }

        engine.clear({ 0, 0, 0, 255 }); // black background
        game.draw(&engine, hoverCol);
        engine.flip(); // present renderer
    }

    return 0;
}