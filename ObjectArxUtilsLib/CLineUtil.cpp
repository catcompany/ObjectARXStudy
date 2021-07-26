#include "pch.h"
#include "CLineUtil.h"
#include "CDwgDatebaseUtil.h"


CLineUtil::CLineUtil()
{
}


CLineUtil::~CLineUtil()
{
}

AcDbObjectId CLineUtil::add(const AcGePoint3d& pStartPoint, const AcGePoint3d& pEndPoint)
{
	return add(pStartPoint, pEndPoint, NULL);
}

AcDbObjectId CLineUtil::add(const AcGePoint3d& pStartPoint, const AcGePoint3d& pEndPoint, TCHAR* lineType)
{
	//����ֱ��ʵ��
	AcDbLine* pLine = new AcDbLine(pStartPoint, pEndPoint);
	//acedAlert(lineType);
	if (lineType != NULL)
	{
		pLine->setLinetype(lineType);
	}
	//��ֱ��ʵ����ӵ�ģ�Ϳռ�
	return CDwgDatebaseUtil::PostToModelSpace(pLine);
}

