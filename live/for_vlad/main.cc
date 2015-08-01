#include "server.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) { return -1; }
    //boost::asio::io_service io_service ;
    demo::server server(std::atoi(argv[1]));
    server.run();
}

