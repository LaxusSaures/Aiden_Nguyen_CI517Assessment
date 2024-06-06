#include "MyGame.h"


MyGame::MyGame() : AbstractGame(), numKeys(5), box{ 0, 0, 50, 50 }, box2{ 0, 0, 60, 2000 }, score(0), lives(3), gameWon(false), phy({ 0,0 }, 50, 50), phyobj2({ 0,400 }, 2000, 10)
{

    gfx->setVerticalSync(true);
    customSystem->otherfunction();

    physics->setGravity(2, 2);



    for (int i = 0; i < numKeys; i++)
    {
        std::shared_ptr<GameKey> k = std::make_shared<GameKey>();
        k->isAlive = true;
        k->pos = Point2(getRandom(0, 750), getRandom(0, 550));
        gameKeys.push_back(k);
    }

    SDL_Surface* temp1 = IMG_Load("Assets/Images/slime3.png");   //sprite
    if (!temp1) // if no image is loaded
    {
        std::cout << "\nFailed to load sprite image: " << IMG_GetError();
    }
    else
    {
        sprite1 = SDL_CreateTextureFromSurface(GraphicsEngine::getRenderer(), temp1); // added getRenderer function for this
        SDL_FreeSurface(temp1); // freeing the leap surface
        if (!sprite1) std::cout << "\nFailed to create sprite texture: " << SDL_GetError(); // final error check
    }

    backgroundMusic = Mix_LoadMUS("Assets/Audio/overwhelming_darkness.mp3"); //background audio
     Mix_VolumeMusic(24);

    // playing background music at initialisation
    Mix_PlayMusic(backgroundMusic, -1);

    collectCoin = Mix_LoadWAV("Assets/Audio/beep.wav");
    Mix_Volume(-1, 24);

   
}

MyGame::~MyGame()
{

}




void MyGame::handleKeyEvents()
{
    int speed = 3;

    if (eventSystem->isPressed(Key::W))
    {
        phy.applyForceVertical(15);
    }

    if (eventSystem->isPressed(Key::S))
    {
        phy.applyForceVertical(-speed);
    }

    if (eventSystem->isPressed(Key::A))
    {
        phy.applyForceHorizntal(speed);
    }

    if (eventSystem->isPressed(Key::D))
    {
        phy.applyForceHorizntal(-speed);
    }
}

void MyGame::update()
{
   // Mix_PlayChannel(-1, collectCoin, 0);

    box.y = phy.getCenter().y-box.h/2;  //sets center position to true center
    box.x = phy.getCenter().x-box.w/2;
    box2.x = phyobj2.getCenter().x;
    box2.y = phyobj2.getCenter().y;

    if (!phy.isColliding(phyobj2))
    {
        phy.applyGravity(physics);
    }

    if (phy.isColliding(phyobj2))
    {
        phy.applyBounce(3);
    }
    for (auto key : gameKeys)
    {

        if (key->isAlive && (box.x == key->pos.x && box.y == key->pos.y))
        {
            score += 200;
            key->isAlive = false;
            numKeys--;
        }
    }

    phy.screenLimit(800.0, 600.0);

    if (numKeys == 0)
    {
        gameWon = true;
    }
}

void MyGame::render()
{

    SDL_Rect dstRect = { box.x,box.y,box.w, box.h };
    gfx->drawTexture(sprite1, &dstRect);
    gfx->setDrawColor(SDL_COLOR_GREEN);
    gfx->fillRect(box2.x, box2.y, box2.h, box2.w);
    gfx->setDrawColor(SDL_COLOR_YELLOW);
    for (auto key : gameKeys)
        if (key->isAlive)
        {
            gfx->drawCircle(key->pos, 5);

        }
}

void MyGame::renderUI() {
    gfx->setDrawColor(SDL_COLOR_AQUA);
    std::string scoreStr = std::to_string(score);


    if (gameWon)
        std::cout << "you won: " << score;
}


