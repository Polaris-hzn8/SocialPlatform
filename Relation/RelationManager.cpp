/*************************************************************************
    > File Name: RelationManager.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: Wed 12 Apr 2023 11:53:06 CST
************************************************************************/

#include "../common/ret_value.h"
#include "../include/RelationInfo.h"
#include "../include/RelationManager.h"

int RelationManager::user_relation_init(int user_id) {
    if (_relation_count < MAX_RELATION_NUM) {
        _relations[_relation_count].set_user_id(user_id);
        _relation_count++;
        return SUCCESS;
    } else {
        return RELATION_TOO_MUCH;
    }
}

RelationInfo* RelationManager::get_relation(int user_id) {
    for (int i = 0; i < _relation_count; ++i) {
        if (_relations[i].get_user_id() == user_id) return &_relations[i];
    }
    return NULL;
}

int RelationManager::add_relation(int user_id, int other_id) {
    RelationInfo *relation_info = get_relation(user_id);
    if (relation_info == NULL) return RELATION_NOT_EXIST;
    int ret = relation_info->add_friend(other_id);
    return ret;
}

int RelationManager::del_relation(int user_id, int other_id) {
    RelationInfo *relation_info = get_relation(user_id);
    if (relation_info == NULL) return RELATION_NOT_EXIST;
    int ret = relation_info->del_friend(other_id);
    return ret;
}

int RelationManager::add_black(int user_id, int other_id) {
    RelationInfo *relation_info = get_relation(user_id);
    if (relation_info == NULL) return RELATION_NOT_EXIST;
    int ret = relation_info->del_friend(other_id);
    return ret;
}

int RelationManager::del_black(int user_id, int other_id) {
    RelationInfo *relation_info = get_relation(user_id);
    if (relation_info == NULL) return RELATION_NOT_EXIST;
    int ret = relation_info->del_black(other_id);
    return ret;
}

