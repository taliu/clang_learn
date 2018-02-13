#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
using namespace std::chrono;

namespace Utils
{
	class Stopwatch
	{
	public:
		//开始或继续测量某个时间间隔的运行时间。
		void start()
		{
			startTime = high_resolution_clock::now();
		}
		//获取当前实例测量得出的总运行时间（以毫秒为单位）
		long long elapsed()
		{
			high_resolution_clock::time_point endTime = high_resolution_clock::now();
			return duration_cast<milliseconds>(endTime - startTime).count();
		}
		//停止，并返回当前实例测量得出的总运行时间（以毫秒为单位）。
		long long stop()
		{
			return elapsed();
		}
	private:
		//当前实例测量得出的总运行时间（以毫秒为单位）
		high_resolution_clock::time_point startTime;
	};
	//将字符串s用字符串c分割，返回的结果存放在v数组中
	void split1(const std::string &s, std::vector<std::string> &v, const std::string &c)
	{
		std::string::size_type pos1, pos2;
		pos2 = s.find(c);
		pos1 = 0;
		while (std::string::npos != pos2)
		{
			v.push_back(s.substr(pos1, pos2 - pos1));

			pos1 = pos2 + c.size();
			pos2 = s.find(c, pos1);
		}
		if (pos1 != s.length())
			v.push_back(s.substr(pos1));
	}

	template <typename Out>
	void split(const std::string &s, char delim, Out result)
	{
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim))
		{
			*(result++) = item;
		}
	}
	//将字符串s用字符delim分割，返回的结果存放在elems数组中
	void split2(const std::string &s, std::vector<std::string> &elems, char delim)
	{
		split(s, delim, std::back_inserter(elems));
	}
	//注意：当字符串为空时，也会返回一个空字符串  
	void split3(std::string& s, std::vector< std::string >* ret, std::string& delim)
	{
		size_t last = 0;
		size_t index = s.find_first_of(delim, last);
		while (index != std::string::npos)
		{
			ret->push_back(s.substr(last, index - last));
			last = index + 1;
			index = s.find_first_of(delim, last);
		}
		if (index - last > 0)
		{
			ret->push_back(s.substr(last, index - last));
		}
	}

	void split4(const std::string& str, std::vector<std::string>& result, const std::string& delimiter)
	{
		char* save = nullptr;
		//strtok_r是linux下面的吧，windows是strtok_s
		char* token = strtok_s(const_cast<char*>(str.c_str()), delimiter.c_str(), &save);
		while (token != nullptr)
		{
			result.emplace_back(token);
			token = strtok_s(nullptr, delimiter.c_str(), &save);
		}
	}
}