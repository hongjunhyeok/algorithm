/*

ī�������� ���� ���� ���� �˰���

*/

#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <chrono>

using namespace std;



//num[]�� �ڸ��� �ø��� ó���Ѵ�

void normalize(vector<int> &num)

{

	num.push_back(0);

	//�ڸ��� �ø��� ó���Ѵ�

	for (int i = 0; i < num.size() - 1; i++) //num.size()-1 �߿�

	{

		if (num[i] < 0)

		{

			int borrow = (abs(num[i]) + 9) / 10;

			num[i + 1] -= borrow;

			num[i] += borrow * 10;

		}

		else

		{

			num[i + 1] += num[i] / 10;

			num[i] %= 10;

		}

	}

	while (num.size() > 1 && num.back() == 0)

		num.pop_back();

}

//�� �� �ڿ����� ���� ��ȯ�Ѵ�

//�� �迭���� �� ���� �ڸ����� 1�� �ڸ��������� ������ ����Ǿ� �ִ�

//��:multiply([3,2,1], [6,5,4])=123*456=56088=[8, 8, 0, 6, 5]

vector<int> multiply(const vector<int> &a, const vector<int> &b)

{

	vector<int> c(a.size() + b.size() + 1, 0);

	for (int i = 0; i < a.size(); i++)

		for (int j = 0; j < b.size(); j++)

			c[i + j] += (a[i] * b[j]);

	normalize(c);

	return c;

}



/*

//a+=b*(10^k)�� �����Ѵ�

vector<int> addTo(vector<int> &a, const vector<int> &b, int k)

{

vector<int> b1, c;

for (int i = 0; i < k; i++)

b1.push_back(0);

for (int i = 0; i < b.size(); i++)

b1.push_back(b[i]);

c.resize(a.size() + b1.size() + 1, 0);



vector<int> rest = (a.size() >= b1.size()) ? a : b1; //������ ��ġ�� �� �� �κ��� ���ؾ��Ѵ�

int length = min(a.size(), b1.size());



for(int i=0; i<length; i++)

c[i] += (a[i] + b1[i]);

if (length != rest.size()) //���� �ڸ����� �ٸ��ٸ�

{

for (int i = length; i < rest.size(); i++)

c[i] += rest[i];

}

//����ȭ

for (int i = 0; i < c.size(); i++)

{

if (c[i] > 10)

{

c[i + 1] += c[i] / 10;

c[i] %= 10;

}

}

while (c.size() > 1 && c.back() == 0)

c.pop_back();

return c;

}



//a-=b;�� �����Ѵ� a>=b�� �����Ѵ�

vector<int> subFrom(vector<int> &a, const vector<int> &b)

{

vector<int> c;

c.resize(a.size(), 0);

for (int i = 0; i < b.size(); i++)//a>=b�̹Ƿ�

{

c[i] += (a[i] - b[i]);

}

if (a.size() != b.size()) //���� �ڸ����� �ٸ��ٸ�

{

for (int i = b.size(); i < a.size(); i++) //������

c[i] += a[i];

}

//����ȭ

for (int i = 0; i < c.size(); i++)

if (c[i] < 0)

{

c[i] += 10;

c[i + 1]-=1;

}

while (c.size() > 1 && c.back() == 0)

c.pop_back();

return c;

}



//�� �� ������ ���� ��ȯ�Ѵ�

//(a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)�� ����

vector<int> karatsuba(const vector<int> &a, const vector<int> &b)

{

int an = a.size(), bn = b.size();

//a�� b���� ª�� ��� ���� �ٲ۴�

if (an < bn)

return karatsuba(b, a);

//���� ���:a�� b�� ����ִ� ���

if (an == 0 || bn == 0)

return vector<int>();

//���� ���:a�� ���� ª�� ��� O(n^2) �������� �����Ѵ�

if (an <= 5)

return multiply(a, b);

int half = an / 2;

//a�� b�� �ؿ��� half�ڸ��� �������� �и��Ѵ�

vector<int> a0(a.begin(), a.begin() + half);

vector<int> a1(a.begin() + half, a.end());

vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));

vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

//z2=a1*b1

vector<int> z2 = karatsuba(a1, b1);

//z0=a0*b0

vector<int> z0 = karatsuba(a0, b0);

//a0=a0+a1;

//b0=b0+b1

a0=addTo(a0, a1, 0);

b0=addTo(b0, b1, 0);

//z1=(a0+a1)*(b0+b1)-z0-z2

vector<int> z1 = karatsuba(a0, b0);

z1=subFrom(z1, z0);

z1=subFrom(z1, z2);

//result=z0+z1*10^half+z2*10^(half*2)

vector<int> result;

result=addTo(result, z0, 0);

result=addTo(result, z1, half);

result=addTo(result, z2, half + half);

return result;

}

*/



