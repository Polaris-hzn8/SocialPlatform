/*************************************************************************
	> File Name: MessageInfo.h
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Tue 11 Apr 2023 17:50:53 CST
************************************************************************/

#ifndef _MESSAGEINFO_H
#define _MESSAGEINFO_H

#include <string>
#include "../common/macro.h"
using namespace std;

class MessageInfo {
private:
	GETSETVAR(int, user_id)
	GETSETVAR(int, message_id)
	GETSETVAR(int, message_time)
	GETSETSTR(1024, message_content)
};

#endif
