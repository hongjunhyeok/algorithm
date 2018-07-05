#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	stack<int> s;
	while (n--) {

		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}

		//top은 스택에 있는 데이터를 반환한다.
		else if (cmd == "top") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
		}

		//size는 스택에 있는 데이터의 개수를 반환한다.
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}

		//empty는 비어있으면 1(true) 비어있지 않으면 0(false)를 반환.
		else if (cmd == "empty") {
			cout << s.empty() << '\n';
		}

		//pop은 스택위에 있는 데이터를 반환한다. 없으면 에러가 발생.
		else if (cmd == "pop") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
			if (!s.empty()) {
				s.pop();
			}
		}
	}
	return 0;
}