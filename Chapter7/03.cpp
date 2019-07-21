#include <iostream>
using namespace std;

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volum;
};

void output(const box bs);
void volume(box * pb);

int main() {
	box cube = { "rubics", 3.5, 4.5, 6 };
	volume(&cube);
	output(cube);
	return 0;
}

void output(const box bs) {
	cout << bs.maker << endl;
	cout << bs.height << endl;
	cout << bs.width << endl;
	cout << bs.length << endl;
	cout << bs.volum << endl;
}

void volume(box * pb) {
	pb->volum = pb->height * pb->width * pb->length;
}