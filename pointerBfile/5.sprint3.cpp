#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char header[12];
	int* n;   n = (int*)header;  *n = 500;
	float* f;   f = (float*)(header + 4);  *f = 1000;
	short* a;   a = (short*)(header + 8);  *a = 500;
	short* p;   p = (short*)(header + 10);  *p = 12;

	short* data; data = new short[*n];
	const float pi = 3.141592;
	float dt = 1. / f[0] / 20.0;
	for (int i = 0; i < n[0]; i++)       //   *n�� n[0]�� ����.
		data[i] = (short)(a[0] * sin(2.0 * pi * f[0] * i * dt));

	ofstream xx("a.dat", ios::binary | ios::out);
	if (!xx) return 666;  // ���� ������ ������ ������ ���α׷��� ������.
	xx.write(header, 12 * sizeof(char));
	xx.write((char*)data, n[0] * sizeof(short));
	xx.close();
}
