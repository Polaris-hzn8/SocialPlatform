/*************************************************************************
	> File Name: UserManager.h
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Wed 12 Apr 2023 09:00:38 AM CST
 ************************************************************************/

#ifndef _USERMANAGER_H
#define _USERMANAGER_H

#include "../common/macro.h"
#include "../common/setting.h"
#include "UserInfo.h"

class UserManager {
private:
	UserInfo _users[MAX_USER_NUM];
	GETSETVAR(int, user_count)
	GETSETVAR(int, cur_user_id)//系统自动为用户绑定的user_id
public:
	/* 归于UserManager服务器的基本操作 */
	int start();
	int proc();
	int restart();
	int shutdown();
public:
	UserInfo *get_user(int user_id);
	int check_exist(int user_id);

	int create_user(const char *user_name, const char *passwd, int from, int reg_time);
	int delete_user(int user_id);
	int save_user();

	int login_check(const char *user_name, const char *passwd);
	int logout(int user_id, int time_now);

	int get_userid_by_name(const char *user_name);

	int update_user_login_time(int user_id, int time_now);
	int update_user_logout_time(int user_id, int time_now);
	int update_user_fresh_time(int user_id, int time_now);
};


#endif
