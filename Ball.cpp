#include "Ball.hpp"
#include <vector>

Ball::Ball(b2World* world, const glm::vec2& position, const float radius)
{
    props.x = position.x;
    props.y = position.y;
    props.r = radius + ((static_cast <float> (rand()) /
        static_cast <float> (RAND_MAX)) - 0.5f) * 4;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    body = world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    //circleShape.m_p.Set(position.x, position.y);
    circleShape.m_radius = props.r;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.2f;
    fixtureDef.restitution = 0.0f;
    fixture = body->CreateFixture(&fixtureDef);
}

Ball::~Ball()
{

}

void Ball::render(SDL_Renderer* renderer)
{
    const int32_t diameter = (props.r * 2);

    int32_t x = (props.r - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    float xPos = body->GetPosition().x;
    float yPos = body->GetPosition().y;

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_FPoint points[8];
        points[0].x = xPos + x;
        points[0].y = yPos - y;

        points[1].x = xPos + x;
        points[1].y = yPos + y;

        points[2].x = xPos - x;
        points[2].y = yPos - y;

        points[3].x = xPos - x;
        points[3].y = yPos + y;

        points[4].x = xPos + y;
        points[4].y = yPos - x;

        points[5].x = xPos + y;
        points[5].y = yPos + x;

        points[6].x = xPos - y;
        points[6].y = yPos - x;

        points[7].x = xPos - y;
        points[7].y = yPos + x;

        SDL_RenderDrawPointsF(renderer, points, 8);

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