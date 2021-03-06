#include "pch.h"
#include "CCircleUtil.h"
#include "CDwgDatebaseUtil.h"
#include "CGetPointUtil.h"
#include "CCalculation.h"

CCircleUtil::CCircleUtil()
{
}


CCircleUtil::~CCircleUtil()
{
}

AcDbObjectId CCircleUtil::add(const AcGePoint3d & Point, const AcGeVector3d & Normal, double radius)
{
	AcDbCircle *pCilcle = new AcDbCircle(Point, Normal, radius);
	return CDwgDatebaseUtil::PostToModelSpace(pCilcle);
}

AcDbObjectId CCircleUtil::add(AcGePoint3d & Point, double radius)
{
	AcGeVector3d NormalPanel(0, 0, 1);
	return add(Point, NormalPanel, radius);
}

AcDbObjectId CCircleUtil::add(AcGePoint2d & FirstPoint, AcGePoint2d & SecondPoint)
{
	AcGePoint2d CenterPoint = CGetPointUtil::GetMiddlePoint(FirstPoint, SecondPoint);
	AcGePoint3d CenterPoint3d(CenterPoint.x, CenterPoint.y, 0);
	double radius = CenterPoint.distanceTo(FirstPoint);
	return add(CenterPoint3d, radius);
}

AcDbObjectId CCircleUtil::add(AcGePoint2d & FirstPoint, AcGePoint2d & SecondPoint, AcGePoint2d & ThirdPoint)
{
	AcGeCircArc2d geArc(FirstPoint, SecondPoint, ThirdPoint);
	AcGePoint3d CenterPoint3d(geArc.center().x, geArc.center().y, 0);

	return add(CenterPoint3d, geArc.radius());
}

AcGePoint2d CCircleUtil::getPoint(AcGePoint2d pointCenter, ads_real radius, ads_real angel, bool isDegree)
{
	AcGePoint2d point;
	if (isDegree)
	{
		angel = CCalculation::GtoR(angel);
	}
	point.x = pointCenter.x - radius * cos(angel);
	point.y = pointCenter.y + radius * sin(angel);
	return point;
}
