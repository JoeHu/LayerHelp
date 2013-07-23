//
//  CCLayerHelpTest.h
//  LayerHelp
//
//  Created by pengfei sun on 7/22/13.
//
//

#ifndef __LayerHelp__CCLayerHelpTest__
#define __LayerHelp__CCLayerHelpTest__

#include "CCLayerHelp.h"

class CCLayerHelpTest:public CCLayerHelp {
    
    
public:
    bool init();
    static cocos2d::CCScene* scene();
    void addSprites();
    void addButtons();
    
    void buttonPress(CCObject* pSender);
    CREATE_FUNC(CCLayerHelpTest);
};

#endif /* defined(__LayerHelp__CCLayerHelpTest__) */
