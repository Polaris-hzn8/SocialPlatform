/*************************************************************************
	> File Name: RelationManager.h
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Wed 12 Apr 2023 11:03:32 AM CST
 ************************************************************************/

#ifndef _RELATIONMANAGER_H
#define _RELATIONMANAGER_H

#include "../common/macro.h"
#include "../common/setting.h"
#include "../include/RelationInfo.h"

class RelationManager {
private:
	RelationInfo _relations[MAX_RELATION_NUM];
	GETSETVAR(int, relation_count)
public:
	/* 归于UserManager服务器的基本操作 */
	int start();
	int proc();
	int restart();
	int shutdown();
public:
	int user_relation_init(int user_id);
	RelationInfo *get_relation(int user_id);

	int add_relation(int user_id, int other_id);
	int del_relation(int user_id, int other_id);
	int add_black(int user_id, int other_id);
	int del_black(int user_id, int other_id);
};

#endif
