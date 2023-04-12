/*************************************************************************
    > File Name: UserManager.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: Wed 12 Apr 2023 09:36:10 CST
************************************************************************/

#include "../include/UserManager.h"
#include "../common/ret_value.h"
#include "../include/UserInfo.h"

int UserManager::start() {
    //remain to be finish
    set_cur_user_id(10001);//read cur_user_id avalible from db
    set_user_count(0);//read users_count/num from db
}

int UserManager::proc() {
    //remain to be finish
}

int UserManager::restart() {
    //remain to be finish
}

int UserManager::shutdown() {
    //remain to be finish
}

UserInfo* UserManager::get_user(int user_id) {
    for (int i = 0; i < _user_count; ++i) {
        if (_users[i].get_user_id() == user_id) return &_users[i];
    }
    return NULL;
}

int UserManager::check_exist(int user_id) {
    for (int i = 0; i < _user_count; ++i) {
        if (_users[i].get_user_id() == user_id) return USER_ALREADY_EXIST;
    }
    return USER_NOT_EXIST;
}

int UserManager::create_user(const char *user_name, const char *passwd, int from, int reg_time) {
    for (int i = 0; i < _user_count; ++i) {
        if (!strcmp(_users[i].get_user_name(), user_name)) return USER_ALREADY_EXIST;
    }
    if (_user_count < MAX_USER_NUM) {
        _users[_user_count].set_user_id(get_cur_user_id());
        _users[_user_count].set_user_name(user_name);
        _users[_user_count].set_passwd(passwd);
        _users[_user_count].set_reg_from(from);
        _users[_user_count].set_reg_time(reg_time);
        _users[_user_count].set_db_flag(DBFLAG_INSERT);
        _user_count++;
    }
    //todo saveuser() in db
}

int UserManager::delete_user(int user_id) {
    for (int i = 0; i < _user_count; ++i) {
        if (_users[i].get_user_id() == user_id) {
            /* 回写数据库的方式进行用户信息数据的删除 */
            _users[i].set_db_flag(DBFLAG_DELETE);
            return SUCCESS;
        }
    }
    return USER_NOT_EXIST;
}

int UserManager::save_user() {
    //todo save userInfo into db

}

int UserManager::login_check(const char *user_name, const char *passwd) {
    for (int i = 0; i < _user_count; ++i) {
        if (!strcmp(_users[i].get_user_name(), user_name)) {
            if (!strcmp(_users[i].get_passwd(), passwd)) return SUCCESS;
            return WRONG_PASSWD;
        }
    }
    return USER_NOT_EXIST;
}

int UserManager::logout(int user_id, int time_now) {
    for (int i = 0; i < _user_count; ++i) {
        if (_users[i].get_user_id() == user_id) {
            _users[i].set_logout_time(time_now);
            return SUCCESS;
        }
    }
    return USER_NOT_EXIST;
}

int UserManager::get_userid_by_name(const char *user_name) {
    for (int i = 0; i < _user_count; ++i) {
        if (!strcmp(_users[i].get_user_name(), user_name)) {
            return _users[i].get_user_id();
        }
    }
    return USER_NOT_EXIST;
}


int UserManager::update_user_login_time(int user_id, int time_now) {
    for (int i = 0; i < _user_count; ++i) {
        if (_users[i].get_user_id() == user_id) {
            _users[i].set_login_time(time_now);
            _users[i].set_db_flag(DBFLAG_UPDATE);//数据定时统一回写
            return SUCCESS;
        }
    }
    return USER_NOT_EXIST;
}

int UserManager::update_user_logout_time(int user_id, int time_now) {
    for (int i = 0; i < _user_count; ++i) {
        if (_users[i].get_user_id() == user_id) {
            _users[i].set_logout_time(time_now);
            _users[i].set_db_flag(DBFLAG_UPDATE);//数据定时统一回写
            return SUCCESS;
        }
    }
    return USER_NOT_EXIST;
}

int UserManager::update_user_fresh_time(int user_id, int time_now) {
    for (int i = 0; i < _user_count; ++i) {
        if (_users[i].get_user_id() == user_id) {
            _users[i].set_fresh_time(time_now);
            _users[i].set_db_flag(DBFLAG_UPDATE);//数据定时统一回写
            return SUCCESS;
        }
    }
    return USER_NOT_EXIST;
}



