#include "pch.h"
#include "MyData.h"

IMPLEMENT_SERIAL(MyData, CObject, 1)

void MyData::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//���л�
		ar << r1;
		ar << r2;
		ar << r3;
		ar << r4;

	}
	else {
		//�����л�
		ar >> r1;
		ar >> r2;
		ar >> r3;
		ar >> r4;

	}
}
