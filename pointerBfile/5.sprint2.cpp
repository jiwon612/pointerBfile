#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char header[12];
	ifstream xx("a.dat", ios::binary | ios::in);
	if (!xx) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
	xx.read(header, 12 * sizeof(char));
	xx.close();

	int* n;
	float* f;
	short* a;
	n = (int*)(header);
	f = (float*)(header + 4);
	a = (short*)(header + 8);
	*f = 700;

	short* data; data = new short[*n];
	const float pi = 3.141592;
	float dt = 1. / 1000 / 20.0;
	for (int i = 0; i < n[0]; i++) data[i] = (short)(a[0] * sin(2.0 * pi * f[0] * i * dt));

	ofstream yy("b.dat", ios::binary | ios::out);
	if (!yy) return 666;
	yy.write(header, sizeof(header));
	yy.write((char*)data, n[0] * sizeof(short));
	yy.close();
}