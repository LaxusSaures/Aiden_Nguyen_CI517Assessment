//
//  AbstractGame.h
//  GameEngineBase
//
// all code resources are taken from https://github.com/AlmasB/xcube2d/tree/master



#include <stdio.h>
#include "XCube2d.h"

class AbstractGame {
private:
    /* Main loop control */

    void handleMouseEvents();
    void updatePhysics();
protected:
    AbstractGame();
    virtual ~AbstractGame();
    // step 5;
    /* Engine systems */

    std::shared_ptr<GraphicsEngine> gfx;
    std::shared_ptr<EventEngine> eventSystem;
    std::shared_ptr<MyCustomSubsystem> customSystem;
    std::shared_ptr<PhysicsEngine> physics;
    std::shared_ptr<AudioEngine> audioSystem;
    /* Main loop control */
    bool running;
    bool paused;
    double gameTime;
    /**
     A virtual function in C++ is a base class member function that you can redefine in a derived class to achieve polymorphism.
     */

    virtual void update() = 0;
    virtual void render() = 0;
    //
    virtual void handleKeyEvents() = 0;

    virtual void onLeftMouseButton();
    virtual void onRightMouseButton();

    void pause() { paused = true; }
    void resume() { paused = false; }

public:
    int runMainLoop();
};
