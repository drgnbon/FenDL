#include <FenDL/FenDL.hxx>

int main() {
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({10000,100,10});
  network.setActivationFunction<Sigmoid>();

  TrainerStrategy trainer(network);
  trainer.setLossFunction<SquareError>();
  trainer.setOptimizer<Adagrad>(network);

  //trainer.setHyperparameters(0.999,0.9,1e-8);

  Branch branch(10000,10);
  branch.generateRandomBranch(1,0,0.9);
  branch.buildBranch();

  trainer.fit(branch, 1000000,0.001,true);
}


//ADADELTA DON'T WORK, USE ADAGRAD