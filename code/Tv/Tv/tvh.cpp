// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include <iostream>
#include "tvh.h"
#include "pch.h"
using namespace std;
bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}
bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}
void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}
void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}
void Tv::settings()const
{
	cout << "tv is" << (state == Off ? "OFF" : "On") << endl;
	if (state == On)
	{
		cout << "volume setting =" << volume << endl;
		cout << "channel setting=" << channel << endl;
		cout << "mode=" << (mode == Antenna ? "antenna" : "cabel") << endl;
		cout << "input=" << (input == TV ? "TV" : "DVD") << endl;
	}
}


// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
