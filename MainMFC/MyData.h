#pragma once

#define VERSION 20210714
class DataStruct
{

public:
	DataStruct(CString configFilePath);
	//����
	CString Save(DataStruct data);
	//��ȡ
	void Read(DataStruct data, double result[14]);
	//�汾��Ϣ
	int version;
	//����
	double r1, r2, r3, r4, r5;
	double h1, h2, h_2;
	double radius1, radius_1, radius2, radius3, radius4, radius5;
private:
	CString filePath;
};

