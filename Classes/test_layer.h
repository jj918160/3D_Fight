//
//  test_layer.h
//  3D_fight
//
//  Created by mac on 15-10-5.
//
//

#ifndef ___D_fight__test_layer__
#define ___D_fight__test_layer__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
//class DrawNode3D;
class testLayer : public Layer
{
public:
    //初始化当前层
    virtual bool init();
    CREATE_FUNC(testLayer);
    float rotation;
    void calculateArcBall( cocos2d::Vec3 & axis, float & angle, float p1x, float p1y, float p2x, float p2y );
    void updateCameraTransform();
    void onTouchsMoved( const std::vector<Touch*> &touchs, Event *event );
    float _radius;
    float projectToSphere( float r, float x, float y );
    Camera* pCamera;
    Sprite3D *sp_orc;
    float aaa;
    Sprite3D*temp;
    void update(float dt);
    OBB obbnode;
protected:
//    //鱼精灵
//    cocos2d::Sprite3D*_sprite;
//    //向前游的动作
//    cocos2d::Animate3D*_swim;
//    //受伤的动作
//    cocos2d::Animate3D*_hurt;
};
#endif /* defined(___D_fight__test_layer__) */
