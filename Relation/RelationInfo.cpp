/*************************************************************************
    > File Name: RelationInfo.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: Tue 11 Apr 2023 22:00:43 CST
************************************************************************/

#include "../include/RelationInfo.h"
#include "../common/ret_value.h"
#include "../common/setting.h"

int RelationInfo::check_friend(int other_id) {
    for (int i = 0; i < _friend_count; ++i) {
        if (_friend_list[i] == other_id) return SUCCESS;
    }
    return NOT_FRIEND;
}

int RelationInfo::check_black(int other_id) {
    for (int i = 0; i < _black_count; ++i) {
        if (_black_list[i] == other_id) return SUCCESS;
    }
    return NOT_BLACK;
}

int RelationInfo::add_friend(int other_id) {
    if (check_friend(other_id) == SUCCESS) return ALREADY_FRIEND;
    if (_friend_count < MAX_FRIEND_NUM) {
        _friend_list[_friend_count] = other_id;
        _friend_count++;
    } else {
        return FRIEND_TOO_MUCH;
    }
    return SUCCESS;
}

int RelationInfo::add_black(int other_id) {
    if (check_black(other_id) == SUCCESS) return ALREADY_BLACK;
    if (_black_count < MAX_BLACK_NUM) {
        _black_list[_black_count] = other_id;
        _black_count++;
    } else {
        return BLACK_TOO_MUCH;
    }
    return SUCCESS;
}

int RelationInfo::del_friend(int other_id) {
    if (check_friend(other_id) == SUCCESS) {
        for (int i = 0; i < _friend_count; ++i) {
            if (_friend_list[i] == other_id) {
                /* 将 other_id 从 _friend_list 中删去 */
                for (int k = i; k < _friend_count - 1; ++k) _friend_list[k] = _friend_list[k + 1];
                _friend_list[_friend_count - 1] = -1;
                break;
            }
        }
        _friend_count--;
    } else {
        return NOT_FRIEND;
    }
}

int RelationInfo::del_black(int other_id) {
    if (check_friend(other_id) == SUCCESS) {
        for (int i = 0; i < _black_count; ++i) {
            if (_black_list[i] == other_id) {
                /* 将 other_id 从 _friend_list 中删去 */
                for (int k = i; k < _black_count - 1; ++k) _black_list[k] = _black_list[k + 1];
                _black_list[_black_count - 1] = -1;
                break;
            }
        }
        _black_count--;
    } else {
        return NOT_BLACK;
    }
}

int RelationInfo::get_friend_by_index(int index) {
    if (index < 0 || index > _friend_count) return FRIEND_INDEX_WRONG;
    return _friend_list[index];
}

int RelationInfo::get_black_by_index(int index) {
    if (index < 0 || index > _black_count) return BLACK_INDEX_WRONG;
    return _black_list[index];
}



