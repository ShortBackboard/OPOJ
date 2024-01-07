#include <sw/redis++/redis++.h>
#include <string>
#include <iostream>

using namespace std;
using namespace sw::redis;

int main()
{
    Redis redis("tcp://@127.0.0.1:6379");
    redis.set("name", "lcy");
    redis.set("age", "20");
    redis.set("hobby", "running");
    cout << "hobby: " << *redis.get("hobby") << endl;
    redis.del("hobby");
    redis.setex("k1", 20, "timeleft");
    cout << "expire time left: " << redis.ttl("k1") << endl;

    return 0;
}
