// User headers
#include "../Header/clock.h"

#include <math.h>

Clock::Clock(float dt, int h, int w) : m_dt(dt)
{
  m_canvas = cv::Mat(cv::Size(w, h), CV_8UC3, cv::Scalar(0, 0, 0));
  int cx = m_canvas.cols / 2;
  int cy = m_canvas.rows / 2;
  double length = 100;

  // Draw clock face
  for (int i = 0; i < 12; i++)
  {
    double angle = i * (2 * M_PI / 12);
    cv::line(m_canvas, cv::Point(cx + length * cos(angle), cy + length * sin(angle)), cv::Point(cx + length * 0.9 * cos(angle), cy + length * 0.9 * sin(angle)), cv::Scalar(255, 255, 255));
  }
}

void Clock::update()
{
  // Update the angle of the clock arm, to a time step dt into the future
  m_angle += (2 * M_PI / 60.0) * m_dt;
  m_angle = fmod(m_angle, 2 * M_PI);
}

void Clock::draw()
{
  cv::Mat img;
  m_canvas.copyTo(img);

  int cx = m_canvas.cols / 2;
  int cy = m_canvas.rows / 2;
  double length = 100;
  double dangle = (2 * M_PI / 60.0);
  int size = sizeof(m_points) / sizeof(m_points[0]);

  // Draw clock arms
  cv::line(img, cv::Point(cx, cy), cv::Point(cx + length * cos(m_angle), cy + length * sin(m_angle)), cv::Scalar(255, 255, 255));

  // Draw clock center
  cv::circle(img, cv::Point(cx, cy), 3, cv::Scalar(0, 255, 0), -1);

  // Add point to array every 1/60th of a second
  if (fmod(m_angle, dangle) < 0.00001)
  {
    m_index = (m_index + 1) % size;
    m_points[m_index] = m_angle;

    if (m_current_size < size)
    {
      m_current_size++;
    }
  }

  // Draw dot at end of clock arm every fps
  for (int i = 0; i < size - (size - m_current_size); i++)
  {
    int index = (m_index + 1 + i) % m_current_size;
    double angle = m_points[index];
    int color = 0 + 255 * (i) / (m_current_size - 1);
    cv::circle(img, cv::Point(cx + length * cos(angle), cy + length * sin(angle)), 2, cv::Scalar(color, color, color), -1);
  }

  cv::imshow("Image", img);
}

void Clock::simulate(int fps)
{

  while (1)
  {

    // Compute how many updates to do pr. frame
    float updatesPerSecond = 1.0 / m_dt;
    float secondsPerFrame = 1.0 / float(fps);
    float updatesPerFrame = updatesPerSecond * secondsPerFrame;

    // Update the clock's internal state and draw the frame
    for (int i = 0; i < updatesPerFrame; i++)
    {
      update();
    }
    draw();

    // Wait for the next frame
    float millisecondsPerFrame = 1000.0 * secondsPerFrame;
    char key = cv::waitKey(millisecondsPerFrame);
    if (key == 'q')
    {
      break;
    }
  }
}
