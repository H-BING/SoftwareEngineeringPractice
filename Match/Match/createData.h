
#include "json.h"
#include "JsonHandler.h"
#include "Constant.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class createData {
public:
	const string freetime[6] = { "8:00~10:00","10:00~12:00","14:00~16:00","16:00~18:00","18:30~20:30","20:30~22:30" };
	const string week[7] = { "Mon","Tues","Wed","Thur","Fri","Sat","Sun" };
	const string tag[3][8] = { { "tennis", "pingpong", "swimming", "climbing", "basketball", "soccer", "fishing", "running" },{ "movies","singing", "dancing", "acting", "reading","travel", "collect", "painting" },{ "PS","Linux","Android","iOS", "Web",".net","Java", "SQL" } };
	
	void print();
	string randDno(int x);
	string randSno(int x);
	void randStuDno(Value &v);
	int randNum(int x, int y);
	void randTag(Value &v, int y, int op);
	void randFreeTime(Value &v, int x, int y);
	
};
