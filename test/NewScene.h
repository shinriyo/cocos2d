//
//  NewScene.h
//  test
//
//  Created by sugita on 13/03/10.
//
//

#ifndef __test__NewScene__
#define __test__NewScene__

#include <iostream>
#include "cocos2d.h"

class NewScene : public cocos2d::CCLayer
{
public:
    NewScene(void);
    ~NewScene(void);
    
    static cocos2d::CCScene* scene();
    virtual bool init();
    void startHelloWorldLayer();
                         
    CREATE_FUNC(NewScene);
};

#endif /* defined(__test__NewScene__) */
