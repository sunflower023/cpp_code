#pragma once


template<class T>
class shared_ptr
{
public:
	shared_ptr(T* ptr = nullptr, function<void(T*)> del = ([](T* ptr) {delete ptr}))
		:_ptr(ptr)
		,_count(new int(1))
		,_del(del)
	{}

	shared_ptr(const shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		,_pcount(sp._pcount)
		,_del(sp._del)
	{
		(*_pcount)++;
	}

	void release()
	{
		if (--(*_pcount) == 0)
		{
			_del(_ptr);
			delete _pcount;
			_ptr = nullptr;
			_pcount = nullptr;
		}
	}

	~shared_ptr()
	{
		release();
	}

	shared_ptr<T>& operator=(const shared_ptr<T>& sp)
	{
		//判断是否是给自己赋值
		if (_ptr == sp._ptr)
		{
			return *this;
		}
		else
		{
			//该判断必须有，否则就会造成内存泄漏
			if (--(*_pcount) == 0)
				release();

			_ptr = sp._ptr;
			_pcount = sp._pcount;
			_del = sp._del;
			++(*_pcount);

			return *this;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator[](size_t pos)
	{
		return _ptr[pos];
	}

	T* get()const
	{
		return _ptr;
	}

	int use_count() const
	{
		return *_pcount;
	}


private:
	T* _ptr;
	int* _pcount;

	funciton<void(T*)> _del;
};