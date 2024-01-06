#include "HttpServer.h"
#include "../include/httplib.h"
#include <jsoncpp/json/json.h>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "Control.h"

using namespace std;
Control control;

void doGetImage(const httplib::Request &req, httplib::Response &res)
{
    printf("doGetImage start!!!\n");
    // 获取图片
    int index = stoi(req.matches[1]);
    string path = "../www/image/avatar" + to_string(index) + ".webp";
    ifstream infile;
    infile.open(path.data());
    if (!infile.is_open())
    {
        string str = "图片获取失败";
        res.set_content(str, "text");
    }
    // 将infile的内容读取到image中
    string image((istreambuf_iterator<char>(infile)),
                 (istreambuf_iterator<char>()));
    printf("doGetImage end!!!\n");
    // 设置返回的图片格式
    res.set_content(image, "webp");
}

void HttpServer::Run()
{
    using namespace httplib;
    Server server;

    // 获取图片资源
    // 正则表达式
    server.Get(R"(/image/(\d+))", doGetImage);

    // 设置静态资源路径
    // server.set_base_dir("../www");

    server.listen("0.0.0.0", 8081);
}

HttpServer::HttpServer()
{
}

HttpServer::~HttpServer()
{
}