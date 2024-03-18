//
// Created by Andrey on 17.03.2024.
//

#include "FenDL/Logging.hxx"

void Logging::Log(TrainerStrategy& ts){

    sf::Color grayColor(45, 50, 56);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Network loss");
    std::mutex mutex;
    window.clear(grayColor);
    window.display();

    while(true){
        if(ts._loss_history.size() > 1)
        {
            window.clear(grayColor);
            drawCoordinateAxes(window, *std::max_element(ts._loss_history.begin(), ts._loss_history.end()));
            drawGraph(window, ts._loss_history);
            window.display();
        }
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        std::lock_guard<std::mutex> lock(mutex);
        if (_kbhit() && _getch() == 115)
        {
            system("cls");
            printf("Saving weights...\n");
            printf("Please, write path to weights\n");
            std::string path;
            std::cin >> path;
            ts._network.SaveNeuralNetworkData(path);
            printf("The weights have been saved :)\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        }

        auto t = clock();
        system("cls");
        printf("Epoch: %d | Test: %d / %d  \n", ts._epoch,ts._test_number,ts._branch_size);
        printf("Average Loss: %f | Average Percentage: %f % \n", ts._average_loss,ts._average_percentage);
        printf("Time for branch: %f ms | Time for test: %f ms \n", ts._time_for_branch,ts._time_for_test);
        printf("Error decreesing speed: %f | Learning speed: %f \n", ts._error_decreeding_speed,ts._learning_speed);
        //sleep((1000/2 - (clock()-t)%(1000/2))/1000.0);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


void Logging::drawCoordinateAxes(sf::RenderWindow& window, double maxValue) {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int padding = 50;

    sf::Font font;
    sf::Color grayColor(45, 50, 56);
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }
    for (int i = 0; i <= 10; ++i) {
        sf::Text text(std::to_string(i * (maxValue / 10)).substr(0, 4), font, 10);
        text.setPosition(padding - 30, windowHeight - padding - i * ((windowHeight - 2 * padding) / 10) - 10);
        // Устанавливаем цвет текста
        text.setFillColor(sf::Color::White);
        window.draw(text);
    }


    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(padding, windowHeight - padding);
    xAxis[1].position = sf::Vector2f(windowWidth - padding, windowHeight - padding);
    window.draw(xAxis);

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(padding, padding);
    yAxis[1].position = sf::Vector2f(padding, windowHeight - padding);
    window.draw(yAxis);
}

void Logging::drawGraph(sf::RenderWindow& window, const std::vector<double>& values) {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int padding = 50;

    sf::Color grayColor( 150, 159, 171);
    double maxValue = *std::max_element(values.begin(), values.end());

    sf::VertexArray graph(sf::LineStrip, values.size());
    for (size_t i = 0; i < values.size(); ++i) {
        double x = padding + i * ((windowWidth - 2 * padding) / (values.size() - 1));
        double y = windowHeight - padding - ((values[i] + 0.1) / maxValue) * (windowHeight - 2 * padding); // Adding 0.1 to avoid zero values
        graph[i].position = sf::Vector2f(x, y);
        graph[i].color = grayColor;
    }
    window.draw(graph);
}