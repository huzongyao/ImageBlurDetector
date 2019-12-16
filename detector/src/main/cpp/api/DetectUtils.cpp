//
// Created by huzongyao on 2019/12/13.
//

#include "DetectUtils.h"

using namespace cv;

double DetectUtils::detectBlur(cv::Mat &gray) {
    cv::Mat lap;
    Laplacian(gray, lap, CV_64F);
    Scalar m, s;
    meanStdDev(lap, m, s);
    double st = s[0];
    return st * st;
}
