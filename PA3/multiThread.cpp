#include <iostream>
#include <pthread.h>

using namespace std;
#define THREAD_NUM 5
void *printHello(void *input)
{
	int* tid;
	tid = (int*) input;
	cout<<"This is thread number:"<<*tid<<endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads [THREAD_NUM];
	for (int i = 0; i < THREAD_NUM; i++)
	{
		cout<<"main(): creating thread No. "<<i<<endl;
		pthread_create(&threads[i], NULL, printHello, &i);
	}
	cout<<"flag1"<<endl;
	for (int i = 0; i < THREAD_NUM; i++)
	{
		cout<<"waiting for threads to terminate"<<i<<endl;
		pthread_join(threads[i], NULL);
	}
	cout<<"flag2"<<endl;


}