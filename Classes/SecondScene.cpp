//
// Created by Alex Sid on 27.08.2018.
//

#include <base/CCRef.h>
#include "SecondScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* SecondScene::createScene()
{
    return SecondScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

bool SecondScene::init() {
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           [&](Ref* sender){
                                               menuCloseCallback(sender);
                                           });

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // create and initialize a label

    auto label = Label::createWithTTF("Second Scene", "fonts/Marker Felt.ttf", 24);
    label->setColor(ccBLACK);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }


    auto sprite = Sprite::create("testimage.jpg");
    if (sprite == nullptr)
    {
        problemLoading("testimage.jpg");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    return true;
};

void SecondScene::menuCloseCallback(Ref* pSender) {
    log("close");
    //Close the cocos2d-x game scene and quit the application

    auto scene = HelloWorld::createScene();

    // run
    Director::getInstance()->runWithScene(scene);
}