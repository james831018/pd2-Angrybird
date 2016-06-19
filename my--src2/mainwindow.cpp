#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
    pigexist = 0;//豬在不在
    score = 0;//分數
    ifskill = 0;//是否可觸發能力
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
// Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
// Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
// Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
// Create ground (You can edit here)
    itemList.push_back(new Land(16,2,32,3,QPixmap(":/ground.png").scaled(960,100),world,scene));
    //itemList.push_back(new Land(16.0, 1.5, 32.0, 3.0, QPixmap(":/ground.png").scaled(960, 110), world,scene));

// Create Slingshot
    itemList.push_back(new Land(2,5,1.5,3,QPixmap(":/Slingshot.png").scaled(100,100),world,scene));
    //itemList.push_back(new Land(5.0, 4.5, 2.0, 2.0, QPixmap(":/Slingshot.png").scaled(50, 105), world, scene));

// Create bird (You can edit here)
    //Bird *fuck = new Bird(2.7f,10.0f,0.27,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie[0] = new Bird(2.7f,10.0f,0.4,&timer,QPixmap(":/bird.png").scaled(60,60),world,scene);
    birdie[1] = new Bird(0.0f,10.0f,0.4,&timer,QPixmap(":/bluebird.png").scaled(60,60),world,scene);
    birdie[2] = new yello_bird(0.0f,13.0f,0.4,&timer,QPixmap(":/yellowbird.png").scaled(60,60),world,scene);
    birdie[3] = new Bird(0.0f,15.0f,0.27,&timer,QPixmap(":/whitebirds.png").scaled(60,60),world,scene);

    //Bird *birdie2 = new Bird(3.0f,12.0f,0.27f,&timer,QPixmap(":/1.jpg").scaled(height()/9.0,height()/9.0),world,scene);
// Create barrier
    verbarrier[0] = new barrier(20.0f,10.0f,2,3.0,&timer,QPixmap(":/verbarrier.png").scaled(30,80),world,scene);
    //barrier *verbarrier2 = new barrier(25.0f,8.0f,1.1,1.2,&timer,QPixmap(":/verbarrier.png").scaled(30,100),world,scene);
    //barrier *verbarrier2 = new barrier(25.0f,8.0f,1.1,1.2,&timer,QPixmap(":/verbarrier.png").scaled(30,100),world,scene);
    //barrier *horbarrier = new barrier(16.0f,15.0f,9,1,&timer,QPixmap(":/horbarrier.png").scaled(200,40),world,scene);
    //barrier *verbarrier3 = new barrier(22.0, 5.5, 1.0, 4.0, &timer, QPixmap(":/verbarrier").scaled(30, 120), world, scene);
    //itemList.push_back(new barrier(25.0f,3.0f,1.2,0.5,&timer,QPixmap(":/horbarrier.png").scaled(100,30),world,scene));
    //for(int i = 0; i < 3; ++i) itemList.push_back(new barrier(22.0 + i * 3.5, 5.5, 1.0, 4.0, &timer, QPixmap(":/verbarrier.png").scaled(30, 120), world, scene));

// Create pig
    birdie[4] = new Bird(20.0f,13.0f,0.27,&timer,QPixmap(":/pig.png").scaled(height()/9.0,height()/9.0),world,scene);
    pigexist = 1;
    getvelocityx = birdie[4]->GetLinearVelocity().x;
    //std::cout<<"the getposition is"<<getvelocityx<<"\n";
    //std::cout<<getvelocityx;
    //if(birdie[3]->get_linear_velocity())


// Setting the Velocity
    birdie[0]->SetLinearVelocity(b2Vec2(0,0));
    //birdie2->setLinearVelocity(b2Vec2(5,0));
    //itemList.push_back(birdie);
// Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

}
bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    /*int startx;
    int endx;
    int diffx;*/
    //right=0;
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        //QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
        //if (mouse_event->button() == Qt::LeftButton)
        //{

        beginx = QCursor::pos().x();
        beginy = QCursor::pos().y();

        //std::cout<<"the y is "<<beginy<<"\t";

        if(beginx>=346 && beginx <=284 &&beginy<=448 &&beginy>=500 && whichbird == 3 && ifskill==1)//---OK
        {
            //std::cout<<"the bird 3\n";
            std::cout<<"skill\n";
            birdie[2]->skill();
        }
        if(beginx<=346 && beginx >=284 &&beginy>=448 &&beginy<=500)
        {
            //std::cout<<"i am inside \n";
            right = 1;
           //birdie[0]->SetLinearVelocity(b2Vec2(5,3));
            ifskill = 1;
        }
        //std::cout<<"the press x is"<<beginx<<"\n";
        //}

        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        // TODO : add your code here
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        endx = QCursor::pos().x();
        endy = QCursor::pos().y();
        diffx = (beginx - endx)*0.1;
        diffy = (endy - beginy)*0.1;
        //std::cout<<"the endx is "<<endx<<"\n";
        //std::cout<<"the diffy is "<<diffy<<"\n";
        //std::cout<<"the right is "<<right<<"\n";
        //std::cout<<(endx-beginx)/50<<"\n";
        if(right == 1  && whichbird==1)
        {
            birdie[0]->SetLinearVelocity(b2Vec2(diffx,diffy));
            right = 0;
            birdie[1]->~QObject();//---------消掉鳥
            birdie[1] = new Bird(2.5f,13.0f,0.27,&timer,QPixmap(":/bluebird.png").scaled(height()/9.0,height()/9.0),world,scene);
            whichbird+=1;
            //ifskill = 0;
        }
        else if(right == 1  && whichbird==2)
        {
            birdie[1]->SetLinearVelocity(b2Vec2(diffx,diffy));
            right = 0;
            birdie[2]->~QObject();//---------消掉鳥
            birdie[2] = new yello_bird(2.5f,13.0f,0.27,&timer,QPixmap(":/yellowbird.png").scaled(height()/9.0,height()/9.0),world,scene);
            whichbird+=1;
            //birdie[2]->skill();//try
            //ifskill = 0;
        }
        else if(right == 1  && whichbird==3)
        {
            birdie[2]->SetLinearVelocity(b2Vec2(diffx,diffy));
            right = 0;
            birdie[3]->~QObject();//---------消掉鳥
            birdie[3] = new Bird(2.5f,13.0f,0.27,&timer,QPixmap(":/whitebirds.png").scaled(height()/9.0,height()/9.0),world,scene);
            whichbird+=1;
            //ifskill = 0;
        }
        else if(right == 1  && whichbird==4)
        {
            birdie[3]->SetLinearVelocity(b2Vec2(diffx,diffy));
            right = 0;
            //birdie[2]->~QObject();//---------消掉鳥
            //birdie[2] = new Bird(2.5f,13.0f,0.27,&timer,QPixmap(":/yellowbird.png").scaled(height()/9.0,height()/9.0),world,scene);
            whichbird+=1;
            //ifskill = 0;
        }
        //std::cout<<"the release x is"<<mouse_event->x()<<"\n";

        //TODO : add your code here
        //std::cout << "Release !" << std::endl ;
        //birdie[0]->SetLinearVelocity(b2Vec2(5,3));

    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
    getvelocityx = birdie[4]->GetLinearVelocity().x;
    getvelocityy = birdie[4]->GetLinearVelocity().y;
    //std::cout<<"the getpositiony is "<<getvelocityy<<"\n";
    if((getvelocityx+getvelocityy) >= 4 && pigexist==1)
    {
        //std::cout<<"the getposition is "<<getvelocityx<<"\n";
        //std::cout<<"the getpositiony is "<<getvelocityy<<"\n";
        birdie[4]->~QObject();
        pigexist = 0;
        score+=1000;
        ui->showscore->display(score);
    }

}

void MainWindow::QUITSLOT()
{
    // For debug
    this->close();
    //std::cout << "Quit Game Signal receive !" << std::endl ;
}
void MainWindow ::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_U)
    {
       //QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
       //std::cout <<"in the key U\n";
       //birdie->setLinearVelocity(b2Vec2(5,10));
       restart();

    }
    if(event->key() == Qt::Key_L)
    {
        //this->close();
        quitGame();
    }
    if(event->key() == Qt::Key_S)
    {
        if(ifskill==1)
        {
            //std::cout<<"the skill is 1\n";
            birdie[2]->skill();
        }
    }
}
void MainWindow::restart()
{
    //std::cout<<"i am restart\n";
    birdie[0]->~QObject();
    birdie[1]->~QObject();
    birdie[2]->~QObject();
    birdie[3]->~QObject();
    birdie[0] = new Bird(2.7f,10.0f,0.4,&timer,QPixmap(":/bird.png").scaled(60,60),world,scene);
    birdie[1] = new Bird(0.0f,10.0f,0.4,&timer,QPixmap(":/bluebird.png").scaled(60,60),world,scene);
    birdie[2] = new Bird(0.0f,13.0f,0.4,&timer,QPixmap(":/yellowbird.png").scaled(60,60),world,scene);
    birdie[3] = new Bird(0.0f,15.0f,0.4,&timer,QPixmap(":/whitebirds.png").scaled(60,60),world,scene);
    whichbird = 1;//第一隻鳥發射
    verbarrier[0]->~QObject();
    verbarrier[0] = new barrier(20.0f,10.0f,2,3.0,&timer,QPixmap(":/verbarrier.png").scaled(30,80),world,scene);
    if(pigexist==1)
    {
        birdie[4]->~QObject();
    }
    birdie[4] = new Bird(20.0f,13.0f,0.27,&timer,QPixmap(":/pig.png").scaled(height()/9.0,height()/9.0),world,scene);
    pigexist = 1;
    score = 0;
    ui->showscore->display(0);
}
