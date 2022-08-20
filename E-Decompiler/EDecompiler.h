#pragma once
#include <pro.h>
#include <QMap>
#include <QVariant>
#include "SectionManager.h"
#include "ESymbol.h"
#include "./Module/CTreeFixer.h"

enum EArchitectureType
{
	E_UNKNOWN = 0,  //δ֪����
	E_DYNAMIC,      //��̬�������
	E_STATIC,       //��̬�������
};

struct mid_EAppInfo
{
	bool b_IsWindowProgram;                            //�Ƿ��Ǵ������
	unsigned int m_EventSum;                           //���еĿؼ��¼�����
};

class IDAMenu;

class EDecompiler
{
public:
	EDecompiler();
	~EDecompiler();
public:
	//����ģʽ
	static EDecompiler& Instance();

	//��ʼ�������Է���������
	bool InitDecompilerEngine();

	bool DoDecompile();


	static ssize_t ui_callback(void* ud, int notification_code, va_list va);
private:
	//ɨ�������Ժ���
	void makeFunction(ea_t startAddr, ea_t endAddr);

	//̽�������Գ�������
	bool InitEArchitectureType();

	bool Parse_EStatic(unsigned int eHeadAddr);


	

	//�޸�����������
	void FixEStructure();
public:
	EArchitectureType arch;
	ESymbol eSymbol;
	CTreeFixer cTreeFixer;
	mid_EAppInfo m_eAppInfo;
private:

	IDAMenu* gMenu_ShowResource = nullptr;
	IDAMenu* gMenu_ShowGUIInfo = nullptr;
	IDAMenu* gMenu_ShowEventInfo = nullptr;
	IDAMenu* gMenu_ShowImportsInfo = nullptr;
};