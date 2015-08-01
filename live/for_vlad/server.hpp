#include <cstdlib>
#include <future>
#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include <utility>
size_t fibo(size_t n) {
    if ( n < 2) {
        return n;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}
namespace demo {
using boost::asio::ip::tcp;
class handler : public std::enable_shared_from_this<handler> {
    tcp::socket _socket;
    enum {length = 8};
    char _data[length];
public:
    handler(tcp::socket socket) : _socket {std::move(socket)} {
    }
    
    handler& start() {
        perform_read();
        return *this;
    }

private:
    void perform_read() {
        auto self(shared_from_this());
        _socket.async_read_some(boost::asio::buffer(_data, length),
                                [this, self](auto error, auto len ) {
                                    if(!error) {
                                        std::cout << "query\n";
                                        std::cout << fibo(42) << std::endl;;
                                        std::cout << this->_data << std::endl;
                                        this->perform_write(len);
                                    } 
                                });
    }
    void perform_write(size_t len) {
        auto self(shared_from_this());
        boost::asio::async_write(_socket, boost::asio::buffer(_data, len),
                                [this, self](auto error, auto len) {
                                    if(!error) {
                                        this->perform_read();
                                    }
                                 });
    }
};


class server {
    tcp::acceptor _acceptor;
    tcp::socket _socket;
    boost::asio::io_service _io_service;
public:
    server(
           // boost::asio::io_service &io_service,
            short port) :// server(),
                         _acceptor{_io_service, tcp::endpoint(tcp::v4(), port)},
                         _socket{_io_service} 
    {
    }
    void run() {
        std::cout << "HELLO\n";
        //_io_service.run();
        //run_forever();
    }
    void run_forever() {
       std::cout << "Run_server\n";
       accept();
       std::cout << "END\n";
    }
private:
    void accept() {
        std::cout << "accept()\n";
      _acceptor.async_accept(_socket,
                              [this](auto error) {
                                if(!error) {
                                    std::cout << "Make session\n";
                                    std::make_shared<handler>(std::move(_socket))->start();
                                }
                                this->accept();
                              t.join();
                              });

    }
};

} // END of namespace demo
