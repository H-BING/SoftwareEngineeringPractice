#include "createData.h"
#include "json.h"
#include "Constant.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include<iostream>
#include <cstring>
using namespace std;
using namespace Json;


void createData::print() {
	
	
	
	srand((unsigned)time(NULL));
	int vis[3][9];
	Value root;
	Value stu;
	Value dept;
	string dno = "D0";
	string sno = "031502";
	int flag[8][8], f[25], ff[3][9];
	for (int i = 0;i < 20;++i) {
		Value temp_dep;
		string dno_tmp = dno;
		dno_tmp += i / 10+'0';
		dno_tmp += i % 10 + '0';
		temp_dep[Dno] = dno_tmp;

		int t = (rand() % 5)+10;
		temp_dep[Dnum] = t;

		int r = rand() % 6;
		if (r < 2) r += 4;
		memset(flag, 0, sizeof flag);
		string free_time = "";
		for (int j = 0;j < r;++j) {
			free_time = "";
			int t = rand() % 7;
			free_time += week[t] + ".";
			int tt = rand() % 6;
			if (flag[t][tt]) {
				tt = (2 * rand() + 5) % 6;
			}
			if (flag[t][tt]) continue;
			free_time += freetime[tt];
			flag[t][tt] = 1;
			temp_dep[Dsche].append(free_time);
		}


		r = rand() % 6 + 1;
		
		t = rand() % 3;
		memset(f, 0, sizeof f);
		string tagtmp = "";
		if (r < 2) r += 4;
		for (int i = 0;i < r;++i) {
			tagtmp = "";
			int tt = rand() % 8;
			if (f[tt]) {
				tt = (3 * rand() + 5) % 8;
				if (f[tt]) continue;
			}
			
			tagtmp += tag[t][tt];
			temp_dep[Dtag].append(tagtmp);
			vis[t][tt] = 1;
			f[tt] = 1;
		}
		dept.append(temp_dep);

	}


	
	for (int i = 0;i < 300;i++) {
		Value temp_stu;
		string sno_tmp=sno;
		sno_tmp += i / 100 + '0';
		sno_tmp += (i / 10)%10 + '0';
		sno_tmp += i %10 + '0';
		
		
		temp_stu[Sno] = sno_tmp;
		int r = (rand()+7) % 12;
		if (r < 2) r += 8;
		memset(flag, 0, sizeof flag);
		string free_time = "";
		for (int j = 0;j < r;++j) {
			free_time = "";
			int t = rand() % 7;
			free_time += week[t]+".";
			int tt = rand() % 6;
			if (flag[t][tt]) {
				tt = (2*rand()+5) % 6;
			}
			if (flag[t][tt]) continue;
			free_time += freetime[tt];
			flag[t][tt] = 1;
			temp_stu[Sfree].append(free_time);
		}

		
		r = rand() % 5;
		if (r < 2) r += 3;
		memset(f, 0, sizeof f);
		for (int i = 0;i < r;++i) {
			string dep = "D0";
			int t = (2 * rand() + 7) % 20;
			if (f[t]) {
				t = (3 * rand() + 5) % 20;
				if (f[t]) continue;
			}
			dep += t / 10 + '0';
			dep += t % 10 + '0';
			temp_stu[Sdept].append(dep);
			f[t] = 1;
		}

		
		
		r = rand() % 6;
		if (r < 2) r += 4;
		memset(ff, 0, sizeof ff);
		for (int i = 0;i < r;++i) {
			int t = rand() % 3;
			int tt = rand() % 8;
			if (!vis[t][tt]) continue;
			if (ff[t][tt]) {
				int t = (2 * rand() + 7) % 20;
				if (f[t]) {
					t = (3 * rand() + 5) % 20;
					if (f[t]) continue;
				}
			}
			if (ff[t][tt]) continue;
			ff[t][tt] = 1;
			
			
			temp_stu[Stag].append(tag[t][tt]);
		}
		stu.append(temp_stu);
	}


	root[Stu] = stu;
	root[Dept] = dept;

	cout << root << endl;
}
