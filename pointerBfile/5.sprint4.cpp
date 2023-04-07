#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char header1[12];
	ifstream xx("a.dat", ios::binary | ios::in);
	if (!xx) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
	xx.read(header1, 12 * sizeof(char));

	int* n;
	float* f;
	n = (int*)(header1);
	f = (float*)(header1 + 4);
	float dt = 1. / f[0] / 20.0;
	short* data1; data1 = new short[*n];
	xx.read((char*)data1, n[0] * sizeof(short));
	xx.close();

	char header2[12];
	ifstream yy("b.dat", ios::binary | ios::in);
	if (!yy) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
	yy.read(header2, 12 * sizeof(char));
	short* data2; data2 = new short[*n];
	yy.read((char*)data2, n[0] * sizeof(short));
	yy.close();

	ofstream zz("c.txt");
	if (!zz) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
	for (int i = 0; i < n[0]; i++) zz << i * dt << " " << data1[i] << " " << data2[i] << endl;
	zz.close();

}