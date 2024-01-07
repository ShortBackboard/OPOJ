#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/pipeline.hpp>

#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/builder/basic/array.hpp>
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
using bsoncxx::builder::basic::make_array;

using namespace std;
mongocxx::instance instance{}; // This should be done only once.
mongocxx::uri uri{};           // 连接配置
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
    // pipe.sort({make_document(kvp("age", 1))});
    // pipe.limit(2);

    // mongocxx::cursor cursor = collection.aggregate(pipe);
    // for (auto doc : cursor)
    // {
    //     reader.parse(bsoncxx::to_json(doc), jsonvalue);
    //     cout << jsonvalue.toStyledString() << endl;
    // }

    // // 3.修改aaa的age为100
    // document
    //     << "$set" << open_document
    //     << "age" << 100
    //     << close_document;

    // collection.update_one({make_document(kvp("name", "aaa"))}, document.view());

    // // 4.删除ccc
    // collection.delete_one({make_document(kvp("name", "ccc"))});

    // 5.查看所有age小于20的同学
    // $lt：（小于）；$gt（大于）；$lte（小于等于）；$gte（大于等于）
    // pipe.match(make_document(kvp("age", make_document(kvp("$lt", 20)))));
    // mongocxx::cursor cursor = collection.aggregate(pipe);
    // for (auto doc : cursor)
    // {
    //     reader.parse(bsoncxx::to_json(doc), jsonvalue);
    //     cout << jsonvalue.toStyledString() << endl;
    // }


    // 6.查看所有age大于20小于等于30的同学
    // pipe.match(make_document(kvp("age", make_document(kvp("$lt", 30), 
    //                                 kvp("$gte", 20)))));
    // mongocxx::cursor cursor = collection.aggregate(pipe);
    // for (auto doc : cursor)
    // {
    //     reader.parse(bsoncxx::to_json(doc), jsonvalue);
    //     cout << jsonvalue.toStyledString() << endl;
    // }

    // 7.查看所有name为aaa的age
    // pipe.match(make_document(kvp("name", "aaa")));
    // pipe.project(make_document(kvp("_id", 0), kvp("age", 1)));

    // mongocxx::cursor cursor = collection.aggregate(pipe);
    // for (auto doc : cursor)
    // {
    //     reader.parse(bsoncxx::to_json(doc), jsonvalue);
    //     cout << jsonvalue.toStyledString() << endl;
    // }

    // 8.查看所有name为aaa或者name为bbb的age
    // $or（或）
    // pipe.match(make_document(kvp("$or", make_array(make_document(kvp("name", "aaa")),
    //                                                  make_document(kvp("name", "bbb"))))));
    // pipe.project(make_document(kvp("_id", 0), kvp("age", 1)));
    // mongocxx::cursor cursor = collection.aggregate(pipe);
    // for (auto doc : cursor)
    // {
    //     reader.parse(bsoncxx::to_json(doc), jsonvalue);
    //     cout << jsonvalue.toStyledString() << endl;
    // }

    // // 9.查看所有name为aaa并且age为20的文档
    // // $and（与）
    // pipe.match(make_document(kvp("$and", make_array(make_document(kvp("name", "aaa")),
    //                                                  make_document(kvp("age", 21))))));
    // pipe.project(make_document(kvp("_id", 0), kvp("age", 1)));
    // mongocxx::cursor cursor = collection.aggregate(pipe);
    // for (auto doc : cursor)
    // {
    //     reader.parse(bsoncxx::to_json(doc), jsonvalue);
    //     cout << jsonvalue.toStyledString() << endl;
    // }

    // 10.删除所有age大于20的同学
    // $gt（大于）
    // collection.delete_many(make_document(kvp("age", make_document(kvp("$gt", 20)))));

    // 11.插入一条数据
    collection.insert_one(make_document(kvp("_id", 12),
                                        kvp("name", "aaa"),
                                        kvp("age", 22),
                                        kvp("grades", make_array(make_document(kvp("Chinese", "122")),
                                                                 make_document(kvp("Math", "150"))))));
    

    return 0;
}