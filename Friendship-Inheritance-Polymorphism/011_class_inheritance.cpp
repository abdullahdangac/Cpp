#include<iostream>
using namespace std;


class polygon {
	private:
		int priv;
	protected:
		int width;
		int height;
	public:
		void set_values(int wd, int hg) {
			width = wd;
			height = hg;
			priv = 10;
		}		
		virtual int area() {
			return 0;
		}
};


class square: public polygon {
	public:
		int area(){
			return width * height;
		}
};


class triangle: public polygon {
	public:
		int area() {
			return width * height / 2;
		}
	
};


int main(){	
	square sq;
	sq.set_values(2, 4);
	cout << "sq area: "<< sq.area() << endl;
	//cout << sq.priv;  no access
	
	triangle tg;
	tg.set_values(4, 3);
	cout << "tg area: " << tg.area() << endl << endl;
	
	
	polygon* poly1 = &sq;
	polygon* poly2 = &tg;
	
	cout << "sq area: " << poly1->area() << endl;
	cout << "tg area: " << poly2->area() << endl << endl;	
	
	
	typedef polygon* polyPtr;
	
	polyPtr poly3;
	triangle tg2;
	poly3 = &tg2;
	
	poly3->set_values(5, 6);
	cout << "tg2 area: " << poly3->area() << endl;
	
	
	return 0;
}
