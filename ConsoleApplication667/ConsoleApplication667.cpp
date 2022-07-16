#include <iostream>
using namespace std;

class DumpTruckBody {
private:
	static int allCount;
public:
	int buycost = 2500;
	int sellcost = 6000;

	DumpTruckBody() { allCount++; }
	~DumpTruckBody() { allCount--; }
	int getcount() { return allCount; }
};
int DumpTruckBody::allCount = 0;


class Awning {
private:
	static int allCount;
public:
	int buycost = 1500;
	int sellcost = 4000;

	Awning() { allCount++; }
	~Awning() { allCount--; }
	int getcount() { return allCount; }
};
int Awning::allCount = 0;

class TruckParts {
private:
	static int allCount;
protected:
	Awning awning;
	DumpTruckBody dumpTruckBody;
	int getcountTP() { return allCount; }
public:
	TruckParts() : awning(), dumpTruckBody()
	{
		allCount = awning.getcount() + dumpTruckBody.getcount();
	}
	void setsellcostDTB(int new_sell_cost) { dumpTruckBody.sellcost = new_sell_cost; }
	void setsellcostAwning(int new_sell_cost) { awning.sellcost = new_sell_cost; }
};
int TruckParts::allCount = 0;




class TurbulentWing {
private:
	static int allCount;
public:
	int buycost = 7500;
	int sellcost = 15000;

	TurbulentWing() { allCount++; }
	~TurbulentWing() { allCount--; }
	int getcount() { return allCount; }
};
int TurbulentWing::allCount = 0;


class Router4G {
private:
	static int allCount;
public:
	int buycost = 500;
	int sellcost = 2000;

	Router4G() { allCount++; }
	~Router4G() { allCount--; }
	int getcount() { return allCount; }
};
int Router4G::allCount = 0;

class CarParts {
private:
	static int allCount;
protected:
	TurbulentWing turbulentwing;
	Router4G router;
	int getcountCP() { return allCount; }
public:
	CarParts() : turbulentwing(), router()
	{
		allCount = turbulentwing.getcount() + router.getcount();
	}
	void setsellcostTW(int new_sell_cost) { turbulentwing.sellcost = new_sell_cost; }
	void setsellcostRouter4G(int new_sell_cost) { router.sellcost = new_sell_cost; }
};
int CarParts::allCount = 0;

class CompanyManagment :public TruckParts, public CarParts {
private:
	static int alltimeEarnings;
	static int alltimeWaste;
	static int alltimeSellParts;
	static int alltimeWOffParts;
	static int alltimeTranferedParts;
	static int alltimeTruckPartsSell;
	static int alltimeCarPartsSell;
public:
	CompanyManagment() { alltimeWaste += awning.buycost + dumpTruckBody.buycost + router.buycost + turbulentwing.buycost; }

	void sellDTB() {
		if (dumpTruckBody.getcount() == 0) return;
		alltimeEarnings += dumpTruckBody.sellcost;
		dumpTruckBody.~DumpTruckBody();
		alltimeSellParts++;
		alltimeTruckPartsSell++;
	}
	void sellAwning() {
		if (awning.getcount() == 0) return;
		alltimeEarnings += awning.sellcost;
		awning.~Awning();
		alltimeSellParts++;
		alltimeTruckPartsSell++;
	}

	void writeoffDTB() {
		if (dumpTruckBody.getcount() == 0) return;
		dumpTruckBody.~DumpTruckBody();
		alltimeWOffParts++;
	}
	void writeoffAwning() {
		if (awning.getcount() == 0) return;
		awning.~Awning();
		alltimeWOffParts++;
	}

	void transferDTB() { if (dumpTruckBody.getcount() == 0) return; alltimeTranferedParts++; }
	void transferAwning() { if (awning.getcount() == 0) return; alltimeTranferedParts++; }


	void sellTW() {
		if (turbulentwing.getcount() == 0) return;
		alltimeEarnings += turbulentwing.sellcost;
		turbulentwing.~TurbulentWing();
		alltimeSellParts++;
		alltimeCarPartsSell++;
	}
	void sellRouter4G() {
		if (router.getcount() == 0) return;
		alltimeEarnings += router.sellcost;
		router.~Router4G();
		alltimeSellParts++;
		alltimeCarPartsSell++;
	}

	void writeoffTW() {
		if (turbulentwing.getcount() == 0) return;
		turbulentwing.~TurbulentWing();
		alltimeWOffParts++;
	}
	void writeoffRouter4G() {
		if (router.getcount() == 0) return;
		router.~Router4G();
		alltimeWOffParts++;
	}

	void transferTW() { if (turbulentwing.getcount() == 0) return; alltimeTranferedParts++; }
	void transferRouter4G() { if (router.getcount() == 0) return; alltimeTranferedParts++; }

	void info()
	{
		cout << "all time parts income'-> " << getcountTP() + getcountCP()
			<< "\nthat moment parts owned'-> " << getcountTP() + getcountCP() - alltimeSellParts
			<< "\nsold parts'-> " << alltimeSellParts
			<< "\nwritten off parts'-> " << alltimeWOffParts
			<< "\ntransfered to another shop'-> " << alltimeTranferedParts
			<< "\nTRUCK CATEGORY parts sold'-> " << alltimeTruckPartsSell
			<< "\nCAR CATEGORY parts sold'-> " << alltimeCarPartsSell
			<< "\n\nALL TIME WASTED MONEY'-> " << alltimeWaste << "$"
			<< "\nALL TIME EARNED MONEY'-> " << alltimeEarnings << "$"
			<< "\nPROFIT'-> " << alltimeEarnings - alltimeWaste << "$"
			<< endl;
	}

};

int CompanyManagment::alltimeEarnings = 0;
int CompanyManagment::alltimeWOffParts = 0;
int CompanyManagment::alltimeCarPartsSell = 0;
int CompanyManagment::alltimeSellParts = 0;
int CompanyManagment::alltimeTranferedParts = 0;
int CompanyManagment::alltimeTruckPartsSell = 0;
int CompanyManagment::alltimeWaste = 0;

int main()
{
	CompanyManagment* cargo_boat[4]
	{
		new CompanyManagment,
		new CompanyManagment,
		new CompanyManagment,
		new CompanyManagment
	};

	cargo_boat[0]->sellAwning();
	cargo_boat[0]->sellTW();
	cargo_boat[1]->sellDTB();
	cargo_boat[1]->setsellcostTW(25000);
	cargo_boat[1]->sellTW();
	cargo_boat[2]->sellRouter4G();
	cargo_boat[2]->sellTW();
	cargo_boat[3]->transferAwning();
	cargo_boat[3]->transferTW();
	cargo_boat[3]->writeoffDTB();
	cargo_boat[3]->setsellcostRouter4G(1750);
	cargo_boat[3]->sellRouter4G();

	cargo_boat[0]->info(); /* -> метод <<info>> не прив'язаний до об'єктів,
							  він виводить дані про статичні змінні всередині класу
							  незалежно від самих об'єктів через які він оголошений.
							  Оголошення об'єктів цього класу означає прихід нової
							  партії запчастин  */

	delete cargo_boat[0];
	delete cargo_boat[1];
	delete cargo_boat[2];
	delete cargo_boat[3];
}