//a+=b*(10^k)�� �����Ѵ�

void addTo(vector<int> &a, const vector<int> &b, int k)

{

	int length = b.size();

	a.resize(max(a.size(), b.size() + k));



	for (int i = 0; i< length; i++)

		a[i + k] += b[i]; //�̷��� �����ν� ���� �ٸ� vector�� �������� �ʾƵ� �ǰ� ����������



						  //����ȭ              

	for (int i = 0; i < a.size(); i++)

	{

		if (a[i] > 10)

		{

			a[i + 1] += a[i] / 10;

			a[i] %= 10;

		}

	}

}



//a-=b;�� �����Ѵ� a>=b�� �����Ѵ�

void subFrom(vector<int> &a, const vector<int> &b)

{

	int length = b.size();

	a.resize(max(a.size(), b.size()) + 1);



	for (int i = 0; i< length; i++)

		a[i] -= b[i];



	//����ȭ

	for (int i = 0; i < a.size(); i++)

	{

		if (a[i] < 0)

		{

			a[i] += 10;

			a[i + 1] -= 1;

		}

	}

}



//�� �� ������ ���� ��ȯ�Ѵ�

//(a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)�� ����

vector<int> karatsuba(const vector<int> &a, const vector<int> &b)

{

	int an = a.size(), bn = b.size();

	//a�� b���� ª�� ��� ���� �ٲ۴�

	if (an < bn)

		return karatsuba(b, a);

	//���� ���:a�� b�� ����ִ� ���

	if (an == 0 || bn == 0)

		return vector<int>();

	//���� ���:a�� ���� ª�� ��� O(n^2) �������� �����Ѵ�

	if (an <= 5)

		return multiply(a, b);

	int half = an / 2;

	//a�� b�� �ؿ��� half�ڸ��� �������� �и��Ѵ�

	vector<int> a0(a.begin(), a.begin() + half);

	vector<int> a1(a.begin() + half, a.end());

	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));

	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	//z2=a1*b1

	vector<int> z2 = karatsuba(a1, b1);

	//z0=a0*b0

	vector<int> z0 = karatsuba(a0, b0);

	//a0=a0+a1;

	//b0=b0+b1

	addTo(a0, a1, 0);

	addTo(b0, b1, 0);

	//z1=(a0+a1)*(b0+b1)-z0-z2

	vector<int> z1 = karatsuba(a0, b0);

	subFrom(z1, z0);

	subFrom(z1, z2);

	//result=z0+z1*10^half+z2*10^(half*2)

	vector<int> result;

	addTo(result, z0, 0);

	addTo(result, z1, half);

	addTo(result, z2, half + half);

	return result;

}



int main(void)

{

	using namespace std::chrono;



	vector<int> a, b, result;

	string number;

	high_resolution_clock::time_point t1, t2;

	duration<double> time_span; //�ð� ��� ����
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {


		cout << "ù��° ���� �Է�: ";

		cin >> number;

		for (int i = number.size() - 1; i >= 0; i--)

			a.push_back(number[i] - '0');

		cout << "�ι�° ���� �Է�: ";

		cin >> number;

		for (int i = number.size() - 1; i >= 0; i--)

			b.push_back(number[i] - '0');



		t1 = high_resolution_clock::now();

		result = multiply(a, b);

		for (int i = result.size() - 1; i >= 0; i--)

			cout << result[i];

		cout << endl;

		t2 = high_resolution_clock::now();

		time_span = duration_cast<duration<double>>(t2 - t1);

		cout << "�⺻ ���ϱ� ����ð�: " << time_span.count() << "��" << endl;



		t1 = high_resolution_clock::now();

		result = karatsuba(a, b);

		t2 = high_resolution_clock::now();

		for (int i = result.size() - 1; i >= 0; i--)

			cout << result[i];

		cout << endl;

		time_span = duration_cast<duration<double>>(t2 - t1);

		cout << "ī������ ���ϱ� ����ð�: " << time_span.count() << "��" << endl;

	}

	return 0;

}

