#pragma once
class CCalculation
{
public:
	// ��ά����ת��Ϊ��ά����
	static AcGePoint3d Pt2dTo3d(AcGePoint2d pt);

	// ��ά����תΪ��ά
	static AcGePoint2d Pt3dTo2d(AcGePoint3d pt);

	// �Ƕ�תΪ����
	static double radiusToAngel(double radius);
};

