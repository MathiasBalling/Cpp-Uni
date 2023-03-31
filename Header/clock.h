// stdlib
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>

// Matrix

// Opencv
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class Clock
{
  cv::Mat m_canvas;
  double m_angle = 3 * M_PI / 2;
  double m_dt;
  double m_points[30] = {m_angle};
  int m_index = 0;
  int m_current_size = 1;

public:
  Clock(float dt, int h, int w);
  void update();
  void draw();
  void simulate(int fps);
};
