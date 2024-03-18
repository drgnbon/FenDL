//
// Created by Andrey on 17.03.2024.
//

#ifndef FENDL_LOGGING_HXX
#define FENDL_LOGGING_HXX

#include "FenDL/TrainerStrategy.hxx"
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <conio.h>

class Logging {
private:
    int windowWidth = 800;
    int windowHeight = 600;
    int padding = 50;
    std::thread t;
public:

    Logging(){};

    static void Log(TrainerStrategy& ts);
    static void drawCoordinateAxes(sf::RenderWindow&,double);
    static void drawGraph(sf::RenderWindow&, const std::vector<double>&);

    void startLogging(TrainerStrategy& ts){
        t = std::thread(Log,std::ref(ts) ) ;
    }
    void stopLogging(){
        t.join();
    }


};


#endif //FENDL_LOGGING_HXX
