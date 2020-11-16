
#include <iostream>
using namespace std;
#include<deque>
//stl-stack
namespace mlk
{
	template<class T,class Con = deque<T>>
	class stack
	{
	public:
		stack(){}
		void push(const T& x)
		{
			c.push_back(x);
		}
		void pop()
		{
			if (c.empty())
				return;
			c.pop_back();
		}
		T& top()
		{
			return c.back();
		}
		const T& top()const
		{
			return c.back();
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
}
int main()
{
	mlk::stack<int,deque<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	cout << st.size() << endl;
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
