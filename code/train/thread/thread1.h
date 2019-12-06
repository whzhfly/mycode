
#include <iostream>
#include <windows.h>
#include<thread>
#include<vector>
#include<atomic>
#include<mutex>
using namespace std;

int n = 0;
void hello(int i) {
	cout << "hello world1   " << endl;
	cout << n << endl;
	n++;
}
void hello1(int i) {
	//cout << endl;
	cout << "   hello world 2" << endl;
	cout << n << endl;
	n++;
}
class thread_c {
public:
	void thread_1(int a) {
		cout << "hello world" <<endl;
	}
};
class thread_c2 {
public:
	thread_c2() {
		t1 = thread(&thread_c2::thread_1, this);
	}
	void thread_1() {
		cout << "hello world " << endl;
	}
private:
	thread t1;
};
class mythread {
public:

	//����ȫ�ֺ���
	static void mythread1() {
		thread t1(hello, 1);
		thread t2(hello1, 2);
		t1.join();
		t2.join();
	}
	//����lambda���ʽ
	static void mythread2() {
		vector<thread> threads;
		for (int i = 0; i < 5; i++) {
			threads.push_back(thread([]() { cout << "hello world " << this_thread::get_id() << endl; }));
		}
		for (auto& thread0 : threads) {
			thread0.join();
		}
	}

	//ͨ����Ա���������߳�
	static void mythread3()
	{
		thread_c a;
		thread t1(&thread_c::thread_1,a,1);
		t1.join();
		this_thread::sleep_for(chrono::seconds(2));
	}

	static void mythread4() {
		thread_c2 a;
		cout << "test" << endl;
	}
};

/*********************************************/
int g_value = 0;
atomic<bool> g_data_ready = false;
condition_variable g_CV;
mutex g_mtx;  //ȫ�ֻ�����  ������һ���̵߳ģ�
void read_thread(int a)
{
	while (true)
	{
		while (!g_data_ready.load());//���ڿ��ƽ���
		cout << g_value << endl;
		g_data_ready = false;
	}
}
void read_thread_mutex(int a) {
	while (true)
	{
		unique_lock<mutex> ul(g_mtx);  //��һ�����������ռ �������߳�ֻ�ܵ����������ܻ������������һ��
		g_CV.wait(ul);  //���unique_lcok�������̣߳�ֱ��һ��notify_all�ĺ���
		cout << g_value << endl;
	}
}
void write_thread(int b) {
	while (true)
	{
		while (g_data_ready.load());
		//_sleep(100);
		//this_thread::sleep_for(100);
		this_thread::sleep_for(chrono::seconds(1));
		g_value++;
		g_data_ready = true;
	}
}
void write_thread_mutex(int b) {
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(1));  //ȷ������߳�������У�ÿ�ζ��ܵ�read����������
		lock_guard<mutex> lg(g_mtx);  //����Ļ�����������Ĳ�һ�������������������� �൱�ڷ���ĸ����������
		g_value++;
		g_CV.notify_all();//֪ͨ����
	}
}
class atomicpro {  //ԭ�Ӳ���  
public:
	static void ato1() {  //��׼ԭ�Ӳ�����������������ԭ�Ӳ���
		thread th(read_thread, 1);
		th.detach();  //��ͬ��join���˳� �����̶߳�������һ���߳��˳������ͷ����з������Դ������ detach �� *this ����ռ���κ��̡߳�
		thread th2(write_thread,2);
		th2.detach();
		char a;
		while (cin >> a);
	}
	static void ato2() {  //��������������ԭ�Ӳ���
		thread th(read_thread_mutex, 1);
		th.detach(); 
		thread th2(write_thread_mutex, 2);
		th2.detach();
		/*thread th3(write_thread_mutex, 3);
		th3.detach();*/
		char a;
		while (cin >> a);

	}
};
/*******************************/
condition_variable condi;
mutex mtx;  //ȫ�ֻ�����  ������һ���̵߳ģ�
int travelcount = 0;
string taxi;
void travel_arrival(string name) {
	cout << "Travel: " << name << " need a taxi now" << endl;
	unique_lock<mutex> unilock(mtx);
	travelcount++;
	condi.wait(unilock);
	cout << "Travel: " << name << " has got a taxi " << taxi<<endl;
	travelcount--;
}
void taxi_arrival(string name) {
	cout << "Taxi: " << name << "arrival " << endl;
	while (1)
	{
		lock_guard<mutex> lg(mtx);
		if (travelcount > 0) {
			taxi = name;
			condi.notify_all();
			break;
		}
	}
}
class taxi {
public:
	static void taxiwait() {
		thread th1(taxi_arrival," taxi_jack ");
		Sleep(100);
		thread th5(taxi_arrival, " taxi_king ");
		Sleep(100);
		thread th6(taxi_arrival, " taxi_queen");
		Sleep(100);
		thread th2(travel_arrival, " travel_hzh ");
		Sleep(100);
		thread th3(taxi_arrival, " taxi_tom ");
		Sleep(100);  //(ֻ�������¼���ֹ�̳߳���������������)
		thread th4(travel_arrival, " travel_hlh ");
		th1.join();
		th2.join();
		th3.join();
		th4.join();
		th5.join();
		th6.join();
	}
};

