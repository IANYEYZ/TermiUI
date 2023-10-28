#ifndef _TCOLOR_HPP__
#define _TCOLOR_HPP__
//typedef int color;
struct color{
	int r,g,b;
	color(int r = 0,int g = 0,int b = 0):r(r),g(g),b(b){}
	bool operator==(color o) {
		return (r == o.r && g == o.g && b == o.b);
	}
	bool operator!=(color o) {
		return !(*this == o);
	}
};
void SetColor(color c) {
	string te = "\x1b[48;2;" + to_string(c.r) + ";" + to_string(c.g) + ";" + to_string(c.b) + "m";
	cout << te;
	/*if(c==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
    if(c==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE);
    if(c==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN);
    if(c==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE);
    if(c==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
    if(c==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_BLUE);
    if(c==6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN);*/
}
#endif
