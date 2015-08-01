//
// echo_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <thread>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/spawn.hpp>
#include <chrono>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/write.hpp>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;

class session : public std::enable_shared_from_this<session>
{
public:
  explicit session(tcp::socket socket) : socket_    (std::move(socket)), 
                                         timer_     (socket_.get_io_service()),
                                         strand_    (socket_.get_io_service()) {}

  void go() {
    auto self(shared_from_this());
    boost::asio::spawn(strand_,
        [this, self](boost::asio::yield_context yield) {
          try {
            char data[128];
            for (;;) {
              timer_.expires_from_now(std::chrono::seconds(10));
              std::size_t n = socket_.async_read_some(boost::asio::buffer(data), yield);
              boost::asio::async_write(socket_, boost::asio::buffer(data, n), yield);
            }
          }
          catch (std::exception& e) {
            std::cout << "end\n";
            socket_.close();
            timer_.cancel();
          }
        });

    boost::asio::spawn(strand_,
        [this, self](boost::asio::yield_context yield) {
          while (socket_.is_open()) {
            // std::cout << "check()\n";
            boost::system::error_code ignored_ec;
            timer_.async_wait(yield[ignored_ec]);
            if (timer_.expires_from_now() <= std::chrono::seconds(0))
              socket_.close();
          }
        });
  }

private:
  tcp::socket socket_;
  boost::asio::steady_timer timer_;
  boost::asio::io_service::strand strand_;
};

class async_server_t {
    //tcp::socket socket_;
    boost::asio::io_service service;
    tcp::acceptor acceptor;
public:
    async_server_t(int port) : acceptor(service, tcp::endpoint(tcp::v4(), port)) {
        boost::asio::spawn(service, [this](boost::asio::yield_context yield) { this->spawn(yield); });
    }

    void spawn(boost::asio::yield_context yield) {
        //auto start = std::chrono::high_resolution_clock::now();
        static int c = 0;
        for (;;) {
            boost::system::error_code ec;
            tcp::socket socket(service);
            acceptor.async_accept(socket, yield[ec]);
            std::cout << "Welcome user #" << ++c << std::endl;
            if (!ec) std::make_shared<session>(std::move(socket))->go();
        }
    }
    void run() { service.run(); }
};


void run_server(int port) {
  try {
    async_server_t(port).run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }
}


int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: echo_server <port>\n";
    return 1;
  }

  int port = std::atoi(argv[1]);
  run_server(port);
  
  return 0;
}

