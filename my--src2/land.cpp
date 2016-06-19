#include "land.h"

Land::Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSize(w,h);

    /*g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);---------bird*/


// Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
//-------------------------------------------動態物件特性(形狀，角速度)
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    g_body->CreateFixture(&bodyBox,9.0f/*密度*/);
//-------------------------------------------

    /*
    //-------------------------------------------------------------------
        // Create Body
        b2BodyDef bodydef;
        bodydef.type = b2_dynamicBody;
        bodydef.bullet = true;
        bodydef.position.Set(x,y);
        bodydef.userData = this;
        g_body = world->CreateBody(&bodydef);
    //-------------------------------------------動態物件特性(形狀，角速度)
        b2CircleShape bodyshape;
        bodyshape.m_radius = radius;

        b2FixtureDef fixturedef;
        fixturedef.shape = &bodyshape;
        fixturedef.density = BIRD_DENSITY;
        fixturedef.friction = BIRD_FRICTION;
        fixturedef.restitution = BIRD_RESTITUTION;
        g_body->SetAngularDamping(3);//角速度，越小轉得越快
        g_body->CreateFixture(&fixturedef);
    //---------------------------------------------------------------
*/
    scene->addItem(&g_pixmap);
    paint();
}
