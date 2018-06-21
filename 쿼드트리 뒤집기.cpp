#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <chrono>

using namespace std;

string reverse(string::iterator &it) {
	char head = *it; 
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	else {
		string upper_left = reverse(it);
		string upper_right = reverse(it);
		string lower_left = reverse(it);
		string lower_right = reverse(it);
		return string("x")+lower_left + lower_right + upper_left + upper_right;
		}
}

int main()
{
	int c;
	cin >> c;
	for (int i = 1; i <= c; i++) {
		string input;
		
		cin >> input;
		string::iterator it = input.begin();
		cout << reverse(it) << endl;
	}
	return 0;
}

