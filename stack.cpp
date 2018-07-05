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

		//top�� ���ÿ� �ִ� �����͸� ��ȯ�Ѵ�.
		else if (cmd == "top") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
		}

		//size�� ���ÿ� �ִ� �������� ������ ��ȯ�Ѵ�.
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}

		//empty�� ��������� 1(true) ������� ������ 0(false)�� ��ȯ.
		else if (cmd == "empty") {
			cout << s.empty() << '\n';
		}

		//pop�� �������� �ִ� �����͸� ��ȯ�Ѵ�. ������ ������ �߻�.
		else if (cmd == "pop") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
			if (!s.empty()) {
				s.pop();
			}
		}
	}
	return 0;
}