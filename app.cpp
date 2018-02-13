#include <iostream>
#include <string>
#include <vector>
#include "Utils.h"
using namespace std;
int split_test() {

	Utils::Stopwatch sw;
	int count = 10000 * 10;
	string s = "117.142.173.161|game.gtimg.cn.|20180110134149|117.169.98.75;223.82.245.30;223.82.245.33;117.169.98.99;117.169.98.89;223.82.245.32;117.169.98.98;117.169.98.97;223.82.245.27;223.82.245.24|0|A";
	string seq = "|";
	char ceq = '|';
	sw.start();

	for (int i = 0; i < count; i++) {
		vector<string> v;
		Utils::split1(s, v, seq);
	}
	long time = sw.stop();
	cout << "void split1(const std::string &s, std::vector<std::string> &v, const std::string &c):ִ��" << count << "��," << "��ʱ:" << time << "ms," << "ÿ��" <<count*1000/time<< "��" << endl;

	sw.start();
	for (int i = 0; i < count; i++) {
		vector<string> v;
		Utils::split2(s, v, ceq);
	}
    time = sw.stop();
	cout << "void split2(const std::string &s, std::vector<std::string> &elems, char delim):ִ��" << count << "��," << "��ʱ:" << time << "ms," << "ÿ��" <<count*1000/time<< "��" << endl;



	sw.start();
	for (int i = 0; i < count; i++) {
		vector<string> v;
		Utils::split3(s,&v,seq);
	}
	time = sw.stop();
	cout << "void split3(std::string& s, std::vector< std::string >* ret, std::string& delim):ִ��" << count << "��," << "��ʱ:" << time << "ms," << "ÿ��" << count * 1000 / time << "��" << endl;


	sw.start();
	for (int i = 0; i < count; i++) {
		vector<string> v;
		Utils::split4(s, v, seq);
	}
	time = sw.stop();
	cout << "void split4(const std::string& str, std::vector<std::string>& result, const std::string& delimiter):ִ��" << count << "��," << "��ʱ:" << time << "ms," << "ÿ��" << count * 1000 / time << "��" << endl;

	cin.get();
	return 0;
}

int main() {
	split_test();
	/*
	void split1(const std::string &s, std::vector<std::string> &v, const std::string &c):ִ��100000��,��ʱ:41391ms,ÿ��2415��
	void split2(const std::string &s, std::vector<std::string> &elems, char delim):ִ��100000��,��ʱ:72649ms,ÿ��1376��
	void split3(std::string& s, std::vector< std::string >* ret, std::string& delim):ִ��100000��,��ʱ:41691ms,ÿ��2398��
	void split4(const std::string& str, std::vector<std::string>& result, const std::string& delimiter):ִ��100000��,��ʱ:3727ms,ÿ��26831��
	*/
	return cin.get();
}