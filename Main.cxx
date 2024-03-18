#include <FenDL/FenDL.hxx>

int main() {
    Eigen::setNbThreads(2);
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({100,10,2});
  network.setActivationFunction<Sigmoid>();

  TrainerStrategy trainer(network);
  trainer.setLossFunction<SquareError>();
  trainer.setOptimizer<ADAM>(network);
  //trainer.setHyperparameters(0.999,0.9,1e-8);

  Logging log;
  log.startLogging(trainer);

  Branch branch(100,2);
  branch.generateRandomBranch(10,0,0.9);
  branch.buildBranch();

  trainer.fit(branch, 10000,0.5,false);

  log.stopLogging();
}


//Adadelta очень быстрый, неточный. Под конец обучения ошибка будет сильно прыгать и до конца не дойдет, не нужен learning rate
//RMSProp очень быстрый, более точный чем Adadelta. Под конец обучения ошибка будет сильно прыгать и до конца не дойдет
//Adagrad быстрый, точный, норм темка
//ADAM средний по скорости, точный, идет без вопросов к глобальному минимуму не страшны неровности
//BGFS быстрый, очень точный, огромные требования к оперативной памяти и процессору, оптимизатор 2-го порядка
//GD медленный, точный, самый базовый оптимизатор работающий на градиенте0