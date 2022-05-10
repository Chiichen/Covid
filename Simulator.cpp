#include "Simulator.h"

Area::Area()
{
	LocalArea** newspace = new LocalArea * [I * J];
	LocalArea* localarea = NULL;
	for (int i = 0; i < I; i++)
	{
		for (int j = 0; j < J; j++)
		{
			localarea = new LocalArea(j, i, 1);
			newspace[j + J * i] = localarea;
		}
	}
	this->area_arr = newspace;
}

Area::~Area()
{
	delete[] this->area_arr;
}

LocalArea::LocalArea(short x0, short y0, bool b)
{
	LocalCoord.x = x0;
	LocalCoord.y = y0;
	this->Existence = b;
	default_random_engine e(unsigned int(time(0)));//���������
	uniform_int_distribution<unsigned> u1(3000, 10000);
	uniform_int_distribution<unsigned> u2(34, 145);
	uniform_int_distribution<unsigned> u3(1000, 2000);
	uniform_int_distribution<unsigned> u4(3, 5);
	uniform_int_distribution<unsigned> u5(50, 300);
	this->Population = u1(e);//�����˿�������ʼ�� 3000 - 10000
	this->Natural_Growth_Rate = 0.01 * u2(e);//�����˿�����Ȼ�����ʳ�ʼ�� 0.34 - 1.45 
	this->Natural_Growth_Daily = this->Population * int(this->Natural_Growth_Rate / 365);//����ÿ����Ȼ�����˿ڳ�ʼ��	
	this->Infectious_Rate = 0.0001 * u5(e);//�������������ʳ�ʼ��  0.005 - 0.03
	this->Fund = u3(e);//�������ʲ���ʼ�� 1000 - 2000
	this->Income_Rate_Daily = 0.00001 * u3(e);//����ÿ�������ʳ�ʼ�� 0.01 - 0.02
	this->Income_Daily = Fund * int(Income_Rate_Daily);//����ÿ�������ʼ�� 10 - 20 
	this->Known_Infectious_Amount = 0;//��֪������Ⱦ������ʼ��
	this->Real_Infectious_Amount = 0;//ʵ�ʵ�����Ⱦ������ʼ��
	this->Fatality_Daily = 0;//������������ʼ��
	this->Fatality_Rate = 0;//���������ʳ�ʼ��
	this->Recovered_Rate = 0.1 * (u4(e) * 2 - 3);//���������ʳ�ʼ�� 0. 3 - 0.7
	this->Recovered_Amount = 0;//����������
	this->Paramedic_Amount = 10;//����ҽ����Ա����ʼ��
}

Coord LocalArea::getLoccalCoord()
{
	return this->LocalCoord;
}

int LocalArea::getPopulation()
{
	return this->Population;
}
double LocalArea::getNatural_Growth_Rate()
{
	return this->Natural_Growth_Rate;
}
int LocalArea::getNatural_Growth_Daily()
{
	return this->Natural_Growth_Daily;
}
int LocalArea::getFund()
{
	return this->Fund;
}
double LocalArea::getIncome_Rate()
{
	return this->Income_Rate_Daily;
}
int LocalArea::getIncome()
{
	return this->Income_Daily;
}
double LocalArea::getInfectious_Rate()
{
	return this->Infectious_Rate;
}
double LocalArea::getInfectious_num()
{
	return this->Infectious_num;
}
int LocalArea::getNew_Infectious()
{
	return this->New_Infectious;

}
int LocalArea::getKnown_Infectious()
{
	return this->Known_Infectious_Amount;
}
int LocalArea::getActaul_Infectious()
{
	return this->Real_Infectious_Amount;
}
double LocalArea::getFatality_Rate()
{
	return this->Fatality_Rate;
}
int LocalArea::getFatality()
{
	return this->Fatality_Amount;
}
int LocalArea::getFatality_Daily()//��ȡ�������첡����
{
	return this->Fatality_Daily;
}
double LocalArea::getRecovered_Rate()
{
	return this->Recovered_Rate;
}
int LocalArea::getRecovered()
{
	return this->Recovered_Amount;
}
int LocalArea::getParamedic()
{
	return this->Paramedic_Amount;
}

