
#include<iostream>
#include<deque>
using namespace std;

	template<class T, class Con = deque<T>>
	class queue
	{
	public:
		queue() {}
		void push(const T& x)
		{
			c.push_back(x);
		}
		void pop()
		{
			if (c.empty())
				return;
			c.pop_front();
		}
		T& back()
		{
			return c.back();
		}
		const T& back()const
		{
			return c.back();
		}
		T& front()
		{
			return c.front();
		}
		const T& front()const
		{
			return c.front();
		}
		size_t size()const
		{
			return c.size();
		}
		bool empty()const
		{
			return c.empty();
		}

	private:
		Con c;
	};

int main()
{
	queue<float, deque<float>> q;
	q.push(1.1);
	q.push(2.2);
	q.push(3.3);
	q.push(4.4);
	q.push(5.4);
	cout << q.size() << endl;
	cout << q.back() << endl;
	cout << q.front() << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
