#include "Ball.hpp"
#include <vector>

Ball::Ball(b2World* world, const glm::vec2& position, const float radius)
{
<<<<<<< Updated upstream
    props.x = position.x;
    props.y = position.y;
    props.r = radius + ((static_cast <float> (rand()) /
        static_cast <float> (RAND_MAX)) - 0.5f) * 4;

=======
>>>>>>> Stashed changes
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    body = world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
<<<<<<< Updated upstream
    //circleShape.m_p.Set(position.x, position.y);
    circleShape.m_radius = props.r;
=======

    circleShape.m_radius = radius;
>>>>>>> Stashed changes

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.2f;
    fixtureDef.restitution = 0.0f;
<<<<<<< Updated upstream
    fixture = body->CreateFixture(&fixtureDef);
=======
    body->CreateFixture(&fixtureDef);
>>>>>>> Stashed changes
}

Ball::~Ball()
{

}

void Ball::render(SDL_Renderer* renderer)
{
    b2Fixture* fixture = body->GetFixtureList();
    b2Shape* shape = fixture->GetShape();

    float32 radius = shape->m_radius;

    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    float xPos = body->GetPosition().x;
    float yPos = body->GetPosition().y;

    while (x >= y)
    {
<<<<<<< Updated upstream
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
=======
        SDL_FPoint points[8];
        points[0].x = xPos + x; points[0].y = yPos - y;
        points[1].x = xPos + x; points[1].y = yPos + y;
        points[2].x = xPos - x; points[2].y = yPos - y;
        points[3].x = xPos - x; points[3].y = yPos + y;
        points[4].x = xPos + y; points[4].y = yPos - x;
        points[5].x = xPos + y; points[5].y = yPos + x;
        points[6].x = xPos - y; points[6].y = yPos - x;
        points[7].x = xPos - y; points[7].y = yPos + x;
>>>>>>> Stashed changes

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
