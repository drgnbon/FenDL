#include <FenDL/FenDL.hxx>

int main() {
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({50000,10000,3});
  network.setActivationFunction<Sinc>();

  TrainerStrategy trainer(network);
  trainer.setLossFunction<SquareError>();
  trainer.setOptimizer<ADAM>(network);

  Branch branch(50000,3);
  branch.generateRandomBranch(10,0.5,0.9);
  branch.buildBranch();

  trainer.fit(branch,100000,0.00005,true);
}