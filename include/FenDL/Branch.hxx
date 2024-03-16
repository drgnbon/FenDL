#ifndef FENDL_BRANCH_HXX
#define FENDL_BRANCH_HXX

#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <filesystem>
#include "Eigen/Core"

typedef Eigen::MatrixXd Matrixd;

class Branch {

public:
    Matrixd *_inputs{};
    Matrixd *_targets{};

    size_t _count_of_tests{};

    Branch(size_t input_layer_size, size_t output_layer_size);

    ~Branch();

    void generateRandomBranch(int count_of_tests, double min_rnd, double max_rnd);

    void generateRandomBranch(int count_of_tests);

    void loadTestsFromDir(const std::string& path_to_folder_branches,const std::string& name_of_branch);

    void addTestToBranch(const std::vector<double>& input, const std::vector<double>& target);

    void buildBranch();

    void clearBranch();

    void saveBranchToFolder(const std::string& path,const std::string& branch_name);

private:
    std::string _name_branches_directory = "Branches";

    size_t _input_layer_size;
    size_t _output_layer_size;

    std::vector<std::string> _path_to_inputs;
    std::vector<std::string> _path_to_targets;

    std::vector<std::vector<double> > _inputsv;
    std::vector<std::vector<double> > _targetsv;

    static bool containsString(const std::string &input_string, const std::string &find_string);

    static std::vector<double> getDataFromFile(const std::string& path, size_t data_size);

    std::vector<std::string> getFilePathsWithKey(const std::string& path_to_folder, const std::string& key);
};

#endif

