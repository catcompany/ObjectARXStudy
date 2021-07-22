#include "stdafx.h"
#include "CCreateEntity.h"
#include <CLineUtil.h>
#include <CArcUtil.h>
#include <CCalculation.h>


//"��㣬Բ�ģ�Բ���Ƕ�"����Բ��
Acad::ErrorStatus CCreateEntity::CreateArc(AcGePoint3d ptCenter, double radius, double startRadius, double endRadius)
{
	CString msg;
	msg.Format(L"����Բ��(%lf,%lf)��Բ�� \n", ptCenter.x, ptCenter.y);
	acutPrintf(msg);

	CArcUtil::add(ptCenter, radius, startRadius, endRadius);
	//CArcUtil::add(ptStartPoint, ptCenterPoint, ptEndPoint);
	return Acad::eOk;
}

Acad::ErrorStatus CCreateEntity::CreateLine(AcGePoint2d ptStart, AcGePoint2d ptEnd)
{
	AcGePoint3d pointStart = CCalculation::Pt2dTo3d(ptStart), pointEnd = CCalculation::Pt2dTo3d(ptEnd);
	CString msg;
	msg.Format(L"���:(%f��%f)\n", ptStart.x, ptStart.y);
	acutPrintf(msg);

	CLineUtil::add(pointStart, pointEnd);

	msg.Format(L"�յ�:(%f��%f)\n", ptEnd.x, ptEnd.y);
	acutPrintf(msg);

	return Acad::eOk;

}

Acad::ErrorStatus CCreateEntity::CreateLayer(const TCHAR *layerName, AcDbObjectId &layerId)
{
	Acad::ErrorStatus errorStatus;
	AcDbDatabase *db = acdbHostApplicationServices()->workingDatabase();

	AcDbSymbolTable *layerTbl = NULL;
	errorStatus = db->getLayerTable(layerTbl, AcDb::kForRead);
	if (errorStatus != Acad::eOk) {
		acutPrintf(_T("\nCommand internal error: getLayerTable() = %d"), errorStatus);
		return errorStatus;
	}

	errorStatus = layerTbl->getAt(layerName, layerId);
	if (errorStatus == Acad::eOk) {
		layerTbl->close();
		acutPrintf(_T("\nFound layer <%s>: %d-%d"), layerName, layerId.handle().high(), layerId.handle().low());
		return Acad::eOk;
	}

	acutPrintf(_T("\nupgrading opened table for writing"));
	errorStatus = layerTbl->upgradeOpen();
	if ((errorStatus != Acad::eOk) && (errorStatus != Acad::eWasOpenForWrite)) {
		acutPrintf(_T("\nCommand internal error: upgradeOpen() = %d"), errorStatus);
		layerTbl->close();
		return errorStatus;
	}
	AcDbLayerTableRecord *pLayerTableRecord = new AcDbLayerTableRecord();
	//set layer name
	pLayerTableRecord->setName(layerName);
	//set color
	pLayerTableRecord->setLineWeight(AcDb::LineWeight::kLnWt035);
	errorStatus = static_cast<AcDbLayerTable *>(layerTbl)->add(layerId, pLayerTableRecord);
	if (errorStatus != Acad::eOk) {
		acutPrintf(_T("\nCommand internal error: add() = %d"), errorStatus);
		layerTbl->close();
		return errorStatus;
	}
	acutPrintf(_T("\nCreated layer <%s>: %d-%d"), layerName, layerId.handle().high(), layerId.handle().low());

	pLayerTableRecord->close();
	layerTbl->close();

	return Acad::eOk;
}
