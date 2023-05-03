#include "stats.hpp"

void calculateStats(
        cv::Mat imgCenterBlue,
        cv::Mat imgCenterYellow,
        opendlv::proxy::GroundSteeringRequest gsr,
        bool isBlueLeft)
{

    static int hasBlue = 0;
    static int hasYellow = 0;
    static bool blue = false;
    static bool yellow = false;
    static bool gsrbool = false;
    static int countYellow = 0;
    static int countBlue = 0;
    static int onlygsrblue = 0;
    static int onlyblue = 0;
    static int onlyyellow = 0;
    static int onlygsryellow = 0;
    static int emptyBlue = 0;
    static int emptyYellow = 0;

    hasBlue = cv::countNonZero(imgCenterBlue);

    // this is when the car should turn right
    if (hasBlue > 250) {
        blue = true;
    }
    // this is when the car actually turns right
    if (isBlueLeft) {
        if (gsr.groundSteering() < 0) {
            gsrbool = true;
        }
    } else {
        if (gsr.groundSteering() > 0) {
            gsrbool = true;
        }
    }
    if (blue && gsrbool){
        countBlue++;
    }
    if (blue && !gsrbool){
        onlyblue++;
    }
    if (!blue && gsrbool){
        onlygsrblue++;
    }
    if (!blue && !gsrbool){
        emptyBlue++;
    }
    // Our algorithm turns the car when it should
    std::cout << "Correct blue  : ";
    std::cout << countBlue << std::endl;
    // Our algorithm turns the car when it shouldn’t
    std::cout << "onlyBlue      : ";
    std::cout << onlyblue << std::endl;
    // Our algorithm doesn’t turn the car when it should
    std::cout << "only Gsr right: ";
    std::cout << onlygsrblue << std::endl;
    // Our algorithm doesn’t turn the car, and it shouldn’t
    std::cout << "Neither output: ";
    std::cout << emptyBlue << std::endl;

    blue = false;
    gsrbool = false;

    hasYellow = 0;
    hasYellow = cv::countNonZero(imgCenterYellow);
    // this is when the car should turn left
    if (hasYellow > 250) {
        yellow = true;
    }

    if (isBlueLeft) {
        if (gsr.groundSteering() > 0) {
            gsrbool = true;
        }
    } else {
        if (gsr.groundSteering() < 0) {
            gsrbool = true;
        }
    }

    if (yellow && gsrbool){
        countYellow++;
    }
    if (yellow && !gsrbool){
        onlyyellow++;
    }
    if (!yellow && gsrbool){
        onlygsryellow++;
    }
    if (!yellow && !gsrbool){
        emptyYellow++;
    }
    // Our algorithm turns the car when it should
    std::cout << "Correct yellow: ";
    std::cout << countYellow << std::endl;
    // Our algorithm turns the car when it shouldn’t
    std::cout << "onlyYellow    : ";
    std::cout << onlyyellow << std::endl;
    // Our algorithm doesn’t turn the car when it should
    std::cout << "only Gsr left : ";
    std::cout << onlygsryellow << std::endl;
    // Our algorithm doesn’t turn the car, and it shouldn’t
    std::cout << "Neither output: ";
    std::cout << emptyYellow << std::endl;

    yellow = false;
    gsrbool = false;
}