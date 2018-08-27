//
// Created by Alex Sid on 27.08.2018.
//

#ifndef PROJ_ANDROID_SECONDSCENE_H
#define PROJ_ANDROID_SECONDSCENE_H

#include "cocos2d.h"

class SecondScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(SecondScene);
};


#endif //PROJ_ANDROID_SECONDSCENE_H
