#include <iostream>
#include <hayai.hpp>
#include <nn.hpp>
#include <msgpack.hpp>
#include <cereal/archives/binary.hpp>

struct InterThreadBenchmark : public ::hayai::Fixture {
};

BENCHMARK_F(InterThreadBenchmark,SimpleAddition,1000,1000) {
    2+2;
}

int main(int argc, char* argv[])
{
    hayai::ConsoleOutputter consoleOutputter;

    hayai::Benchmarker::AddOutputter(consoleOutputter);

    try {
        hayai::Benchmarker::RunAllTests();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
