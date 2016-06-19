#ifndef BARRIER_H
#define BARRIER_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define barrier_DENSITY 0.9f
#define barrier_FRICTION 0.02f
#define barrier_RESTITUTION 0.5f

class barrier : public GameItem
{
public:
    barrier(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
};

#endif // BARRIER_H
