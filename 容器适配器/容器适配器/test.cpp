//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <algorithm>
//#include <list>
//#include <deque>
//using namespace std;
//
///*
//struct Mul2
//{
//	int operator()(int x, int y)
//	{
//		return x + 2 * y;
//	}
//};
//
//void test1()
//{
//	//�������е�Ԫ�ؽ����ۼ�
//	vector<int> v{ 10, 20, 30 };
//	cout << accumulate(v.begin(),v.end(),1) << endl;
//
//	// �������е�ÿ��Ԫ�س�2��Ȼ���ۼ�
//	// �����е�ÿһ��Ԫ�ذ��� Mul2 �е���������������֮�� + ������ 2
//	cout << accumulate(v.begin(), v.end(), 2, Mul2())<<endl;
//}
//
//
//// ͳ���������������ֵĴ���
//bool isOdd(int i)
//{
//	return (i % 2 == 1);
//}
//void test2(){
//	//ͳ��10��v1�г��ֵĴ���
//	vector<int> v1{ 10, 2, 2, 3, 4 , 5, 6, 7, 8, 10 };
//	cout << count(v1.begin(), v1.end(), 10) << endl;
//	// ͳ��v1���ж��ٸ�����
//	cout << count_if(v1.begin(), v1.end(), isOdd) << endl;
//}
//
//void test(){
//	vector<int> v{ 12, 4, 5, 6, 2 };
//	list<int> L{ 3, 5, 2, 10, 4 };
//
//	sort(v.begin(), v.end());
//	L.sort();
//
//	vector<int> Vret(v.size() + L.size());
//	// ����Ҫ������ܵ��õ�ǰ�ϲ�����
//	merge(v.begin(),v.end(),L.begin(),L.end(),Vret.begin());
//
//	for (auto e : Vret)
//		cout << e << " ";
//	cout << endl;
//}
//
//
//void test()
//{
//	deque<int> dq;
//	dq.push_back(1);
//	dq.push_back(1);
//	dq.push_back(3);
//	dq.push_back(5);
//
//	for (auto e : dq)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//*/
//
//// ����������ʵ�� stack , queue , priority_queue
//
//// stack��ʵ��
//				// �ײ�ʵ������Ĭ��Ϊ˫�˶���
//template<class T,class Container = deque<T>>
//class Stack
//{
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//	}
//
//	void pop()
//	{
//		_c.pop_back();
//	}
//
//	const T& top()
//	{
//		return _c.back();
//	}
//	
//	size_t size() const
//	{
//		return _c.size();
//	}
//
//	bool empty() const
//	{
//		return _c.empty();
//	}
//private:
//	Container _c;
//};
//
//// ��������������ʵ��queue
//template<class T,class Container=deque<T>>
//class Queue
//{
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//	}
//
//	void pop()
//	{
//		_c.pop_front();
//	}
//
//	T& front()
//	{
//		return _c.front();
//	}
//
//	T& back()
//	{
//		return _c.back();
//	}
//
//	size_t size() const
//	{
//		return _c.size();
//	}
//
//	bool empty() const
//	{
//		return _c.empty();
//	}
//private:
//	Container _c;
//};
//
//template<class T>
//struct Greater
//{
//	bool operator()(const T& val1, const T& val2)
//	{
//		return val1 > val2;
//	}
//};
//
//template<class T>
//struct Less
//{
//	bool operator()(const T& val1, const T& val2)
//	{
//		return val1 < val2;
//	}
//};
//// ����������ʵ�����ȼ�����
//// ��һ���º���������������
//template<class T,class Container = vector<T>,class Compare=Greater<T>>
//class Priority_Queue
//{
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//		shiftUp(_c.size() - 1);
//	}
//
//	void pop()
//	{
//		swap(_c[0], _c[_c.size() - 1]);
//		_c.pop_back();
//		ShiftDown(0);
//	}
//
//	T& top()
//	{
//		return _c.front();
//	}
//
//	size_t size() const
//	{
//		return _c.size();
//	}
//
//	bool empty() const
//	{
//		return _c.empty();
//	}
//private:
//	void Swap(int& a, int& b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//
//	void ShiftDown(int parent)
//	{
//		int child = 2 * parent + 1;
//		while (child < _c.size())
//		{
//			// ͨ���º���ʵ�ֱȽ��߼�
//			if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1]))
//				//if (child + 1 < _c.size() && _c[child]< _c[child + 1])
//				child++;
//			//if (_c[parent] < _c[child])
//			if (_cmp(_c[parent], _c[child]))
//			{
//				swap(_c[parent], _c[child]);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else{
//				break;
//			}
//		}
//	}
//
//	// ���ϵ�����ʵ�ִ��
//	void shiftUp(int child)
//	{
//		int parent = (child - 1) >> 1;
//		
//		while (parent >= 0)
//		{
//			//if (_c[parent] < _c[child])
//			if (_cmp(_c[parent], _c[child]))
//			{
//				swap(_c[parent], _c[child]);
//				child = parent;
//				parent = (child - 1) >> 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//private:
//	Container _c;
//	Compare _cmp;
//};
//class Date{
//public:
//	Date(int y, int m, int d)
//		:_y(y)
//		, _m(m)
//		, _d(d)
//	{}
//
//	bool operator<(const Date& d) const
//	{
//
//		if (_y < d._y)
//			return true;
//		else if (_y == d._y)
//		{
//			if (_m < d._m)
//			{
//				return true;
//			}
//			else if (_m == d._m)
//			{
//				if (_d<d._d)
//					return true;
//			}
//		}
//		return false;
//
//	}
//
//	bool operator>(const Date& d) const
//	{
//		if (_y > d._y)
//			return true;
//		else if (_y == d._y)
//		{
//			if (_m > d._m)
//			{
//				return true;
//			}
//			else if (_m == d._m)
//			{
//				if (_d>d._d)
//					return true;
//			}
//		}
//		return false;
//	}
//public:
//	int _y;
//	int _m;
//	int _d;
//};
//
//ostream& operator<<(ostream& cout, const Date& d)
//{
//	cout << d._y << "-" << d._m << "-" << d._d << endl;
//	return cout;
//}
//void t2()
//{
//	Priority_Queue<Date, deque<Date>, Greater<Date>> pq;
//	pq.push(Date(3923, 23, 24));
//	pq.push(Date(3293, 3, 42));
//	pq.push(Date(3923, 30, 4));
//	pq.push(Date(393, 31, 24));
//	pq.push(Date(393, 13, 24));
//	pq.push(Date(3932, 3, 4));
//	while (!pq.empty())
//	{
//		cout << pq.top();
//		pq.pop();
//	}
//	cout << endl;
//}
//void testPriorityQueue()
//{
//	Priority_Queue<int> pq;
//	pq.push(61);
//	pq.push(13);
//	pq.push(8);
//	pq.push(6);
//	pq.push(5);
//	pq.push(3);
//	pq.push(90);
//
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}
//void testQ()
//{
//	Queue<int> q;
//	// vector:����ʵ�֣���Ϊ����pop_front
//	//Queue<int, vector<int>> q;
//	q.push(1);
//	q.push(51);
//	q.push(31);
//	q.push(12);
//	q.push(11);
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}
//void testST()
//{
//	//Stack<int> st;
//	//Stack<int, vector<int>> st;
//	Stack<int, list<int>> st;
//	st.push(12);
//	st.push(42);
//	st.push(22);
//	st.push(92);
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//}
//
//template<class T,class Container = vector<T>>
//class PRIORITY_QUEUE
//{
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//		shiftUp(_c.size() - 1);
//	}
//
//	void pop()
//	{
//		// �˴���pop��ͷɾ
//		// �ѵ�ͷɾ�ǽ���һ��λ�û������Ȼ��ɾ�����һ��
//		swap(_c[0], _c[_c.size() - 1]);
//		_c.pop_back();
//		shiftDown(0);
//	}
//
//	T& top()
//	{
//		return _c.front();
//	}
//
//	T& back()
//	{
//		return _c.back();
//	}
//
//	size_t size() const
//	{
//		return _c.size();
//	}
//
//	bool empty() const
//	{
//		return _c.empty();
//	}
//private:
//	// ����ΪС����
//	void shiftDown(int parent)
//	{
//		int child = 2 * parent + 1;
//		while (child < _c.size()){
//			if (child + 1 < _c.size() && _c[child + 1] < _c[child])
//				child++;
//			if (_c[parent] > _c[child])
//			{
//				swap(_c[parent], _c[child]);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else{
//				break;
//			}
//		}
//	}
//	// ���ϵ���ΪС��
//	void shiftUp(int child)
//	{
//		int parent = (child - 1) >> 1;
//
//		while (child > 0)
//		{
//			if (_c[child] < _c[parent])
//			{
//				swap(_c[child], _c[parent]);
//				child = parent;
//				parent = (child - 1) >> 1;
//			}
//			else{
//				break;
//			}
//		}
//	}
//private:
//	Container _c;
//};
//
//void testPQ(){
//	PRIORITY_QUEUE<int> PQ;
//	PQ.push(1);
//	PQ.push(14);
//	PQ.push(41);
//	PQ.push(21);
//	PQ.push(11);
//	PQ.push(10);
//
//	while (!PQ.empty())
//	{
//		cout << PQ.top() << " ";
//		PQ.pop();
//	}
//	cout << endl;
//}
//
//void t1(){
//	Priority_Queue<int, vector<int>, Greater<int>> pq;
//	pq.push(1);
//	pq.push(23);
//	pq.push(11);
//	pq.push(15);
//	pq.push(91);
//
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}
//
//
//
//int main1(){
//	t2();
//	//t1();
//	//testPQ();
//	//testPriorityQueue();
//	//testQ();
//	//testST();
//	//test();
//
//	system("pause");
//
//	return 0;
//}