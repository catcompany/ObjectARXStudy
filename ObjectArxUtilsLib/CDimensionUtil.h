#pragma once


class CDimensionUtil
{
public:
	CDimensionUtil();
	virtual ~CDimensionUtil();

	// �½���ע��ʽ
	static AcDbObjectId CreateStyle(TCHAR* StyleName);
	// �����ע
	static AcDbObjectId AddDimAligned(const AcGePoint3d& pt1,
		const AcGePoint3d& pt2, const AcGePoint3d& ptLine, const TCHAR* dimText = NULL,
		AcDbObjectId dimStyle = AcDbObjectId::kNull);
	static AcDbObjectId AddDimAligned(const AcGePoint3d& pt1,
		const AcGePoint3d& pt2, const AcGePoint3d& ptLine,
		const AcGeVector3d& vecOffset = AcGeVector3d::kIdentity,
		const TCHAR* dimText = NULL);

	// ת�Ǳ�ע
	static AcDbObjectId AddDimRotated(const AcGePoint3d& pt1,
		const AcGePoint3d& pt2, const AcGePoint3d& ptLine,
		double rotation, const TCHAR* dimText = NULL,
		AcDbObjectId dimStyle = AcDbObjectId::kNull);

	// �뾶��ע
	static AcDbObjectId AddDimRadial(const AcGePoint3d& ptCenter,
		const AcGePoint3d& ptChord, double leaderLength,
		const TCHAR* dimText = NULL,
		AcDbObjectId dimStyle = AcDbObjectId::kNull);
	static AcDbObjectId AddDimRadial(const AcGePoint3d& ptCenter,
		double radius, double angle, double leaderLength = 5);

	// ֱ����ע
	static AcDbObjectId AddDimDiametric(const AcGePoint3d& ptChord1,
		const AcGePoint3d& ptChord2, double leaderLength,
		const TCHAR* dimText = NULL,
		AcDbObjectId dimStyle = AcDbObjectId::kNull);
	static AcDbObjectId AddDimDiametric(const AcGePoint3d& ptCenter,
		double radius, double angle, double leaderLength = 5);

	// �Ƕȱ�ע
	static AcDbObjectId AddDim2LineAngular(const AcGePoint3d& ptStart1,
		const AcGePoint3d& ptEnd1, const AcGePoint3d& ptStart2,
		const AcGePoint3d& ptEnd2, const AcGePoint3d& ptArc,
		const TCHAR* dimText = NULL,
		AcDbObjectId dimStyle = AcDbObjectId::kNull);
	static AcDbObjectId AddDim3PtAngular(const AcGePoint3d& ptCenter,
		const AcGePoint3d& ptEnd1, const AcGePoint3d& ptEnd2,
		const AcGePoint3d& ptArc, const TCHAR* dimText = NULL,
		AcDbObjectId dimStyle = AcDbObjectId::kNull);

	// �����ע
	static AcDbObjectId AddDimOrdinate(Adesk::Boolean xAxis,
		const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd,
		const TCHAR* dimText = NULL,
		AcDbObjectId dimStyle = AcDbObjectId::kNull);
	static AcDbObjectIdArray AddDimOrdinate(const AcGePoint3d& ptDef,
		const AcGePoint3d& ptTextX, const AcGePoint3d& ptTextY);
	static AcDbObjectIdArray AddDimOrdinate(const AcGePoint3d& ptDef,
		const AcGeVector3d& vecOffsetX, const AcGeVector3d& vecOffsetY);
};