void LocalArea::setPopulation(int a)//�޸ĵ����˿�����
{
	this->Population = a;
}
void LocalArea::setFund(int a)//�޸ĵ����������ʲ�
{
	this->Fund = a;
}
void LocalArea::setIncome_Rate(double a)
{
	this->Income_Rate_Daily = a;
}
void LocalArea::setIncome(int a)//�޸ĵ���ÿ������
{
	this->Income_Daily = a;
}
void LocalArea::setNew_Infectious(int a)
{
	this->New_Infectious = a;
}
void LocalArea::setKnown_Infectious(int a)//�޸���֪������Ⱦ����
{
	this->Known_Infectious_Amount = a;
}
void LocalArea::setActual_Infectious(int a)//�޸�ʵ�ʵ�����Ⱦ����
{
	this->Real_Infectious_Amount = a;
}
void LocalArea::setInfectious_Rate(double r)//
{
	this->Infectious_Rate = r;
}
void LocalArea::setInfectious_num(double r)
{
	this->Infectious_num = r;
}
void LocalArea::setFatality_Rate(double r)
{
	this->Fatality_Rate = r;
}
void LocalArea::setFatality(int a)//�޸ĵ����ܲ�����
{
	this->Fatality_Amount = a;
}
void LocalArea::setFatality_Daily(int a)//�޸ĵ������ղ�����
{
	this->Fatality_Daily = a;
}
void LocalArea::setRecovered_Rate(double r)//
{
	this->Recovered_Rate = r;
}
void LocalArea::setRecovered(int a)//�޸ĵ�����������	
{
	this->Recovered_Amount = a;
}
void LocalArea::setParamedic(int a)//�޸ĵ���ҽ����Ա��
{
	this->Paramedic_Amount = a;
}

