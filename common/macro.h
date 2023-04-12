/*************************************************************************
	> File Name: macro.h
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Tue 11 Apr 2023 05:58:44 PM CST
 ************************************************************************/

#ifndef _MACRO_H
#define _MACRO_H

#include<cstring>

/* 利用宏定义自动生成GTE\SET方法 */
/* 灵活应用const类型 减少对象的拷贝 */
/* 函数前const:普通函数或成员函数（非静态成员函数）前均可加const修饰，表示函数的返回值为const，不可修改 */
/* 函数后const：只有类的非静态成员函数后可以加const修饰，表示该类的this指针为const类型，不能改变类的成员变量的值，即成员变量为read only */
#define GETSETVAR(type, name) \
	private: \
		type _##name; \
	public: \
		const type& get_##name() const { \
			return _##name; \
		} \
		void set_##name(const type& value) { \
			_##name = value; \
		}

#define GETSETSTR(size, name) \
	private: \
		char _##name[size]; \
	public: \
		const char* get_##name() const { \
			return _##name; \
		} \
		void set_##name(const char* value) { \
			strncpy(_##name, value, size); \
		}

#endif
