#include "mygamescene.h"

extern const int DIR_VALUE[4][2];

MyGameScene::MyGameScene(GMap *map,int level,QObject *parent):QGraphicsScene(parent),map(map),level(level)
{
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0,0,BRICK_SIZE*MAPLENGTH,BRICK_SIZE*MAPLENGTH);

    BackGround=new QPixmap(GAME_WINDOW_HEIGHT+200,GAME_WINDOW_HEIGHT+200);
    QPainter *painter=new QPainter(BackGround);

    painter->translate(100,100);        //该偏移量与drawBackground中的translated参数必须一样

    switch(level)
    {
    case 1:
    {
        painter->setBrush(QBrush(Qt::black));
         painter->drawRect(-BRICK_SIZE*MAPLENGTH/2,-BRICK_SIZE*MAPLENGTH/2,BRICK_SIZE*MAPLENGTH*2,BRICK_SIZE*MAPLENGTH*2);
        QPixmap GreyStone=QPixmap(":/Images/Brick_5.png").scaled(QSize(BRICK_SIZE,BRICK_SIZE));

        for(int i=0;i<MAPLENGTH;++i)
            for(int j=0;j<MAPLENGTH;++j)
                if (map->WallData[i][j]) painter->drawPixmap(j*BRICK_SIZE,i*BRICK_SIZE,GreyStone);
        break;
    }
    case 2:
    {
        painter->setBrush(QBrush(Qt::black));
         painter->drawRect(-BRICK_SIZE*MAPLENGTH/2,-BRICK_SIZE*MAPLENGTH/2,BRICK_SIZE*MAPLENGTH*2,BRICK_SIZE*MAPLENGTH*2);
        QPixmap GreyStone=QPixmap(":/Images/Brick_4.png").scaled(QSize(BRICK_SIZE,BRICK_SIZE));

        for(int i=0;i<MAPLENGTH;++i)
            for(int j=0;j<MAPLENGTH;++j)
                if (map->WallData[i][j]) painter->drawPixmap(j*BRICK_SIZE,i*BRICK_SIZE,GreyStone);
        break;
    }
    case 3:
    {
        painter->setBrush(QBrush(Qt::black));
         painter->drawRect(-BRICK_SIZE*MAPLENGTH/2,-BRICK_SIZE*MAPLENGTH/2,BRICK_SIZE*MAPLENGTH*2,BRICK_SIZE*MAPLENGTH*2);
        QPixmap GreyStone=QPixmap(":/Images/Brick_3.png").scaled(QSize(BRICK_SIZE,BRICK_SIZE));

        for(int i=0;i<MAPLENGTH;++i)
            for(int j=0;j<MAPLENGTH;++j)
                if (map->WallData[i][j]) painter->drawPixmap(j*BRICK_SIZE,i*BRICK_SIZE,GreyStone);
        break;
    }
    case 4:
    {
        painter->setBrush(QBrush(Qt::black));
         painter->drawRect(-BRICK_SIZE*MAPLENGTH/2,-BRICK_SIZE*MAPLENGTH/2,BRICK_SIZE*MAPLENGTH*2,BRICK_SIZE*MAPLENGTH*2);
        QPixmap GreyStone=QPixmap(":/Images/Brick_2.png").scaled(QSize(BRICK_SIZE,BRICK_SIZE));

        for(int i=0;i<MAPLENGTH;++i)
            for(int j=0;j<MAPLENGTH;++j)
                if (map->WallData[i][j]) painter->drawPixmap(j*BRICK_SIZE,i*BRICK_SIZE,GreyStone);
        break;
    }

    }
    delete painter;

    GateLine=new QGraphicsLineItem(QLineF(0,0,3*BRICK_SIZE,0));
    QPen* Gate=new QPen(Qt::white);
    Gate->setWidth(3);
    GateLine->setPen(*Gate);
    GateLine->setPos(8*BRICK_SIZE,7*BRICK_SIZE);
    GateLine->setZValue(4);
    addItem(GateLine);
    delete Gate;
}

MyGameScene::~MyGameScene()
{
    delete BackGround;
    delete GateLine;
}

void MyGameScene::drawBackground(QPainter *painter, const QRectF &rect)
{

    //当背景修改时只在改变部分进行局部重新画图，减小背景绘图的负荷！
    //只在rect部分绘画就行了
    painter->drawPixmap(rect,*BackGround,QRectF(rect).translated(100,100));
}
