# OPOJ

基于C++和Vue.js的OJ在线判题系统

## 测试

  1.进入项目: cd ./.../OPOJ
  2.创建 build 文件夹并进入: mkdir build && cd build
  3.构建项目并编译: cmake && make
  4.运行: ./opoj
  
## 测试get请求

  curl -i "127.0.0.1:8081/test/get?userid=1"
  
## 测试post请求

  curl -i -X POST -d '{"name":"lcy", "hobby":["running","reading","rap"]}' 127.0.0.1:8081/test/post

- i 输出 HTTP 头和返回内容。
- X 指定与服务器通信使用的请求方法
- d 主要是针对 http 协议的 post 请求指定要在消息体中发送的数据

## MongoDB数据库环境搭建 以及C++调用数据库

使用图形化界面：VSCode 左侧栏中 MongoDB 插件
启动mongoDb：sudo mongod -f /usr/local/mongo/conf/mongo.conf
MongoDB学习：https://docs.mongoing.com/

## 系统工作流程介绍：
  1.HttpServer 模块监听 8081 端口。
  2.用户向网络中发送对后端数据的请求并携带请求参数。
  3.HttpServer 模块监听到请求，将参数封装成 JSON 变量，并传递给 Control 模块。
  4.Control 模块会调用一个或多个模块进行逻辑处理，这些模块会调用 MongoDB 数据库或 Redis 数据库请求数据或操作数据。
  5.Control 模块调用完成后将结果返回给 HttpServer 模块。
  6.HttpServer 模块会根据返回结果的 Result 参数调整不同的状态码并将最终结果进行返回到前端。
