//
//  HelloWorldLayer.cpp
//  test
//
//  Created by sugita on 13/03/10.
//
//

#include "HelloWorldLayer.h"
#include "NewScene.h"

using namespace cocos2d;

CCScene* HelloWorldLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorldLayer *layer = HelloWorldLayer::create();
 
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool HelloWorldLayer::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLabelTTF *label = CCLabelTTF::create(CCString::createWithFormat("W:%.2f, H:%.2f", size.width, size.height)->getCString(), "Marker Feit", 64);
    // position the label ont the center of the scene
    label->setPosition(ccp(size.width / 2, size.height / 2));
    this->addChild(label);
    
    // NewSceneに遷移するためのメニューを作ります
    CCMenuItemFont::setFontName("Helvetica-BoldOblique");
    CCMenuItemFont::setFontSize(40);
    CCMenuItemFont* item = CCMenuItemFont::create("NewSceneへ", this, menu_selector(HelloWorldLayer::startNewScene));


    CCMenu* menu = CCMenu::create(item, NULL);
    menu->setPosition(CCPointMake(size.width / 2, size.height / 2 - 60));
    // メニューをthisレイヤーに追加します
    this->addChild(menu);
}

void HelloWorldLayer::startNewScene()
{
    CCDirector::sharedDirector()->replaceScene(NewScene::scene());
}