void Area::Pre_Update(short num)//�������ݸ���
{
	double tem = 0;
	if (num == 0 || num == I * J - 1 || num == (I - 1) * J || num == J - 1)
	{
		if (num == 0)
		{
			tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
				+ this->area_arr[num + 1]->getInfectious_num() * this->area_arr[num + 1]->getActaul_Infectious()
				+ this->area_arr[num + J]->getInfectious_num() * this->area_arr[num + J]->getActaul_Infectious();
			this->area_arr[num]->setNew_Infectious(int(tem));
		}
		else if (num == I * J - 1)
		{
			tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
				+ this->area_arr[num - 1]->getInfectious_num() * this->area_arr[num - 1]->getActaul_Infectious()
				+ this->area_arr[num - J]->getInfectious_num() * this->area_arr[num - J]->getActaul_Infectious();
			this->area_arr[num]->setNew_Infectious(int(tem));
		}
		else if (num == (I - 1) * J)
		{
			tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
				+ this->area_arr[num + 1]->getInfectious_num() * this->area_arr[num + 1]->getActaul_Infectious()
				+ this->area_arr[num - J]->getInfectious_num() * this->area_arr[num - J]->getActaul_Infectious();
			this->area_arr[num]->setNew_Infectious(int(tem));
		}
		else if (num == J - 1)
		{
			tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
				+ this->area_arr[num - 1]->getInfectious_num() * this->area_arr[num - 1]->getActaul_Infectious()
				+ this->area_arr[num + J]->getInfectious_num() * this->area_arr[num + J]->getActaul_Infectious();
			this->area_arr[num]->setNew_Infectious(int(tem));
		}
	}
	else if (num<J || num>I * J - 1 - J || num % J == 0 || num % J == J - 1)
	{
		if (num < J)
		{
			tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
				+ this->area_arr[num - 1]->getInfectious_num() * this->area_arr[num - 1]->getActaul_Infectious()
				+ this->area_arr[num + 1]->getInfectious_num() * this->area_arr[num + 1]->getActaul_Infectious()
				+ this->area_arr[num + J]->getInfectious_num() * this->area_arr[num + J]->getActaul_Infectious();
			this->area_arr[num]->setNew_Infectious(int(tem));
		}
		else if (num > I * J - 1 - J)
		{
			tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
				+ this->area_arr[num - 1]->getInfectious_num() * this->area_arr[num - 1]->getActaul_Infectious()
				+ this->area_arr[num + 1]->getInfectious_num() * this->area_arr[num + 1]->getActaul_Infectious()
				+ this->area_arr[num - J]->getInfectious_num() * this->area_arr[num - J]->getActaul_Infectious();
			this->area_arr[num]->setNew_Infectious(int(tem));
		}
		else if (num % J == 0)
		{
			tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
				+ this->area_arr[num - J]->getInfectious_num() * this->area_arr[num - J]->getActaul_Infectious()
				+ this->area_arr[num + 1]->getInfectious_num() * this->area_arr[num + 1]->getActaul_Infectious()
				+ this->area_arr[num + J]->getInfectious_num() * this->area_arr[num + J]->getActaul_Infectious();
			this->area_arr[num]->setNew_Infectious(int(tem));
		}
		else if (num % J == J - 1)
		{
			tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
				+ this->area_arr[num - J]->getInfectious_num() * this->area_arr[num - J]->getActaul_Infectious()
				+ this->area_arr[num - 1]->getInfectious_num() * this->area_arr[num - 1]->getActaul_Infectious()
				+ this->area_arr[num + J]->getInfectious_num() * this->area_arr[num + J]->getActaul_Infectious();
			this->area_arr[num]->setNew_Infectious(int(tem));
		}
	}
	else
	{

		tem = this->area_arr[num]->getInfectious_Rate() * this->area_arr[num]->getPopulation()
			+ this->area_arr[num - 1]->getInfectious_num() * this->area_arr[num - 1]->getActaul_Infectious()
			+ this->area_arr[num + 1]->getInfectious_num() * this->area_arr[num + 1]->getActaul_Infectious()
			+ this->area_arr[num - J]->getInfectious_num() * this->area_arr[num - J]->getActaul_Infectious()
			+ this->area_arr[num + J]->getInfectious_num() * this->area_arr[num + J]->getActaul_Infectious();
		this->area_arr[num]->setNew_Infectious(int(tem));
	}
}
void Area::Update(short num)
{
	if (this->area_arr[num]->Existence)
	{
		double tem_i = 0;
		double tem_d = 0;
		//�����˿ڸ���
		tem_i = this->area_arr[num]->getPopulation() + this->area_arr[num]->getNatural_Growth_Daily()
			- this->area_arr[num]->getFatality_Daily();
		this->area_arr[num]->setPopulation(int(tem_i));
		//���������ʲ�����     
		tem_d = this->area_arr[num]->getPopulation() * 0.000001 + 0.01;
		this->area_arr[num]->setRecovered_Rate(tem_d);
		tem_i = this->area_arr[num]->getFund() * this->area_arr[num]->getIncome_Rate();
		this->area_arr[num]->setIncome(int(tem_i));
		//����������ݸ���
		tem_i = this->area_arr[num]->getActaul_Infectious() + this->area_arr[num]->getNew_Infectious()
			- this->area_arr[num]->getFatality_Daily() - this->area_arr[num]->getRecovered_Rate()
			* (this->area_arr[num]->getPopulation() - this->area_arr[num]->getActaul_Infectious());
		this->area_arr[num]->setActual_Infectious(int(tem_i));
		tem_i = this->area_arr[num]->getFatality_Rate() * this->area_arr[num]->getActaul_Infectious() + 0.5;
		this->area_arr[num]->setFatality_Daily(int(tem_i));
		tem_i = this->area_arr[num]->getFatality() + this->area_arr[num]->getFatality_Daily();
		this->area_arr[num]->setFatality(int(tem_i));
		this->area_arr[num]->setFatality_Daily(0);
		tem_d = this->area_arr[num]->getParamedic() * 0.05 + 0.1;
		this->area_arr[num]->setRecovered_Rate(tem_d);
		tem_i = this->area_arr[num]->getRecovered() + this->area_arr[num]->getRecovered_Rate()
			* this->area_arr[num]->getActaul_Infectious();
		this->area_arr[num]->setRecovered(int(tem_i));
	}
}


