#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>


#define I 18//行数
#define J 23//列数

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
	int Income_Total = 0;//总收益
	void Operation(int, char);
	void Pre_Update(short);//特殊数据更新
	void Update(short);//数据更新
	vector<wstring> outtext_im(int);
	void GenerallyUpdate();
	int date = 1;
};

//坐标结构体
struct Coord
{
	short x;
	short y;
};

class LocalArea
{
private:
	//基本参数
	Coord LocalCoord;//地区坐标
	int Population = 0;//地区人口总数
	double Natural_Growth_Rate = 0;//地区人口年自然增长率
	int Natural_Growth_Daily = 0;//地区每日自然增长人口

	//地区资产相关
	int Fund = 0;//地区政府总资产
	double Income_Rate_Daily = 0;//原始地区每日收益率
	int Income_Daily = 0;//地区每日收益

	//地区病毒传播相关
	double Infectious_Rate = 0;//地区病毒传播率
	double Infectious_num = 0.01;//邻区传播系数
	int New_Infectious = 0;//地区当天新增感染者
	int Real_Infectious_Amount = 1;//实际地区感染者数
	int Known_Infectious_Amount = 0;//已知地区感染者数
	double Fatality_Rate = 0;//地区病死率
	int Fatality_Amount = 0;//地区病死数
	int Fatality_Daily = 0;//地区当日病死数
	double Recovered_Rate = 0;//地区康复率
	int Recovered_Amount = 0;//地区康复者数	
	int Paramedic_Amount = 0;//地区医护人员数


public:
	LocalArea(short x, short y, bool b);
	bool Existence = 1;//地区是否存在


	Coord getLoccalCoord();
	int getPopulation();//获取地区人口总数
	double getNatural_Growth_Rate();//获取地区人口年自然增长率
	int getNatural_Growth_Daily();//获取地区每日自然增长人口
	int getFund();//获取地区政府总资产
	double getIncome_Rate();//获取原始地区每日收益率
	int getIncome();//获取地区每日收益
	double getInfectious_Rate();//获取地区传播率
	double getInfectious_num();//获取邻区传播系数
	int getNew_Infectious();//获取地区当日新增感染者
	int getKnown_Infectious();//获取已知地区感染者数
	int getActaul_Infectious();//获取实际地区感染者数
	double getFatality_Rate();//获取地区病死率
	int getFatality();//获取地区总病死数
	int getFatality_Daily();//获取地区当天病死数
	double getRecovered_Rate();//获取地区康复率
	int getRecovered();//获取地区康复者数	
	int getParamedic();//获取地区医护人员数

	void setPopulation(int);//修改地区人口总数
	void setFund(int);//修改地区政府总资产		●
	void setIncome_Rate(double);//修改地区每日收益率		
	void setIncome(int);//修改地区每日收益		●
	void setInfectious_Rate(double r);//修改地区传播率		●
	void setInfectious_num(double r);//修改邻区传播系数
	void setNew_Infectious(int);//修改地区当日新增传播者
	void setKnown_Infectious(int);//修改已知地区感染者数		●
	void setActual_Infectious(int);//修改实际地区感染者数		
	void setFatality_Rate(double);//修改地区病死率
	void setFatality(int);//修改地区总病死数			
	void setFatality_Daily(int);//修改地区当日病死数
	void setRecovered_Rate(double);//修改地区康复率		
	void setRecovered(int);//修改地区康复者数	
	void setParamedic(int);//修改地区医护人员数		●

};

class Event
{


};