/*3���̵߳�ID�ֱ�ΪA��B��C�����Լ���ID����Ļ�ϴ�ӡ10�飬��ABC��˳����ʾ���磺ABCABC��.���ε���*/
mutex x;
condition_variable cond;
int loop = 10;
int flag = 0;
void print(int id) {
	for (int i = 0; i < 10; i++) {
		unique_lock<mutex> uq(x);
		while (flag != id)
			cond.wait(uq);//�����unique��ͬ��lock_guard �������unlock()��Ҳ���ǽ���
		cout << static_cast<char>('A' + id) << " ";
		flag = (flag + 1) % 3;
		cond.notify_all();  //֪ͨ�����߳�
	}
}
class printabc {
public:
	static void main() {
		thread t1(print, 0);
		thread t2(print, 1);
		print(2);
		cout << endl;
		t1.join();
		t2.join();
	}
};

/*���ĸ��߳�1��2��3��4���߳�1�Ĺ��ܾ������1���߳�2�Ĺ��ܾ������2���Դ�����.........�������ĸ��ļ�ABCD
A��1 2 3 4 1 2....
B��2 3 4 1 2 3....
C��3 4 1 2 3 4....
D��4 1 2 3 4 1....
mutex x;
condition_variable cond;
int loop = 10;
int flag = 0;(�����Ѿ�������)
*/
void file4abcd(int num) {
	for (int i = 0; i < loop; i++) {
		unique_lock<mutex> uq(x);
		while (flag != num) 
			cond.wait(uq);
		cout << num + 1 << " ";
		flag = (flag + 1) % 4;
		cond.notify_all();
	}
}
class fileabcd {
public:
	static void main() {
		int k = 0;
		int abcdvec[4]={0,1,2,3};
		while (k<4)
		{
			flag = abcdvec[k];
			thread one(file4abcd, 1);
			thread two(file4abcd, 2);
			thread three(file4abcd, 3);
			file4abcd(0);
			one.join();
			two.join();
			three.join();
			cout << endl;
			k++;
		}	
	}
};

/*����д������
��һ��д�ߺܶ���ߣ�������߿���ͬʱ���ļ�����д����д�ļ�ʱ�������ж����ڶ��ļ���ͬ���ж��߶�ʱд��Ҳ����д
*/
class rwlock {
private:
	mutex _lock;
	condition_variable writecon, readcon;
	unsigned writer, reader;
	int active;//��������� ����Ϊ0 дΪ1 ��Ϊn
public:
	void read_lock() {
		unique_lock<mutex> lock(_lock);
		reader++;
		while (active < 0 && writer>0)
			readcon.wait(lock);
		reader--;
		active++;//
	}
	void write_lock() {
		unique_lock<mutex> lock(_lock);
		writer++;
		while (active != 0)
			writecon.wait(lock);
		writer--;
		active = -1;//������reader��writer������
	}
	void unlock() {
		unique_lock<mutex> lock(_lock);
		if (active > 0) {
			active--;
			if (active == 0)
				writecon.notify_one();
		}
		else  //writer������
		{
			active = 0;
			if (writer > 0)
				writecon.notify_one();
			else if(reader>0)
			{
				readcon.notify_all();  //����Ķ�����֪ͨ���� ������������������Ƶ�id!=num ���������ж���
			}
		}
	}
	rwlock() :writer(0), reader(0), active(0) {};
};
void t1(rwlock* rwl) {
	while (1)
	{
		cout << "I want to write. " << endl;
		rwl->write_lock();
		cout << "writing..." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		rwl->unlock();
		this_thread::sleep_for(chrono::seconds(4));
	}
}
void t2(rwlock* rwl) {
	while (1) {
		cout << "A want to read." << endl;
		rwl->read_lock();
		cout << "A reading..." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		rwl->unlock();
	}
}
void t3(rwlock* rwl) {
	while (1) {
		cout << "B want to read." << endl;
		rwl->read_lock();
		cout << "B reading..." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		rwl->unlock();
	}
}
class rwlockshow {
public:
	static void main() {
		rwlock* rwl = new rwlock();
		thread t1(t1, rwl);
		Sleep(100);
		thread t2(t2, rwl);
		Sleep(100);
		thread t3(t3, rwl);
		t1.join();
		t2.join();
		t3.join();
	}
};
#pragma once
