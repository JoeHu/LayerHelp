//
//  CCLayerHelp.h
//  LayerHelp
//
//  Created by 123 on 13-7-22.
//
//

#ifndef __LayerHelp__CCLayerHelp__
#define __LayerHelp__CCLayerHelp__

#include "cocos2d.h"
enum SCALE_MODE{
    SCALE_MODE_NONE = 0X00,
    SCALE_MODE_X    = 0X01,
    SCALE_MODE_Y    = 0X02,
    SCALE_MODE_X_Y    = 0X04,
};
class CCLayerHelp:public cocos2d::CCLayer {
    
public:
    bool init();
    
public:
    cocos2d::CCSprite* addSpriteFromPic(const char* picname,cocos2d::CCPoint pos,float scale = 1,int zorder = 0,int tag = -1, CCNode* parent = NULL,SCALE_MODE mode = SCALE_MODE_X);
    cocos2d::CCSprite* addSpriteFromFrame(const char* frmaename,cocos2d::CCPoint pos,float scale = 1,int zorder = 0,int tag = -1, CCNode* parent = NULL,SCALE_MODE mode = SCALE_MODE_X);
    cocos2d::CCMenu* addButtonFromPic(const char *picname,const char *dsablepicname, cocos2d::CCPoint pos,cocos2d::SEL_MenuHandler fun,int tag = -1,int zorder = 7000, float scale = 1.0, bool isscale = true, cocos2d::CCNode *layer = NULL,SCALE_MODE mode = SCALE_MODE_X);
    cocos2d::CCMenu* addButtonFromFrame(const char *picname,const char *dsablepicname, cocos2d::CCPoint pos,cocos2d::SEL_MenuHandler fun,int tag = -1,int zorder = 7000, float scale = 1.0, bool isscale = true, cocos2d::CCNode *layer = NULL,SCALE_MODE mode = SCALE_MODE_X);
    void setMenuButtonEnable(bool flag,int tag, CCNode* parent = NULL);
    
public:
    inline float getScaleX(){return m_scale_x;};
    inline float getScaleY(){return m_scale_y;};
    inline float getWidth(){return m_width;};
    inline float getHeight(){return m_height;};
    
private:
    void initScale();
    void updateSpriteParaments(cocos2d::CCSprite* sprite ,cocos2d::CCPoint pos,float scale = 1,int zorder = 0,int tag = -1, CCNode* parent = NULL,SCALE_MODE mode = SCALE_MODE_NONE);
private:
    float m_scale_x;
    float m_scale_y;
    float m_width;
    float m_height;
public:
    CREATE_FUNC(CCLayerHelp);
};

#endif /* defined(__LayerHelp__CCLayerHelp__) */
