#include "PhysicsEngine.h"
#include <iostream>
PhysicsObject::PhysicsObject(const Point2& center, float x, float y) : center(center), lX(x), lY(y), hlX(x / 2.0f), hlY(y / 2.0f), force(0.0f, 0.0f)
{



}

bool PhysicsObject::isColliding(const PhysicsObject& other)
{
    Rectf r1 = { center.x - hlX, center.y - hlY, lX, lY };
    Rectf r2 = { other.center.x - other.hlX, other.center.y - other.hlY, other.lX, other.lY };

    return r1.intersects(r2);
}




void PhysicsObject::applyForce(const Vector2f& v) {
    force = v;
}

void PhysicsObject::applyGravity(const std::shared_ptr<PhysicsEngine>& engine)
{
    center += engine->gravity;
}
void PhysicsObject::applyForceVertical(const float& speed)
{
    center.y -= speed;
}
void PhysicsObject::applyForceHorizntal(const float& speed)
{
    center.x -= speed;
}
void PhysicsObject::applyAntiGravity(const PhysicsEngine& engine)
{
    center -= engine.gravity;
}

void PhysicsObject::applyBounce(const float& speed)  //no physics applied - created easter egg
{
    std::cout << "\nAiden_Nguyen-CI517-2023-24" ;
}

/* PHYSICS ENGINE */

PhysicsEngine::PhysicsEngine() : gravity(Vector2f(0, DEFAULT_GRAVITY))
{

}

void PhysicsEngine::setGravity(float val, float interval)
{

    gravity = Vector2f(0, val * interval);

}

void PhysicsEngine::registerObject(std::shared_ptr<PhysicsObject> obj)
{
    objects.push_back(obj);
}


void PhysicsObject::screenLimit(const float& width, const float& height)
{
    // limit to edges
    bool stopMoving = false;
    if (center.x + hlX > width) // if obj overextends right edge
    {
        stopMoving = true;
        center.x = width - hlX;
    }
    if (center.x - hlX < 0) // if obj overextends left edge
    {
        stopMoving = true;
        center.x = hlX;
    }
    if (center.y + hlY > height) // if obj overextends bottom edge
    {
        stopMoving = true;
        center.y = height - hlY;
    }
    if (center.y - hlY < 0) // if obj overextends top edge
    {
       
        stopMoving = true;
        center.y = hlY;
    }

    if (stopMoving)
    {
        // stopping movement when colliding with bounds
        center.x += 0;
        center.y += 0;
    }
}





void PhysicsEngine::update()
{

}
