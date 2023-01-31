#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include "CustomMdSpi.h"
#include "CustomTradeSpi.h"
//#include "CreateFiel.h"

using namespace std;

//链接库(导入链接库的第二种方法）
//#pragma comment (lib, "thostmduserapi_se.lib")
//#pragma comment (lib, "thosttraderapi_se.lib")


// ---- 全局变量(公共参数) ---- //
// SimNow（模拟）
TThostFtdcBrokerIDType gBrokerID = "9999";								   // 模拟经纪商代码
TThostFtdcInvestorIDType gInvesterID = "******";                           // 投资者账户名
TThostFtdcPasswordType gInvesterPassword = "**********";                   // 投资者密码
TThostFtdcAppIDType	AppID = "simnow_client_test";			               // AppID
TThostFtdcAuthCodeType	AuthCode = "0000000000000000";                     // 授权码

// 行情参数
CThostFtdcMdApi* g_pMdUserApi = nullptr;                             // 行情指针
char gMdFrontAddr[] = "tcp://180.168.146.187:10131";               // 模拟行情前置地址--全天站点
//char gMdFrontAddr[] = "tcp://180.168.146.187:10211";               // 模拟行情前置地址--电信
//char gMdFrontAddr[] = "tcp://180.168.146.187:10212";               // 模拟行情前置地址--电信1
//char gMdFrontAddr[] = "tcp://180.168.146.187:10213";               // 模拟行情前置地址--移动
const char* g_pInstrumentID[] = { "p2209" };							     // 行情合约代码列表，中、上、大、郑交易所各选一种   期权："IO2105-C-5000"
char* a1 = new char[10];
int instrumentNum = 1;                                               // 行情合约订阅数量


// 交易参数
CThostFtdcTraderApi* g_pTradeUserApi = nullptr;						 // 交易指针
char gTradeFrontAddr[] = "tcp://180.168.146.187:10130";            // 模拟交易前置地址--全天站点
//char gTradeFrontAddr[] = "tcp://180.168.146.187:10201";            // 模拟交易前置地址--电信
//char gTradeFrontAddr[] = "tcp://180.168.146.187:10202";            // 模拟交易前置地址--电信1
//char gTradeFrontAddr[] = "tcp://180.168.146.187:10203";            // 模拟交易前置地址--移动

TThostFtdcInstrumentIDType g_pTradeInstrumentID = "p2209";           // 所交易的合约代码
TThostFtdcPriceType gLimitPrice = 11064;                             // 交易价格

int main()
{
	// 若文件夹不存在，则创建所需文件夹
//	createFile();

	// 初始化行情线程
	cout << "初始化行情..." << endl;
	char* mdFlowPath = ".//MarketData/";                                    // 存放行情接口在本地生成的流文件的文件路径（.con）
	g_pMdUserApi = CThostFtdcMdApi::CreateFtdcMdApi(mdFlowPath, true);      // 创建行情实例
	CThostFtdcMdSpi* pMdUserSpi = new CustomMdSpi;							// 创建行情回调实例
	g_pMdUserApi->RegisterSpi(pMdUserSpi);									// 注册事件类
	g_pMdUserApi->RegisterFront(gMdFrontAddr);								// 设置行情前置地址
	g_pMdUserApi->Init();													// 连接运行

	// 初始化交易线程
	cout << "初始化交易..." << endl;
	char* tdFlowPath = ".//TradingData/";                                    // 存放交易接口在本地生成的流文件的文件路径（.con）
	g_pTradeUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(tdFlowPath);  // 创建交易实例
	//CThostFtdcTraderSpi *pTradeSpi = new CustomTradeSpi;
	CustomTradeSpi* pTradeSpi = new CustomTradeSpi;							 // 创建交易回调实例
	g_pTradeUserApi->RegisterSpi(pTradeSpi);								 // 注册事件类
	g_pTradeUserApi->RegisterFront(gTradeFrontAddr);						 // 设置交易前置地址
	g_pTradeUserApi->SubscribePublicTopic(THOST_TERT_RESTART);				 // 订阅公共流
	g_pTradeUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);				 // 订阅私有流
	g_pTradeUserApi->Init();												 // 连接运行


	// 等到线程退出
	g_pMdUserApi->Join();
	delete pMdUserSpi;
	g_pMdUserApi->Release();

	g_pTradeUserApi->Join();
	delete pTradeSpi;
	g_pTradeUserApi->Release();

	//getchar();
	system("pause");
	return 0;
}