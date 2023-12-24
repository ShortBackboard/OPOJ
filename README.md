# OPOJ

基于C++和Vue.js的OJ在线判题系统

## 测试

  1.进入项目: cd ./.../OPOJ
  2.创建 build 文件夹并进入: mkdir build && cd build
  3.构建项目并编译: cmake && make
  4.运行: ./OPOJ
  
## 测试get请求

  curl -i "127.0.0.1:8081/test/get?userid=1"
  
## 测试post请求

  curl -i -X POST -d '{"name":"lcy", "hobby":["running","reading","rap"]}' 127.0.0.1:8081/test/post

- i 输出 HTTP 头和返回内容。
- X 指定与服务器通信使用的请求方法
- d 主要是针对 http 协议的 post 请求指定要在消息体中发送的数据

## MongoDB数据库环境搭建 以及C++调用数据库

使用图形化界面：VSCode 左侧栏中 MongoDB 插件
MongoDB学习：https://docs.mongoing.com/