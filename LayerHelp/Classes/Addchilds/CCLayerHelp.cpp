//
//  CCLayerHelp.cpp
//  LayerHelp
//
//  Created by 123 on 13-7-22.
//
//

#include "CCLayerHelp.h"
using namespace cocos2d;

bool CCLayerHelp::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    initScale();
    return true;
}


void CCLayerHelp::initScale()
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    m_width = size.width;
    m_height = size.height;
    if (size.width < size.height) {
        
        m_scale_x = CCDirector::sharedDirector()->getWinSize().width / 768.0;
        m_scale_y = CCDirector::sharedDirector()->getWinSize().height / 1024.0;
    }
    else
    {
        m_scale_x = CCDirector::sharedDirector()->getWinSize().width / 1024.0;
        m_scale_y = CCDirector::sharedDirector()->getWinSize().height / 768.0;
    }
}
cocos2d::CCSprite* CCLayerHelp::addSpriteFromPic(const char* picname,cocos2d::CCPoint pos,float scale,int zorder,int tag  , CCNode* parent,SCALE_MODE mode)
{
    CCSprite* sp = CCSprite::create(picname);
    updateSpriteParaments(sp,pos,scale,zorder,tag,parent,mode);
    return sp;
}
cocos2d::CCSprite* CCLayerHelp::addSpriteFromFrame(const char* framename,cocos2d::CCPoint pos,float scale,int zorder,int tag , CCNode* parent,SCALE_MODE mode)
{
    CCSprite* sp =  CCSprite::createWithSpriteFrameName(framename);//CCSprite::create(picname);
    updateSpriteParaments(sp,pos,scale,zorder,tag,parent,mode);
    return sp;
}
CCMenu* CCLayerHelp::addButtonFromPic(const char *picname, const char *disablepicname, cocos2d::CCPoint pos,SEL_MenuHandler fun,int tag ,int zorder, float scale, bool isscale, cocos2d::CCNode *layer,SCALE_MODE mode)
{
    CCMenu *menu = NULL;
    CCMenuItem* item = NULL;
    CCSprite* normalsprite = CCSprite::create(picname);
    CCSprite* selectsprite = CCSprite::create(picname);
    if (isscale) {
        selectsprite->setScale( 0.95);
    }
    
    
    if (disablepicname == NULL) {
        item = CCMenuItemSprite::create(normalsprite, selectsprite, this, fun);
    }
    else
    {
        CCSprite* disablesprite = CCSprite::create(disablepicname);
        item = CCMenuItemSprite::create(normalsprite, selectsprite, disablesprite, this, fun);
    }
    item->setPosition(CCPointZero);
    item->setScale(scale);
    item->setTag(tag);
    menu = CCMenu::create(item,NULL);
    menu->setPosition(pos);
    if (layer == NULL) {
        
        this->addChild(menu, zorder, tag);
    }
    else
    {
        layer->addChild(menu, zorder, tag);
    }
    return menu;
}
CCMenu* CCLayerHelp::addButtonFromFrame(const char *picname, const char *disablepicname, cocos2d::CCPoint pos,SEL_MenuHandler fun,int tag ,int zorder, float scale, bool isscale, cocos2d::CCNode *layer,SCALE_MODE mode)
{
    CCMenu *menu = NULL;
    CCMenuItem* item = NULL;
    CCSprite* normalsprite = CCSprite::createWithSpriteFrameName(picname);//CCSprite::create(picname);
    CCSprite* selectsprite = CCSprite::createWithSpriteFrameName(picname);
    if (isscale) {
        selectsprite->setScale( 0.95);
    }
    
    if (disablepicname == NULL) {
        item = CCMenuItemSprite::create(normalsprite, selectsprite, this, fun);
    }
    else
    {
        CCSprite* disablesprite = CCSprite::createWithSpriteFrameName(disablepicname);
        item = CCMenuItemSprite::create(normalsprite, selectsprite, disablesprite, this, fun);
    }
    item->setPosition(CCPointZero);
    item->setScale(scale);
    item->setTag(tag);
    menu = CCMenu::create(item,NULL);
    menu->setPosition(pos);
    if (layer == NULL) {
        
        this->addChild(menu, zorder, tag);
    }
    else
    {
        layer->addChild(menu, zorder, tag);
    }
    return menu;
}

void CCLayerHelp::updateSpriteParaments(cocos2d::CCSprite* sprite ,cocos2d::CCPoint pos,float scale ,int zorder,int tag , CCNode* parent,SCALE_MODE mode)
{
    sprite->setPosition(pos);
    if (parent != NULL) {
        parent->addChild(sprite, zorder, tag);
    }
    else
    {
        addChild(sprite, zorder, tag);
    }
    
    switch (mode) {
        case SCALE_MODE_NONE:
            sprite->setScale(scale);
            break;
        case SCALE_MODE_X:
            sprite->setScale(m_scale_x * scale);
            break;
        case SCALE_MODE_Y:
            sprite->setScale(m_scale_y * scale);
            break;
        case SCALE_MODE_X_Y:
            sprite->setScaleX(m_scale_x * scale);
            sprite->setScaleY(m_scale_y * scale);
            break;
            
        default:
            break;
    }
}
void CCLayerHelp::setMenuButtonEnable(bool flag, int tag,CCNode* parent)
{
    CCMenu *menu = NULL;
    if (parent == NULL) {
        menu = (CCMenu*) getChildByTag(tag);
    }
    else
    {
        menu = (CCMenu*)parent->getChildByTag(tag);
    }
    if (menu != NULL) {
        CCMenuItemSprite * item = (CCMenuItemSprite*)menu->getChildByTag(tag);
        if (item != NULL) {
            item->setEnabled(flag);
        }
    }
}