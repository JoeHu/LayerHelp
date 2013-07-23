//
//  CCResourceManger.cpp
//  Rockey
//
//  Created by 123 on 13-7-11.
//
//

#include "CCResourceManger.h"
using namespace cocos2d;
CCResourceManger::CCResourceManger():
m_pic_names(NULL),
m_plist_names(NULL)
{
    
}
CCResourceManger::~CCResourceManger()
{
    
    releasePic();
    releasePlist();
    CCLOG("~CCResourceManger");
}
void CCResourceManger::addPic(const char* pic)
{
    if (m_pic_names == NULL) {
        m_pic_names = CCArray::create();
        m_pic_names->retain();
    }
    CCString* str = CCString::createWithFormat("%s",pic);
    if (!m_pic_names->containsObject(str)) {
        m_pic_names->addObject(str);
    }
}
void CCResourceManger::addPlist(const char* plist)
{

    if (m_plist_names == NULL) {
        m_plist_names = CCArray::create();
        m_plist_names->retain();
    }
    CCString* str = CCString::createWithFormat("%s",plist);
    if (!m_plist_names->containsObject(str)) {
        m_plist_names->addObject(str);
    }
}
void CCResourceManger::releasePic()
{
    if (m_pic_names != NULL) {
        for (int i = 0; i < m_pic_names->count(); i ++) {
            CCString* str = (CCString*)m_pic_names->objectAtIndex(i);
            CCTextureCache::sharedTextureCache()->removeTextureForKey(str->getCString());
        }
        m_pic_names->removeAllObjects();
        m_pic_names->release();
        m_pic_names = NULL;
    }
}
void CCResourceManger::releasePlist()
{
    if (m_plist_names != NULL) {
        for (int i = 0; i < m_plist_names->count(); i ++) {
            CCString* str = (CCString*)m_plist_names->objectAtIndex(i);
            CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(str->getCString());
            
            CCDictionary* dic = CCDictionary::createWithContentsOfFile(str->getCString());
            CCDictionary* dic0 = (CCDictionary*)dic->objectForKey("metadata");
            CCString* strname = (CCString*)dic0->objectForKey("textureFileName");
            CCTextureCache::sharedTextureCache()->removeTextureForKey(strname->getCString());
            
        }
        m_plist_names->removeAllObjects();
        m_plist_names->release();
        m_plist_names = NULL;
    }
}