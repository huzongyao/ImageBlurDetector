# ImageBlurDetector
Simply check if an image is blur on Android device

### Details
* 对图像模糊度检测，简单的方式是拉普拉斯变换再求方差获取一个数值，python代码仅需1行
``` python
cv2.Laplacian(image, cv2.CV_64F).var()
```

* 安卓上实现的话可以用OpenCV Android SDK，我使用了OpenCV静态库方式，生成的动态库不是很大，可以用于生产。
``` c++
double detectBlur(cv::Mat &gray) {
    cv::Mat lap;
    Laplacian(gray, lap, CV_64F);
    Scalar m, s;
    meanStdDev(lap, m, s);
    double st = s[0];
    return st * st;
}
```

* https://www.pyimagesearch.com/2015/09/07/blur-detection-with-opencv/

### Attention
* In Order to Speed up Repository clone process, OpenCV SDK files are git ignored by this project. So after first time clone the Repository, Please download the OpenCV Android SDK and copy folders under sdk/native/ into /detector/cpp/opencv/, and then compile could process. 
* Download Address: https://opencv.org/releases/

* 注意：使用前需要先下载OpenCV SDK。为了避免大量无需修改的SDK的库文件和头文件占用Git仓库， OpenCV SDK的库文件排除版本控制，所以第一次克隆项目后，需要下载OpenCV SDK， 并把sdk/native目录下的文件拷贝到项目目录/detector/cpp/opencv/目录下， 再编译即可，否则编译报错，找不到OpenCV.mk文件。

### About Me
 * GitHub: [https://huzongyao.github.io/](https://huzongyao.github.io/)
 * ITEye博客：[https://hzy3774.iteye.com/](https://hzy3774.iteye.com/)
 * 新浪微博: [https://weibo.com/hzy3774](https://weibo.com/hzy3774)

### Contact To Me
 * QQ: [377406997](https://wpa.qq.com/msgrd?v=3&uin=377406997&site=qq&menu=yes)
 * Gmail: [hzy3774@gmail.com](mailto:hzy3774@gmail.com)
 * Foxmail: [hzy3774@qq.com](mailto:hzy3774@qq.com)
 * WeChat: hzy3774

 ![image](https://raw.githubusercontent.com/hzy3774/AndroidP7zip/master/misc/wechat.png)

### Others
 * 想捐助我喝杯热水(¥0.01起捐)</br>
 ![donate](https://github.com/huzongyao/JChineseChess/blob/master/misc/donate.png?raw=true)
