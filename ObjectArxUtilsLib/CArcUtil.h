#pragma once


class CArcUtil
{
public:

	//����Բ��(���ĵ㡢�뾶����ʼ�Ƕȡ���ֹ�Ƕȣ� isGra�ж��Ƿ��ǻ��ȣ�Ĭ���õĽǶ�
	static AcDbObjectId add(AcGePoint3d ptCenter, double radius, double startAngel, double endAngel, bool isGra = false);

	//����Բ��(��㡢Բ�ġ��յ�)
	static AcDbObjectId add(AcGePoint3d ptStart, AcGePoint3d ptCenter, AcGePoint3d ptEnd);

	//����Բ��(��㡢Բ�ġ���ת�Ƕȣ� 
	static AcDbObjectId add(AcGePoint3d ptStart, AcGePoint3d ptCenter, double angle);

};

