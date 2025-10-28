#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/asio/ssl.hpp>
#include <iostream>
#include <thread>
#include <string>
#include "include/json.hpp"



class Socket {
    boost::asio::ip::tcp::resolver resolver;
    boost::beast::websocket::stream<boost::beast::ssl_stream<boost::asio::ip::tcp::socket>> ws;
    int heartbeat_interval;
public:
    Socket(boost::asio::io_context& ioc, boost::asio::ssl::context& ssl_ctx);
    void connect();
    void authenticate(const std::string& token);
    void send(const std::string& message);
private:

};

#endif