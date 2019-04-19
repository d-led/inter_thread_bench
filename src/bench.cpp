#include <hayai.hpp>
#include "synchronous/sync_fire_and_forget_sink.hpp"

struct SyncFireAndForgetSink : public ::hayai::Fixture {
    sync_fire_and_forget_sink sink;
};

struct AtomicFireAndForgetSink : public ::hayai::Fixture {
    atomic_fire_and_forget_sink sink;
};

BENCHMARK_F(SyncFireAndForgetSink,one_way_ping,10000,100000) {
    sink.do_ping(1);
}

BENCHMARK_F(AtomicFireAndForgetSink, one_way_ping, 10000, 100000) {
    sink.do_ping(1);
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
