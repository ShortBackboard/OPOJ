#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/pipeline.hpp>

#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <mongocxx/pool.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

#include <iostream>
#include <jsoncpp/json/json.h>


using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

using namespace std;
mongocxx::instance instance{};                                                                       // This should be done only once.
mongocxx::uri uri{}; // 连接配置
mongocxx::client client(uri);

int main()
{
    Json::Value jsonvalue;
    Json::Reader reader;
    mongocxx::pipeline pipe;
    bsoncxx::builder::stream::document document{};
    auto collection = client["Mongotest"]["Grades"];

    // 1. 查询全部
    // mongocxx::cursor cursor = collection.find({});
    // for (auto doc : cursor)
    // {
    //     reader.parse(bsoncxx::to_json(doc), jsonvalue);
    //     cout << jsonvalue.toStyledString() << endl;
    // }

    // 2.查询年龄最小的两个人
    pipe.sort({make_document(kvp("age", 1))});
    pipe.limit(2);

    mongocxx::cursor cursor = collection.aggregate(pipe);
    for (auto doc : cursor)
    {
        reader.parse(bsoncxx::to_json(doc), jsonvalue);
        cout << jsonvalue.toStyledString() << endl;
    }

    // 3.修改aaa的age为100
    // document
    //     << "$set" << open_document
    //     << "age" << 100
    //     << close_document;

    // collection.update_one({make_document(kvp("name", "aaa"))},document.view());


    // 4.删除ccc
    collection.delete_one({make_document(kvp("name", "ccc"))});

    return 0;
}