vector<wstring> Area::outtext_im(int num)
{
	vector<wstring>str_v;
	str_v[0] = L"�������꣺ �� " + to_wstring(this->area_arr[num]->getLoccalCoord().x + 1) + L" , "
		+ to_wstring(this->area_arr[num]->getLoccalCoord().y + 1) + L" )";
	str_v[1] = L"���ص�ǰ�˿ڣ� " + to_wstring(this->area_arr[num]->getPopulation());
	str_v[2] = L"���ؽ��������˿ڣ� " + to_wstring(this->area_arr[num]->getNatural_Growth_Daily());
	str_v[3] = L"����������ǰ�ʲ���" + to_wstring(this->area_arr[num]->getFund());
	str_v[4] = L"���ؽ������棺 " + to_wstring(this->area_arr[num]->getIncome());
	str_v[5] = L"������֪��Ⱦ������ " + to_wstring(this->area_arr[num]->getKnown_Infectious());
	str_v[6] = L"�����ۼƿ��������� " + to_wstring(this->area_arr[num]->getRecovered());
	str_v[7] = L"�����ۼƲ��������� " + to_wstring(this->area_arr[num]->getFatality());
	str_v[8] = L"����ҽ����Ա������ " + to_wstring(this->area_arr[num]->getParamedic());
	return str_v;
}

vector<wstring> outtext_event()
{
	vector<wstring>str;
	return str;
}

void Area::Operation(int num, char tem)
{
	switch (tem)
	{
		//����ҽ��
	case '+':
		this->area_arr[num]->setParamedic(this->area_arr[num]->getParamedic() + 2);
		this->area_arr[num]->setFund(this->area_arr[num]->getFund() - 100);
		if (this->area_arr[num]->getInfectious_Rate() > 0.005)
		{
			this->area_arr[num]->setInfectious_Rate(this->area_arr[num]->getInfectious_Rate() - 0.005);
		}
		else
			this->area_arr[num]->setInfectious_Rate(0);
		this->area_arr[num]->setRecovered_Rate(this->area_arr[num]->getRecovered_Rate() + 0.05);
		break;
		//���ģ����ɸ��
	case 'h':
		this->area_arr[num]->setKnown_Infectious(this->area_arr[num]->getActaul_Infectious());
		this->area_arr[num]->setFund(this->area_arr[num]->getFund() - 100);
		if (this->area_arr[num]->getInfectious_Rate() > 0.0005)
		{
			this->area_arr[num]->setInfectious_Rate(this->area_arr[num]->getInfectious_Rate() - 0.0005);
		}
		else
			this->area_arr[num]->setInfectious_Rate(0);
		break;
		//���
	case 'o':
		if (this->area_arr[num]->getInfectious_Rate() > 0.01)
		{
			this->area_arr[num]->setInfectious_Rate(this->area_arr[num]->getInfectious_Rate() - 0.01);
		}
		else
			this->area_arr[num]->setInfectious_Rate(0);
		this->area_arr[num]->setInfectious_num(0);
		this->area_arr[num]->setIncome_Rate(0.001);
		break;
		//���и���
	case 'g':
		if (this->area_arr[num]->getInfectious_Rate() > 0.005)
		{
			this->area_arr[num]->setInfectious_Rate(this->area_arr[num]->getInfectious_Rate() - 0.005);
		}
		else
			this->area_arr[num]->setInfectious_Rate(0);
		break;
	case '-':
		this->area_arr[num]->setParamedic(this->area_arr[num]->getParamedic() - 2);
		this->area_arr[num]->setFund(this->area_arr[num]->getFund() + 100);
		if (this->area_arr[num]->getRecovered_Rate() > 0.05)
		{
			this->area_arr[num]->setRecovered_Rate(this->area_arr[num]->getRecovered_Rate() - 0.05);
		}
		else
			this->area_arr[num]->setRecovered_Rate(0.00001);
		this->area_arr[num]->setInfectious_Rate(this->area_arr[num]->getInfectious_Rate() + 0.005);
		break;
	default:
		break;
	}
}


void Area::GenerallyUpdate()
{
	for (int i = 0; i < I * J; i++)
	{
		Pre_Update(i);
	}
	for (int i = 0; i < I * J; i++)
	{
		Update(i);
	}
	date++;
}