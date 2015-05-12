
#include <iostream>


class Noncopyable {
public:
  // �R���X�g���N�^�A�f�X�g���N�^�͊e���ɂ܂�����
  Noncopyable() = default;
  ~Noncopyable() = default;
private:
  // Noncopyable�̋@�\��
  // Object obj = other; �֎~
  Noncopyable(const Noncopyable&) = delete;

  // obj = other; �֎~
  Noncopyable operator = (const Noncopyable&) = delete;
};

class Object : public Noncopyable {
private:
  int val;
public:
  // �R�s�[�R���X�g���N�^
  /*Object(const Object& obj) {
    *this = obj;
  }*/
  // ������Z�q
  /*Object& operator =(const Object& obj) {
    this->val = obj.val;
    return *this;
  }*/
  Object() {
    std::cout << "Object�̃R���X�g���N�^���Ă΂�܂���" << std::endl;
  }
  // �ϊ��R���X�g���N�^
  Object(const int& val) : val(val) {}

  void show() {
    std::cout << val << std::endl;
  }
};


int main() {
  Object obj1(10);
  Object obj2(20);
  obj1.show();
  obj2.show();

  // �R�s�[������������Ȃ�
  //obj1 = obj2; // err
  //Object obj3 = obj1; // err
}