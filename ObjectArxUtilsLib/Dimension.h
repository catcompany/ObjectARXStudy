#pragma once
class Dimension
{
	//��ӱ�ע��ʽ
	static Acad::ErrorStatus addStyle();
	//���ư뾶��ע
	static void addAcDbRadialDimension(const AcGePoint3d& center, const AcGePoint3d& chordPoint,
		double leaderLength, const ACHAR* dimText = NULL, AcDbObjectId dimStyle = AcDbObjectId::kNull);


};

