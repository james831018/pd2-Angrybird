#include "yello_bird.h"

yello_bird::yello_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene): Bird(x, y, radius, timer, pixmap, world, scene)
{
    //Bird(x,y,radius,timer,pixmap,world,scene);
    //: bird(x, y, radius, timer, pixmap, world, scene)
}


void yello_bird::skill()
{
    printf("i am skill\n");
    g_body->SetLinearVelocity(b2Vec2(10,10));
}


//----------------到這OK
