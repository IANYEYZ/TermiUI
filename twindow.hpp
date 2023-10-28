#ifndef _TWINDOW_HPP__
#define _TWINDOW_HPP__
class Scene{
	private:
		stack<color> a[110][110];
		int w,h;
	public:
		Scene(){}
		Scene(int h,int w):h(h),w(w) {
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					a[i][j].push(color(0,0,0));
				}
			}
		}
		Scene operator=(Scene o) {
			h = o.h;
			w = o.w;
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					a[i][j] = o.a[i][j];
				}
			}
		}
		void Show(int x,int y) {
			//printf("works here!");
			SetTCursorPos(x,y);
			//printf("works here!");
			/*for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					//SetColor(a[i][j].top());
					printf("%d",a[i][j].size());
				}
				printf("\n");
			}*/
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					SetColor(a[i][j].top());
					cout << "  ";
				}
				cout << "\n";
			}
		}
		void ShowWithLst(int x,int y,Scene lst) {
			SetTCursorPos(x,y);
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					if(lst.a[i][j].empty() || a[i][j].top() != lst.a[i][j].top()) {
						SetTCursorPos(x + i - 1,y + j - 1);
						SetColor(a[i][j].top());
						cout << "  ";
					}
				}
				//cout << "\n";
			}
		}
		void Clear(int x,int y,color Bg) {
			SetTCursorPos(x,y);
			SetColor(Bg);
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					cout << "  ";
				}
				cout << "\n";
			}
		}
		void Set(int x,int y,color x1) {
			a[x][y].push(x1);
		}
		void Del(int x,int y) {
			a[x][y].pop();
		}
		void SetW(int w1) {
			w = w1;
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					if(a[i][j].size() == 0) a[i][j].push(color(0,0,0));
				}
			}
		}
		void SetH(int h1) {
			h = h1;
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					if(a[i][j].size() == 0) a[i][j].push(color(0,0,0));
				}
			}
		}
		void DrawImage(Image ima,int x,int y) {
			vector<vector<color> > tem = ima.GetImage();
			//cout << tem.size() << "\n";
			int h = ima.GetH(),w = ima.GetW();
			for(int i = x;i <= x + h - 1;i++) {
				for(int j = y;j <= y + w - 1;j++) {
					//cout << i - x + 1 << " " << j - y + 1 << "\n";
					Set(i,j,tem[i - x + 1][j - y + 1]);
				}
			}
			//cout << "Worked here!" << "\n";
		}
		void ClearImage(Image ima,int x,int y) {
			//vector<vector<color> > tem = ima.GetImage();
			int h = ima.GetH(),w = ima.GetW();
			for(int i = x;i <= x + h - 1;i++) {
				for(int j = y;j <= y + w - 1;j++) {
					Del(i,j);
				}
			}
		}
		void DrawSpirite(Spirite& spi,int x,int y) {
			Image ima1 = spi.GetImage();
			ClearImage(ima1,x,y);
			//cout << "Worked here" << "\n";
			spi.NextImage();
			Image ima2 = spi.GetImage();
			//cout << "Worked here" << "\n";
			DrawImage(ima2,x,y);
			//cout << "Worked here" << "\n";
		}
		void DrawSpiriteFirst(Spirite& spi,int x,int y) {
			//cout << "Worked here" << "\n";
			Image ima2 = spi.GetImage();
			//cout << "Worked here" << "\n";
			DrawImage(ima2,x,y);
			//cout << "Worked here" << "\n";
		}
		void ClearSpirite(Spirite& spi,int x,int y) {
			//cout << "Worked here" << "\n";
			Image ima2 = spi.GetImage();
			//cout << "Worked here" << "\n";
			ClearImage(ima2,x,y);
			//cout << "Worked here" << "\n";
		}
		void DrawObjectFirst(Object& obj) {
			int x = obj.Getposx();
			int y = obj.Getposy();
			Spirite tspi = obj.GetSpirite();
			DrawSpiriteFirst(tspi,x,y);
		}
		void DrawObject(Object& obj) {
			int x = obj.Getposx();
			int y = obj.Getposy();
			Spirite tspi = obj.GetSpirite();
			DrawSpirite(tspi,x,y);
			obj.SetSpirite(tspi);
		}
		void MoveObject(Object& obj,int dx,int dy) {
			int x = obj.Getposx();
			int y = obj.Getposy();
			Spirite tspi =  obj.GetSpirite();
			ClearSpirite(tspi,x,y);
			//cout << "Worked here!" << "\n";
			tspi.NextImage();
			//cout << "Worked here!" << "\n";
			obj.move(dx,dy);
			//cout << "Worked here!" << "\n";
			int x1 = obj.Getposx();
			int y1 = obj.Getposy();
			//cout << "Worked here!" << "\n";
			DrawSpiriteFirst(tspi,x1,y1);
			//cout << "Worked here!" << "\n";
			obj.SetSpirite(tspi);
		}
}MainScene;
int TMainLoop() {
	int cnt = 0;
	Scene lst;
	while(1) {
		cnt++;
		asyncevent("Loop",(EPARA)cnt);
		SetTCursorPos(0,0);
		MainScene.ShowWithLst(0,0,lst);
		lst = MainScene;
	}
	return 0;
}
#endif
