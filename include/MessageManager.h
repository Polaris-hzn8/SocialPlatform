/*************************************************************************
	> File Name: MessageManager.h
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Wed 12 Apr 2023 12:59:45 PM CST
 ************************************************************************/

#ifndef _MESSAGEMANAGER_H
#define _MESSAGEMANAGER_H

#include "../include/MessageInfo.h"

class MessageManager {
private:
	MessageInfo _messages[10240];
	GETSETVAR(int, message_count)
public:
	void start();
	void proc();
	void shutdown();
	void restart();
public:
    MessageInfo *get_message(int user_id, int message_id);
    MessageInfo *get_message(int message_id);
    int get_message(int message_id, MessageInfo &message_info);
    int publish_message(int publisher, string content, int publish_time, int &message_id);
    int publish_message(MessageInfo message, int &message_id);
    int modify_message(int user_id, int message_id, int modify_time, string &content);
    int delete_message(int user_id, int message_id);
    int delete_message(int message_id);
};

#endif
