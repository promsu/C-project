// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
class CPU {
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
	CPU(CPU_Rank r, int f, float v) {
		rank = r;
		frequency = f;
		voltage = v;
		cout << "构造了一个CPU对象！" << endl;
	}
	~CPU() { cout << "析构了一个CPU对象！" << endl; }
	CPU_Rank GetRank()const { return rank; }
	int GetFrequency()const { return frequency; }
	float GetVoltage()const { return voltage; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequency = f; }
	void SetFrequency(float v) { voltage = v; }

	void Run() { cout << "CPU开始运行！" << endl; }
	void Stop() { cout << "CPU停止运行！" << endl; }
};
enum RAM_Type { DDR2 = 2, DDR3, DDR4 };
class RAM {
private:
	enum RAM_Type type;
	unsigned int frequency;//MHZ
	unsigned int size;//GB
public:
	RAM(RAM_Type t, unsigned int f, unsigned int s) {
		type = t;
		frequency = f;
		size = s;
		cout << "构造了一个RAM对象！" << endl;
	}
	~RAM() { cout << "析构了一个RAM对象！" << endl; }

	RAM_Type GetType() { return type; }
	unsigned int GetFrequency() { return frequency; }
	unsigned int GetSize() { return size; }

	void SetType(RAM_Type t) { type = t; }
	void SetFrequency(unsigned int f) { frequency = f; }
	void setSize(unsigned int s) { size = s; }

	void Run() { cout << "RAM开始运行！" << endl; }
	void Stop() { cout << "RAM停止运行！" << endl; }
};
enum CDROM_Interface { SATA, USB };
enum CDROM_Install_Type { external, build_in };
class CD_ROM {
private:
	enum CDROM_Interface interface_type;
	enum CDROM_Install_Type install_type;
	unsigned int cache_size;//MB
public:
	CD_ROM(CDROM_Interface i, unsigned int s, CDROM_Install_Type it) {
		interface_type = i;
		install_type = it;
		cache_size = s;
		cout << "构造了一个ROM对象！" << endl;
	}
	~CD_ROM() { cout << "析构了一个ROM对象！" << endl; }

	CDROM_Interface GetInterfaceType() { return interface_type; }
	CDROM_Install_Type GetInstallType() { return install_type; }
	unsigned int GetCacheSize() { return cache_size; }

	void SetInterfaceType(CDROM_Interface i) { interface_type = i; }
	void SetInstallType(CDROM_Install_Type it) { install_type = it; }
	void SetCacheSize(unsigned int s) { cache_size = s; }

	void Run() { cout << "CDROM开始运行！" << endl; }
	void Stop() { cout << "CDROM停止运行！" << endl; }
};
class Computer {
private:
	CPU my_cpu;
	RAM my_ram;
	CD_ROM my_cdrom;
	unsigned int storage_size;//GB
	unsigned int bandwidth;//MB
public:
	Computer(CPU c, RAM r, CD_ROM cd, unsigned int s, unsigned b);
	~Computer() { cout << "析构了一个Computer对象！" << endl; }

	void Run() {
		my_cpu.Run();
		my_cdrom.Run();
		my_ram.Run();
		cout << "Computer开始运行！" << endl;
	}
	void Stop() {
		my_cpu.Stop();
		my_cdrom.Stop();
		my_ram.Stop();
			cout << "Computer停止运行！" << endl;
	}
};
Computer::Computer(CPU c, RAM r, CD_ROM cd, unsigned int s, unsigned b) :my_cpu(c), my_ram(r), my_cdrom(cd) {
	storage_size = s;
	bandwidth = b;
}
int main() {
	CPU a(P6, 300, 2.8);
	a.Run();
	a.Stop();
	cout << "*************************\n";

	RAM b(DDR3, 1600, 8);
	b.Run();
	b.Stop();
	cout << "************************\n";

	CD_ROM c(SATA, 2, build_in);
	c.Run();
	c.Stop();
	cout << "***************************\n";

	Computer my_computer(a, b, c, 128, 10);
	cout << "****************************\n";

	my_computer.Run();
	my_computer.Stop();
	cout << "*****************************\n";
	return 0;
}