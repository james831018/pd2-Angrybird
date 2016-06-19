/*#include "barrier.h"

barrier::barrier(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
        g_pixmap.setPixmap(pixmap);
        g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);//幹嘛用的?
        g_size = QSize(w,h);
        //-------------------------------------------------------------------
    // Create Body
        b2BodyDef bodydef;

        bodydef.active = true;

        bodydef.type = b2_dynamicBody;
        bodydef.bullet = true;
        bodydef.position.Set(x,y);
        bodydef.userData = this;
        g_body = world->CreateBody(&bodydef);

        //-------------------------------------------動態物件特性(形狀，角速度)
        b2PolygonShape bodyshape;
        bodyshape.SetAsBox(w,h);

        b2FixtureDef fixturedef;
        fixturedef.shape = &bodyshape;
        fixturedef.density = barrier_DENSITY;
        fixturedef.friction = barrier_FRICTION;
        fixturedef.restitution = barrier_RESTITUTION;
        g_body->SetAngularDamping(3);//角速度，越小轉得越快
        g_body->CreateFixture(&fixturedef);
        //---------------------------------------------------------------
    // Bound timer
        connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
        scene->addItem(&g_pixmap);
}

void barrier::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}*/
#include "barrier.h"

barrier::barrier(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : GameItem(world){
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width() / 2, g_pixmap.boundingRect().height() / 2);
   // g_size = QSize(w, h);

    b2BodyDef bodydef;
    bodydef.active = true;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x, y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);

    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(w/2, h/2);

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = barrier_DENSITY;
    fixturedef.friction = barrier_FRICTION;
    fixturedef.restitution = barrier_RESTITUTION;

    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this, SLOT(paint()));

    scene->addItem(&g_pixmap);
}



