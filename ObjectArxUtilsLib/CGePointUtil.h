#pragma once


class CGePointUtil
{
public:
	CGePointUtil();
	virtual ~CGePointUtil();

	// 计算两个点的中点
	static AcGePoint3d GetMiddlePoint(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint);
	static AcGePoint2d GetMiddlePoint(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint);

	// 根据极坐标的方式推算一个点的坐标
	static AcGePoint3d PolarPoint(const AcGePoint3d& basePoint, double angle, double length);
	static AcGePoint2d PolarPoint(const AcGePoint2d& basePoint, double angle, double length);

	// 根据直角坐标推算一个点的坐标
	static AcGePoint3d RelativePoint(const AcGePoint3d& pt, double x, double y);

	// 两个点是否相同
	static bool IsEqual(const AcGePoint3d& firstPoint, const AcGePoint3d& secondPoint, double tol = 1.0E-7);
	static bool IsEqual(const AcGePoint2d& firstPoint, const AcGePoint2d& secondPoint, double tol = 1.0E-7);

	// 数组中是否包含某个点
	// 返回: 点在数组中的索引，如果返回值小于0表示数组中不包含这个点
	static int FindPoint(const AcGePoint3dArray& points, const AcGePoint3d& point, double tol = 1.0E-7);
	static int FindPoint(const AcGePoint2dArray& points, const AcGePoint2d& point, double tol = 1.0E-7);

};

