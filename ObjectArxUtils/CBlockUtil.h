#pragma once
class CBlockUtil
{
public:
	CBlockUtil();
	~CBlockUtil();

	//����һ���鶨�壬����״Ϊһ����Ȧ׼�ǣ������ؿ�����
	static void addMyBlockDefine();

	//�����û�����Ŀ�����λ�õ��������
	static void InsertBlock();

	//��ͼ������ȡ�ض����Ե�ֵ
	static bool GetAttributeValue(AcDbBlockReference *pBlockRef, TCHAR *Tag, AcString &Value);
};

 