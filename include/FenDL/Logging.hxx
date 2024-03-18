//
// Created by Andrey on 17.03.2024.
//

#ifndef FENDL_LOGGING_HXX
#define FENDL_LOGGING_HXX

#include "FenDL/TrainerStrategy.hxx"
#include <unistd.h>
#include <thread>
#include <conio.h>

class Logging {
private:
    std::thread t;
public:

    Logging(){};

    static void Log(TrainerStrategy& ts);

    void startLogging(TrainerStrategy& ts){
        t = std::thread(Log,std::ref(ts) ) ;
    }
    void stopLogging(){
        t.join();
    }


};


#endif //FENDL_LOGGING_HXX
