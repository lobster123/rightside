#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void main11() {

	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.insert(v.begin(), 40);
	v.insert(v.end(), 50);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << "acess index at 1 : " << v.at(1) << endl;

	v.erase(v.begin());
	v.erase(v.end() - 1);

	vector<int>::iterator iter = v.begin();

	cout << "access index at 1 with iterator : " << iter[1] << endl;

	while (iter != v.end()) {
		cout << *iter << endl;
		iter++;
	}
}