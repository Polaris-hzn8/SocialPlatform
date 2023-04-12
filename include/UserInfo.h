/*************************************************************************
	> File Name: UserInfo.h
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Tue 11 Apr 2023 17:50:04 CST
************************************************************************/

#ifndef _USERINFO_H
#define _USERINFO_H

#include "../common/macro.h"

/* 设置数据为固定大小 便于内存管理内存的动态申请与释放 */
/* 包括便于后期将其封装成内存池管理 */
class UserInfo {
private:
	GETSETVAR(int, user_id)
	GETSETSTR(256, user_name)
	GETSETSTR(256, nick_name)
	GETSETSTR(256, passwd)

	GETSETVAR(int, reg_time)//注册时间
	GETSETVAR(int, reg_from)//注册渠道
	GETSETVAR(int, login_time)//登录时间
	GETSETVAR(int, last_login_time)//上次登录时间
	GETSETVAR(int, logout_time)//登录时间
	GETSETVAR(int, fresh_time)//上次刷新时间

	GETSETVAR(int, db_flag)//数据是否回写数据库
};

#endif
