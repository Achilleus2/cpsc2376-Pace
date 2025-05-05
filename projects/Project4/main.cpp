#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "connect4.h"
#include "Engine.h"

void drawWinScreen(Connect4& game, Engine& engine, bool& wantReplay, bool& wantQuit);


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
            else if (e.type == SDL_KEYDOWN) {
                SDL_Keycode key = e.key.keysym.sym;
                if (key >= SDLK_1 && key <= SDLK_7) {
                    int col = key - SDLK_1;
                    game.play(col);
                }
                // R = Restart, ESC = Quit
                if (key == SDLK_r) {
                    game = Connect4();
                }

                if (key == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && game.status() == Connect4::gameState::onGoing) {
                if (hoverCol >= 0 && hoverCol < 7)
                    game.play(hoverCol);
            }

            else if (game.status() != Connect4::gameState::onGoing) {
                bool wantReplay = false, wantQuit = false;
                drawWinScreen(game, engine, wantReplay, wantQuit);
                if (wantQuit) {
                    running = false;
                }
                else if (wantReplay) {
                    game = Connect4();
                }
            }
        }

        engine.clear({ 0, 0, 0, 255 }); 
        game.draw(&engine, hoverCol);
        engine.flip();
    }

    return 0;
}

void drawWinScreen(Connect4& game, Engine& engine, bool& wantReplay, bool& wantQuit)
{
    auto status = game.status();
    SDL_Color overlay = { 0, 0, 0, 215 };
    engine.drawRectangle(0, 0, 2000, 2000, overlay);

    // Circle positions
    int circleY = 250;
    int leftX = 300;
    int rightX = 500;

    // Draw red and yellow player circles
    engine.drawCircle(leftX, circleY, 50, { 255, 0, 0, 255 });    
    engine.drawCircle(rightX, circleY, 50, { 255, 255, 0, 255 });

    // Draw a W on the winners circle
    if (status == Connect4::player1Wins) {
        for (int i = -1; i <= 1; ++i) {
            engine.drawLine(leftX - 20 + i, circleY - 20, leftX - 10 + i, circleY, { 255, 215, 0, 255 });
            engine.drawLine(leftX - 10 + i, circleY, leftX + i, circleY - 20, { 255, 215, 0, 255 });
            engine.drawLine(leftX + i, circleY - 20, leftX + 10 + i, circleY, { 255, 215, 0, 255 });
            engine.drawLine(leftX + 10 + i, circleY, leftX + 20 + i, circleY - 20, { 255, 215, 0, 255 });
        }
    }
    else if (status == Connect4::player2Wins) {
        for (int i = -1; i <= 1; ++i) {
            engine.drawLine(rightX - 20 + i, circleY - 20, rightX - 10 + i, circleY, { 255, 215, 0, 255 });
            engine.drawLine(rightX - 10 + i, circleY, rightX + i, circleY - 20, { 255, 215, 0, 255 });
            engine.drawLine(rightX + i, circleY - 20, rightX + 10 + i, circleY, { 255, 215, 0, 255 });
            engine.drawLine(rightX + 10 + i, circleY, rightX + 20 + i, circleY - 20, { 255, 215, 0, 255 });
        }
    }

    // Draw replay button (circle with arrow)
    int replayX = 300, replayY = 450;
    // Draw replay button border
    engine.drawCircle(replayX, replayY, 34, { 255, 255, 255, 255 }); // white border
    // Replay button (green)
    engine.drawCircle(replayX, replayY, 30, { 0, 255, 0, 255 });
    // Arrow (same as before)
    for (int i = -1; i <= 1; ++i) {
        engine.drawLine(replayX + i, replayY - 10, replayX + i, replayY + 10, { 0, 100, 0, 255 });
        engine.drawLine(replayX + i, replayY - 10, replayX + 10 + i, replayY , { 0, 100, 0, 255 });
    }

    // Draw quit button (X in red box)
    int quitX = 500, quitY = 450;
    engine.drawRectangle(quitX, quitY, 64, 64, { 255, 255, 255, 255 }); // white border
    // Quit button (red box)
    engine.drawRectangle(quitX, quitY, 60, 60, { 255, 0, 0, 255 });
    // "X" icon
    for (int i = -1; i <= 1; ++i) {
        engine.drawLine(quitX - 20 + i, quitY - 20, quitX + 20 + i, quitY + 20, { 255, 255, 255, 255 });
        engine.drawLine(quitX + 20 + i, quitY - 20, quitX - 20 + i, quitY + 20, { 255, 255, 255, 255 });
    }

    engine.flip();

    SDL_Event event;
    while (true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                wantQuit = true;
                return;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                int mx = event.button.x;
                int my = event.button.y;

                // Check replay circle
                int dx = mx - replayX;
                int dy = my - replayY;
                if (dx * dx + dy * dy <= 30 * 30) {
                    wantReplay = true;
                    return;
                }

                // Check quit box
                if (mx >= quitX - 30 && mx <= quitX + 30 &&
                    my >= quitY - 30 && my <= quitY + 30) {
                    wantQuit = true;
                    return;
                }
            }
            // R = Restart, ESC = Quit
            if (event.type == SDL_KEYDOWN) {
                SDL_Keycode key = event.key.keysym.sym;
                if (key == SDLK_r) {
                    wantReplay = true;
                    return;
                }

                if (key == SDLK_ESCAPE)
                {
                    wantQuit = true;
                    return;
                }
            }
        }
    }
}