// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include <string>


struct TimeSegment {
	uint64_t btime;
	uint64_t etime;
	TimeSegment() : btime(0), etime(0) {
	}
	TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_) {
	}
};


inline void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment>& lstTimeSegment) {
	// TODO
	int len = lstTimeSegment.size();
	int start = 0;
	int end = 0;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		bool flag = false;

		if (lstTimeSegment[i].btime >= nBeginTime) {
			flag = true;
			start = nBeginTime;
			for (int j = i; i < len; j++) {
				if (lstTimeSegment[j].etime >= nEndTime) {
					end = lstTimeSegment[j].etime;
					count = j - i;
					break;
				}
				if (lstTimeSegment[j].btime >= nEndTime) {
					end = lstTimeSegment[j].btime;
					count = j - i;
					break;
				}
			}

		}
		if (lstTimeSegment[i].etime >= nBeginTime) {
			flag = true;
			start = lstTimeSegment[i].etime;
			for (int j = i; i < len; j++) {
				if (lstTimeSegment[j].etime >= nEndTime) {
					end = lstTimeSegment[j].etime;
					count = j - i;
					break;
				}
				if (lstTimeSegment[j].btime >= nEndTime) {
					end = lstTimeSegment[j].btime;
					count = j - i;
					break;
				}
			}
		}
		if (flag) {

			lstTimeSegment[i].btime = start;
			lstTimeSegment[i].etime = end;

			for (int k = i + 1; k < len - count; k++) {
				lstTimeSegment[k].btime = lstTimeSegment[k + count].btime;
				lstTimeSegment[k].etime = lstTimeSegment[k + count].etime;
			}
			while (count--)
				lstTimeSegment.pop_back();
			break;
		}

	}

}

TimeSegment ParseTimeSegmentString(const std::string& input) {
	TimeSegment timestamp;
	size_t nPos = input.find("-");
	size_t nLength = input.length();
	if (nPos > 0 && nPos < nLength) {
		try {
			timestamp.btime = std::stoull(input.substr(0, nPos));
			timestamp.etime = std::stoull(input.substr(nPos + 1, nLength));
		}
		catch (...) {
			std::cout << "请输入有效数据.\n";
		}
	}
	else {
		std::cout << "请输入有效数据.\n";
	}

	return timestamp;
}

std::list<TimeSegment> ParseTimeSegmentList(const std::string& input) {
	TimeSegment timestamp;
	std::list<TimeSegment> lstTimestamp;
	std::string temp;
	size_t nStartPos = 0;
	size_t nEndPos = input.find(",");
	size_t nLength = input.length();
	while (nEndPos > nStartPos && nEndPos <= nLength) {
		temp = input.substr(nStartPos, nEndPos);
		if (temp.size() > 0) {
			timestamp = ParseTimeSegmentString(temp);
			lstTimestamp.push_back(timestamp);
		}
		nStartPos = nEndPos + 1;
		nEndPos = input.find(",", nStartPos);
		if (-1 == nEndPos) {
			nEndPos = nLength;
		}
	}

	return lstTimestamp;
}

int main(int argc, char* argv[]) {
	std::string input;
	std::cin >> input;
	int nPos = input.find(";");
	std::list<TimeSegment> lstTimestamp = ParseTimeSegmentList(input.substr(0, nPos));
	TimeSegment timestamp = ParseTimeSegmentString(input.substr(nPos + 1, input.size()));

	MergeTimeSegment(timestamp.btime, timestamp.etime, lstTimestamp);

	for (auto it = lstTimestamp.begin(); it != lstTimestamp.end();) {
		std::cout << it->btime << "-" << it->etime;
		if (++it != lstTimestamp.end()) {
			std::cout << ",";
		}
	}

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
