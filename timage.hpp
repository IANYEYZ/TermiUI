#ifndef _TIMAGE_HPP__
#define _TIMAGE_HPP__
struct Image{
	private:
		color image[110][110];
		int h,w;
	public:
		Image(vector<vector<color> > ima,int h,int w):h(h),w(w) {
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					image[i][j] = ima[i][j];
				}
			}
			//printf("works here!");
		}
		Image operator=(Image o) {
			h = o.h;
			w = o.w;
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					image[i][j] = o.image[i][j];
				}
			}
		}
		/*void Show(int x,int y,Scene &s) {
			//SetCursorPos(x,y);
			for(int i = x;i <= x + h - 1;i++) {
				for(int j = y;j <= y + w - 1;j++) {
					//if(image[i][j]) printf("  ");
					s.Set(x,y,image[i][j]);
				}
				//printf("\n");
			}
		}
		void Clear(int x,int y,Scene &s) {
			//SetCursorPos(x,y);
			//SetColor(Bg);
			for(int i = x;i <= x + h - 1;i++) {
				for(int j = y;j <= y + w - 1;j++) {
					//printf("  ");
					s.Del(i,j);
				}
				//printf("\n");
			}
		}*/
		void Debug(int x,int y) {
			SetTCursorPos(x,y);
			for(int i = 1;i <= h;i++) {
				for(int j = 1;j <= w;j++) {
					SetColor(image[i][j]);
					printf("  ");
				}
				printf("\n");
			}
		}
		vector<vector<color> > GetImage() {
			vector<vector<color> > res;
			res.push_back({});
			for(int i = 1;i <= h;i++) {
				vector<color> te;
				te.push_back({0,0,0});
				for(int j = 1;j <= w;j++) {
					te.push_back(image[i][j]);
				}
				res.push_back(te);
			}
			return res;
		}
		int GetH() {
			return h;
		}
		int GetW() {
			return w;
		}
};
#endif
