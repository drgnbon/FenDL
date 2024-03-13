#include "FenDL/Branch.hxx"

Branch::Branch(size_t input_layer_size,size_t output_layer_size)
{
    _input_layer_size = input_layer_size;
    _output_layer_size = output_layer_size;
}

Branch::~Branch()
{
    delete _inputs;
    delete _targets;
}

void Branch::generateRandomBranch(int count_of_tests,double min_rnd,double max_rnd)
{
    _count_of_tests = count_of_tests;

    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_real_distribution<double> rng_coin(min_rnd,max_rnd);

    _inputsv = std::vector<std::vector<double> >(_count_of_tests);
    _targetsv = std::vector<std::vector<double> >(_count_of_tests);
    for(int i = 0;i < _count_of_tests;++i)
    {
        _inputsv[i] = std::vector<double>(_input_layer_size);
        _targetsv[i] = std::vector<double>(_output_layer_size);

        for(int j = 0;j < _input_layer_size;++j)
            _inputsv[i][j] = rng_coin(gen);
        for(int j = 0;j < _output_layer_size;++j)
            _targetsv[i][j] = rng_coin(gen);
    }
}

void Branch::generateRandomBranch(int count_of_tests)
{
    _count_of_tests = count_of_tests;

    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_real_distribution<double> rng_coin(-1,1);

    _inputsv = std::vector<std::vector<double> >(_count_of_tests);
    _targetsv = std::vector<std::vector<double> >(_count_of_tests);
    for(int i = 0;i < _count_of_tests;++i)
    {
        _inputsv[i] = std::vector<double>(_input_layer_size);
        _targetsv[i] = std::vector<double>(_output_layer_size);
        for(int j = 0;j < _input_layer_size;++j)
            _inputsv[i][j] = rng_coin(gen);
        for(int j = 0;j < _output_layer_size;++j)
            _targetsv[i][j] = rng_coin(gen);
    }
}

void Branch::loadTestsFromDir(const std::string& path_to_folder_branches,const std::string& name_of_branch)
{
    _path_to_inputs = getFilePathsWithKey(path_to_folder_branches+'/'+_name_branches_directory+'/' + name_of_branch,"input");
    _path_to_targets = getFilePathsWithKey(path_to_folder_branches+'/'+_name_branches_directory+'/' + name_of_branch,"target");

    if(_path_to_inputs.size() != _path_to_targets.size())
    {
        std::cout << "the count of input tests does not match the count of targets !\n#branch #filesystem\n";
        system("pause");
        exit(0);
    }

    _count_of_tests = _path_to_inputs.size();
    _inputsv = std::vector<std::vector<double> >(_count_of_tests);
    _targetsv = std::vector<std::vector<double> >(_count_of_tests);

    for(int i = 0; i < _count_of_tests; ++i)
    {
        _inputsv[i] = getDataFromFile(_path_to_inputs[i],_input_layer_size);
        _targetsv[i] = getDataFromFile(_path_to_targets[i],_output_layer_size);
    }
}

void Branch::saveBranchToFolder(const std::string& path,const std::string& branch_name)
{
    std::filesystem::create_directory(path + "/" + _name_branches_directory);
    std::filesystem::create_directory(path + "/" + _name_branches_directory + "/" + branch_name);

    for(int i = 0;i < _count_of_tests;++i)
    {
        std::string file_path = path + "/" + _name_branches_directory + "/" + branch_name + "/" + std::to_string(i + 1);
        std::ofstream file_stream_input(file_path + "input.txt");
        std::ofstream file_stream_target(file_path + "target.txt");

        for(double & j : _inputsv[i])
            file_stream_input << j << " ";

        for(double & j : _targetsv[i])
            file_stream_target << j << " ";

        file_stream_input.close();
        file_stream_target.close();

    }
}

void Branch::addTestToBranch(const std::vector<double>& input, const std::vector<double>& target)
{
    if(input.size() != _input_layer_size || target.size() != _output_layer_size)
    {
        std::cout << "incorrect vector size for the neural network structure !\n#branch #nnstructure\n";
        system("pause");
        exit(0);
    }
    ++_count_of_tests;
    _inputsv.push_back(input);
    _targetsv.push_back(target);
}

void Branch::buildBranch()
{
    _inputs = new Matrixd[_count_of_tests];
    _targets = new Matrixd[_count_of_tests];
    for(int i = 0;i < _count_of_tests;++i)
    {
        _inputs[i] = Matrixd(1,_input_layer_size);
        _targets[i] = Matrixd(1,_output_layer_size);

        for(int j = 0;j < _input_layer_size;++j)
            _inputs[i](j) = _inputsv[i][j];

        for(int j = 0;j < _output_layer_size;++j)
            _targets[i](j) = _targetsv[i][j];
    }
}

void Branch::clearBranch()
{
    _count_of_tests = 0;
    _inputsv.clear();
    _targetsv.clear();
}

bool Branch::containsString(const std::string& input_string, const std::string& find_string) {
    return input_string.find(find_string) != std::string::npos;
}

std::vector<double> Branch::getDataFromFile(const std::string& path,size_t data_size)
{
    std::vector<double> output_vector(data_size);

    std::ifstream file_stream(path);
    if (file_stream.is_open()) {
        for (size_t i = 0; i < data_size; ++i) {
            double value;
            file_stream >> value;
            output_vector[i] = value;
        }
        file_stream.close();
    }
    else
    {
        std::cerr << "Error opening file" << path << std::endl;
        system("pause");
        exit(0);
    }
    return output_vector;
}

std::vector<std::string> Branch::getFilePathsWithKey(const std::string& path_to_folder, const std::string& key)
{
    std::vector<std::string> output_vector;
    for (auto& p : std::filesystem::directory_iterator(path_to_folder))
    {
        if(containsString(p.path().filename().string(),key))
            output_vector.push_back(p.path().string());
    }
    return output_vector;
}












