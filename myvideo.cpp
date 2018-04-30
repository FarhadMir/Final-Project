

// opencv
#include <opencv2/opencv.hpp>

// ORB-SLAM
#include "System.h"
#include <string>
#include <chrono>   
#include <iostream>

using namespace std;



string parameterFile = "./Mytest.yaml";
string vocFile = "./Vocabulary/ORBvoc.txt";


string videoFile = "./IMG_1343.MOV";

int main(int argc, char **argv) {

    
    ORB_SLAM2::System SLAM(vocFile, parameterFile, ORB_SLAM2::System::MONOCULAR, true);

   
    cv::VideoCapture cap(videoFile);    

    
    auto start = chrono::system_clock::now();

    while (1) {
        cv::Mat frame;
        cap >> frame;   
        if ( frame.data == nullptr )
            break;

        

        auto now = chrono::system_clock::now();
        auto timestamp = chrono::duration_cast<chrono::milliseconds>(now - start);
        SLAM.TrackMonocular(frame, double(timestamp.count())/1000.0);
        
	SLAM.SaveKeyFrameTrajectoryTUM("KFTrajectory_5.txt");
    }

    SLAM.Shutdown();


   

    return 0;
}
