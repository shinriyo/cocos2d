//
//  IntroLayer.h
//  test
//
//  Created by sugita on 13/03/10.
//
//

#ifndef __test__IntroLayer__
#define __test__IntroLayer__

#include "cocos2d.h"

class IntroLayer : public cocos2d::CCLayer
{
public:
    IntroLayer(void);
    ~IntroLayer(void);
    
    static cocos2d::CCScene* scene();
    void makeTransition(cocos2d::CCTime dt);
    void onEnter();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(IntroLayer);
};
#endif /* defined(__test__IntroLayer__) */
