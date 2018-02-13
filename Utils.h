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
		//��ʼ���������ĳ��ʱ����������ʱ�䡣
		void start()
		{
			startTime = high_resolution_clock::now();
		}
		//��ȡ��ǰʵ�������ó���������ʱ�䣨�Ժ���Ϊ��λ��
		long long elapsed()
		{
			high_resolution_clock::time_point endTime = high_resolution_clock::now();
			return duration_cast<milliseconds>(endTime - startTime).count();
		}
		//ֹͣ�������ص�ǰʵ�������ó���������ʱ�䣨�Ժ���Ϊ��λ����
		long long stop()
		{
			return elapsed();
		}
	private:
		//��ǰʵ�������ó���������ʱ�䣨�Ժ���Ϊ��λ��
		high_resolution_clock::time_point startTime;
	};
	//���ַ���s���ַ���c�ָ���صĽ�������v������
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
	//���ַ���s���ַ�delim�ָ���صĽ�������elems������
	void split2(const std::string &s, std::vector<std::string> &elems, char delim)
	{
		split(s, delim, std::back_inserter(elems));
	}
	//ע�⣺���ַ���Ϊ��ʱ��Ҳ�᷵��һ�����ַ���  
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
		//strtok_r��linux����İɣ�windows��strtok_s
		char* token = strtok_s(const_cast<char*>(str.c_str()), delimiter.c_str(), &save);
		while (token != nullptr)
		{
			result.emplace_back(token);
			token = strtok_s(nullptr, delimiter.c_str(), &save);
		}
	}
}