#pragma once


class CArcUtil
{
public:
	//����λ��XOYƽ���ϵ�Բ���ĺ���
	static AcDbObjectId add(AcGePoint2d ptCenter, double radius, double startAngle, double endAngle);

	//���㷨����Բ��
	static AcDbObjectId add(AcGePoint2d ptStart, AcGePoint2d ptOnArc, AcGePoint2d ptEnd);

	//"��㣬Բ�ģ��յ�"����Բ��
	static AcDbObjectId addArc(AcGePoint2d ptStart, AcGePoint2d ptCenter, AcGePoint2d ptEnd);

	//"��㣬Բ�ģ�Բ���Ƕ�"����Բ��
	static AcDbObjectId add(AcGePoint2d ptStart, AcGePoint2d ptCenter, double angle);

	//����Բ��
	static AcDbObjectId add(AcGePoint3d ptCenter, AcGeVector3d vec, double radius, double starAngle, double endAngle);

};

