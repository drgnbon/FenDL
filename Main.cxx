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

  trainer.fit(branch, 1000000,0.01,true);
}


//Adadelta очень быстрый, неточный. Под конец обучения ошибка будет сильно прыгать и до конца не дойдет, не нужен learning rate
//RMSProp очень быстрый, более точный чем Adadelta. Под конец обучения ошибка будет сильно прыгать и до конца не дойдет
//Adagrad быстрый, точный, норм темка
//ADAM средний по скорости, точный, идет без вопросов к глобальному минимуму не страшны неровности
//BGFS быстрый, очень точный, огромные требования к оперативной памяти и процессору, оптимизатор 2-го порядка
//GD медленный, точный, самый базовый оптимизатор работающий на чистейшем градиенте