#include "createData.h"
using namespace std;
using namespace Json;
#define de(x) cout<<#x<<" = "<<x<<endl;

int createData::randNum(int x,int y) {
	int t = y;
	y = x;
	x = t - x + 1;
	return rand() % x + y;
}
string createData::randDno(int x) {
	string ans = "D0";
	ans += x / 10 + '0';
	ans += x % 10 + '0';
	return ans;
}
string createData::randSno(int x) {
	string ans = "031502";
	ans += x / 100 + '0';
	ans += (x / 10) % 10 + '0';
	ans += x % 10 + '0';
	return ans;
}
void createData::randFreeTime(Value &v,int x, int y) {
	int flag[8][8];
	int event_size = randNum(x, y);
	memset(flag, 0, sizeof flag);
	string free_time = "";
	int redone = 15;
	for (int j = 0;j < event_size;++j) {
		free_time = "";
		int week_day = randNum(0, 6);
		free_time += week[week_day] + ".";
		int time_no = randNum(0, 5);
		if (flag[week_day][time_no]) {
			if ((--redone) >= 0) ++event_size;
			continue;
		}
		free_time += freetime[time_no];
		flag[week_day][time_no] = 1;
		v.append(free_time);
	}
	
}
void createData::randStuDno(Value &v) {
	int flag[25];
	int redone = 5;
	memset(flag, 0, sizeof flag);
	int dep_size = randNum(0, 5);
	for (int i = 0;i < dep_size;++i) {
		
		int no = randNum(0, 19);
		if (flag[no]) {
			if ((--redone) >= 0) ++dep_size;
			continue;
		}
		flag[no] = 1;
		v.append(randDno(no));
	}
}
void createData::randTag(Value &v, int y, int op) {
	int flag[3][10];
	int tag_size = randNum(2, y);
	int type = randNum(0, 2), redone=5;
	memset(flag, 0, sizeof flag);
	for (int i = 0;i < tag_size;++i) {
		if (op) {
			type = randNum(0, 2);
		}
		int no = randNum(0, 7);
		if (flag[type][no]) {
			if ((--redone) >= 0) ++tag_size;
			continue;
		}
		flag[type][no] = 1;
		v.append(tag[type][no]);
	}

}

void createData::print() {
	srand((unsigned)time(NULL));
	Value root, stu, dept;
	for (int i = 0;i < 300;i++) {
		Value temp_stu;

		randFreeTime(temp_stu[Sfree], 2, 10);

		temp_stu[Sno] = randSno(i);

		randStuDno(temp_stu[Sdept]);

		randTag(temp_stu[Stag], 8, 1);

		stu.append(temp_stu);
	}

	for (int i = 0;i < 20;++i) {
		Value temp_dep;

		randFreeTime(temp_dep[Dsche], 2, 5);
		
		temp_dep[Dnum].append(randNum(10, 15));
		
		temp_dep[Dno] = randDno(i);
		
		randTag(temp_dep[Dtag], 5, 0);

		dept.append(temp_dep);

	}

	root[Stu] = stu;
	root[Dept] = dept;
	cout << root << endl;
}
