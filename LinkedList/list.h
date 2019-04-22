#pragma once

template<typename T>
class list
{
public:
	struct _Node
	{
		_Node()
		{

		}

		T* _data = nullptr;
		_Node* _prev = nullptr;
		_Node* _next = nullptr;

		bool operator == (const _Node& other)
		{
			if (other._data == this->_data &&
				other._next == this->_next &&
				other._prev == this->_prev)
				return true;
			else
				return false;
		}
	};

	struct iterator
	{
		_Node* _pNode = nullptr;

		iterator() {}
		iterator(_Node* node) : _pNode(node) {}
		virtual ~iterator() {}

		T* operator* ()
		{
			return _pNode->_data;
		}

		bool operator == (const iterator& other)
		{
			return _pNode == other._pNode;
		}

		bool operator !=(const iterator & other)
		{
			return !(*this == other);
		}

		void operator++()
		{
			_pNode = _pNode->_next;
		}
	};
private:
	_Node* _begin_node = nullptr;
	_Node* _end_node = nullptr;
public:
	list();
	virtual ~list();

	const iterator& begin() {
		iterator iter = iterator(_begin_node);
		return iter;
	}
	const iterator& end() {
		iterator iter = iterator(_end_node);
		return iter;
	}

	_Node& erase(_Node& _where)
	{
		if (_where._data)
			delete _where._data;

		_Node* _this = _where._prev->_next;

		_where._prev->_next = _where._next;
		_where._next->_prev = _where._prev;

		delete _this;
	}

	void push_back(T _data);
	void clear()
	{
		_Node* _cur = _begin_node->_next;
		delete _begin_node->_data;
		_begin_node->_data = nullptr;

		while (_cur != _end_node)
		{
			_Node* _next = _cur->_next;

			delete _cur->_data;
			delete _cur;

			_cur = _next;
		}

		_begin_node->_next = _end_node;
		_end_node->_prev = _begin_node;
	}
};

template<typename T>
inline list<T>::list()
{
	_begin_node = new _Node;
	_end_node = new _Node;

	_begin_node->_next = _end_node;
	_begin_node->_prev = nullptr;
	_begin_node->_data = nullptr;

	_end_node->_next = nullptr;
	_end_node->_prev = _begin_node;
	_end_node->_data = nullptr;
}

template<typename T>
inline list<T>::~list()
{
	clear();
	delete _begin_node;
	delete _end_node;
}

template<typename T>
inline void list<T>::push_back(T _data)
{
	_Node* _new_iter = new _Node;

	_new_iter->_prev = _end_node->_prev;
	_new_iter->_next = _end_node;
	_new_iter->_data = new T(_data);

	_end_node->_prev->_next = _new_iter;

	_end_node->_prev = _new_iter;
	_end_node->_next = nullptr;
}