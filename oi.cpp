//
// Created by andre on 10/05/23.
//

#include <iostream>
#include "oi.hpp"

void oi() {
    cv::Mat image_test = cv::Mat::zeros(cv::Size(100, 100), CV_8U);
    std::cout << "OI, fui chamada pela Tchau" << std::endl;
    std::cout << "Essas são minhas flags de image_test " << image_test.flags << std::endl;

    cv::imshow("teste", image_test);
    cv::waitKey(0);

}
