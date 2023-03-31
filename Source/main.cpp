// stdlib
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>

// Opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// User headers
#include "../Header/clock.h"

int main()
{
  int height = 600;
  int width = 800;
  float dt = 0.001;

  Clock clock(dt, height, width);

  clock.simulate(25);

  return 0;
}
