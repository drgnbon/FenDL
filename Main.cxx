#include <iostream>
#include <Eigen/Dense>
#include <FenDL/FenDL.hxx>

int main() {

  NeuralNetwork network;
  TrainerStrategy ts(std::make_shared<ADAM>());
  network.setLayers<PerceptronLayer>({5,100,3});
  network.setActivationFunction(std::make_shared<Sigmoid>());

  int t = 0;

  Matrixd input;
  Matrixd output;

  input.setRandom(1,5);
  output.setRandom(1,3);

  while(t < 100000){

      t++;
      std::cout << t << " : ";

      ts.train(network,input,output,0.5,false);

      //network.learn(input,output,0.5);

      std::cout << network._current_loss_function -> getMediumLoss(network._layers[network._layers.size()-1]->_active_values,output) << " \n" ;
      std::cin.get();
  }

  std::cin.get();
}