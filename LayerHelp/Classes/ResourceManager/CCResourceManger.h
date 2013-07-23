//
//  CCResourceManger.h
//  Rockey
//
//  Created by 123 on 13-7-11.
//
//

#ifndef __Rockey__CCResourceManger__
#define __Rockey__CCResourceManger__

#include "cocos2d.h"

class CCResourceManger {
    
    cocos2d::CCArray* m_pic_names;
    cocos2d::CCArray* m_plist_names;
public:
    CCResourceManger();
    ~CCResourceManger();
public:
    void addPic(const char* pic);
    void addPlist(const char* plist);
    void releasePic();
    void releasePlist();
};

#endif /* defined(__Rockey__CCResourceManger__) */
