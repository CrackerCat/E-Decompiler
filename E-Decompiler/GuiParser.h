#pragma once
#include <pro.h>

class ControlInfoWidget;

class GuiParser
{
public:
	struct ControlIndex
	{
		unsigned int nWindowIndex;
		unsigned int nControlIndex;
	};

	//ÿ���ؼ����еĻ�������
	struct mid_EBasicProperty
	{
		int m_left;                              //���
		int m_top;                               //����
		int m_width;                             //���
		int m_height;                            //�߶�
		qvector<unsigned int> mVec_childControl; //�ӿؼ�
		std::string m_tag;                       //���
	};

public:
	//��ȡ�ؼ��¼��ܸ���
	static unsigned int GetEventCount();
	static void InitUserCodeStartAddr(ea_t addr);
	
	static int MenuHandle_ShowGuiInfo();
	static int MenuHandle_ShowEventInfo();

	//���ݿؼ�����ID����þ��������
	//static ControlType_t GetControlType(unsigned int controlTypeId);
	//���ݿؼ�IDֱ�ӻ�ȡ�ؼ�����
	//static bool GetControlInfo(unsigned int controlId, mid_ControlInfo& out_ControlInfo);

	//static void AddControlType(unsigned int, ControlType_t);

public:
	static ControlInfoWidget* g_ControlInfoWindow;
};