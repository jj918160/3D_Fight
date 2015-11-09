//
//  Charecter3.cpp
//  3D_Fight
//
//  Created by mac on 15-10-14.
//
//

#include "Charecter3.h"
bool Charecter3::init(){
    if (!Sprite3D::init()) {
        return false;
    }
    this->initWithFile("XXX5.c3b");
    //缓存动画
    auto xks=Animation3D::create("XXX5.c3b");
    Animation3DCache::getInstance()->addAnimation("xiakeshu",xks);
    xks_stand=Animate3D::createWithFrames(xks, 0, 116);
    xks_beizhan=Animate3D::createWithFrames(xks,117,153);
    xks_attack1=Animate3D::createWithFrames(xks,154,199);
    xks_attack2=Animate3D::createWithFrames(xks,200, 244);
    xks_walk=Animate3D::createWithFrames(xks,245, 284);
    xks_run=Animate3D::createWithFrames(xks,285, 311);
    xks_yun=Animate3D::createWithFrames(xks,312, 372);
    xks_dead=Animate3D::createWithFrames(xks,373, 405);
    
    return true;
}

void Charecter3::walk(){
    this->stopAllActions();
    this->runAction(RepeatForever::create(xks_walk));
}
void Charecter3::run(){
    this->stopAllActions();
    this->runAction(RepeatForever::create(xks_run));
}
void Charecter3::yun(){
    this->stopAllActions();
    this->runAction(RepeatForever::create(xks_yun));
}
void Charecter3::stand(){
    this->stopAllActions();
    this->runAction(RepeatForever::create(xks_stand));
}
void Charecter3::attack_1(){
    this->stopAllActions();
    this->runAction(xks_attack1);
}
void Charecter3::attack_2(){
    this->runAction(xks_attack2);
}
void Charecter3::dead(){
    this->stopAllActions();
    this->runAction(Sequence::create(xks_dead,DelayTime::create(0.1),
                                     CallFunc::create([&](){
        this->runAction(RemoveSelf::create());
    }),NULL));
}
void Charecter3::beizhan()
{
    this->stopAllActions();
    this->runAction(RepeatForever::create(xks_beizhan));
}