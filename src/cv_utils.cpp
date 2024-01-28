#include "cv_utils.hpp"

#include <iostream>
#include <opencv2/highgui.hpp>

void cv_utils::showImageInNewWindow(const cv::Mat& image, const std::string& windowName)
{
    auto windowIsOpen = cv::getWindowProperty(windowName, cv::WND_PROP_VISIBLE) > 0;
    if (windowIsOpen)
    {
        std::cerr << "Window " << windowName << " is already open." << std::endl;
        return;
    }
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);

    for (;;)
    {
        cv::imshow(windowName, image);
        auto keyPressed = cv::waitKey();

        if (keyPressed == 27 || keyPressed == 'q')
        {
            cv::destroyWindow(windowName);
            break;
        }

        windowIsOpen = cv::getWindowProperty(windowName, cv::WND_PROP_VISIBLE) > 0;
        if (!windowIsOpen)
        {
            break;
        }
    }
}
