#include<iostream>
#include"termiui.hpp"
#define WALK 0
#define STAY 1
using namespace std;
vector<vector<color> > col = {
	{},
	{{0,0,0},{100,100,100},{100,100,100},{100,100,100},{100,100,100},{100,100,100}},
	{{0,0,0},{100,100,100},{100,100,100},{100,100,100},{100,100,100},{100,100,100}},
	{{0,0,0},{100,100,100},{100,100,100},{100,100,100},{100,100,100},{100,100,100}},
	{{0,0,0},{100,100,100},{100,100,100},{100,100,100},{100,100,100},{100,100,100}},
	{{0,0,0},{100,100,100},{100,100,100},{100,100,100},{100,100,100},{100,100,100}},
},col1 = {
	{},
	{{0,0,0},{100,10,10},{100,10,10},{100,10,10},{100,10,10},{100,10,10}},
	{{0,0,0},{100,10,10},{100,10,10},{100,10,10},{100,10,10},{100,10,10}},
	{{0,0,0},{100,10,10},{100,10,10},{100,10,10},{100,10,10},{100,10,10}},
	{{0,0,0},{100,10,10},{100,10,10},{100,10,10},{100,10,10},{100,10,10}},
	{{0,0,0},{100,10,10},{100,10,10},{100,10,10},{100,10,10},{100,10,10}},
},col2 = {
	{},
	{{0,0,0},{10,100,10},{10,100,10},{10,100,10},{10,100,10},{10,100,10}},
	{{0,0,0},{10,100,10},{10,100,10},{10,100,10},{10,100,10},{10,100,10}},
	{{0,0,0},{10,100,10},{10,100,10},{10,100,10},{10,100,10},{10,100,10}},
	{{0,0,0},{10,100,10},{10,100,10},{10,100,10},{10,100,10},{10,100,10}},
	{{0,0,0},{10,100,10},{10,100,10},{10,100,10},{10,100,10},{10,100,10}},
},col3 = {
	{},
	{{0,0,0},{10,100,100},{10,100,100},{10,100,100},{10,100,100},{10,100,100}},
	{{0,0,0},{10,100,100},{10,100,100},{10,100,100},{10,100,100},{10,100,100}},
	{{0,0,0},{10,100,100},{10,100,100},{10,100,100},{10,100,100},{10,100,100}},
	{{0,0,0},{10,100,100},{10,100,100},{10,100,100},{10,100,100},{10,100,100}},
	{{0,0,0},{10,100,100},{10,100,100},{10,100,100},{10,100,100},{10,100,100}},
};
Image ima1 = Image(col,5,5),ima2 = Image(col1,5,5),ima3 = Image(col2,5,5),ima4 = Image(col3,5,5);
vector<Image> v = {ima1,ima2},v1 = {ima3,ima4};
Spirite spi(v),spi1(v1);
vector<Spirite> sp = {spi,spi1};
Object obj(sp,1,1,{1,1,50,50});
void MainLoop(EPARA x) {
	//MainScene.DrawObject(obj);
	//cout << "111" << "\n";
	if(KEY_DOWN('A')) {
		obj.SetSpiriteId(WALK);
		MainScene.MoveObject(obj,0,-1);
	} else if(KEY_DOWN('D')) {
		obj.SetSpiriteId(WALK);
		MainScene.MoveObject(obj,0,1);
	} else if(KEY_DOWN('W')) {
		obj.SetSpiriteId(WALK);
		MainScene.MoveObject(obj,-1,0);
	} else if(KEY_DOWN('S')) {
		obj.SetSpiriteId(WALK);
		MainScene.MoveObject(obj,1,0);
	} else {
		obj.SetSpiriteId(STAY);
		MainScene.DrawObject(obj);
	}
}
int main()
{
	rgb_init();
	//SetTCursorPos(10,10);
	//string te = "\33[" + to_string(10) + ";" + to_string(2 * 10) + ";H";
	//cout << te;
	color x(6);
	SetColor(x);
	//cout << "111";
	//printf("\x1b[%d;%d;H",10,10);
	//printf("111");
	//cout << "\x1b[10;10H" << "111" << endl;
	MainScene.SetW(50);
	MainScene.SetH(50);
	Image im(col,5,5);
	//im.Debug(10,10);
	//im.Show(0,0,MainScene);
	//MainScene.DrawImage(im,0,0);
	//Spirite spi(v);
	//MainScene.Show(0,0);
	obj.SetSpiriteId(STAY);
	MainScene.DrawObjectFirst(obj);
	bind("Loop",MainLoop);
	return TMainLoop();
}