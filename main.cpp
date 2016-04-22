
#pragma once


class Noncopyable {
protected:
  // Object obj = other; 禁止
  Noncopyable(const Noncopyable&) = delete;

  // obj = other; 禁止
  Noncopyable operator = (const Noncopyable&) = delete;

  // コンストラクタ,デストラクタ default指定
  Noncopyable() = default;
  virtual ~Noncopyable() {};
};

class Object : public Noncopyable {
private:
  int val;
public:
  // コピーコンストラクタ
  /*Object(const Object& obj) {
    *this = obj;
  }*/
  // 代入演算子
  /*Object& operator =(const Object& obj) {
    this->val = obj.val;
    return *this;
  }*/
  Object() {
    std::cout << "Objectのコンストラクタが呼ばれました" << std::endl;
  }
  // 変換コンストラクタ
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

  // コピー＆代入を許可しない
  //obj1 = obj2; // err
  //Object obj3 = obj1; // err
}