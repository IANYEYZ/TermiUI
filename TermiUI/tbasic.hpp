#ifndef _TBASIC_HPP__
#define _TBASIC_HPP__
#include"tevent.hpp"
#include"tcolor.hpp"
#include"tcursor.hpp"
#include"tds.hpp"

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
void rgb_init() {																// ��ʼ��
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);		//������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//������
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);						//��ȡ����̨����ģʽ
	GetConsoleMode(hOut, &dwOutMode);					//��ȡ����̨���ģʽ
	dwInMode |= 0x0200;									//����
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);						//���ÿ���̨����ģʽ
	SetConsoleMode(hOut, dwOutMode);					//���ÿ���̨���ģʽ
}
#endif
