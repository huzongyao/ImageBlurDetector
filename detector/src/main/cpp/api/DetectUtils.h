//
// Created by huzongyao on 2019/12/13.
//

#ifndef BLURDETECTANDROID_DETECTUTILS_H
#define BLURDETECTANDROID_DETECTUTILS_H

#include <opencv2/imgproc.hpp>

class DetectUtils {
public:
    static double detectBlur(cv::Mat &gray);
};


#endif //BLURDETECTANDROID_DETECTUTILS_H
