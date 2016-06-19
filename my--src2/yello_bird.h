#ifndef YELLO_BIRD_H
#define YELLO_BIRD_H


#include <bird.h>

class yello_bird : public Bird
{
public:
    yello_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void skill();
};

#endif // YELLO_BIRD_H
