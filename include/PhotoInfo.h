/*************************************************************************
	> File Name: PhotoInfo.h
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Tue 11 Apr 2023 17:50:46 CST
************************************************************************/

#ifndef _PHOTOINFO_H
#define _PHOTOINFO_H

#include "../common/macro.h"

/* 消息快照 */
class PhotoInfo {
private:
	GETSETVAR(int, user_id)
	GETSETVAR(int, last_publisher)//上一个消息发布者
};

#endif
