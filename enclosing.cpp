#include "enclosing.h"

void enclosing_contour(IplImage* src, IplImage* res) {
  int contours_count;
  cvCanny(src, res, 50, 200);
  CvMemStorage* storage = cvCreateMemStorage(0);
  CvSeq* contours = 0;
  contours_count = cvFindContours( res, storage,&contours,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
  
  cvReleaseMemStorage(&storage);
}