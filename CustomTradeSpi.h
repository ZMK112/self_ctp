#pragma once

// ������
#include "include/ThostFtdcTraderApi.h"

class CustomTradeSpi : public CThostFtdcTraderSpi
{
	// ---- ctp_api���ֻص��ӿ� ---- //
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	void OnFrontConnected();

	// �ͻ�����֤��Ӧ
	void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///��¼������Ӧ
	void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///����Ӧ��
	void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	void OnFrontDisconnected(int nReason);

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	void OnHeartBeatWarning(int nTimeLapse);

	///�ǳ�������Ӧ
	void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ���߽�����ȷ����Ӧ
	void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ��Ӧ
	void OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ʽ��˻���Ӧ
	void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���Ӧ
	void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///����¼��������Ӧ
	void OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///��������������Ӧ
	void OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///����֪ͨ
	void OnRtnOrder(CThostFtdcOrderField* pOrder);

	///�ɽ�֪ͨ
	void OnRtnTrade(CThostFtdcTradeField* pTrade);


// ---- �Զ��庯��, д��void������Ҫ����ֵ��Ҳ����Ҫ���Σ���ֱ�ӵ��ø÷��� ---- //
public:
	/// ��½�ɹ��ı�ʶ
	bool loginFlag; 

	/// �򿪲�
	void buy_open(TThostFtdcInstrumentIDType instrumentID, TThostFtdcPriceType NewPrice, TThostFtdcVolumeType volume);

	/// ��ƽ��(Ĭ��ƽ�֣�
	void buy_close(TThostFtdcInstrumentIDType instrumentID, TThostFtdcPriceType NewPrice, TThostFtdcVolumeType volume, TThostFtdcTimeConditionType CombOffsetFlag=THOST_FTDC_OF_Close);

	/// ������
	void sell_open(TThostFtdcInstrumentIDType instrumentID, TThostFtdcPriceType NewPrice, TThostFtdcVolumeType volume);

	/// ��ƽ��(Ĭ��ƽ�֣�
	void sell_close(TThostFtdcInstrumentIDType instrumentID, TThostFtdcPriceType NewPrice, TThostFtdcVolumeType volume, TThostFtdcTimeConditionType CombOffsetFlag=THOST_FTDC_OF_Close);

private:
	///�ͻ�����֤����
	void reqAuthenticate();

	/// ��¼����
	void reqUserLogin();

	/// �ǳ�����
	void reqUserLogout(); 

	/// Ͷ���߽��ȷ��
	void reqSettlementInfoConfirm();

	/// �����ѯ��Լ
	void reqQueryInstrument(); 

	/// �����ѯ�ʽ��ʻ�
	void reqQueryTradingAccount(); 

	/// �����ѯͶ���ֲ߳�
	void reqQueryInvestorPosition();

	/// ���󱨵�����
	void reqOrderAction(CThostFtdcOrderField* pOrder);

	/// �Ƿ��յ�������Ϣ
	bool isErrorRspInfo(CThostFtdcRspInfoField* pRspInfo); 

	/// �Ƿ��ҵı����ر�
	bool isMyOrder(CThostFtdcOrderField* pOrder); 

	/// �Ƿ����ڽ��׵ı���
	bool isTradingOrder(CThostFtdcOrderField* pOrder); 
};
