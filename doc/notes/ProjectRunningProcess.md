# 以注册用户功能为例

## 1

在Httplib.cpp中编写一个函数，该函数能够发送POST请求，并接收响应。

// 请求注册用户
void doRegisterUser(const httplib::Request &req, httplib::Response &res)
{
    printf("doRegister start!!!\n");
    Json::Value jsonvalue;
    Json::Reader reader;
    // 解析传入的json
    reader.parse(req.body, jsonvalue);
    Json::Value resjson = control.RegisterUser(jsonvalue);

    printf("doGetProblem end!!!\n");
    SetResponseStatus(resjson, res);
    res.set_content(resjson.toStyledString(), "json");
}

// run函数中
server.Post("/user/register", doRegisterUser);

## 2

前端  curl -i -X POST -d '{"id":"001"...}' 127.0.0.1:8081/test/post 发送请求，并获取响应。

## 3

后端监听到请求以后，调用doRegisterUser函数
                  ---> control.RegisterUser(jsonvalue)
                  ---> UserList::GetInstance()->RegisterUser(registerjson)
                  ---> MoDB::GetInstance()->RegisterUser(registerjson)，
最终操作数据库并将处理结果以及状态码返回给前端。
