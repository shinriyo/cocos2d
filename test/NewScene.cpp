//
//  NewScene.cpp
//  test
//
//  Created by sugita on 13/03/10.
//
//

#include "NewScene.h"
#include "HelloWorldLayer.h"

using namespace cocos2d;

USING_NS_CC;

NewScene::NewScene(void)
{
}

NewScene::~NewScene(void)
{
}

CCScene* NewScene::scene()
{
    CCScene *scene = CCScene::create();
    NewScene *layer = NewScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool NewScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    /////////////////////////////
    // 2.
    // ==== レイヤーA ====
    // レイヤーAを生成します
    CCLayer* layerA = CCLayer::create();
    // レイヤーAをNewSceneレイヤーに追加します
    this->addChild(layerA);
    // sample.pngをスプライトオブジェクトに読み込みます
    CCSprite* sampleSprite = CCSprite::create("sample.png");
    // スプライトオブジェクトを画面の中心に配置します
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    sampleSprite->setPosition(CCPointMake(winSize.width / 2, winSize.height / 2));
    // スプライトオブジェクトをレイヤーAに追加します
    layerA->addChild(sampleSprite);
    // 回転アニメーションオブジェクトを生成します
    CCRotateBy *rotate = CCRotateBy::create(10, 360);
    CCRepeatForever* roop = CCRepeatForever::create(rotate);
    // レイヤーAにアニメーションを適用します
    layerA->runAction(roop);
    
    // ==== レイヤーB ====
    // レイヤーBを生成します
    CCLayer* layerB = CCLayer::create();
    // レイヤーBをNewSceneレイヤーに追加します
    this->addChild(layerB);
    // 前の画面に戻るメニューを作ります
    CCMenuItemFont::setFontName("Helvetica-BoldOblique");
    CCMenuItemFont::setFontSize(40);
    CCMenuItemFont* item = CCMenuItemFont::create("戻る", this, menu_selector(NewScene::startHelloWorldLayer));

    CCMenu* menu = CCMenu::create(item, NULL);
    // メニューをレイヤーBに追加します
    layerB->addChild(menu);

    return true;
}

void NewScene::startHelloWorldLayer()
{
    CCDirector::sharedDirector()->replaceScene(HelloWorldLayer::scene());
}