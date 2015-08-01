#include <cstdlib>
#include <iostream>
#include <thread>
#include <utility>
#include <boost/asio.hpp>
#include <future>
size_t fibo(size_t n) {
    if(n < 2) {
        return 1;
    } else
    return fibo(n - 1) + fibo(n - 1);
}
using boost::asio::ip::tcp;

class handler_t {
  enum { max_length = 1024 };
  char data[max_length];
  handler_t() = default;
  boost::system::error_code error;
  tcp::socket sock;

public:
  handler_t(tcp::socket foo) : sock{std::move(foo)} {}
  void operator()() {
    for (;;) {
      auto len = read();
      write(len);
      if (error) break;
    }
  }

private:
  size_t read() { return sock.read_some(boost::asio::buffer(data), error); }

  void write(size_t len) {
    int x = atoi(data);
    auto str = std::to_string(fibo(x)) + "\n";
    strcpy(data, str.c_str());
    if (!error)
      boost::asio::write(sock, boost::asio::buffer(data, str.length()));
  }
};
class server_t {
  tcp::acceptor a;
  tcp::socket sock;
   
public:
    server_t(boost::asio::io_service &io_service, unsigned short port) : a(io_service, tcp::endpoint(tcp::v4(), port)),
                                                                       sock{io_service} {
    }
    void run_forever() {
            a.accept(sock);
            handler_t h {std::move(sock)};
            h();
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
      std::cerr << "Usage: ./a.out <PORT>\n";
      return 1;
    }
    try {
        int n = 2;
        std::vector<std::thread> t;
        t.reserve(n);
        boost::asio::io_service io_service;
        short port = std::atoi(argv[1]);
        for (int i = 0 ; i < n; i++) {
            t.emplace_back([&io_service, port] {
                server_t server(io_service, port);
                server.run_forever();
                });
        }
        for(auto &i : t) i.join();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
  return 0;
}
