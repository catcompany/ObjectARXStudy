#include "pch.h"
#include "CArcUtil.h"
#include "CCalculation.h"
#include "CDwgDatebaseUtil.h"

AcDbObjectId CArcUtil::add(AcGePoint3d ptCenter, double radius, double startRadius, double endRadius, bool isAngel)
{
	if (!isAngel)
	{
		startRadius = CCalculation::radiusToAngel(startRadius);
		endRadius = CCalculation::radiusToAngel(endRadius);
	}
	AcDbArc* pArc = new AcDbArc(ptCenter, radius, startRadius, endRadius);
	if (pArc == NULL)
		return NULL;

	//��ʵ����ӵ�ģ�Ϳռ��ǹ̶��Ĵ��룬
	AcDbDatabase* pDb = NULL;
	pDb = acdbHostApplicationServices()->workingDatabase();
	if (pDb == NULL)
		return NULL;
	AcDbBlockTable* pBlkTable;
	if (pDb->getBlockTable(pBlkTable, AcDb::kForRead) != Acad::eOk)
		return NULL;
	AcDbBlockTableRecord* pRec;
	if (pBlkTable->getAt(ACDB_MODEL_SPACE, pRec, AcDb::kForWrite) != Acad::eOk)
		return NULL;
	pBlkTable->close();
	AcDbObjectId objId = AcDbObjectId::kNull;
	if (pRec->appendAcDbEntity(objId, pArc) != Acad::eOk)
		return NULL;
	pArc->close();
	pRec->close();
	return AcDbObjectId();
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
