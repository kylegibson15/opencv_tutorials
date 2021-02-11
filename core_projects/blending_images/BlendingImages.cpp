#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    cout << "Usage: ./BlendingImages.out <Image 1 File> <Image 2 File>" << endl;
    return EXIT_FAILURE;
  }
  double alpha = 0.5;
  double beta;
  double input;

  Mat src1, src2, dst;

  cout << " Simple Linear Blender " << endl;
  cout << "-----------------------" << endl;
  cout << "* Enter Alpha [0.0 - 1.0]: ";
  cin >> input;

  if (input >= 0 && input <= 1)
  {
    alpha = input;
  }

  src1 = imread(argv[1]);
  src2 = imread(argv[2]);

  if (src1.empty())
  {
    cout << "Error loading src1" << endl;
    return EXIT_FAILURE;
  }

  if (src2.empty())
  {
    cout << "Error loading src2" << endl;
    return EXIT_FAILURE;
  }

  beta = (1.0 - alpha);
  addWeighted(src1, alpha, src2, beta, 0.0, dst);

  imshow("Linear Blend", dst);
  waitKey(0);

  return 0;
}