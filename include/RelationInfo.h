/*************************************************************************
	> File Name: RelationInfo.h
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Tue 11 Apr 2023 17:50:36 CST
************************************************************************/

#ifndef _RELATIONINFO_H
#define _RELATIONINFO_H

#include "../common/macro.h"
#include "../common/setting.h"

class RelationInfo {
private:
	GETSETVAR(int, user_id)
	GETSETVAR(int, friend_count)
	int _friend_list[MAX_FRIEND_NUM];//好友数量限制
	GETSETVAR(int, black_count)
	int _black_list[MAX_BLACK_NUM];//黑名单好友数量限制
public:
	int check_friend(int other_id);
	int check_black(int other_id);

	int add_friend(int other_id);
	int add_black(int other_id);

	int del_friend(int other_id);
	int del_black(int other_id);
	
	int get_friend_by_index(int index);
	int get_black_by_index(int index);
};

#endif
