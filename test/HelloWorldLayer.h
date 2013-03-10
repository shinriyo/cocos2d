//
//  HelloWorldLayer.h
//  test
//
//  Created by sugita on 13/03/10.
//
//

#ifndef __test__HelloWorldLayer__
#define __test__HelloWorldLayer__

#include "cocos2d.h" 

class HelloWorldLayer : public cocos2d::CCLayer
{
public:
    HelloWorldLayer(void);
    ~HelloWorldLayer(void);
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    void startNewScene();

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorldLayer);
};

#endif /* defined(__test__HelloWorldLayer__) */
