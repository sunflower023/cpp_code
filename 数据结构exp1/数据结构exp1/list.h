#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


template <class elemType>
class list {
 public:
  virtual void clear() = 0;  // ������Ա�
  virtual int length() const = 0;  // ��ȡ���Ա�ĳ��ȣ���Ԫ�ظ���
  // �ڵ�i��λ�ò���һ��Ԫ��x
  virtual void insert(int i, const elemType &x) = 0;
  virtual void remove(int i) = 0;  // ɾ����i��Ԫ��
  // ����Ԫ��x�Ƿ������Ա��г���
  virtual int search(const elemType &x) const = 0;
  virtual elemType visit(int i) const = 0;  // �������Ա��i��Ԫ��
  virtual void traverse() const = 0;        // �������Ա�
  virtual ~list() {};
};



#endif // LIST_H_INCLUDED
