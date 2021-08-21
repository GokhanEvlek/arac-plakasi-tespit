#include <iostream>
#include "opencv2\core\core.hpp"
#include "opencv2\core.hpp"
#include "opencv2\face.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\opencv.hpp"
#include<direct.h>
#include <vector>


using namespace std;
using namespace cv;
using namespace cv::face;



int main() {
	vector<Rect>tut(10);
	CascadeClassifier plate;
	Mat img;
	plate.load("C:\\Users\\Gökhan\\Desktop\\recoface-master\\classificadores\\haarcascades\\haarcascade_russian_plate_number.xml");
	string path = "C:\\Users\\Gökhan\\Desktop\\Resources\\ozel-plaka.png";
	Mat img2;
	img = imread(path);
	resize(img, img, Size(1920, 1080));
	if (img.channels() == 3) {
		cvtColor(img, img2, COLOR_BGR2GRAY);
	}
	else if (img.channels() == 4) {
		cvtColor(img, img2, COLOR_BGR2GRAY);
	}
	else {

		img2 = img;
	}
	equalizeHist(img2, img2);
	plate.detectMultiScale(img2, tut, 1.1, 2);
	
	for (int i = 0; i < tut.size(); i++) {
		if (tut.size() == 0) {
			break;
		}
		rectangle(img, tut[i].tl(), tut[i].br(), Scalar(255, 0, 255), 3);
		int pos_x = tut[i].br().x - tut[i].width;
		int pos_y = tut[i].br().y +80;
		putText(img, "Plaka Burada", Point(pos_x,pos_y),2, FONT_HERSHEY_COMPLEX, Scalar(255, 0, 255), 2);
	}
	imshow("plaka",img);
	waitKey(0);
}