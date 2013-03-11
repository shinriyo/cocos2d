//
//  IntroLayer.cpp
//  test
//
//  Created by sugita on 13/03/10.
//
//

#include "IntroLayer.h"
#include "HelloWorldLayer.h"

using namespace cocos2d;

USING_NS_CC;

IntroLayer::IntroLayer()
{
}

IntroLayer::~IntroLayer()
{
}

CCScene* IntroLayer::scene()
{
    cocos2d::CCScene *scene = CCScene::create();
    IntroLayer *layer = IntroLayer::create();
    scene->addChild(layer);
    
    return scene;
}

void IntroLayer::onEnter()
{
    CCLayer::onEnter();
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *background;
    // iPhone
    if (true)
    {
        background = CCSprite::create("Default.png");
        background->setRotation(90.0f);
    } else {
        //background = CCSprite::create("Default-Landscape~ipad.png");
    }
    
    background->setPosition(ccp(size.width / 2, size.height / 2));
    
    // add the label as a child to this Layer
    this->addChild(background);
    
    // In one second transition to the new scene
    //this->scheduleOnce(makeTransition, 1);
    this->scheduleOnce(schedule_selector(IntroLayer::makeTransition), 1);
}

void IntroLayer::makeTransition(CCTime dt)
{
    //CCTransitionProgressHorizontal *tran = CCTransitionProgressHorizontal::create(2, HelloWorldLayer::scene());
	//CCTransitionProgressInOut *tran = CCTransitionProgressInOut::create(2, HelloWorldLayer::scene());
	//CCTransitionProgressOutIn *tran = CCTransitionProgressOutIn::create(2, HelloWorldLayer::scene());
	//CCTransitionProgressRadialCCW *tran = CCTransitionProgressRadialCCW::create(2, HelloWorldLayer::scene());
	//CCTransitionProgressRadialCW *tran = CCTransitionProgressRadialCW::create(2, HelloWorldLayer::scene());
	//CCTransitionProgressVertical *tran = CCTransitionProgressVertical::create(2, HelloWorldLayer::scene());
	//CCTransitionRotoZoom *tran = CCTransitionRotoZoom::create(2, HelloWorldLayer::scene());
    
    //CCDirector::sharedDirector()->replaceScene(tran);
    CCDirector::sharedDirector()->replaceScene(CCTransitionProgressRadialCW::create(1.0f, HelloWorldLayer::scene()));
}