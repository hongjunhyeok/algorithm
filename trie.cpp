#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Trie {


	//노드에 대한 기본 세팅
	struct Node {
		int children[26]; //26은 알파벳
		bool valid; // true = 직접작성, false = 자동작성

		Node() {
			for (int i = 0; i < 26; i++) {
				children[i] = -1;	//children값 -1로 초기화
			}
			valid = false;			//노드의 valid = false 초기화.
		}
	};

	vector<Node> trie;	//trie라는 배열을 하나 생성


	int root; //root의 번호

	//노드 추가 하는 함수
	//노드가 없으면 만들어서 넣어준다.
	int init() {
		Node x;//노드 생성
		trie.push_back(x);//노드 추가
		return (int)trie.size() - 1;
	}

	//트리의 root는 0
	Trie() {
		root = init();
	}

	//앞에서부터 하나씩 탐방
	//s 탐방할 string
	//node trie에 저장될 노드번호
	//index 추가될수록 +1이 늘어남 최대 string의 길이
	void add(int node, string &s, int index) {

		//index가 string의 길이만큼이면 내가 넣은 거니까 true;
		if (index == s.size()) {
			trie[node].valid = true;
			return;
		}

		// s[index]는 문자열이므로 아스키코드 값을 뺴주면 정수가 나옴
		int c = s[index] - 'a';

		// c가 없는 문자라면 만들어서 넣어주고
		if (trie[node].children[c] == -1) {
			int next = init();
			trie[node].children[c] = next;
		}

		//있으면 그냥 간다.
		int child = trie[node].children[c];
		add(child, s, index + 1);
	}

	//root 기본으로 추가
	void add(string &s) {
		add(root, s, 0);
	}

	bool search(int node, string &s, int index) {
		if (node == -1) return false;
		if (index == s.length()) return true;
		int c = s[index] - 'a';
		int child = trie[node].children[c];

		return search(child, s, index + 1);
	}
	
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	Trie trie;
	while (n--) {
		string s;
		cin >> s;
		trie.add(s);
	}
	int ans = 0;
	while (m--) {
		string s;
		cin >> s;
		if (trie.search(s)) {
			ans += 1;
		}
	}

	cout << ans << '\n';

}

