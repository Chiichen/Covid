#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>


#define I 18//����
#define J 23//����

using namespace std;


class LocalArea;



class Area
{
public:
	Area();
	~Area();
public:
	bool state;//state=~state;
	LocalArea** area_arr;
	int Income_Total = 0;//������
	void Operation(int, char);
	void Pre_Update(short);//�������ݸ���
	void Update(short);//���ݸ���
	vector<wstring> outtext_im(int);
	void GenerallyUpdate();
	int date = 1;
};

//����ṹ��
struct Coord
{
	short x;
	short y;
};

class LocalArea
{
private:
	//��������
	Coord LocalCoord;//��������
	int Population = 0;//�����˿�����
	double Natural_Growth_Rate = 0;//�����˿�����Ȼ������
	int Natural_Growth_Daily = 0;//����ÿ����Ȼ�����˿�

	//�����ʲ����
	int Fund = 0;//�����������ʲ�
	double Income_Rate_Daily = 0;//ԭʼ����ÿ��������
	int Income_Daily = 0;//����ÿ������

	//���������������
	double Infectious_Rate = 0;//��������������
	double Infectious_num = 0.01;//��������ϵ��
	int New_Infectious = 0;//��������������Ⱦ��
	int Real_Infectious_Amount = 1;//ʵ�ʵ�����Ⱦ����
	int Known_Infectious_Amount = 0;//��֪������Ⱦ����
	double Fatality_Rate = 0;//����������
	int Fatality_Amount = 0;//����������
	int Fatality_Daily = 0;//�������ղ�����
	double Recovered_Rate = 0;//����������
	int Recovered_Amount = 0;//������������	
	int Paramedic_Amount = 0;//����ҽ����Ա��


public:
	LocalArea(short x, short y, bool b);
	bool Existence = 1;//�����Ƿ����


	Coord getLoccalCoord();
	int getPopulation();//��ȡ�����˿�����
	double getNatural_Growth_Rate();//��ȡ�����˿�����Ȼ������
	int getNatural_Growth_Daily();//��ȡ����ÿ����Ȼ�����˿�
	int getFund();//��ȡ�����������ʲ�
	double getIncome_Rate();//��ȡԭʼ����ÿ��������
	int getIncome();//��ȡ����ÿ������
	double getInfectious_Rate();//��ȡ����������
	double getInfectious_num();//��ȡ��������ϵ��
	int getNew_Infectious();//��ȡ��������������Ⱦ��
	int getKnown_Infectious();//��ȡ��֪������Ⱦ����
	int getActaul_Infectious();//��ȡʵ�ʵ�����Ⱦ����
	double getFatality_Rate();//��ȡ����������
	int getFatality();//��ȡ�����ܲ�����
	int getFatality_Daily();//��ȡ�������첡����
	double getRecovered_Rate();//��ȡ����������
	int getRecovered();//��ȡ������������	
	int getParamedic();//��ȡ����ҽ����Ա��

	void setPopulation(int);//�޸ĵ����˿�����
	void setFund(int);//�޸ĵ����������ʲ�		��
	void setIncome_Rate(double);//�޸ĵ���ÿ��������		
	void setIncome(int);//�޸ĵ���ÿ������		��
	void setInfectious_Rate(double r);//�޸ĵ���������		��
	void setInfectious_num(double r);//�޸���������ϵ��
	void setNew_Infectious(int);//�޸ĵ�����������������
	void setKnown_Infectious(int);//�޸���֪������Ⱦ����		��
	void setActual_Infectious(int);//�޸�ʵ�ʵ�����Ⱦ����		
	void setFatality_Rate(double);//�޸ĵ���������
	void setFatality(int);//�޸ĵ����ܲ�����			
	void setFatality_Daily(int);//�޸ĵ������ղ�����
	void setRecovered_Rate(double);//�޸ĵ���������		
	void setRecovered(int);//�޸ĵ�����������	
	void setParamedic(int);//�޸ĵ���ҽ����Ա��		��

};

class Event
{


};

