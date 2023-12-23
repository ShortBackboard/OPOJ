#include "./include/httplib.h"           // HTTP库
#include <jsoncpp/json/json.h> // JSON库
#include <iostream>
#include <string>

using namespace std;

// get请求测试函数
void doTestGet(const httplib::Request &req, httplib::Response &res)
{
    cout << "get请求测试" << endl;
    // 获取请求头参数
    string userid = req.get_param_value("userid");

    // 处理逻辑......

    // 返回数据
    Json::Value resjson;
    if (userid == "1")
    {
        resjson["userid"] = userid;
        resjson["name"] = "lcy";
        resjson["age"] = "22";
        resjson["hobby"].append("basketball");
        resjson["hobby"].append("reading");
    }
    else if (userid == "2")
    {
        resjson["userid"] = userid;
        resjson["name"] = "LCY";
        resjson["age"] = "18";
        resjson["hobby"].append("travelling");
        resjson["hobby"].append("running");
    }
    else
    {
        res.status = 404;
    }

    res.set_content(resjson.toStyledString(), "json");
}

int main()
{
  using namespace httplib;
  Server server;

  // get请求测试
  server.Get("/test/get", doTestGet);

  // 设置监听端口
  server.listen("0.0.0.0", 8081);

  return 0;
}