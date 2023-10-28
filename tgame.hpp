#ifndef _TGAME_HPP__
#define _TGAME_HPP__
class View2D{
	private:
		int x1,y1,x2,y2;
	public:
		View2D() {}
		View2D(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2) {}
		bool IsOutside(int x,int y) {
			if(x < x1 || y < y1 || x > x2 || y > y2) {
				return true;
			} else {
				return false;
			}
		}
		pair<pair<int,int>,pair<int,int> > Get() {
			return {{x1,y1},{x2,y2}};
		}
		View2D operator=(View2D o) {
			x1 = o.x1;
			x2 = o.x2;
			y1 = o.y1;
			y2 = o.y2;
		}
}MainCamera;
class Spirite{
	private:
		vector<Image> v;
		int cnt;
	public:
		Spirite(vector<Image> v1) {
			v = v1;
			cnt = 0;
		}
		Spirite(){v.clear();cnt = 0;}
		void AddImage(Image ima) {
			v.push_back(ima);
		}
		void NextImage() {
			//cout << "Do Next Image!" << cnt << " " << v.size() << "\n";
			cnt++;
			if(cnt >= v.size()) cnt = 0;
		}
		void PreviousImage() {
			cnt--;
			if(cnt < 0) cnt = v.size() - 1;
		}
		Image GetImage() {
			return v[cnt];
		}
};
class Object{
	private:
		vector<Spirite> spi;
		int posx,posy,cnt;
		View2D Able;
	public:
		Object(){}
		Object(vector<Spirite> spi,int posx,int posy,View2D Able):spi(spi),posx(posx),posy(posy),Able(Able),cnt(0){}
		void move(int dx,int dy) {
			//img.Clear()
			if(Able.IsOutside(posx + dx,posy + dy) == true || Able.IsOutside(posx + dx + spi[cnt].GetImage().GetH() + 1,posy + dy + spi[cnt].GetImage().GetW() + 1)) return;
			posx += dx;
			posy += dy;
		}
		Spirite GetSpirite() {
			return spi[cnt];
		}
		void SetSpirite(Spirite o) {
			spi[cnt] = o;
		}
		int Getposx() {
			return posx;
		}
		int Getposy() {
			return posy;
		}
		void NextSpirite() {
			cnt++;
			if(cnt >= spi.size()) cnt = 0;
		}
		void PreviousSpirite() {
			cnt--;
			if(cnt < 0) cnt = spi.size() - 1;
		}
		void AddSpirite(Spirite o) {
			spi.push_back(o);
		}
		void SetSpiriteId(int cnt1) {
			cnt = cnt1;
		}
};
#endif
