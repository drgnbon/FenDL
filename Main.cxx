#include <FenDL/FenDL.hxx>

int main() {
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({300,10,10});
  network.setActivationFunction<Sigmoid>();

  TrainerStrategy trainer(network);
  trainer.setLossFunction<SquareError>();
  trainer.setOptimizer<ADAM>(network);

  Branch branch(300,10);
  branch.generateRandomBranch(50,0.5,0.9);
  branch.buildBranch();

  trainer.fit(branch,100,0.05,true);

}