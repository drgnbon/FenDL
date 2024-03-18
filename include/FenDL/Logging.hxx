//
// Created by Andrey on 17.03.2024.
//

#ifndef FENDL_LOGGING_HXX
#define FENDL_LOGGING_HXX

#include "FenDL/TrainerStrategy.hxx"
#include <unistd.h>
#include <thread>

class Logging {
private:
    double AverageError,AveragePercent;
    std::thread t;
public:

    Logging(){
        AverageError = 0;
        AveragePercent = 0;
    }

    static void Log(TrainerStrategy& ts){

        while(true){
            auto t = clock();
            system("clear");
            printf("Epoch: %d | Test: %d / %d  \n", ts._epoch,ts._test_number,ts._branch_size);
            printf("Average Loss: %f | Average Percentage: %f % \n", ts._average_loss,ts._average_percentage);
            printf("Time for branch: %f ms | Time for test: %f ms \n", ts._time_for_branch,ts._time_for_test);
            printf("Error decreesing speed: %f | Learning speed: %f \n", ts._error_decreeding_speed,ts._learning_speed);
            //std::cout << "Average percent of network : " << ts.getAveragePercent() << "\n";
            sleep((1000/15 - (clock()-t)%(1000/15) )/1000.0);
        }
    }

    void startLogging(TrainerStrategy& ts){
        t = std::thread(Log,std::ref(ts) ) ;
    }
    void stopLogging(){
        t.join();
    }


};


#endif //FENDL_LOGGING_HXX
