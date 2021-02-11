#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace cv;

int main(int argc, char* argv[])
{
  Mat image = imread(argv[1]);

  if (image.empty())
  {
    cout << "Could not open or find the image!\n" << endl;
    cout << "Usage: " << argv[0] << " <Image Path>" << endl;
    return -1;
  }

  Mat new_image = Mat::zeros(image.size(), image.type());
  
  double alpha = 1.0; // Contrast Control
  double beta = 0; // Brightness Control

  cout << " Basic Linear Transforms " << endl;
  cout << "-------------------------" << endl;
  cout << "* Enter the alpha value [1.0 - 3.0]: ";
  cin >> alpha;
  cout << "* Enter the beta value [0 - 100]: ";
  cin >> beta;

  // =====================
  // Learning Purposes: This O(n^3) loop is to show that to modify each pixel individually
  // we need to update (y - rows) (x - columns) (c - blue green red color channels)
  // for (int y = 0; y < image.rows; y++) {
  //   for (int x = 0; x < image.cols; x++) {
  //     for (int c = 0; c < image.channels(); c++) {
  //       new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(alpha*image.at<Vec3b>(y,x)[c] + beta);
  //     }
  //   }
  // }
  // =====================

  image.convertTo(new_image, -1, alpha, beta);

  imshow("Original Image", image);
  imshow("New Image", new_image);
  waitKey(0);
  return 0;
}