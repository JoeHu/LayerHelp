//
//  CCLayerHelpTest.cpp
//  LayerHelp
//
//  Created by pengfei sun on 7/22/13.
//
//

#include "CCLayerHelpTest.h"

using namespace cocos2d;

enum TAG_MENU {
    TAG_MENU_0 = 123,
    TAG_MENU_1 = 124,
    TAG_MENU_2
    };

cocos2d::CCScene* CCLayerHelpTest::scene()
{
    CCScene *scene = CCScene::create();
    CCLayerHelpTest* layer = CCLayerHelpTest::create();
    scene->addChild(layer);
    return scene;
}
bool CCLayerHelpTest::init()
{
    if (!CCLayerHelp::init()) {
        return false;
    }
    addSprites();
    addButtons();
    return true;
}

void CCLayerHelpTest::addSprites()
{
    addSpriteFromPic("Icon.png", ccp(getWidth()*0.2, getHeight() *0.5),1,1,100,this, SCALE_MODE_NONE);
    addSpriteFromPic("Icon.png", ccp(getWidth()*0.4, getHeight() *0.5),1,1,100,this, SCALE_MODE_X);
    addSpriteFromPic("Icon.png", ccp(getWidth()*0.6, getHeight() *0.5),1,1,100,this, SCALE_MODE_Y);
    addSpriteFromPic("Icon.png", ccp(getWidth()*0.8, getHeight() *0.5),1,1,100,this, SCALE_MODE_X_Y);
}
void CCLayerHelpTest::addButtons()
{
    addButtonFromPic("Icon.png", "CloseSelected.png", ccp(getWidth()*0.2, getHeight() *0.3), menu_selector(CCLayerHelpTest::buttonPress),TAG_MENU_0);
    addButtonFromPic("Icon.png", "CloseSelected.png", ccp(getWidth()*0.3, getHeight() *0.3), menu_selector(CCLayerHelpTest::buttonPress),TAG_MENU_1);
    addButtonFromPic("Icon.png", "CloseSelected.png", ccp(getWidth()*0.4, getHeight() *0.3), menu_selector(CCLayerHelpTest::buttonPress),TAG_MENU_2);
}
void CCLayerHelpTest::buttonPress(CCObject* pSender)
{
    CCNode* node = (CCNode*)pSender;
    switch (node->getTag()) {
        case TAG_MENU_0:
            setMenuButtonEnable(false, TAG_MENU_2);
            break;
        case TAG_MENU_1:
            setMenuButtonEnable(true, TAG_MENU_2);
            break;
            
        default:
            break;
    }
}