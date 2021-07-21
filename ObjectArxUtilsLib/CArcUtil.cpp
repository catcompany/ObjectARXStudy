#include "pch.h"
#include "CArcUtil.h"
#include "CCalculation.h"
#include "CDwgDatebaseUtil.h"


AcDbObjectId CArcUtil::add(AcGePoint3d ptCenter, AcGeVector3d vec, double radius, double startAngle, double endAngle)
{
    AcDbArc* pArc = new AcDbArc(ptCenter, vec, radius, startAngle, endAngle);
    //(Բ�ģ�ƽ�棬�뾶�����Ƕȣ��յ�Ƕ�)
    /*StartAngle��EndAngle���������յ�ĽǶȣ�StartAngle������Ϊ�Ǹ��ο��ǣ�
    Ĭ����0�������Բ����Բ����ת10�ȣ������StartAngle����10�ȣ�EndAngleʼ�ղ��䣬��Բ����Բ�Ľǡ�*/
    AcDbObjectId arcId;
    arcId = CDwgDatebaseUtil::PostToModelSpace(pArc);
    return arcId;
}

AcDbObjectId CArcUtil::add(AcGePoint2d ptCenter, double radius, double startAngle, double endAngle)
{
    AcGeVector3d vec(0, 0, 1);
    return CArcUtil::add(CCalculation::Pt2dTo3d(ptCenter), vec, radius, startAngle, endAngle);
}

AcDbObjectId CArcUtil::add(AcGePoint2d ptStart, AcGePoint2d ptOnArc, AcGePoint2d ptEnd)
{
    //ʹ�ü�������Բ�ģ��뾶
    AcGeCircArc2d geArc(ptStart, ptOnArc, ptEnd);
    AcGePoint2d ptCenter = geArc.center();
    double radius = geArc.radius();

    //������ʼ����ֹ�Ƕ�
    AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
    AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
    double startAngle = vecStart.angle();
    double endAngle = vecEnd.angle();
    /*AcGeVector2d ��������ʾһ����ά�ռ��е�ʸ����
    ���Ա���� angle ���ظ�ʸ���� X ��������ĽǶȣ��û�������ʾ����*/
    return CArcUtil::add(ptCenter, radius, startAngle, endAngle);
}

//������������Ʋ����� CreateArc������ CreateArcSCE��������Ϊ�ú����Ĳ����б�����ֵ�������㷨�ĺ�����ͬ���޷�ʵ�ֺ��������أ���ֻ�����¶���һ���µĺ������ơ�
AcDbObjectId CArcUtil::addArc(AcGePoint2d ptStart, AcGePoint2d ptCenter, AcGePoint2d ptEnd)
{
    //����뾶
    double radius = ptCenter.distanceTo(ptStart);
    //�������յ�Ƕ�
    AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
    AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
    double startAngle = vecStart.angle();
    double endAngle = vecEnd.angle();
    //����Բ��
    return CArcUtil::add(ptCenter, radius, startAngle, endAngle);
}

AcDbObjectId CArcUtil::add(AcGePoint2d ptStart, AcGePoint2d ptCenter, double angle)
{
    //����뾶
    double radius = ptCenter.distanceTo(ptStart);
    //������㣬�յ�Ƕ�
    AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
    double startAngle = vecStart.angle();
    double endAngle = startAngle + angle;

    //����Բ��
    return CArcUtil::add(ptCenter, radius, startAngle, endAngle);
}
