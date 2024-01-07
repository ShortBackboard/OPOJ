#include "StatusRecordList.h"
#include "MongoDataBase.h"
#include "RedisDataBase.h"
#include <iostream>
#include <string>

using namespace std;

StatusRecordList *StatusRecordList::GetInstance()
{
    static StatusRecordList statusrecord;
    return &statusrecord;
}

StatusRecordList::StatusRecordList()
{
}

StatusRecordList::~StatusRecordList()
{
}

Json::Value StatusRecordList::SelectStatusRecordList(Json::Value &queryjson)
{
    return MoDB::GetInstance()->SelectStatusRecordList(queryjson);
}

string StatusRecordList::InsertStatusRecord(Json::Value &insertjson)
{
    return MoDB::GetInstance()->InsertStatusRecord(insertjson);
}

bool StatusRecordList::UpdateStatusRecord(Json::Value &updatejson)
{
    return MoDB::GetInstance()->UpdateStatusRecord(updatejson);
}

Json::Value StatusRecordList::SelectStatusRecord(Json::Value &queryjson)
{
    return MoDB::GetInstance()->SelectStatusRecord(queryjson);
}