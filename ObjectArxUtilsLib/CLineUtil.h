#pragma once

class CLineUtil
{
public:
	CLineUtil();
	~CLineUtil();
	//ͨ�������յ㹹��һ��ֱ��
	static AcDbObjectId add(const AcGePoint3d &pStartPoint,const AcGePoint3d &pEndPoint);

	//ͨ�������յ㹹��һ��ֱ�ߣ���ʹ��ָ��������
	static AcDbObjectId add(const AcGePoint3d& pStartPoint, const AcGePoint3d& pEndPoint, TCHAR* lineType);
};

