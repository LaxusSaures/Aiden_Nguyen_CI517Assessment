#include <stdio.h>

#include "AbstractGame.h"

struct GameKey {
    Point2 pos;
    bool isAlive;
};

class MyGame : public AbstractGame
{
private:
    SDL_Rect box, box2;

    PhysicsObject phy, phyobj2;

    SDL_Texture* sprite1 = NULL; //sprite

    // loading audio in for use in the game demo
    Mix_Music* backgroundMusic = NULL;
    Mix_Chunk* collectCoin = NULL;

    std::vector<std::shared_ptr<GameKey>> gameKeys;

    /* GAMEPLAY */
    int score, numKeys, lives;
    bool gameWon;

    void handleKeyEvents();
    void update();
    void render();
    void renderUI();
public:
    MyGame();
    ~MyGame();
};


