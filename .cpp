#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<queue>

/*Roi 값 조절 하는 부분*/
#define Roi_Width 190
#define Roi_Height 20
#define MID_H_VALUE 170    //평균을 내기 위한 roi 중간의 y값.


/*민감도 값 조절하는 부분.*/
#define PEAK_BOUNDARY_VALUE 110  // 해당 값 이하로 픽셀평균값이 내려가면 peak 검사실행.
#define side_length 10			// 픽 baseline을  구하기 위한 피크값과 양옆간의 거리차
#define SIZE_BOUNDARY_VALUE 100


using namespace std;



//peak의 좌표를 받아 그 좌표값의 좌우넓이를 구하는 함수.
//avg=픽셀별 평균값, X=peak 위치정보
vector<int> find_area(int avg[], vector<pair<int, int>> X) {

	vector<int>Peak_Integral;  // 넓이 반환.
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

//픽셀 데이터에서 peak 좌표값을 저장하는 함수.
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

		//픽셀평균 중에서 peak점의 최소값과 위치를 찾음
		if (avg[x] > PEAK_BOUNDARY_VALUE)
		{

			//x2값 x1에 넣어주고 clear
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

		//x2에 넣어줘야해.
		else {
			Under_Boundary_Data.push_back(make_pair(avg[x], x));
		}

	}
	return location;
}



int main() {


	/*적분값을 구하기 위한 메모리*/
	int Roi_Point[Roi_Width][3]; //각 픽셀의 RGB값 y= 고정.
	int Pixel_Avg[Roi_Width];  // 각픽셀의 평균값.


	vector<pair<int, int>>Peak_Location; // peak의 시작과 끝점 위치


	vector<int>Peak_Integral; // peak의 적분값 

							  //avg_x[] = Pixel_Avg,

	Peak_Location.clear();
	Peak_Integral.clear();


	Peak_Location = pixel_data(Pixel_Avg);
	Peak_Integral = find_area(Pixel_Avg, Peak_Location);



	for (int i = 0; i < Peak_Location.size(); i++) {
		//cout << "peak 위치: " << Peak_Location[i] + 1 << endl;;
	}


	for (int i = 0; i < Peak_Integral.size(); i++) {
		cout << "넓이 : " << Peak_Integral[i] << endl;
	}

	for (int i = 0; i < Peak_Integral.size() - 1; i++) {

		if (Peak_Integral[i] < SIZE_BOUNDARY_VALUE) cout << "음성 " << endl;
		else cout << "양성 " << endl;
	}


	return 0;
}