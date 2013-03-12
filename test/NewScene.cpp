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
    CCMenuItemFont *item = CCMenuItemFont::create("戻る", this, menu_selector(NewScene::doHelloWorldLayer));
    // イメージメニューを作ります
    CCMenuItemImage *item2 = CCMenuItemImage::create("NormalButtonImage.png", "SelectedButtonImage.png", "DisabledButtonImage.png", this, menu_selector(NewScene::doItemImageCCLOG));
    
    // トグルメニューを作ります
    // ※ArrayでCCMenuItemFontが作れなかった
    CCMenuItemToggle *item3 = CCMenuItemToggle::createWithTarget(this, menu_selector(NewScene::doItemToggleCCLOG), CCMenuItemFont::create("ON"), CCMenuItemFont::create("OFF"));
    
    CCMenu *menu = CCMenu::create(item, item2, item3, NULL);
    
    // メニューが重なって表示されないように調整します
    menu->alignItemsVerticallyWithPadding(10.0f);
    
    // メニューをレイヤーBに追加します
    layerB->addChild(menu);

    // CCMenuItemImageを選択不可にします
    item2->setEnabled(false);
    
    return true;
}

void NewScene::doHelloWorldLayer(CCObject * p_Sender)
{
    // CCTransitionCrossFade does not support color
    CCTransitionFade *tran = CCTransitionFade::create(1.0f, HelloWorldLayer::scene(), ccWHITE);
    CCDirector::sharedDirector()->replaceScene(tran);
}

void NewScene::doItemImageCCLOG(CCObject * p_Sender)
{
    CCLOG("CCMenuItemImage selected.");
}

void NewScene::doItemToggleCCLOG(CCObject * p_Sender)
{
    CCLog("CCMenuItemToggle selected.");
}