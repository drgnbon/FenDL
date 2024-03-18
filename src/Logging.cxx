//
// Created by Andrey on 17.03.2024.
//

#include "FenDL/Logging.hxx"

void Logging::Log(TrainerStrategy& ts){

    std::mutex mutex;

    while(true){
        std::lock_guard<std::mutex> lock(mutex);
        if (_kbhit() && _getch() == 115)
        {
            system("clear");
            printf("Saving weights...\n");
            printf("Please, write path to weights\n");
            std::string path;
            std::cin >> path;
            ts._network.SaveNeuralNetworkData(path);
            printf("The weights have been saved :)\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        }

        auto t = clock();
        system("clear");
        printf("Epoch: %d | Test: %d / %d  \n", ts._epoch,ts._test_number,ts._branch_size);
        printf("Average Loss: %f | Average Percentage: %f % \n", ts._average_loss,ts._average_percentage);
        printf("Time for branch: %f ms | Time for test: %f ms \n", ts._time_for_branch,ts._time_for_test);
        printf("Error decreesing speed: %f | Learning speed: %f \n", ts._error_decreeding_speed,ts._learning_speed);
        sleep((1000/15 - (clock()-t)%(1000/15) )/1000.0);
    }
}