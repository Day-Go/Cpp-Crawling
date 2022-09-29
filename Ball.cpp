#include "Ball.hpp"

Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::init(b2World* world, const glm::vec2& position, const float radius)
{
    props.x = position.x;
    props.y = position.y;
    props.r = radius;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    body = world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    //circleShape.m_p.Set(position.x, position.y);
    circleShape.m_radius = radius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.01f;
    fixtureDef.restitution = 0.0f;
    fixture = body->CreateFixture(&fixtureDef);

}

void Ball::render(SDL_Renderer* renderer)
{
    const int32_t diameter = (props.r * 2);

    int32_t x = (props.r - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);


    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPointF(renderer, body->GetPosition().x + x, body->GetPosition().y - y);
        SDL_RenderDrawPointF(renderer, body->GetPosition().x + x, body->GetPosition().y + y);
        SDL_RenderDrawPointF(renderer, body->GetPosition().x - x, body->GetPosition().y - y);
        SDL_RenderDrawPointF(renderer, body->GetPosition().x - x, body->GetPosition().y + y);
        SDL_RenderDrawPointF(renderer, body->GetPosition().x + y, body->GetPosition().y - x);
        SDL_RenderDrawPointF(renderer, body->GetPosition().x + y, body->GetPosition().y + x);
        SDL_RenderDrawPointF(renderer, body->GetPosition().x - y, body->GetPosition().y - x);
        SDL_RenderDrawPointF(renderer, body->GetPosition().x - y, body->GetPosition().y + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Ball::update()
{

}