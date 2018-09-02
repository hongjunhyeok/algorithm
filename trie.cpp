#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Trie {


	//��忡 ���� �⺻ ����
	struct Node {
		int children[26]; //26�� ���ĺ�
		bool valid; // true = �����ۼ�, false = �ڵ��ۼ�

		Node() {
			for (int i = 0; i < 26; i++) {
				children[i] = -1;	//children�� -1�� �ʱ�ȭ
			}
			valid = false;			//����� valid = false �ʱ�ȭ.
		}
	};

	vector<Node> trie;	//trie��� �迭�� �ϳ� ����


	int root; //root�� ��ȣ

	//��� �߰� �ϴ� �Լ�
	//��尡 ������ ���� �־��ش�.
	int init() {
		Node x;//��� ����
		trie.push_back(x);//��� �߰�
		return (int)trie.size() - 1;
	}

	//Ʈ���� root�� 0
	Trie() {
		root = init();
	}

	//�տ������� �ϳ��� Ž��
	//s Ž���� string
	//node trie�� ����� ����ȣ
	//index �߰��ɼ��� +1�� �þ �ִ� string�� ����
	void add(int node, string &s, int index) {

		//index�� string�� ���̸�ŭ�̸� ���� ���� �Ŵϱ� true;
		if (index == s.size()) {
			trie[node].valid = true;
			return;
		}

		// s[index]�� ���ڿ��̹Ƿ� �ƽ�Ű�ڵ� ���� ���ָ� ������ ����
		int c = s[index] - 'a';

		// c�� ���� ���ڶ�� ���� �־��ְ�
		if (trie[node].children[c] == -1) {
			int next = init();
			trie[node].children[c] = next;
		}

		//������ �׳� ����.
		int child = trie[node].children[c];
		add(child, s, index + 1);
	}

	//root �⺻���� �߰�
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

