//
//  test_layer.cpp
//  3D_fight
//
//  Created by mac on 15-10-5.
//
//

#include "test_layer.h"
#include "Particle3D/CCParticleSystem3D.h"
#include "Particle3D/PU/CCPUParticleSystem3D.h"
//#include "DrawNode3D.h"
bool testLayer::init()
{
    
    
    if (!Layer::init()) {
        return false;
    }
    
    
    
    aaa=0;
    rotation=0;
    _radius=1.f;
    Size size=Director::getInstance()->getWinSize();
    pCamera=Camera::createPerspective(60.0,size.width/size.height,0.1f,2000);
    pCamera->setCameraFlag(CameraFlag::USER1);
    pCamera->setPosition3D(Vec3(480,320,500));
    pCamera->lookAt(Vec3(480,320,0));

    addChild(pCamera);
//    pCamera->runAction(RepeatForever::create(Sequence::create(  MoveBy::create(2, Vec3(200,0,0)),MoveBy::create(2, Vec3(-200,0,0)), NULL)));
  
//
//    auto pCamera2=Camera::createPerspective(60.0f,size.width/size.height,0.1f,1000);
//    pCamera2->setCameraFlag(CameraFlag::USER1);
//    pCamera2->setPosition3D(Vec3(0,320,500));
//    pCamera2->lookAt(Vec3(480,320,0));
//    addChild(pCamera2);
    
    CCLOG("zeye:%f",Director::getInstance()->getZEye());
    //FileUtils::getInstance()->addSearchPath("Particle3D/materials");
   // FileUtils::getInstance()->addSearchPath("Particle3D/scripts");

    
    

    
    
    
    //auto sprite = Sprite3D::create("car.obj");
//    auto sprite=Sprite3D::create("car.obj","plane.png");
//    sprite->setScale(2.f);
//    //sprite->setTexture("tortoise.png");
//    sprite->setPosition3D( Vec3(480,200,100) );
//    sprite->setCameraMask(2);
//    addChild( sprite );
//    sprite->runAction(RepeatForever::create(RotateBy::create(1,Vec3(0,0,10))));
   //sprite->getBoundingBox()
//     DrawNode3D*node1=DrawNode3D::create();
//    node1->clear();
//    Vec3 corners[8]={};
//    AABB aabbsp1=sprite->getAABB();
//    aabbsp1.getCorners(corners);
//   
//    node1->drawCube(corners, Color4F(0,0,1,1));
//    addChild(node1);
//    
    
    Sprite3D*test=Sprite3D::create("YYY.c3b");
    test->setScale(1.f);
    test->setPosition3D( Vec3(500,200,100) );
    test->setRotation3D(Vec3(0,0,0));
    test->setCameraMask(2);
    addChild(test);
    
    auto panimation=Animation3D::create("YYY.c3b");
    auto panimate=Animate3D::create(panimation,0,20);
    test->runAction(RepeatForever::create(panimate));
    
    
    {
        Sprite3D*test=Sprite3D::create("LLL.c3b");
        test->setScale(1.f);
        test->setPosition3D( Vec3(500,300,100) );
        test->setRotation3D(Vec3(0,0,0));
        test->setCameraMask(2);
        addChild(test);
  
        auto panimation=Animation3D::create("LLL.c3b");
        auto panimate=Animate3D::create(panimation,0,16);
        test->runAction(RepeatForever::create(panimate));
    }
    {
        Sprite3D*test=Sprite3D::create("XXX5.c3b");
        test->setScale(1.f);
        test->setPosition3D( Vec3(500,400,200) );
        test->setRotation3D(Vec3(0,0,0));
        test->setCameraMask(2);
        addChild(test);
        
        auto panimation=Animation3D::create("XXX5.c3b");
        auto panimate=Animate3D::create(panimation,0,50);
        test->runAction(RepeatForever::create(panimate));
    }
    
    
    auto ry1=Sprite3D::create("rysj1.c3b","gw03122.png");
     ry1->setCameraMask(2);
     ry1->setPosition3D( Vec3(200,200,100) );
    addChild(ry1);
    
    
    auto ry2=Sprite3D::create("rysj1.c3b","gw03022.png");
    ry2->setCameraMask(2);
    ry2->setPosition3D( Vec3(300,200,100) );
    addChild(ry2);
    
    auto ry3=Sprite3D::create("caodi.obj","plane.png");
    ry3->setCameraMask(2);
    ry3->setPosition3D( Vec3(500,200,200) );
    ry3->setScale(5.f);
    addChild(ry3);
    
  
    
    
    

    auto touchEvt=EventListenerTouchOneByOne::create();
    touchEvt->onTouchBegan=[=](Touch*ptouch,Event*pevent){
//缩放相机
        //Vec3 lookdir=pCamera->getPosition3D()-sprite->getPosition3D();
//        if (lookdir.length()>=10) {
//            pCamera->setPosition3D(pCamera->getPosition3D()-lookdir.getNormalized()*10);
//        }
//        
        return true;
    };
    touchEvt->onTouchMoved=[=](Touch*ptouch,Event*pevent){
        //圆面相机
        auto location=ptouch->getLocation();
        Vec2 newPos=ptouch->getPreviousLocation()-location;
        Vec3 cameraPos=pCamera->getPosition3D();
         rotation+=newPos.x/1000; //算出角度
        float deltax=500*sin(rotation);//x增量
        float deltaz=500*cos(rotation);//z增量
        pCamera->setPosition3D(Vec3(480,320,0)+Vec3(deltax,0,deltaz));
        pCamera->lookAt(Vec3(480,320,0));
    };
    //touchEvt->onTouchEnded=CC_CALLBACK_2(GameScene::onTouchEnded,this);
    //不可少，否则无效果
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEvt,this);
    return true;
}

void testLayer::update(float dt){

 
   }

