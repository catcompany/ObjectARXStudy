#include "pch.h"
#include "Dimension.h"
#include "CEntityUtil.h"

Acad::ErrorStatus Dimension::addStyle(AcDbObjectId objID, TCHAR* styleName, ads_real scale, int colorIndex = CEntityUtil::Color::Green)
{
	////��õ�ǰͼ�εı�ע��ʽ��  
	AcDbDimStyleTable* pDimStyleTable;
	AcDbDimStyleTableRecord* pDimStyleTblRcd;
	acdbHostApplicationServices()->workingDatabase()->getDimStyleTable(pDimStyleTable, AcDb::kForWrite);


	////�Ƿ��Ѱ���  
	if (pDimStyleTable->has(styleName)) {
		AcDbEntity* pEntity;
		if (acdbOpenAcDbEntity(pEntity, objID, AcDb::kForWrite) == Acad::eOk)
		{

		}
		pEntity->close();
		//TODO: fix function of add dimesion.
		//pDimStyleTblRcd=pDimStyleTable->getAt(styleName,)
	}
	else
	{
		////�����µı�ע��ʽ��  
		pDimStyleTblRcd = new AcDbDimStyleTableRecord();
		////���ñ�ע��ʽ������  
		pDimStyleTblRcd->setName(styleName);
		pDimStyleTblRcd->setDimasz(50 * scale); // ��ͷ����
		pDimStyleTblRcd->setDimblk(L"_ARCHTICK");//���ü�ͷ����״Ϊ�������
		pDimStyleTblRcd->setDimexe(30 * scale); // ָ���ߴ���߳����ߴ��ߵľ���
		pDimStyleTblRcd->setDimlfac(1);//��������
		AcCmColor dimensionColor;
		dimensionColor.setColorIndex(colorIndex);
		pDimStyleTblRcd->setDimclrd(dimensionColor);//Ϊ�ߴ��ߡ���ͷ�ͱ�ע����ָ����ɫ��0Ϊ��ͼ��
		pDimStyleTblRcd->setDimclre(dimensionColor);//Ϊ�ߴ����ָ����ɫ������ɫ������������Ч����ɫ���
		pDimStyleTblRcd->setDimclrt(dimensionColor);//Ϊ��ע����ָ����ɫ��0Ϊ��ͼ��
		pDimStyleTblRcd->setDimdec(0);//���ñ�ע����λ��ʾ��С��λλ����0Ϊ��ͼ��

		pDimStyleTblRcd->setDimexo(30 * scale);//ָ���ߴ����ƫ��ԭ��ľ���

		pDimStyleTblRcd->setDimgap(10 * scale);//���ִӳߴ���ƫ�� '���ߴ��߷ֳɶ���������֮����ñ�ע����ʱ�����ñ�ע������Χ�ľ���
		pDimStyleTblRcd->setDimjust(0);//���Ʊ�ע���ֵ�ˮƽλ��
		pDimStyleTblRcd->setDimtix(1);//���ñ�ע����ʼ�ջ����ڳߴ����֮��

		//'.SetVariable "DimJust", 0       '���Ʊ�ע���ֵ�ˮƽλ��
		// '0  ���������ڳߴ���֮�ϣ����ڳߴ����֮�����ж���
		// '1  ���ڵ�һ���ߴ���߷��ñ�ע����
		// '2  ���ڵڶ����ߴ���߷��ñ�ע����
		// '3  ����ע���ַ��ڵ�һ���ߴ�������ϣ�����֮����
		//'4  ����ע���ַ��ڵڶ����ߴ�������ϣ�����֮����
		pDimStyleTblRcd->setDimtmove(0);//���ñ�ע���ֵ��ƶ�����
										//'0  �ߴ��ߺͱ�ע����һ���ƶ�
										//'1  ���ƶ���ע����ʱ���һ������
										//'2  �����ע���������ƶ��������������
		pDimStyleTblRcd->setDimtxt(100);//ָ����ע���ֵĸ߶ȣ����ǵ�ǰ������ʽ���й̶��ĸ߶�
		pDimStyleTblRcd->setDimtad(1 * scale); // ����λ�ڱ�ע�ߵ��Ϸ�
		//����ע��ʽ���¼��ӵ���ע��ʽ����
		pDimStyleTable->add(pDimStyleTblRcd);
	}
	pDimStyleTblRcd->setDimtxsty(objID);
	pDimStyleTblRcd->close();
	pDimStyleTable->close();
	return Acad::eOk;
}

void Dimension::addAcDbRadialDimension(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength, const ACHAR* dimText, AcDbObjectId dimStyle)
{
	AcDbRadialDimension(center, chordPoint, leaderLength);
}
