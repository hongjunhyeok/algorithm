#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<queue>

/*Roi �� ���� �ϴ� �κ�*/
#define Roi_Width 190
#define Roi_Height 20
#define MID_H_VALUE 170    //����� ���� ���� roi �߰��� y��.


/*�ΰ��� �� �����ϴ� �κ�.*/
#define PEAK_BOUNDARY_VALUE 110  // �ش� �� ���Ϸ� �ȼ���հ��� �������� peak �˻����.
#define side_length 10			// �� baseline��  ���ϱ� ���� ��ũ���� �翷���� �Ÿ���
#define SIZE_BOUNDARY_VALUE 100


using namespace std;



//peak�� ��ǥ�� �޾� �� ��ǥ���� �¿���̸� ���ϴ� �Լ�.
//avg=�ȼ��� ��հ�, X=peak ��ġ����
vector<int> find_area(int avg[], vector<pair<int, int>> X) {

	vector<int>Peak_Integral;  // ���� ��ȯ.
	double base_line = 0.0;
	double left, right;
	int area;
	int size = X.size();
	for (int i = 0; i < size; i++) {
		area = 0;
		int start = X[i].first;
		int end = X[i].second;
		int mid = (start + end) / 2;
		left = (int)avg[mid - side_length], right = (int)avg[mid + side_length];
		base_line = (left + right) / 2;

		for (int j = mid - side_length; j <= mid + side_length; j++) {
			if (avg[j] < base_line)
				area += base_line - avg[j];

		}
		Peak_Integral.push_back(area);
	}
	return Peak_Integral;
}
vector<int> find_height(int avg[], vector<pair<int, int>> Y) {
	vector<int>Peak_Height;
	double base_line = 0.0;
	double left, right;
	int height;
	int size = Y.size();
	for (int i = 0; i < size; i++) {
		height = 0;
		int start = Y[i].first;
		int end = Y[i].second;
		int mid = (start + end) / 2;
		left = (int)avg[mid - side_length], right = (int)avg[mid + side_length];
		base_line = (left + right) / 2;

		height = base_line - avg[mid];

		Peak_Height.push_back(height);

	}
	return Peak_Height;
	
}

//�ȼ� �����Ϳ��� peak ��ǥ���� �����ϴ� �Լ�.
vector<pair<int, int>> pixel_data(int avg[]) {

	//pair<front,end>
	vector<pair<int, int>> location;

	for (int i = 0; i < Roi_Width; i++) {
		/*for (int j = 0; j < 3; j++) {
		cin >> Roi_Point[i][j];
		}*/
		cin >> avg[i];
	}
	int min_peak_index = 0;
	int min_peak_value = PEAK_BOUNDARY_VALUE;



	vector<pair<int, int>>Under_Boundary_Data;



	for (int x = 0; x < Roi_Width; x++) //0 >> 350
	{

		//�ȼ���� �߿��� peak���� �ּҰ��� ��ġ�� ã��
		if (avg[x] > PEAK_BOUNDARY_VALUE)
		{

			//x2�� x1�� �־��ְ� clear
			if (Under_Boundary_Data.size() > 0)
			{
				int s = Under_Boundary_Data.size();
				int min_x_value = Under_Boundary_Data.front().first;
				int min_x_location = Under_Boundary_Data.front().second;

				int first = Under_Boundary_Data.front().second;
				int end = Under_Boundary_Data.back().second;

				location.push_back(make_pair(first, end));

				Under_Boundary_Data.clear();
			}
			else
				continue;
		}

		//x2�� �־������.
		else {
			Under_Boundary_Data.push_back(make_pair(avg[x], x));
		}

	}
	return location;
}



int main() {


	/*���а��� ���ϱ� ���� �޸�*/
	int Roi_Point[Roi_Width][3]; //�� �ȼ��� RGB�� y= ����.
	int Pixel_Avg[Roi_Width];  // ���ȼ��� ��հ�.


	vector<pair<int, int>>Peak_Location; // peak�� ���۰� ���� ��ġ


	vector<int>Peak_Integral; // peak�� ���а� 

							  //avg_x[] = Pixel_Avg,

	Peak_Location.clear();
	Peak_Integral.clear();


	Peak_Location = pixel_data(Pixel_Avg);
	Peak_Integral = find_area(Pixel_Avg, Peak_Location);



	for (int i = 0; i < Peak_Location.size(); i++) {
		//cout << "peak ��ġ: " << Peak_Location[i] + 1 << endl;;
	}


	for (int i = 0; i < Peak_Integral.size(); i++) {
		cout << "���� : " << Peak_Integral[i] << endl;
	}

	for (int i = 0; i < Peak_Integral.size() - 1; i++) {

		if (Peak_Integral[i] < SIZE_BOUNDARY_VALUE) cout << "���� " << endl;
		else cout << "�缺 " << endl;
	}


	return 0;
}