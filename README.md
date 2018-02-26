# c++ split 多种实现比较
```
	void split1(const std::string &s, std::vector<std::string> &v, const std::string &c):执行100000次,耗时:41391ms,每秒2415次
	void split2(const std::string &s, std::vector<std::string> &elems, char delim):执行100000次,耗时:72649ms,每秒1376次
	void split3(std::string& s, std::vector< std::string >* ret, std::string& delim):执行100000次,耗时:41691ms,每秒2398次
	void split4(const std::string& str, std::vector<std::string>& result, const std::string& delimiter):执行100000次,耗时:3727ms,每秒26831次
```

