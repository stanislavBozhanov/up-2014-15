/*
 * functions.cpp
 *
 *  Created on: 6.11.2014 г.
 *      Author: trifon
 */

#include <cmath>
#include <iostream>
#include "functions.h"
using namespace std;

double square(double);
bool stopProblem(int);

void printSquared(int n) {
	cout << "n = " << n << endl;
	cout << "n^2 = " << square(n) << endl;
	return;
}

int readNumber(int from, int to) {
	int n;
	do {
		cout << "n = "; cin >> n;
	} while (from > n || n > to);
	// from <= n && n <= to
	return n;
}


double triarea(double x1, double y1, double x2, double y2,
				double x3, double y3) {
	double a = distance(x1, y1, x2, y2);
	double b = distance(x2, y2, x3, y3);
	double c = distance(x1, y1, x3, y3);
	return heron(a, b, c);
}
double distance(double x1, double y1, double x2, double y2) {
	return sqrt(square(x2-x1)+square(y2-y1));
}
double heron(double a, double b, double c) {
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double square(double x) {
	return x * x;
}

void testArea() {
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << "S = " << triarea(x1, y1, x2, y2, x3, y3) << endl;
}

int main() {
	// printSquared(readNumber(1, 5+5));
	testArea();
	return 0;
}

