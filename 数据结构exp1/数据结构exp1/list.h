#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


template <class elemType>
class list {
 public:
  virtual void clear() = 0;  // 清空线性表
  virtual int length() const = 0;  // 获取线性表的长度，即元素个数
  // 在第i个位置插入一个元素x
  virtual void insert(int i, const elemType &x) = 0;
  virtual void remove(int i) = 0;  // 删除第i个元素
  // 搜索元素x是否在线性表中出现
  virtual int search(const elemType &x) const = 0;
  virtual elemType visit(int i) const = 0;  // 访问线性表第i个元素
  virtual void traverse() const = 0;        // 遍历线性表
  virtual ~list() {};
};



#endif // LIST_H_INCLUDED
