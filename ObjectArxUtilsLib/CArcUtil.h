#pragma once


class CArcUtil
{
public:

	//����Բ��(���ĵ㡢�뾶����ʼ�Ƕȡ���ֹ�Ƕȣ� �Ƕ�Ϊ��
	static AcDbObjectId add(AcGePoint3d ptCenter, double radius, double startRadius, double endRadius,bool isAngel);

	//����Բ��(��㡢Բ�ġ��յ�)
	static AcDbObjectId add(AcGePoint3d ptStart, AcGePoint3d ptCenter, AcGePoint3d ptEnd);

};

