#ifndef _TCURSOR_HPP__
#define _TCURSOR_HPP__
void SetTCursorPos(int x,int y) {
	string te = "\x1b[" + to_string(x) + ";" + to_string(2 * y) + "H";
	cout << te;
	/*COORD pos;
    pos.X=y*2,pos.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);*/
}
void ShowCursor() {
	cout << "\x1b[?25h";
}
void HideCursor() {
	cout << "\x1b[?25l";
}
#endif
