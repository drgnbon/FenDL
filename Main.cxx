#include <FenDL/FenDL.hxx>

int main() {
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({300,100,10});
  network.setActivationFunction<Sigmoid>();

  TrainerStrategy trainer(network);
  trainer.setLossFunction<SquareError>();
  trainer.setOptimizer<Adagrad>(network);

  Branch branch(300,10);
  branch.generateRandomBranch(1,0.5,0.9);
  branch.buildBranch();

  trainer.fit(branch, 1000000,0.000001,true);
}


