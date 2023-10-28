#ifndef _TBASIC_HPP__
#define _TBASIC_HPP__
#include"tevent.hpp"
#include"tcolor.hpp"
#include"tcursor.hpp"
#include"tds.hpp"

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
void rgb_init() {																// 初始化
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);		//输入句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//输出句柄
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);						//获取控制台输入模式
	GetConsoleMode(hOut, &dwOutMode);					//获取控制台输出模式
	dwInMode |= 0x0200;									//更改
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);						//设置控制台输入模式
	SetConsoleMode(hOut, dwOutMode);					//设置控制台输出模式
}
#endif
