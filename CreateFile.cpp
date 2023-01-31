#include "CreateFiel.h"

// 后续可以创建为：./MarketData/179939/md.con/
void createFile()
{
	char* MdPath = ".//MarketData";
	if (_access(MdPath, 0) == -1)
	{
		printf("The  file/dir doesn't exisit");
		int ret = _mkdir(MdPath);  // 返回 0 表示创建成功， - 1 表示失败
	}

	char* TdPath = ".//TradingData";
	if (_access(TdPath, 0) == -1)
	{
		printf("The  file/dir doesn't exisit");
		int ret = _mkdir(TdPath);
	}

	// 判断该文件夹是否存在，不存在则创建（存放数据库，csv文件）
	char* DataPath = ".//SqlData";
	if (_access(DataPath, 0) == -1)
	{
		printf("The  file/dir doesn't exisit");
		int ret = _mkdir(DataPath);  // 返回 0 表示创建成功， - 1 表示失败
	}
}