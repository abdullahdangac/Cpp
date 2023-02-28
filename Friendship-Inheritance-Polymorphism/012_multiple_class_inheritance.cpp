#include<iostream>
using namespace std;


class glass {
	protected:
		int glass_price;
	public:
		void print_glass_price(){
			cout << "glass price: " << glass_price << endl;
		}
	
};


class frame {
	protected:
		int frame_price;
	public:
		void print_frame_price() {
			cout << "frame price: " << frame_price << endl;
		}
};


class glasses: public glass, public frame {
	private:
		int price;
	public:
		glasses(int gl, int fr) {
			glass_price = gl;
			frame_price = fr;
		}
		void print_price() {
			price = glass_price + frame_price;
			cout << "glasses price: " << price << endl;
		}
};


int main() {
	glasses g1(10, 20);
	g1.print_glass_price();
	g1.print_frame_price();
	g1.print_price();
	
	cout << endl;
	
	glasses* gPtr;
	gPtr = &g1;	
	gPtr->print_glass_price();
	gPtr->print_frame_price();
	gPtr->print_price();	

	return 0;
}
