#ifndef _TCOMPONENTS_HPP__
#define _TCOMPONENTS_HPP__
class BaseComponent{
	private:
		vector<Spirite> v;
	public:
		virtual void Draw(){}
		virtual void DrawFirst(){}
};
class Button : BaseComponent{
	private:
		int x,y,w,h;
	public:
		Button(int x,int y,int w,int h,color col,color hover_col):x(x),y(y),w(w),h(h){
			
		}
};
#endif
