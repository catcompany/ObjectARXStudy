#include "pch.h"
#include "CArcUtil.h"
#include "CCalculation.h"
#include "CDwgDatebaseUtil.h"

AcDbObjectId CArcUtil::add(AcGePoint3d ptCenter, double radius, double startAngel, double endAngel, bool isGra)
{
	if (!isGra)
	{
		startAngel = CCalculation::GtoR(startAngel);
		endAngel = CCalculation::GtoR(endAngel);
	}
	AcDbArc* pArc = new AcDbArc(ptCenter, radius, startAngel, endAngel);
	return CDwgDatebaseUtil::PostToModelSpace(pArc);
}

AcDbObjectId CArcUtil::add(AcGePoint3d ptStart, AcGePoint3d ptCenter, AcGePoint3d ptEnd)
{

	//����뾶
	double radius = ptCenter.distanceTo(ptStart);
	//�������յ�Ƕ�
	AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
	AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = vecEnd.angle();
	//����Բ��
	return CArcUtil::add(ptCenter, radius, startAngle, endAngle, TRUE);
}

AcDbObjectId CArcUtil::add(AcGePoint3d ptStart, AcGePoint3d ptCenter, double angle)
{
	//����뾶
	double radius = ptCenter.distanceTo(ptStart);
	//������㣬�յ�Ƕ�
	AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = startAngle + angle;

	acutPrintf(L"��ʼ�Ƕȣ�%f�������Ƕȣ�%f \n", startAngle, endAngle);
	//����Բ��
	return CArcUtil::add(ptCenter, radius, startAngle, endAngle, true);
}
