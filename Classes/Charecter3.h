//
//  Charecter3.h
//  3D_Fight
//
//  Created by mac on 15-10-14.
//
//

#ifndef ___D_Fight__Charecter3__
#define ___D_Fight__Charecter3__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class Charecter3:public Sprite3D
{
public:
    virtual bool init();
    CREATE_FUNC(Charecter3);
    
    void walk();
    void run();
    void yun();
    void stand();
    void attack_1();
    void attack_2();
    void dead();
    void beizhan();
    
private:
    Animate3D* xks_stand;
    Animate3D* xks_attack1;
    Animate3D* xks_attack2;
    Animate3D* xks_walk;
    Animate3D* xks_run;
    Animate3D* xks_yun;
    Animate3D* xks_dead;
    Animate3D* xks_beizhan;
    
    
};
#endif /* defined(___D_Fight__Charecter3__) */
