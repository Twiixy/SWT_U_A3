#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mtx;

void work(int dauer) { //thread schlafen
	this_thread::sleep_for(chrono::milliseconds(dauer));
}

void workref(int& dauer) {
	this_thread::sleep_for(chrono::milliseconds(dauer));
}

void workMutex(int dauer) {
	lock_guard<mutex> lk(mtx);//macht mutex lock und unlock im scope
	mtx.lock();//locked solange bis unlock
	this_thread::sleep_for(chrono::milliseconds(dauer));
	mtx.unlock();
}

class ThreadS {


public:

	void startThread() {
		thread neuerThread(work, 500);	
		neuerThread.join(); //ende alles wartet
	}

	void startrefThread() {
		int a = 2;
		thread neuerThread(workref, ref(a));//hier muss ref hin
		neuerThread.join();
	}
	


};