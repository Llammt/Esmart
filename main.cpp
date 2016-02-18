#include <iostream>
#include "cv.h"
#include "highgui.h"
#include "Bradley.h"
#include "enclosing.h"
 
using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
  IplImage* src;
  IplImage* res;
  
  if (argc > 2) {
    src = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    res = cvCreateImage(cvSize(src->width, src->height), 8, 1);
    //cvEqualizeHist (src, res);
    Bradley_threshold((unsigned char*)src->imageData, (unsigned char*)res->imageData, src->width, src->height);
    cvSaveImage("Bradley.jpg", res);
    cvSmooth(res,res,CV_MEDIAN, 3, 3);
    cvSaveImage("Smooth.jpg", res);
    enclosing_contour(res, res);
    cvSaveImage(argv[2], res);
  }
  else
    cout << "missing argument, ololo" << endl;
  
  return 0;
}
